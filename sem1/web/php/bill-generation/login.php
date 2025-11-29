<style>
    .container{
        width:100%;
        height:100vh;
        display:flex;
        justify-content:center;
        align-items:center;
        background:lightskyblue;
    }

    .container form{
        width:40%;
        display:flex;
        justify-content:center;
        align-items:center;
        flex-direction:column;
    }

    .container form input[type="text"],
    .container form input[type="password"]{
        width:200px;
        padding:10px;
        border-radius:10px;
        border:none;
        margin-bottom:20px;
    }

    .container form input[type="submit"]{
        width: 200px;
        padding:10px;
        color:white;
        background: blue;
        border:none;
        border-radius:20px;
    }
</style>

<?php
    $conn = mysqli_connect('localhost','root','','ajmal');
    if(!$conn){
        die("Connection Failed");
    }

    if($_SERVER["REQUEST_METHOD"] == "POST"){
        $username = $_POST["username"];
        $pass = $_POST["password"];

        $query = "SELECT * FROM admin WHERE username='$username' and password='$pass'";
        $result = mysqli_query($conn, $query);

        if(mysqli_num_rows($result) == 1 && $result){
            echo "<script>top.location.href='dashboard.php'</script>";
            exit;
        }else{
            echo "<script>alert('Invalid Username or Password');</script>";
        }
    }

?>

<div class="container">
    <form method="post">
        <input type="text" name="username" placeholder="admin name">
        <input type="password" name="password" placeholder="password">
        <input type="submit" value="Submit">
    </form>
</div>

