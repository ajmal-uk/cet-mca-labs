<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Mark List</title>
    <style>
        body {
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background: #f0f4f8;
        }

        form {
            background: antiquewhite;
            padding: 30px 40px;
            border-radius: 10px;
            box-shadow: 0 10px 25px rgba(0, 0, 0, 0.1);
            display: flex;
            flex-direction: column;
            gap: 15px;
            width: 300px;
        }

        input[type="text"], input[type="number"], select {
            padding: 10px 12px;
            border-radius: 10px;
            border: 1px solid #ccc;
            font-size: 16px;
            outline: none;
            transition: border-color 0.3s, box-shadow 0.3s;
        }

        input[type="submit"], input[type="reset"] {
            padding: 12px;
            background-color: #007BFF;
            color: white;
            border: none;
            border-radius: 6px;
            font-size: 16px;
            cursor: pointer;
            transition: background-color 0.3s;
        }

        input[type="submit"]:hover {
            background-color: #0056b3;
        }

        .btn-group {
            display: flex;
            justify-content: center;
            gap: 10px;
        }

    </style>
</head>
<body>
    <form action="/aj/data.php" method="post">
        <input type="text" name="name" placeholder="full name" required>
        <input type="number" name="rollno" placeholder="rollno" required>
        <input type="number" name="age" placeholder="age" required>
        <select name="gender">
            <?php
                $genders = ["male","female","other"];
                for ($i = 0; $i < count($genders); $i++) {
                    echo "<option value='$genders[$i]'>". ucfirst($genders[$i]). "</option>";
                }

            ?>
        </select>

        <input type="number" name="mark1" placeholder="Mark1" required>
        <input type="number" name="mark2" placeholder="Mark2" required>
        <div class="btn-group">
            <input type="submit" value="Submit">
            <input type="reset" value="Reset">
        </div>

    </form>

    <a href="/aj/result.php">Show All data</a>
</body>
</html>