<?php
	require "includes/connectToDB.inc";
	
	$query = "INSERT INTO reviews (parkID, userEmail, review, rating, datePosted) ".
			"VALUES (:park, :email, :review, :rating, :date)";
		
	date_default_timezone_set('Australia/Brisbane');
	$date = date("Y-m-d H:i:s");
	
	$stmt = $pdo->prepare($query);
	
	$stmt->bindValue(':park', $_GET['id']);
	$stmt->bindValue(':email', $_SESSION['email']);
	$stmt->bindValue(':review', $_POST['id']);
	$stmt->bindValue(':review', $_POST['reviewTextarea']);
	$stmt->bindValue(':rating', $_POST['stars']);
	$stmt->bindValue(':date', $date);
	$stmt->execute();
	
	echo "Review submitted successfully";
?>