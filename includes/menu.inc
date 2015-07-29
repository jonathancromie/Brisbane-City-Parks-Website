<div id="wrapper">
	<div id="header">
		<a class="h1" href="index.php">Brisbane City Parks</a>
		<a href="Search.php">Search</a>
		<a href="Register.php">Register</a>
		<?php
		if (isset($_SESSION['email'])) {
			echo "<a href=\"logout.php\">Logout</a>";
			if (isset($_SESSION['isAdmin'])) {
				echo "<a href=\"admin.php\">Admin</a>";
			}
		} else {
			echo "<a href=\"Login.php\">Log In</a>";
		}
		?>
		<label id="lblWelcome"></label>
	</div>        
</div>