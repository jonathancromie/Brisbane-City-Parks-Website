<?php session_start(); ?>
<!DOCTYPE html>
<html>
	<head>
        <?php include_once "includes/header.inc"; ?>
		<link rel="stylesheet" href="http://cdn.leafletjs.com/leaflet-0.7.3/leaflet.css" />
		<script type="text/javascript" src="http://cdn.leafletjs.com/leaflet-0.7.3/leaflet.js"></script>
    </head>
    <body class="home">
    	<?php include 'includes/menu.inc'; ?>

        <div id="content" align="center">
        	<h2>Search Results</h2>
			<?php 
				include "includes/searchQuery.inc";
				include "includes/resultsMap.inc";
				include "includes/resultsTable.inc";
			?>

        </div>
		
		<?php include 'includes/footer.inc'; ?>
    </body>
</html>
