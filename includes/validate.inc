<?php

	function validate(&$errors) {
		foreach ($_POST as $element => $value) {
			$_POST[$element] = htmlspecialchars($value);
		}
		validateEmail($errors, $_POST);
		validateName($errors, $_POST, 'firstName');
		validateName($errors, $_POST, 'surname');
		validateSex($errors, $_POST);
		validateDate($errors, $_POST);
		validatePassword($errors, $_POST);
		validatePhone($errors, $_POST);
		validateStreet($errors, $_POST);
		validateSuburb($errors, $_POST);
		validateCity($errors, $_POST);
		validateState($errors, $_POST);
		validatePostcode($errors, $_POST);
		validateUpdates($errors, $_POST);
	}

	function validateElement(&$errors, $pattern, $field_list, $field_name) {
		if (!isset($field_list[$field_name])|| empty($field_list[$field_name]))
			$errors[$field_name] = "$field_name is required";
		else if (!preg_match($pattern, $field_list[$field_name]))
			$errors[$field_name] = "$field_name is invalid";
	}
	
	function validateEmail(&$errors, $field_list) {
		$pattern = '/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/';
		validateElement($errors, $pattern, $field_list, 'email');
	}
	
	function validateName(&$errors, $field_list, $field_name) {
		$pattern = '/^[A-Z]{1}[A-z ,.\'-]+$/';
		validateElement($errors, $pattern, $field_list, $field_name);
	}
	
	function validateSex(&$errors, $field_list) {
		$pattern = '/male|female/';
		validateElement($errors, $pattern, $field_list, 'sex');
	}
	
	function validateDate(&$errors, $field_list) {
		$pattern = '/^(0[1-9]|[12][0-9]|3[01])[-\/](0[1-9]|1[012])[-\/](18|19|20)[0-9][0-9]$/';
		validateElement($errors, $pattern, $field_list, 'dob');
	}
	
	function validatePhone(&$errors, $field_list) {
		//the below pattern was retrieved from http://regexlib.com/REDetails.aspx?regexp_id=1787 by commenter Craig
		//should account for all forms of phone numbers
		$pattern = '/(^\({0,1}((0|\+61)(2|4|3|7|8)){0,1}\){0,1}(\ |-){0,1}[0-9]{2}(\ |-){0,1}[0-9]{2}(\ |-){0,1}[0-9]{1}(\ |-){0,1}[0-9]{3}$)|(^13((\ |-){0,1}[0-9]{2}(\ |-){0,1}[0-9]{2})$)|(^1(3|8)[0-9]{2}(\ |-){0,1}[0-9]{3}(\ |-){0,1}[0-9]{3})$/';
		validateElement($errors, $pattern, $field_list, 'phone');
	}
	
	function validateStreet(&$errors, $field_list) {
		$pattern = '/^[0-9]+ [A-z]+ [A-z]+$/';
		validateElement($errors, $pattern, $field_list, 'street');
	}
	
	function validateState(&$errors, $field_list) {
		$pattern = '/QLD|NSW|VIC|ACT|WA|NT|SA|TAS/';
		validateElement($errors, $pattern, $field_list, 'state');
	}
	
	function validatePassword(&$errors, $field_list) {
		$password = 'password';
		$confirm = 'confirmPassword';
		$pattern = '/^[A-z0-9!@#$%^&*]{6,}$/';
		if (!isset($field_list[$password])|| empty($field_list[$password]))
			$errors[$password] = 'Password is required';
		else if (!preg_match($pattern, $field_list[$password]))
			$errors[$password] = 'Password is invalid';
		else if ($field_list[$password] != $field_list[$confirm]) {
			$errors[$password] = 'Passwords must match';
		}
	}
	
	function validateSuburb(&$errors, $field_list) {
		$pattern = '/^[A-z]{4}[ A-z]{0,25}$/';
		validateElement($errors, $pattern, $field_list, 'suburb');
	}
	
	function validateCity(&$errors, $field_list) {
		$pattern = '/^[A-z]{4}[ A-z]{0,25}$/';
		validateElement($errors, $pattern, $field_list, 'city');
	}
	
	function validatePostcode(&$errors, $field_list) {
		$pattern = '/^[0-9]{4}$/';
		validateElement($errors, $pattern, $field_list, 'postcode');
	}
	
	function validateUpdates(&$errors, $field_list) {
		if (isset($field_list['updates'])) {
			$value = $field_list['updates'][0];
			if ($value != 1) {
				$errors['updates'] = 'Invalid value for checkbox';
			}
		}
	}
?>