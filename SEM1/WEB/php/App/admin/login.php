<?php
        session_start();
        if (isset($_SESSION['admin_logged_in']) && $_SESSION['admin_logged_in'] === true) {
            header("Location: dashboard.php");
            exit;
        }

        $conn = mysqli_connect("localhost", "root", "", "ajmal");

        if (!$conn) {
            die("Connection failed: " . mysqli_connect_error());
        }

        
        if ($_SERVER["REQUEST_METHOD"] === "POST") {
            $email = $_POST['email-admin'];
            $password = $_POST['password-admin'];
            $sql_query = "SELECT email, password FROM admin WHERE email = '$email' AND password = '$password'";

            $result = mysqli_query($conn, $sql_query);

            if ($result && mysqli_num_rows($result) === 1) {
                $_SESSION['admin_logged_in'] = true;
                $_SESSION['admin_email'] = $email;
                header("Location: dashboard.php");
                exit;
            }
            else{
                echo"<script>alert('Invalid Email or Password');</script>";
            }
        }

        if ($conn) {
            mysqli_close($conn);
        }
    ?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin Login</title>
</head>
<body>

    <div>
        <form action="" method="POST">
            <input type="email" placeholder="email" name="email-admin" class="email-admin" id="email-admin" required>
            <input type="password" placeholder="password" name="password-admin" class="password-admin" id="password-admin">
            <input type="submit" class="submit-button">
        </form>

        
    </div>
</body>
</html>
