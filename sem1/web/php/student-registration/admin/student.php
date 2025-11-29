<?php
    $conn = mysqli_connect("localhost", "root", "", "ajmal");

    if (!$conn) {
        die("Connection failed: " . mysqli_connect_error());
    }

    $sql = "SELECT * FROM student";

    $result = mysqli_query($conn, $sql);
    if (mysqli_num_rows($result) <= 0) {
        echo "Not Student Yet";
    }
    else{
        echo <<<EOF
        <h2>Student Management</h2>
        <p>Here you can view and manage student information.</p>

        <table border="1" cellpadding="8">
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Gender</th>
                <th>Email</th>
            </tr>
        EOF;


        while ($row = mysqli_fetch_assoc($result)) {
            echo <<<EOF
                    <tr>
                        <th>{$row['rollno']}</th>
                        <th>{$row['name']}</th>
                        <th>{$row['gender']}</th>
                        <th>{$row['email']}</th>
                    </tr>
                EOF;
        }
        echo "</table>";
    }
?>