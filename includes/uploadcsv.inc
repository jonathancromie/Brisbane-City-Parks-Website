<?php
	require "connectToDB.inc";

	$csvFile = $_FILES['csvFile']['tmp_name'];
	$csvAsArray = array_map('str_getcsv', file($csvFile));

	$query = "INSERT INTO parks (id, ParkCode, Name, Street, Suburb, Easting, Northing, Latitude, Longitude) VALUES";
	
	$numRows = count($csvAsArray);
	
	for ($i = 1; $i < $numRows; $i++) {
		
		//Retrieve the values from each row and add necessary formatting
		$id = $csvAsArray[$i][0];
		$parkCode = "'".$csvAsArray[$i][1]."'";
		$name = "'".addslashes($csvAsArray[$i][2])."'";
		$street = "'".addslashes($csvAsArray[$i][3])."'";
		$suburb = "'".addslashes($csvAsArray[$i][4])."'";
		$east = "'".addslashes($csvAsArray[$i][5])."'";
		$north = "'".addslashes($csvAsArray[$i][6])."'";
		$lat = addslashes($csvAsArray[$i][7]);
		$lon = addslashes($csvAsArray[$i][8]);
		
		//Add values to query
		$query = $query."($id, $parkCode, $name, $street, $suburb, $east, $north, $lat, $lon)";
		
		//Don't add a , to the last row
		if ($i != $numRows - 1) {
			$query = $query.",";
		}
	}
	
	//Execute query
	$stmt = $pdo->prepare($query);
	$stmt->execute();
	
	include "csvSuccess.inc";
?>