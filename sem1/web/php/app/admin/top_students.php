<?php
$conn = mysqli_connect("localhost","root","","ajmal");
if(!$conn){
    die("Connection Error: " . mysqli_connect_error());
}

$sql = "SELECT * FROM mark WHERE (mark1 + mark2 + mark3) = (SELECT MAX(mark1 + mark2 + mark3) FROM mark)";
$result = mysqli_query($conn, $sql);

if(mysqli_num_rows($result) > 0){
    while($row = mysqli_fetch_assoc($result)){
        $rollno = $row['rollno'];

        $sql2 = "SELECT * FROM student WHERE rollno = $rollno";
        $result2 = mysqli_query($conn, $sql2);

        if(mysqli_num_rows($result2) > 0){
            $student = mysqli_fetch_assoc($result2);
            echo "<p>Roll No: {$student['rollno']}</p>";
            echo "<p>Name: {$student['name']}</p>";
        }
    }
} else {
    echo "<p>No records found</p>";
}
?>
