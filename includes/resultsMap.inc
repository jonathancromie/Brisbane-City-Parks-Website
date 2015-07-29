<?php
	
	$centerLat = $result[0]['Latitude'];
	$centerLon = $result[0]['Longitude'];
	
	echo "<div id=\"map\" style=\"height: 400px; width: 800px\"></div>
			<script type=\"text/javascript\" src=\"javascript/map.js\" onload=\"map_at($centerLat, $centerLon	, 13);\"></script>";
	
	echo "<script type='text/javascript'>";
	foreach ($result as $park) {
		
		$id = $park['id'];
		$name = addslashes($park['Name']);
		$street = addslashes($park['Street']);
		$suburb = addslashes($park['Suburb']);
		$lat = $park['Latitude'];
		$lon = $park['Longitude'];
		
		echo "marker($lat, $lon, '$name', $id); ";
		
	}
	echo "</script>";
?>