<style>
    :root{
        --primary-color : #20a7db;
        --button-color : #097969;
        --input-color : #cfecf7;
    }
    body{
        background: var(--primary-color);
        font-family:Arial, Helvetica, sans-serif;
    }
    form{
        display: flex;
        justify-content: center;
        align-items: center;
        flex-direction: column;
    }
    form input[type="password"]{
        margin-top: 100px;
        width: 300px;
        padding: 10px;
        margin-bottom: 20px;
        background-color: var(--input-color);
        border: none;
        border-radius: 15px;
    }
    button{
        width: 200px;
        padding: 10px;
        background-color: var(--button-color);
        color: #fff;
        border: none;
        border-radius: 15px;
    }
</style>

<?php 
session_start();

if (!isset($_SESSION['user_logged_in']) || $_SESSION['user_logged_in'] !== true) {
    header("Location: login.php");
    exit;
}

$conn = mysqli_connect("localhost", "root", "", "ajmal");

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

$email = mysqli_real_escape_string($conn, $_SESSION['user_email']);

$message = "";

if ($_SERVER["REQUEST_METHOD"] === "POST") {

    $password = mysqli_real_escape_string($conn, $_POST["password"]);

    $sql = "UPDATE student SET password = '$password' WHERE email = '$email'";

    if (mysqli_query($conn, $sql)) {
        $message = "Password updated successfully!";
    } else {
        $message = "Error: " . mysqli_error($conn);
    }
}
?>

<?php if ($message) echo "<p>$message</p>"; ?>

<form method="post">
    <input type="password" placeholder="New Password" name="password" required>
    <button type="submit">Change</button>
</form>


