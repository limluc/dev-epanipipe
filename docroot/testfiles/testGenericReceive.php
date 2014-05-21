<?php

$token = $_REQUEST['token']; // the authentication token;
$from = $_REQUEST['from']; // the sender's phone number;
$to = $_REQUEST['to']; // the receiver's phone number;
$mid = $_REQUEST['mid']; // ID of the message in our network;
$text = $_REQUEST['text']; // the body of the message;

//  if(!in_array($_SERVER['REMOTE_ADDR'],
//      array('144.76.18.242', '78.46.106.211', '78.46.106.219'))) {
//    die("Error: Unknown IP");
//  }

echo "Thank you $sender for sending $message";

$water_level = intval ($text);

if($water_level<"5")
{

$token = "C3RBU5EIVNT4FR4JJBHAX9L996EF45MUI"; // the authentication token;
$from = "447937946751"; // the sender's phone number;
$to = "447938797117"; // the phone number you want to send message to;
$text = "check water level"; // the body of the message;
$umid = ""; // ID of the message in your system, optional string;


$text = urlencode("$text");

$url = "http://www.2-waysms.com/my/api/sms.php?token=$token&from=$from&to=$to&umid=$umid&text=$text";
$ret = file($url);
echo "message sent";
}

?>