<?php
	function checkPassword($email, $password) {
		require "connectToDB.inc";
		$query = "	SELECT *
					FROM members
					WHERE email_address = :email and
					password = SHA2(CONCAT(:password, '4dffdfjkshdkfjjfhfhf'), 0)
					";

					$stmt = $pdo->prepare($query);
					$stmt->bindValue(':email', $email);
					$stmt->bindValue(':password', $password);

					$stmt->execute();

					if ($stmt->rowCount() > 0) {
						return true;
					} else {
						return false;
					}
	}

	function checkAdmin($email) {
		require "connectToDB.inc";
		$query = "	SELECT is_admin
					FROM members
					WHERE email_address = :email";
					
		$stmt = $pdo->prepare($query);
		$stmt->bindValue(':email', $email);
		$stmt->execute();
		
		$user = $stmt->fetch();
		
		if($user['is_admin'] == 1) {
			return true;
		} else {
			return false;
		}
	}
	
?>
