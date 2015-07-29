/* validate(form)
 *		Checks the given form element to ensure it properly validates with all required fields being in the correct format, matching passwords etc.
 *
 * Input:
 *		form element for validation
 *
 * Output: 
 *		returns false if form failed to validate
 * 		returns true otherwise and currently displays an alert box to notify of successful submission as no server side processing is implemented yet
 */
function validate(form) {
	var valid = true;
	
	if(!checkEmail(form.email)) {
		valid = false;
	}
	if (!checkFirstName(form.firstName)) {
		valid = false;
	}
	if(!checkSurname(form.surname)) {
		valid = false;
	}
	if(!checkSex('sex')) {
		valid = false;
	}
	if(!checkDob(form.dob)) {
		valid = false;
	}
	if(!checkPhone(form.phone)) {
		valid = false;
	}
	if(!checkStreet(form.street)) {
		valid = false;
	}
	if(!checkState(form.state)) {
		valid = false;
	}
	if(!checkSuburb(form.suburb)) {
		valid = false;
	}
	if(!checkCity(form.city)) {
		valid = false;
	}
	if (!checkPostcode(form.postcode)) {
		valid = false;
	}
	if (!checkPassword(form.password, form.confirmPassword)) {
		valid = false;
	}
	return valid;
}

/* displayError(boolDisplay, id, errorMessage)
 * 
 * Input:
 * 		boolDisplay: Boolean value for whether to display or hide the error message
 * 		id: id of the error message span element
 *		errorMessage: Error message to display
 * 
 * Output:
 * 		If boolDisplay is true, will make the error message visible for the span element with the given id
 * 		If boolDisplay is false, will hide the error message and remove for the span element with the given id
 */
function displayError(boolDisplay, id, errorMessage) {
	if (boolDisplay) {
		document.getElementById(id).style.visibility = "visible";
		document.getElementById(id).innerHTML = errorMessage;
	} else {
		document.getElementById(id).style.visibility = "hidden";
		document.getElementById(id).innerHTML = "";
	}
	
}

/* validateElement(required, pattern, element, displayName)
 *		Validates the given form element by checking if it's required and if it matches the given pattern. Displays error if validation fails
 *
 * Input:
 *		required: A boolean value indicating whether the element is required to be filled in
 * 		pattern: The regular expression pattern to match the element's input to
 * 		element: The form element to validate
 * 		displayName: The name of the element to use when displaying the error message
 *
 * Output: 
 *		returns false if form fails to validate and displays a relevant error
 * 		returns true if form successfully validates and hides any previous errors
 */
function validateElement(required, pattern, element, displayName) {
	var valid = false;
	var id = element.id;
	var errorId = id + 'Error';
	var errorMessageInvalid = 'Invalid ' + displayName;
	var errorMessageRequired = displayName + ' is required'
	if ((element.value == "" || element.value == null) && required) {
		displayError(true, errorId, errorMessageRequired);
	} else if (!(pattern.test(element.value))) {
		displayError(true, errorId, errorMessageInvalid);
	} else {
		displayError(false, errorId, '');
		valid = true;
	}
	return valid;
}

/* checkEmail(email)
 *		Checks the given form text element to ensure it is matches email format
 *
 * Input:
 *		form text element for the email field
 *
 * Output: 
 *		returns false if given field is does not match a valid email format and makes the error message in the html form visible
 * 		returns true otherwise and makes the error message hidden
 */
function checkEmail(email) {
	var pattern = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/;
	return validateElement(true, pattern, email, 'Email');
}

/* checkFirstName(firstName)
 *		Checks the given form text element to ensure it is not empty
 *
 * Input:
 *		form text element for the surname field
 *
 * Output: 
 *		returns false if given field is empty and makes the error message in the html form visible
 * 		returns true otherwise and makes the error message hidden
 */
