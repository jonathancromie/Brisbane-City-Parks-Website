<?php
	if (!isset($_GET['id'])) {
		echo "Sorry, something went wrong when selecting a park. Please try again";
		return;
	}
	$id = $_GET['id'];

	require "connectToDB.inc";
	
	$query = "SELECT Name, Street, Suburb, Latitude, Longitude FROM parks WHERE id = :id";
	
	$stmt = $pdo->prepare($query);
	$stmt->bindvalue(':id', $id);
	$stmt->execute();
	
	$park = $stmt->fetch();
	//echo $stmt[0]['Name'];
	
	$name = addslashes($park['Name']);
	$street = addslashes($park['Street']);
	$suburb = addslashes($park['Suburb']);
	$lat = $park['Latitude'];
	$lon = $park['Longitude'];
	
	echo "<h2>$name</h2>";
	echo "<p>$street, $suburb</p>";
	
	echo "<div id=\"map\" style=\"height: 400px; width: 800px\"></div>
			<script type=\"text/javascript\" src=\"javascript/map.js\" onload=\"map_at($lat, $lon, 13);\"></script>";
	
	echo "<script type='text/javascript'>marker($lat, $lon, '$name', $id);</script>";
	
?>