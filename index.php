<!DOCTYPE html>
<html>
	<head>
        <?php session_start(); ?>
        <?php include_once "includes/header.inc"; ?>
        
    </head>
    <body class="home">
        <?php include 'includes/menu.inc'; ?>

        <div id="content" align="center">
            <h2>Highlighted Reviews</h2>

            <?php include 'includes/displayReviewsIndex.inc'; ?>

        </div>
		
		<?php include 'includes/footer.inc'; ?>
    </body>
</html>