function checkFirstName(firstName) {
	var pattern = /^[A-Z]{1}[A-z ,.'-]+$/; //supports names such as Martin Luther King, Jr.
	return validateElement(true, pattern, firstName, 'First Name');
}

/* checkSurname(surname)
 *		Checks the given form text element to ensure it is not empty
 *
 * Input:
 *		form text element for the surname field
 *
 * Output: 
 *		returns false if given field is empty and makes the error message in the html form visible
 * 		returns true otherwise and makes the error message hidden
 */
function checkSurname(surname) {
	var pattern = /^[A-Z]{1}[A-z ,.'-]+$/; //supports names such as Martin Luther King, Jr.
	return validateElement(true, pattern, surname, 'Surname');
}

function validateRadio(required, pattern, name, displayName) {
	var radioButtons = document.getElementsByName(name);
	var errorMessageInvalid = 'Invalid ' + displayName;
	var errorMessageRequired = displayName + ' is required'
	var errorId = name + "Error";
	var valid = false;
	var checked = false;
	for (i = 0; i < radioButtons.length; i++) {
		if (radioButtons[i].checked) {
			checked = true;
			value = radioButtons[i].value;
			break
		}
	}
	
	if (!checked) {
		displayError(true, errorId, errorMessageRequired);
	} else if (!pattern.test(value)) {
		displayError(true, errorId, errorMessageInvalid);
	} else {
		displayError(false, errorId, '');
		valid = true;
	}
	return valid;
}

/* checkSex(sex)
 *		Checks the given form radio button element to ensure a valid selection has been made
 *
 * Input:
 *		form radio button element for the sex field
 *
 * Output: 
 *		returns false if neither radio button is selected and makes the error message in the html form visible
 * 		returns true otherwise and makes the error message hidden
 */
function checkSex(name) {
	var pattern = /male|female/;
	return validateRadio(true, pattern, name, 'Sex');
	
}

/* checkDob(dob)
 *		Checks the given form date element to ensure it is a valid date format
 *
 * Input:
 *		form date element for the dob field
 *
 * Output: 
 *		returns false if given field is of an invalid format and makes the error message in the html form visible
 * 		returns true otherwise and makes the error message hidden
 */
function checkDob(dob) {
	var pattern = /^(0[1-9]|[12][0-9]|3[01])[-/](0[1-9]|1[012])[-/](18|19|20)\d\d$/g; //pattern for dd/mm/yyyy
	return validateElement(true, pattern, dob, 'Date of Birth');
}

/* checkPhone(phone)
 *		Checks the given form text element to ensure it is a valid phone format
 *
 * Input:
 *		form text element for the phone field
 *
 * Output: 
 *		returns false if given field is of an invalid format and makes the error message in the html form visible
 * 		returns true otherwise and makes the error message hidden
 */
function checkPhone(phone) {
	//the below pattern was retrieved from http://regexlib.com/REDetails.aspx?regexp_id=1787 by commenter Craig
	//should account for all forms of phone numbers
	var pattern = /(^\({0,1}((0|\+61)(2|4|3|7|8)){0,1}\){0,1}(\ |-){0,1}[0-9]{2}(\ |-){0,1}[0-9]{2}(\ |-){0,1}[0-9]{1}(\ |-){0,1}[0-9]{3}$)|(^13((\ |-){0,1}[0-9]{2}(\ |-){0,1}[0-9]{2})$)|(^1(3|8)[0-9]{2}(\ |-){0,1}[0-9]{3}(\ |-){0,1}[0-9]{3})$/g;
	return validateElement(true, pattern, phone, 'Phone');
}

/* checkStreet(street)
 *		Checks the given form text element to ensure it is not empty
 *
 * Input:
 *		form text element for the street field
 *
 * Output: 
 *		returns false if given field is empty and makes the error message in the html form visible
 * 		returns true if given field is not empty and makes the error message hidden
 */
function checkStreet(street) {
	var pattern = /^[0-9]+ [A-z]+ [A-z]+$/;
	return validateElement(true, pattern, street, 'Street');
}

function checkSuburb(suburb) {
	var pattern =  /^[A-z]{4}[ A-z]{0,25}$/;
	return validateElement(true, pattern, suburb, 'Suburb');
}

function checkCity(city) {
	var pattern =  /^[A-z]{4}[ A-z]{0,25}$/;
	return validateElement(true, pattern, city, 'City');
}

function checkPostcode(postcode) {
	var pattern =  /^[0-9]{4}$/;
	return validateElement(true, pattern, postcode, 'Postcode');
}

/* checkState(state)
 *		Checks the given form select element to ensure a state is selected
 *
 * Input:
 *		form select element for the state field
 *
 * Output: 
 *		returns false if no state selection has been made (value is empty) and makes the error message in the html form visible
 * 		returns true otherwise and makes the error message hidden
 */
function checkState(state) {
	var pattern = /QLD|NSW|VIC|ACT|WA|NT|SA|TAS/;
	return validateElement(true, pattern, state, 'State');
}

/* checkPassword(password1, password2)
 *		Checks the given form password elements to ensure they both match and are not empty
 *
 * Input:
 *		form text elements for the enterPassword and confirmPassword fields
 *
 * Output: 
 *		returns false if given field is empty or the passwords do not match and makes the error message in the html form visible
 * 		returns true otherwise and makes the error message hidden
 */
function checkPassword(password1, password2) {
	var valid = false;
	var id = 'password';
	var errorId = id + 'Error';
	var pattern = /^[A-z0-9!@#$%^&*]{6,}$/;
	var errorMessageInvalid = 'Password must be at least 6 characters';
	if ((password1.value == "" || password1.value == null)) {
		displayError(true, errorId, 'Password Missing');
	} else if (!(pattern.test(password1.value))) {
		displayError(true, errorId, errorMessageInvalid);
	} else if (password1.value != password2.value) {
		displayError(true, errorId, 'Passwords don\'t match');
	} else {
		displayError(false, errorId, '');
		valid = true;
	}
	return valid;
}