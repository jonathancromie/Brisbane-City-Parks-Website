<!DOCTYPE html>
<html>
	<head>
		<?php include_once 'header.inc' ?>
		<script type="text/javascript" src="javascript/registration.js"></script>
	</head>
	<body class="register">
		<?php include 'includes/menu.inc'; ?>
		<!--
		<div id="wrapper">
			<div id="header">
				<a class="h1" href="index.php">Brisbane City Parks</a>
				<a href="Search.php">Search</a>
				<a href="Register.php">Register</a>
				<a href="Login.php">Log In</a>
				<a href="admin.php">Admin</a>
				<label id="lblWelcome"></label>
			</div>        
		</div>
		-->
		<div id="content" float:"left">
			<h2>User Registration:</h2>

			<form name="registration" action="Register.php" method="post" onsubmit="return validate(registration)">
				<div style="float:left" id="AccountDetails" name="AccountDetails">
					<?php
						include "formInputs.inc";

						textInput($errors, 'email', 'Email Address', 'example@email.com');
						textInput($errors, 'firstName', 'First Name', '');
						textInput($errors, 'surname', 'Surname', '');
						sexInput($errors);
						textInput($errors, 'dob', 'Date of Birth (dd/mm/yyyy)', 'dd/mm/yyyy');
						passwordInput($errors, 'password', 'Password');
						passwordInput($errors, 'confirmPassword', 'Confirm Password');
					?>
				</div>

				<div style="float:right" id="ContactDetails" name="ContactDetails">
					<?php
						textInput($errors, 'phone', 'Phone', '');
						textInput($errors, 'street', 'Street', '');
						textInput($errors, 'suburb', 'Suburb', '');
						textInput($errors, 'city', 'City', '');
						textInput($errors, 'postcode', 'Postcode', '');
						stateSelect($errors);
						checkBoxInput($errors, 'updates', 'Do you wish to receive email updates?');

						echo ('<div><tr><td>');
						echo ('<input type="submit" value="Submit" id="submit"/><input type="reset" value="Reset" id="reset"/>');
						echo ('</tr></td></div>');
					?>
				</div>


				
			</form>
		</div>

		<?php include "footer.inc" ?>
	</body>
</html>
