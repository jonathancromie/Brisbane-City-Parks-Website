<form name="postReviewForm" id="postReviewForm" action="parkResult.php?id=<?php echo $_GET['id']; ?>" method="POST">
	<textarea name="reviewTextarea" id="reviewTextarea" maxlength="500" cols=50 rows=5></textarea></br>
	<?php
		include "includes/formInputs.inc";
		$stars = array(1, 2, 3, 4, 5);
		createLabel("stars", "Stars");
		selectInput("stars", $stars);
	?>
	<input type="hidden" name='id' value=>
	<input type="submit" name="submit" value="Submit Review">
</form>