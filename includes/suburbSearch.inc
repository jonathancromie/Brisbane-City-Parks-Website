<?php
	require "connectToDB.inc";
	
	$result = $pdo->query('SELECT DISTINCT Suburb FROM parks ORDER BY Suburb ASC');
	
	echo "<select name='Suburb' id='Suburb' align=\"middle\"/>";
	
	foreach ($result as $park) {
		$suburb = $park['Suburb'];
		echo "<option>$suburb</option>";
	}
	
    echo "</select>";
?>