<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php 
        $name  = $_POST["name"];
        $age = $_POST["age"];
        $rollno = $_POST["rollno"];
        $gender = $_POST["gender"];
        $mark1 = $_POST["mark1"];
        $mark2 = $_POST["mark2"];
        

        $conn = mysqli_connect("localhost","root","","ajmal");
        if ($conn) {
            echo "Success";
        }else{
            echo "Not Success";
        }

        $check_query = "SELECT * FROM student WHERE rollno = $rollno";
        $result = mysqli_query($conn, $check_query);

        if (mysqli_num_rows($result) > 0) {
            echo "<script>alert('Roll number already exists!'); window.history.back();</script>";
        } else {
            $sql_query = "INSERT INTO student (name, rollno, age, gender, mark1, mark2) 
                        VALUES ('$name', $rollno, $age, '$gender', $mark1, $mark2)";
            
            if (mysqli_query($conn, $sql_query)) {
                echo "<script>alert('Student added successfully!');</script>";
            } else {
                echo "Error: " . mysqli_error($conn);
            }
        }

        mysqli_close($conn);
        ?>

        <a href="/aj/result.php">Show All Data</a>
    </body>
</html>