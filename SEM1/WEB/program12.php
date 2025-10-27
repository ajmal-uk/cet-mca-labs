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

        input[type="text"], input[type="date"], select {
            padding: 10px 12px;
            border-radius: 10px;
            border: 1px solid #ccc;
            font-size: 16px;
            outline: none;
            transition: border-color 0.3s, box-shadow 0.3s;
        }

        input[type="submit"] {
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

        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 10px;
            border-radius: 8px;
            overflow: hidden;
        }

        th {
            
            background-color: #007BFF;
            color: white;
            text-align: left;
            padding: 10px;
        }

        td {
            padding: 10px;
        }

        table tr td input[type="number"] {
            width: 100%;
            padding: 8px;
            border-radius: 5px;
            border: 1px solid #ccc;
            box-sizing: border-box;
            font-size: 14px;
            outline: none;
            transition: border-color 0.3s, box-shadow 0.3s;
        }

        table tr td input[type="number"]:focus {
            border-color: #007BFF;
            box-shadow: 0 0 5px rgba(0, 123, 255, 0.5);
        }

        #total {
            width: 60%;
        }
        button{
            width: 35%;
            padding: 12px;
            background-color: #007BFF;
            color: white;
            border: none;
            border-radius: 6px;
            font-size: 16px;
            cursor: pointer;
            transition: background-color 0.3s;
        }
    </style>
</head>
<body>
    <form action="/aj/marksheet.php" method="post">
        <input type="text" name="name" placeholder="full name" required>
        <input type="date" name="dob" required>
        <select name="gender">
            <?php
                $genders = ["male","female","other"];
                for ($i = 0; $i < count($genders); $i++) {
                    echo "<option value='$genders[$i]'>". ucfirst($genders[$i]). "</option>";
                }

            ?>
        </select>
        <table border="1">
            <tr>
                <th>Subject</th>
                <th>Marks</th>
            </tr>
            <tr>
                <td>Web</td>
                <td>
                    <input type="number" name="web" id="web" min="0" max="60" required>
                </td>
            </tr>
            <tr>
                <td>DS</td>
                <td>
                    <input type="number" name="ds" id="ds" min="0" max="60" required>
                </td>
            </tr>
            <tr>
                <td>Python</td>
                <td>
                    <input type="number" name="python" id="python" min="0" max="60" required>
                </td>
            </tr>
            <tr>
                <td>Total</td>
                <td>
                    <input type="number" name="total" id="total" readonly>
                    <button type="button" onclick="totalMark()" >Calc</button>
                </td>
            </tr>
        </table>
        <input type="submit">
    </form>
    <script>

        function validateMark(input) {
            let value = Number(input.value);
            if (value < 0) input.value = 0;
            if (value > 60) input.value = 60;
        }

        const form = document.querySelector("form");

        form.addEventListener("submit", function(event) {
            totalMark();
        });

        document.getElementById("web").addEventListener("input", function() { validateMark(this); });
        document.getElementById("ds").addEventListener("input", function() { validateMark(this); });
        document.getElementById("python").addEventListener("input", function() { validateMark(this); });

        function totalMark(){
            const web_mark = Number(document.getElementById("web").value) || 0;
            const ds_mark = Number(document.getElementById("ds").value) || 0;
            const python_mark = Number(document.getElementById("python").value) || 0;


            document.getElementById("total").value= (web_mark + ds_mark + python_mark);
        }
    </script>
</body>
</html>