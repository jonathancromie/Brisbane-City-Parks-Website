<?php
	if (isset($_GET['id'])) {
		include "includes/individualParkInfo.inc";
	} else {
		include "includes/errorPage.inc";
	}
?>