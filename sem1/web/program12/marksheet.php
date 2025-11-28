<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Mark Sheet</title>
    <style>
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background-color: #f4f6f9;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
        }

        .card {
            background: white;
            padding: 30px 40px;
            border-radius: 12px;
            box-shadow: 0 8px 20px rgba(0, 0, 0, 0.1);
            width: 400px;
        }

        h1 {
            color: #007BFF;
            text-align: center;
            margin-bottom: 10px;
        }

        h3 {
            text-align: center;
            color: #555;
            margin: 5px 0;
        }

        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }

        th, td {
            padding: 10px;
            border: 1px solid #ccc;
            text-align: center;
        }

        th {
            background-color: #007BFF;
            color: white;
        }

        tr:last-child {
            background-color: #e9f3ff;
            font-weight: bold;
        }
    </style>
</head>
<body>
    <?php
        $name = $_POST["name"];
        $dob = $_POST["dob"];
        $gender = $_POST["gender"];
        $web_mark = $_POST["web"];
        $ds_mark = $_POST["ds"];
        $python_mark = $_POST["python"];
        $total_mark = $_POST["total"];
    ?>

    <div class="card">
        <h1>Student Mark Sheet</h1>
        <h3><?php echo htmlspecialchars($name); ?></h3>
        <h3>DOB: <?php echo htmlspecialchars($dob); ?></h3>
        <h3>Gender: <?php echo ucfirst($gender); ?></h3>

        <table>
            <tr>
                <th>Subject</th>
                <th>Marks</th>
            </tr>
            <tr>
                <td>Web Development</td>
                <td><?php echo $web_mark; ?></td>
            </tr>
            <tr>
                <td>Data Structures</td>
                <td><?php echo $ds_mark; ?></td>
            </tr>
            <tr>
                <td>Python</td>
                <td><?php echo $python_mark; ?></td>
            </tr>
            <tr>
                <td>Total</td>
                <td><?php echo $total_mark; ?></td>
            </tr>
        </table>
    </div>
</body>
</html>
