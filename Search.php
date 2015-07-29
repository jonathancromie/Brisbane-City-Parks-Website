<?php session_start(); ?>
<!DOCTYPE html>
<html>
  <head>
    <?php include_once "includes/header.inc"; ?>
    <script type="text/javascript" src="javascript/geolocation.js"></script>
  </head>
  <body onload="getLocation();">
  <?php include 'includes/menu.inc'; ?>

    <div id="content" align="center">

      <h2>Search by Name</h2><br>
	  <form name="nameSearch" id="nameSearch" action="Results.php" method="GET">
      <input type="text" name="parkName" id="parkName" align="middle">
      <input type="submit" value="Go">
	  </form><br>
	  
      <h2>Search by Surburb</h2>
	  <form name="suburbSearch" id="suburbSearch" action="Results.php" method="GET">
	  <?php include "includes/suburbSearch.inc"; ?>
	  <input type="submit" value="Go">
      </form><br>
	  
	  <h2>Search by Location</h2><br>
	  <form name="geolocationSearch" id="geolocationSearch" action="Results.php">
		<span name="geolocationError" id="geolocationError">Enable geolocation to search by location</span>
		<input type="hidden" name="lat" id="lat"/>
		<input type="hidden" name="lon" id="lon"/>
		<input type="submit" name="locationSubmit" value="Go" style="visibility:hidden">
	  </form>
	  
    </div>
	
	<?php include 'includes/footer.inc'; ?>
  </body>
</html>
