<?php
$conn = mysqli_connect("localhost", "root", "", "ajmal");

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

$message = "";
$student = null;

// Fetch all existing roll numbers for dropdown
$rollnos = [];
$q = mysqli_query($conn, "SELECT rollno FROM student ORDER BY rollno ASC");
while ($row = mysqli_fetch_assoc($q)) {
    $rollnos[] = $row['rollno'];
}

// When clicking the LOAD button
if (isset($_POST['load_student'])) {
    $rollno = (int)$_POST['rollno'];

    $query = mysqli_query($conn, "SELECT * FROM student WHERE rollno = $rollno");

    if (mysqli_num_rows($query) > 0) {
        $student = mysqli_fetch_assoc($query);
    } else {
        $message = "Student not found.";
    }
}

// When clicking the SAVE button
if (isset($_POST['save_student'])) {
    $rollno = (int)$_POST['rollno'];
    $name = mysqli_real_escape_string($conn, $_POST['name']);
    $gender = mysqli_real_escape_string($conn, $_POST['gender']);
    $email = mysqli_real_escape_string($conn, $_POST['email']);
    $password = $_POST['password'];

    $update_sql = "
        UPDATE student 
        SET name='$name', gender='$gender', email='$email', password='$password'
        WHERE rollno = $rollno
    ";

    if (mysqli_query($conn, $update_sql)) {
        $message = "Student updated successfully!";
    } else {
        $message = "Error: " . mysqli_error($conn);
    }
}

mysqli_close($conn);
?>

<!-- Display Messages -->
<?php if($message) echo "<p>$message</p>"; ?>

<h2>Edit Student</h2>

<!-- Step 1: Roll Number Dropdown + Load Button -->
<form method="POST">

    <label><b>Select Roll No:</b></label>
    <select name="rollno" required>
        <option value="">Choose...</option>
        <?php
            foreach ($rollnos as $r) {
                echo "<option value='$r'>$r</option>";
            }
        ?>
    </select>

    <button type="submit" name="load_student">Load</button>
</form>

<hr>

<?php if ($student): ?>
<form method="POST">

    <input type="hidden" name="rollno" value="<?php echo $student['rollno']; ?>">

    <label>Full Name:</label><br>
    <input type="text" name="name" required value="<?php echo $student['name']; ?>"><br><br>

    <label>Gender:</label><br>
    <input type="radio" name="gender" value="male"   <?php if ($student['gender']=="male") echo "checked"; ?>> Male
    <input type="radio" name="gender" value="female" <?php if ($student['gender']=="female") echo "checked"; ?>> Female
    <input type="radio" name="gender" value="other"  <?php if ($student['gender']=="other") echo "checked"; ?>> Other
    <br><br>

    <label>Email:</label><br>
    <input type="email" name="email" required value="<?php echo $student['email']; ?>"><br><br>

    <label>Password:</label><br>
    <input type="text" name="password" required value="<?php echo $student['password']; ?>"><br><br>

    <button type="submit" name="save_student">Save Changes</button>

</form>
<?php endif; ?>
