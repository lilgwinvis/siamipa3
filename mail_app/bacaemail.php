
<html  xmlns="http://www.w3.org/1999/xhtml">
<head>
  <title>FMIPA Mail</title>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
</head>
<body>
<?php
set_time_limit(300);
// open IMAP connection
//$mail = imap_open('{s10iix.solidrockservers.com:993/imap/ssl}','mat@fmipa-unibba.org','mat2015');
// or, open POP3 connection
//$mail = imap_open('{s10iix.solidrockservers.com:995/pop3/ssl}','fmipa@fmipa-unibba.org','fmipa2015');
$mail = imap_open('{mail.fmipa-unibba.org:995/pop3/ssl}','fmipa@fmipa-unibba.org','mat2017');
var_dump($mail);
// grab a list of all the mail headers
$headers = imap_headers($mail);

// grab a header object for the last message in the mailbox
$last = imap_num_msg($mail);

for($i=1;$i<=$last;$i++){	
	$header = imap_header($mail, $i);

	echo "Header : <br>";
	echo "Date   : ".$header->Date."<br>";
	echo "Sender : ".$header->senderaddress."<br>";
	echo "Subject : ".$header->subject."<br>"; 
	echo "<br>";
}



//echo "<br><br>";
// grab the body for the same message
//$body = imap_body($mail, $last);

//echo "Body : <br><br><br>";

//print_r($body);

// close the connection
imap_close($mail);
?>
</body>
</html>