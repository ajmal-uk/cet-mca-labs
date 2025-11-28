<?php
session_start();
if (!isset($_SESSION['admin_logged_in']) || $_SESSION['admin_logged_in'] !== true) {
    header("Location: login.php");
    exit;
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin Dashboard - Student Management</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: Arial, sans-serif;
        }

        .sidebar {
            width: 230px;
            height: 100vh;
            background-color: #2c3e50;
            color: white;
            position: fixed;
            top: 0;
            left: 0;
            padding: 20px 0;
        }

        .sidebar h2 {
            text-align: center;
            margin-bottom: 30px;
            font-size: 22px;
        }

        .sidebar ul {
            list-style-type: none;
            padding-left: 0;
        }

        .sidebar ul li {
            margin: 15px 0;
        }

        .sidebar ul li a {
            color: white;
            text-decoration: none;
            padding: 10px 20px;
            display: block;
            border-left: 4px solid transparent;
            transition: 0.3s;
        }

        .sidebar ul li a:hover {
            background-color: #34495e;
            border-left: 4px solid #1abc9c;
        }

        .main-content {
            margin-left: 230px;
            height: 100vh;
            background-color: #ecf0f1;
        }
        iframe {
            width: 100%;
            height: 100%;
            border: none;
        }
    </style>
</head>
<body>
    <div class="sidebar">
        <h2>Admin Panel</h2>
        <ul>
            <li><a href="student.php" target="contentFrame">Student</a></li>
            <li><a href="add_student.php" target="contentFrame">Add Student</a></li>
            <li><a href="edit_student.php" target="contentFrame">Edit Student</a></li>
            <li><a href="mark_add.php" target="contentFrame">Add or Edit Mark</a></li>
            <li><a href="top_students.php" target="contentFrame">Top Students</a></li>
            <li style="margin-top: 40px;"><a style="background-color: red; color: white;" href="logout.php" target="_top">Logout</a></li>
        </ul>
    </div>
    <div class="main-content">
        <iframe name="contentFrame" src="student.php" frameborder="0"></iframe>
    </div>
</body>
</html>
