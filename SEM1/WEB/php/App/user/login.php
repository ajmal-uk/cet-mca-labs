<?php
        session_start();
        if (isset($_SESSION['user_logged_in']) && $_SESSION['user_logged_in'] === true) {
            header("Location: dashboard.php");
            exit;
        }

        $conn = mysqli_connect("localhost", "root", "", "ajmal");

        if (!$conn) {
            die("Connection failed: " . mysqli_connect_error());
        }

        
        if ($_SERVER["REQUEST_METHOD"] === "POST") {
            $email = $_POST['email'];
            $password = $_POST['password'];
            $sql_query = "SELECT email, password FROM student WHERE email = '$email' AND password = '$password'";

            $result = mysqli_query($conn, $sql_query);

            if ($result && mysqli_num_rows($result) === 1) {
                $_SESSION['user_logged_in'] = true;
                $_SESSION['user_email'] = $email;
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
    <title>User Login</title>
    <style>
        :root{
        --primary-color : #20a7db;
        --button-color : #097969;
        --input-color : #cfecf7;
        }
        body{
            font-family:Arial, Helvetica, sans-serif;
            background: var(--primary-color);
        }
        form{
            display: flex;
            justify-content: center;
            align-items: center;
            flex-direction: column;
        }
        form input[type="email"]{
            margin-top: 100px;
        }
        form input[type="password"],form input[type="email"]{
            width: 300px;
            padding: 10px;
            margin-bottom: 20px;
            background-color: var(--input-color);
            border: none;
            border-radius: 15px;
        }
        form input[type="submit"]{
            width: 200px;
            padding: 10px;
            background-color: var(--button-color);
            color: #fff;
            border: none;
            border-radius: 15px;
        }
    </style>
</head>
<body>
    <div>
        <form action="" method="POST">
            <input type="email" placeholder="email" name="email" class="email" id="email" required>
            <input type="password" placeholder="password" name="password" class="password" id="password">
            <input type="submit" class="submit-button">
        </form>
    </div>
</body>
</html>
