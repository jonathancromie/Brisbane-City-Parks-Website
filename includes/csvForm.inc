<!DOCTYPE HTML>
<html>
	<head>
		<?php include_once "header.inc"; ?>
	</head>
	
	<body class="admin">
		<?php include 'includes/menu.inc'; ?>
		
		<div id="content" align="center">
			<form action="admin.php" method="POST" enctype="multipart/form-data">
				<h2>Upload CSV file to the database:</h2>
				Select a file to upload:</br></br>
				<input type="file" name="csvFile" id="csvFile"/></br></br>
				<input type="submit" value="Upload CSV" name="submit"/>
			</form>
			
		</div>
		
		<?php include 'footer.inc'; ?>
	</body>
</html>