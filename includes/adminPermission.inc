<?php
	if (!isset($_SESSION['isAdmin'])) {
		header("Location: http://{$_SERVER['HTTP_HOST']}/project/Login.php");
		exit();
	}
?>