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

$query = "
    SELECT * 
    FROM mark 
    WHERE rollno = (
        SELECT rollno FROM student WHERE email = '$email'
    )
";

$result = mysqli_query($conn, $query);

if (mysqli_num_rows($result) > 0) {
    while ($row = mysqli_fetch_assoc($result)) {
        $mark1 = $row["mark1"];
        $mark2 = $row["mark2"];
        $mark3 = $row["mark3"];
    }
    echo <<<EOF
    <div class="content">
        <table>
            <tr></tr>  
        </table>
        <ul>
            <li>Mark 1 : ${mark1}</li>
            <li>Mark 2 : ${mark2}</li>
            <li>Mark 3 : ${mark3}</li>
        </ul>
    </div>
EOF;
}
else{
    echo <<<EOF
    <p>Update Soon</p>
    EOF;
}
?>