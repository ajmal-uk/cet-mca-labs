<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>View Students</title>
</head>
<body>
    <h2>All Students</h2>

    <?php 
        include('connection.php');
        $sql = "SELECT * FROM student";
        $result = mysqli_query($conn, $sql);

        if (mysqli_num_rows($result) > 0) {
            echo "<table border='1' cellpadding='10'>";
            echo "<tr>
                    <th>Name</th>
                    <th>Roll No</th>
                    <th>Age</th>
                    <th>Gender</th>
                    <th>Mark 1</th>
                    <th>Mark 2</th>
                  </tr>";

            while ($row = mysqli_fetch_assoc($result)) {
                echo "<tr>
                        <td>{$row['name']}</td>
                        <td>{$row['rollno']}</td>
                        <td>{$row['age']}</td>
                        <td>{$row['gender']}</td>
                        <td>{$row['mark1']}</td>
                        <td>{$row['mark2']}</td>
                      </tr>";
            }
            echo "</table>";
        } else {
            echo "No records found.";
        }

        mysqli_close($conn);
    ?>
</body>
</html>
