<?php
	date_default_timezone_set('Australia/Brisbane');
	require "connectToDB.inc";

	
	$query = "SELECT first_name, review, rating, datePosted FROM reviews, members WHERE parkID = :id AND reviews.userEmail = members.email_address ORDER BY datePosted ASC";
	$stmt = $pdo->prepare($query);
	$stmt->bindValue(":id", $_GET['id']);
	$stmt->execute();
	$result = $stmt->fetchAll();
	if (isset($result)) {
		foreach ($result as $review) {
			$name = $review['first_name'];
			$reviewText = $review['review'];
			$rating = $review['rating'];

			//create php DateTime objects for dates
			$currentDate = date_create_from_format('Y-m-d H:i:s', date('Y-m-d H:i:s'));
			$datePosted = date_create_from_format('Y-m-d H:i:s', $review['datePosted']);
			
			//calculate time since review was posted
			$timeSince = date_diff($currentDate, $datePosted);
			$timeSince = $timeSince->format('%d days, %h hours and %i minutes ago');
			
			// echo "<div class='review'>";
			// 	echo "<div class='reviewHead'";
			// 		echo "<span class-'reviewName'>$name </span><span class='datePosted'>$timeSince</span>";
			// 	echo "</div>";
			// 	echo "<div class='reviewBody'>";
			// 		echo "<span class='reviewText'>$reviewText</span></br>";
			// 		echo "<span class='rating'>";
			// 			for ($i = 0; $i < $rating; $i++) {
			// 				echo "<img src='images/star2.png' alt='Star' align='right'>";
			// 			}
			// 		echo "</span>";
			// 	echo "</div>";
			// echo "</div>";

			echo "<div class='review'>";
				echo "<div class='reviewHead'";
					echo "<span align='left' class='datePosted'>$timeSince</span> - <span class-'reviewName'>$name </span>says <span class='reviewText'>$reviewText</span>";
				echo "</div>";
				echo "<span class='rating'>";
						for ($i = 0; $i < $rating; $i++) {
							echo "<img src='images/star2.png' alt='Star' align='right'>";
						}
				echo "</span>";
			echo "</div>";
		}	
	}
?>