<?php
	
	require "includes/connectToDB.inc";
	
	$checkNotDupe = "SELECT * FROM members WHERE email_address = :email";
	$stmt1 = $pdo->prepare($checkNotDupe);
	$stmt1->bindValue(':email', $_POST['email']);
	$stmt1->execute();
	if ($stmt1->rowCount() > 0) {
		echo "Sorry, that email is already in use";
		return;
	}
	
	$query2 = "INSERT INTO members (email_address, first_name, last_name, sex, date_of_birth, phone_number, street, suburb, city, post_code, state, password, salt, updates) ".
			"VALUES (:email, :fName, :lName, :sex, :dob, :phone, :street, :suburb, :city, :postCode, :state, SHA2(CONCAT(:password, :salt), 0), :salt, :updates)";
		
	
	$dob = date_create_from_format('d/m/Y', $_POST['dob']);
	$dob = $dob->format('Y-m-d');
	
	$stmt = $pdo->prepare($query2);
	$stmt->bindValue(':email', $_POST['email']);
	$stmt->bindValue('fName', $_POST['firstName']);
	$stmt->bindValue(':lName', $_POST['surname']);
	$stmt->bindValue(':sex', $_POST['sex']);
	$stmt->bindValue(':dob', $dob);
	$stmt->bindValue(':phone', $_POST['phone']);
	$stmt->bindValue(':street', $_POST['street']);
	$stmt->bindValue(':suburb', $_POST['suburb']);
	$stmt->bindValue(':city', $_POST['city']);
	$stmt->bindValue(':postCode', $_POST['postcode']);
	$stmt->bindValue(':state', $_POST['state']);
	$stmt->bindValue(':password', $_POST['password']);
	$stmt->bindValue(':salt', '4dffdfjkshdkfjjfhfhf');
	if (!isset($_POST['updates'])) {
		$_POST['updates'] = 0;
	}
	$stmt->bindValue(':updates', $_POST['updates']);
	
	$stmt->execute();
	
?>