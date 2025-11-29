
<style>
    :root{
        --primary-color : #20a7db;
        --button-color : #097969;
        --input-color : #cfecf7;
    }
    body{
        background: var(--primary-color);
        display: flex;
        justify-content: center;
        align-items: center;
        font-family:Arial, Helvetica, sans-serif;
    }
    .content{
        display: flex;
        justify-content: center;
        align-items: center;
        flex-direction: column;
        background-color: var(--button-color);
        width: 300px;
        border-radius: 10px;
        color: #fff;
    }

    
</style>

<?php
session_start();

if (!isset($_SESSION['user_logged_in']) || $_SESSION['user_logged_in'] !== true) {
    header("Location: login.php");
    exit;
}

$email = $_SESSION['user_email'];

$conn = mysqli_connect("localhost", "root", "", "ajmal");

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

$sql = "SELECT name, rollno, gender FROM student WHERE email = '{$email}'";
$result = mysqli_query($conn, $sql);

if ($result && mysqli_num_rows($result) > 0) {
    $row = mysqli_fetch_assoc($result);

    $name = htmlspecialchars($row["name"]);
    $rollno = htmlspecialchars($row["rollno"]);
    $gender = htmlspecialchars($row["gender"]);

    echo <<<HTML
    <div class="content">
        <p><strong>Name:</strong> {$name}</p>
        <p><strong>Roll No:</strong> {$rollno}</p>
        <p><strong>Gender:</strong> {$gender}</p>
    </div>
    HTML;
} else {
    echo "<p>No student record found for this email.</p>";
}

mysqli_close($conn);
?>
