<?php
	session_start();
	require "includes/adminPermission.inc";
	if (isset($_POST['submit'])) {
		include "includes/uploadcsv.inc";
	} else {
		include "includes/csvForm.inc";
	}
?>