<?php
$conn = mysqli_connect("localhost", "root", "", "ajmal");

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
    
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $rollno = $_POST['rollno'];
    $mark1 = $_POST['mark1'];
    $mark2 = $_POST['mark2'];
    $mark3 = $_POST['mark3'];

    if (!empty($rollno) && $mark1 !== '' && $mark2 !== '' && $mark3 !== '') {
        // Check if rollno already exists in the mark table
        $check_query = "SELECT * FROM mark WHERE rollno = '$rollno'";
        $result = mysqli_query($conn, $check_query);

        if (mysqli_num_rows($result) > 0) {
            // Roll number exists → update marks
            $update_query = "UPDATE mark 
                             SET mark1 = '$mark1', mark2 = '$mark2', mark3 = '$mark3' 
                             WHERE rollno = '$rollno'";
            if (mysqli_query($conn, $update_query)) {
                echo "<script>alert('Marks updated successfully!');</script>";
            } else {
                echo "<script>alert('Error updating marks: " . mysqli_error($conn) . "');</script>";
            }
        } else {
            // Roll number not found → insert new record
            $insert_query = "INSERT INTO mark (rollno, mark1, mark2, mark3) 
                             VALUES ('$rollno', '$mark1', '$mark2', '$mark3')";
            if (mysqli_query($conn, $insert_query)) {
                echo "<script>alert('Marks added successfully!');</script>";
            } else {
                echo "<script>alert('Error inserting marks: " . mysqli_error($conn) . "');</script>";
            }
        }
    } else {
        echo "<p style='color:red;'>Please fill all fields!</p>";
    }
}
?>

<h2>Add / Update Student Marks</h2>

<form method="POST">
    <label>Select Roll No:</label><br>
    <select name="rollno" required>
        <option value="">-- Select Roll No --</option>
        <?php
        $result = mysqli_query($conn, "SELECT rollno, name FROM student");
        while ($row = mysqli_fetch_assoc($result)) {
            echo "<option value='" . $row['rollno'] . "'>" . $row['rollno'] . " - " . htmlspecialchars($row['name']) . "</option>";
        }
        ?>
    </select><br><br>

    <label>Mark 1:</label><br>
    <input type="number" name="mark1" required><br><br>

    <label>Mark 2:</label><br>
    <input type="number" name="mark2" required><br><br>

    <label>Mark 3:</label><br>
    <input type="number" name="mark3" required><br><br>

    <input type="submit" value="Save">
</form>

<?php mysqli_close($conn); ?>