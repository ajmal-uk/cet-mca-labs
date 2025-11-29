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
    .container form select{
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
    $conn=mysqli_connect('localhost','root','','ajmal');
    if(!$conn){
        die("Failed");
    }
?>
<div class="container">
    <form method="post">
        <select name="consumer_id" required>
            <option value="" disabled selected>Select Consumer</option>
            <?php 
                $query = "SELECT * FROM consumer";
                $result = mysqli_query($conn, $query);

                if ($result && mysqli_num_rows($result) > 0) {
                    while ($row = mysqli_fetch_assoc($result)) {
                        $consumer_id = $row['consumer_id'];
                        $consumer_name = $row['consumer_name'];
                        echo "<option value='$consumer_id'>$consumer_name - $consumer_id</option>";
                    }
                } else {
                    echo "<option disabled>No Consumer Exist</option>";
                }
            ?>
        </select>
        <select name="month" required>
            <option value="" disabled selected>Select Month</option>
            <?php
                $month_drop = ['jan','feb','mar','april','may','jun','jul','aug','sept','oct','nov','dec'];
                for($i=0;$i<count($month_drop);$i++){
                    $mon = $month_drop[$i];
                    echo "<option value='${mon}'>$mon</option>";
                }
            ?>
        </select>
        <input type="number" name="amount" placeholder="amount">
        <input type="number" name="unit" placeholder="unit">
        <input type="submit" value="Add">
    </form>
</div>
<?php 
    if($_SERVER['REQUEST_METHOD'] == "POST"){
        $consumer_id = $_POST['consumer_id'];
        $month = $_POST['month'];
        $amount = $_POST['amount'];
        $unit = $_POST['unit'];
        $ins_query = "INSERT INTO bill(consumer_id,month,amount,unit)VALUES($consumer_id,'$month',$amount,$unit)";
        $result = mysqli_query($conn,$ins_query);
        echo "<script>alert('Succes fully added bill, $consumer_id' : with $amount on $month');</script>";
    }
?>