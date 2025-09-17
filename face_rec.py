import cv2
import os
import glob
import numpy as np
from deepface import DeepFace
from PIL import Image


class SimpleFacerec:
    def __init__(self, model_name="ArcFace"):
        self.known_face_encodings = []
        self.known_face_names = []
        self.model_name = model_name

    def _safe_path(self, img_path):
        """Convert .webp to .jpg if needed so DeepFace can read properly"""
        if img_path.lower().endswith(".webp"):
            temp_path = img_path.replace(".webp", "_temp.jpg")
            Image.open(img_path).convert("RGB").save(temp_path)
            return temp_path
        return img_path

    def load_encoding_images(self, images_path):
        """Load and encode all images in a folder"""
        images_path = glob.glob(os.path.join(images_path, "*"))
        print(f"{len(images_path)} images found in {images_path}")

        for img_path in images_path:
            basename = os.path.basename(img_path)
            filename, _ = os.path.splitext(basename)

            try:
                safe_img = self._safe_path(img_path)
                embedding = DeepFace.represent(
                    img_path=safe_img,
                    model_name=self.model_name,
                    enforce_detection=False
                )[0]["embedding"]

                embedding = np.array(embedding)  # ArcFace is already normalized

                self.known_face_encodings.append(embedding)
                self.known_face_names.append(filename)
                print(f"[INFO] Loaded encoding for {filename}")
            except Exception as e:
                print(f"[WARNING] Could not encode {filename}: {e}")

    def match_image(self, query_img_path, tolerance=0.45):
        """Find best match for a query image"""
        try:
            safe_img = self._safe_path(query_img_path)
            embedding = DeepFace.represent(
                img_path=safe_img,
                model_name=self.model_name,
                enforce_detection=False
            )[0]["embedding"]

            query_encoding = np.array(embedding)

        except Exception as e:
            print(f"[ERROR] Could not process query image: {e}")
            return "Unknown"

        if not self.known_face_encodings:
            print("[ERROR] No known faces loaded")
            return "Unknown"

        # Cosine similarity
        similarities = [
            np.dot(query_encoding, known) / (
                np.linalg.norm(query_encoding) * np.linalg.norm(known)
            )
            for known in self.known_face_encodings
        ]

        best_match_index = np.argmax(similarities)
        best_score = similarities[best_match_index]

        print(f"[DEBUG] Similarities: {similarities}")
        print(f"[DEBUG] Best score: {best_score:.4f}")

        if best_score >= (1 - tolerance):  # e.g. 0.55 with tolerance=0.45
            return self.known_face_names[best_match_index]
        else:
            return "Unknown"


# ===== USAGE =====
sfr = SimpleFacerec(model_name="ArcFace")
sfr.load_encoding_images("images/")

query_image = "amartest.jpeg"  # ✅ use correct folder
best_match = sfr.match_image(query_image, tolerance=0.45)

print(f"[RESULT] Best match: {best_match}")
