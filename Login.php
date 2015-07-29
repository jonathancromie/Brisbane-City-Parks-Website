<?php
	session_start();
	if (isset($_POST['login'])) {
		require "includes/validateLogin.inc";
		if (checkPassword($_POST['email'], $_POST['password'])) {
			session_start(); 
			if (checkAdmin($_POST['email'])) {
				 $_SESSION['isAdmin'] = true;
				 header("Location: http://{$_SERVER['HTTP_HOST']}/Project 2/admin.php");
			}
			else {
				header("Location: http://{$_SERVER['HTTP_HOST']}/Project 2/index.php");
			}
			$_SESSION['email'] = $_POST['email'];
			exit();
		} else {
			echo "<h2>Login Failed<h2>";
		}

	}
?>

<!DOCTYPE html>
<html>
	<head>
		<?php include_once "includes/header.inc"; ?>
        <script type="text/javascript" src="javascript/script.js"></script>
	</head>
	<body class="login">
		<?php include 'includes/menu.inc'; ?>

        <form id="loginForm" method="POST" action="Login.php">
          <div id="content" align="center">
          <h2>Login</h2>
			<table>
				<tbody>
					<tr><td>Email: </td><td><input type="text" name="email" id="email" align="center" placeholder="example@email.com" /></td></tr>
					<tr><td>Password: </td><td><input type="password" name="password" id="password" align="center" width="100%" /></td></tr>
					<tr><td><input type="submit" name="login" id="login" value="Login"/></td></tr>
				</tbody>
			</table>
          </div>
        </form>
		
		<?php include 'includes/footer.inc'; ?>
	</body>
</html>
