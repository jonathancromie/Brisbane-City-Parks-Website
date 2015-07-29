<?php
	require "connectToDB.inc";
	
	$query = "SELECT id, Name, Street, Suburb, Latitude, Longitude FROM parks";
	if (isset($_GET['Suburb'])) {
		$query = $query." WHERE Suburb = :suburb";
		$stmt = $pdo->prepare($query);
		$stmt->bindValue(":suburb", $_GET['Suburb']);
	} else if (isset($_GET['parkName'])) {
		$query = $query." WHERE Name LIKE :name";
		$stmt = $pdo->prepare($query);
		$parkName = $_GET['parkName'];
		$stmt->bindValue(":name", "%$parkName%");
	} else if (isset($_GET['lat']) && isset($_GET['lon'])) {
		$query = $query." WHERE (Latitude BETWEEN :lat - 0.01 AND :lat + 0.01) AND (Longitude BETWEEN :lon - 0.01 AND :lon + 0.01)";
		$stmt = $pdo->prepare($query);
		$stmt->bindValue(":lat", $_GET['lat']);
		$stmt->bindValue(":lon", $_GET['lon']);
	} else {
		$stmt = $pdo->prepare($query);
	}
	
	$stmt->execute();
	$result = $stmt->fetchAll();
	
	
	if (!isset($result)) {
		echo "Sorry, no results could be found with that search term";
		return;
	}
?>