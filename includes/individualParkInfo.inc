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
			<?php 
				include "includes/individualMap.inc";
			?>
			
			<div class="postReview">
				<h2>Post a review</h2>
				<?php
					if (isset($_POST['submit'])) {
						include "postReview.inc";
					} else {
						include "includes/reviewForm.inc";
					}
				?>
			</div>
			
			<div class="reviews">
				<h2>Reviews</h2>
				<?php include "includes/displayReviews.inc"; ?>
			</div>
			
        </div>
		
		<?php include 'includes/footer.inc'; ?>
    </body>
</html>