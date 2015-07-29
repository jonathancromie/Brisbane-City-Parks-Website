<?php
	echo "<table id=\"results\" name=\"results\">
		<thead>
			<tr>
				<th>Name</th>
				<th>Street</th>
				<th>Suburb</th>
			</tr>
		</thead>
		<tbody>";

	foreach ($result as $park) {
		
		echo "<tr>";
		
		$id = $park['id'];
		$name = $park['Name'];
		$street = $park['Street'];
		$suburb = $park['Suburb'];
		
		echo "<td><a href='parkResult.php?id=$id'>$name</a></td>";
		echo "<td>$street</td>";
		echo "<td>$suburb</td>";
		
		echo "</tr>";
	}
	
	echo "</tbody>
		</table>";
		
?>