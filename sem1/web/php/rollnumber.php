<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>All Roll Numbers</title>
</head>
<body>
    <form>
        <label for="rollno">Select Roll Number:</label>
        <select name="rollno" id="rollno">
            <?php
            $conn = mysqli_connect("localhost", "root", "", "ajmal");

            if (!$conn) {
                die("Connection failed: " . mysqli_connect_error());
            }

            $sql = "SELECT rollno FROM student";
            $result = mysqli_query($conn, $sql);

            if (mysqli_num_rows($result) > 0) {
                while ($row = mysqli_fetch_assoc($result)) {
                    echo "<option value='{$row['rollno']}'>{$row['rollno']}</option>";
                }
            } else {
                echo "<option disabled>No roll numbers found</option>";
            }

            mysqli_close($conn);
            ?>
        </select>
    </form>
</body>
</html>
