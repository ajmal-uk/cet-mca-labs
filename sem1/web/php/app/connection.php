<?php
    $conn = mysqli_connect("localhost", "root", "", "ajmal");

    if (!$conn) {
        die("Connection failed: " . mysqli_connect_error());
    }
?>