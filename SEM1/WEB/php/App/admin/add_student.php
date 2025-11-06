<?php
$conn = mysqli_connect("localhost", "root", "", "ajmal");

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

$message = '';

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $name = mysqli_real_escape_string($conn, $_POST['name']);
    $rollno = (int)$_POST['rollno'];
    $gender = mysqli_real_escape_string($conn, $_POST['gender']);
    $email = mysqli_real_escape_string($conn, $_POST['email']);
    $password = $_POST['password'];

    $sql_query = "SELECT email, rollno FROM student WHERE email = '$email' OR rollno = $rollno";
    $result = mysqli_query($conn, $sql_query);

    if ($result && mysqli_num_rows($result) > 0) {
        $message = "Email or Roll No already exists!";
    } else {
        $sql_insert = "INSERT INTO student (name, rollno, gender, email, password) 
                       VALUES ('$name', $rollno, '$gender', '$email', '$password')";

        if (mysqli_query($conn, $sql_insert)) {
            $message = "Student registered successfully!";
        } else {
            $message = "Error: " . mysqli_error($conn);
        }
    }
}

mysqli_close($conn);
?>

<?php if($message) echo "<p>$message</p>"; ?>

<form action="" method="POST">
    <input type="text" name="name" id="name" placeholder="Full Name" required>
    <input type="number" name="rollno" id="rollno" placeholder="Roll No" required>

    <input type="radio" name="gender" value="male" id="male" required>
    <label for="male">Male</label>
    <input type="radio" name="gender" value="female" id="female" required>
    <label for="female">Female</label>
    <input type="radio" name="gender" value="other" id="other" required>
    <label for="other">Other</label>

    <input type="email" name="email" id="email" placeholder="Email" required>
    <input type="password" name="password" id="password" placeholder="Password" required>
    <input type="submit" value="Submit">
</form>
