<?php
session_start();

// Check login
if (!isset($_SESSION['user_logged_in']) || $_SESSION['user_logged_in'] !== true) {
    header("Location: login.php");
    exit;
}

$email = $_SESSION['user_email'];

// Database connection
$conn = mysqli_connect("localhost", "root", "", "ajmal");

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// ✅ You don’t need mysqli_prepare() if you’re using mysqli_query()
$sql = "SELECT name, rollno, gender FROM student WHERE email = '{$email}'";
$result = mysqli_query($conn, $sql);

if ($result && mysqli_num_rows($result) > 0) {
    $row = mysqli_fetch_assoc($result);

    $name = htmlspecialchars($row["name"]);
    $rollno = htmlspecialchars($row["rollno"]);
    $gender = htmlspecialchars($row["gender"]);

    echo <<<HTML
        <p><strong>Name:</strong> {$name}</p>
        <p><strong>Roll No:</strong> {$rollno}</p>
        <p><strong>Gender:</strong> {$gender}</p>
    HTML;
} else {
    echo "<p>No student record found for this email.</p>";
}

// Close connection
mysqli_close($conn);
?>
