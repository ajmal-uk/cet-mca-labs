<style>
    .container{
        width:100%;
        height:100vh;
        display:flex;
        justify-content:center;
        align-items:center;
        background:lightblue;
    }

    .container form{
        width:40%;
        display:flex;
        justify-content:center;
        align-items:center;
        flex-direction:column;
    }

    .container form input[type="text"],
    .container form input[type="number"],
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

if($_SERVER['REQUEST_METHOD']=="POST"){
    $consumer_id = $_POST['consumer_id'];
    $consumer_name = $_POST['consumer_name'];
    $adress = $_POST['adress'];
    $phone_no = $_POST['phone_no'];

    $check_id_query = "SELECT * FROM consumer WHERE consumer_id='$consumer_id'";

    $check_result = mysqli_query($conn,$check_id_query);

    if($check_result && mysqli_num_rows($check_result) ==1){
        echo "<script>alert('Consumer number exist');</script>";
    }else{
        $ins_query = "INSERT INTO consumer(consumer_id,consumer_name,adress,phone_no)VALUES($consumer_id,'$consumer_name','$adress','$phone_no')";
        $result = mysqli_query($conn,$ins_query);
        echo "<script>alert('Consumer Added');</script>";
    }
}
?>
<div class="container">
    <form action="" method="post">
        <input type="number" name="consumer_id" placeholder="id">
        <input type="text" name="consumer_name" placeholder="consumer name">
        <input type="text" name="phone_no" placeholder="Mobile no">
        <input type="text" name="adress" placeholder="adress">
        <input type="submit" value="Add">
    </form>
</div>


