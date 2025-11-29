<?php
    $conn = mysqli_connect('localhost', 'root', '', 'ajmal');
    if (!$conn) {
        die("Connection Failed: " . mysqli_connect_error());
    }
?>

<style>
    .container{
        width:100%;
        height:100vh;
        display:flex;
        justify-content:center;
        align-items:center;
        background:lightblue;
        flex-direction:column;
    }

    .container form{
        width:40%;
        display:flex;
        justify-content:center;
        align-items:center;
        flex-direction:column;
    }

    .container form input[type="number"],.container form select{
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

    .container .result{
        width:40%;
        display:flex;
        justify-content:center;
        align-items:center;
        flex-direction:column;
    }

    .result h3{
        font-family: Arial, Helvetica, sans-serif;
    }

    .result .not-found{
        color:red;
    }
</style>

<div class="container">
    <form method="post">
        <input type="number" name="consumer_id" placeholder="Consumer Number">
        <select name="month">
            <?php
                $month_drop = ['jan','feb','mar','april','may','jun','jul','aug','sept','oct','nov','dec'];
                for($i = 0;$i<count($month_drop);$i++){
                    $mon = $month_drop[$i];
                    echo "<option value='${mon}'>${mon}</option>";
                }
            ?>
        </select>
        <input type="submit" value="Search">
    </form>
    <div class="result">
        <?php
            if ($_SERVER['REQUEST_METHOD'] == "POST") {

                $cons_id = $_POST['consumer_id'];
                $month   = $_POST['month'];

                $bill_query = "SELECT * FROM bill WHERE consumer_id='$cons_id' AND month='$month'";
                $bill = mysqli_query($conn, $bill_query);

                if (mysqli_num_rows($bill) == 1) {
                    $row = mysqli_fetch_assoc($bill);
                    $amount = $row['amount'];
                    $unit = $row['unit'];

                    $user_query= "SELECT * FROM consumer where consumer_id='$cons_id'";
                    $result_con = mysqli_query($conn,$user_query);
                    if($result_con && mysqli_num_rows($result_con)>0){
                        $data = mysqli_fetch_assoc($result_con);
                        $con_name = $data['consumer_name'];
                        echo "<h3>Consumer Name : $con_name</h3>";
                        echo "<h3>Consumer ID : $cons_id</h3>";
                    }
                    echo "<h3>Amount : $amount</h3>";
                    echo "<h3>Unit : $unit</h3>";           
                } else {
                    echo "<h3 class='not-found'>No data found</h3>";
                }
            }
        ?>
    </div>
</div>