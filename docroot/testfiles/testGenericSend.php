<?php

  $to = $_REQUEST['to']; // the receiver's phone number;
  $text = $_REQUEST['text']; // ID of the message in our network;

  $token = "C3RBU5EIVNT4FR4JJBHAX9L996EF45MUI"; // the authentication token;
  $from = "447937946751"; // the sender's phone number;
  $umid = ""; // ID of the message in your system, optional string;


  $text = urlencode("$text");

  $url = "http://www.2-waysms.com/my/api/sms.php?token=$token&from=$from&to=$to&umid=$umid&text=$text";
  $ret = file($url);
  echo "message sent"; 
?>