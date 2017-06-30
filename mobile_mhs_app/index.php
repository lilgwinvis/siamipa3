<?php
   require_once 'shared.php';
?>

<html>

<head>
    <title>SIA FMIPA</title>  
    <link rel="stylesheet" href="http://code.jquery.com/mobile/1.4.5/jquery.mobile-1.4.5.min.css" />
	<script src="http://code.jquery.com/jquery-1.11.1.min.js"></script>
	<script src="http://code.jquery.com/mobile/1.4.5/jquery.mobile-1.4.5.min.js"></script>  	
</head>
<body>     

 <div data-role="page"  id="pageone">
 <div data-role="header">
    <h1>SIA FMIPA</h1>
  </div>
 
  <div data-role="main" class="ui-content">
    <a href="#pagetwo" class="ui-btn" data-transition="slide" data-direction="reverse" >Go to Page Two</a>
  </div>
  
  <div data-role="footer">
    <h1>created by cecep suwanda</h1>
  </div>

</div>

<div data-role="page"   id="pagetwo">
  <div data-role="header">
    <h1>SIA FMIPA</h1>
  </div>
  
  <div data-role="main" class="ui-content">
    <a href="#pageone" class="ui-btn" data-transition="slide" data-direction="reverse" >Go to Page One</a>
  </div>
  <div data-role="footer">
    <h1>created by cecep suwanda</h1>
  </div>

  
</div>
</body>
</html>