<?php
    header("Access-Control-Allow-Origin: *");
    header('Content-Type: application/json');

    $msg = "First line of text\nSecond line of text";

    // use wordwrap() if lines are longer than 70 characters
    $msg = wordwrap($msg,70);

    $mail_s = mail("goat090@gmail.com","My subject",$msg);

/*    $mail = $_POST['mail'];
    $username = $_POST['username'];
    $otp = rand(0,9).rand(0,9).rand(0,9).rand(0,9);
    $d=strtotime("+30 Minute");

    $msg = "รหัส OTP ของคุณคือ ".$otp;

    $res = array();

    $connection = mysqli_connect("localhost", "zp11107_itmobile", "K0V5Piqnf55tM","zp11107_itmobile"); 
    if (mysqli_connect_errno())
    {
      $res['otp'] = "error";
    }
    else{
      $sql = "SELECT *
              FROM dorm_users
              WHERE email = '".$mail."' or username = '".$username."'";

      $result = mysqli_query($connection, $sql);

      if (mysqli_num_rows($result)>0){
        $res['otp'] = "same";
      }
      else{
        $success = mail($mail,"รหัสสำหรับยืนยันตัวตน",$msg);
        $res['otp'] = $otp;
      }
    }
    
	  mysqli_close($connection); 
    echo json_encode($res);*/
?>