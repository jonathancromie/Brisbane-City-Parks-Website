<?php
  session_start();
  unset($_SESSION['isAdmin']);
  unset($_SESSION['email']);
?>
<!DOCTYPE HTML>
<html>
	<head>
		<?php include_once "includes/header.inc"; ?>
	</head>
	
	<body class="admin">
		<?php include 'includes/menu.inc'; ?>
		
		<div id="content" align="center">
		<h2>You have successfully logged out</h2>
	</div>
		
	<?php include 'includes/footer.inc'; ?>
	</body>
</html>
