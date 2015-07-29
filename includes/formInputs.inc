<?php
	function createLabel($name, $label) {
		echo "<label for=\"$name\">$label </label>";
	}

	function posted_value($name) {
		if (isset($_POST[$name])) {
			return $_POST[$name];
		}
	}

	function errorLabel($errors, $name) {
		if (isset($errors[$name])) {
			echo " <span id=\"$name"."Error\" class=\"error\" style=\"color:red\">$errors[$name]</span>";
		} else {
			echo " <span id=\"$name"."Error\" class=\"error\" style=\"color:red;visibility:hidden\"></span>";
		}
	}

	function textInput($errors, $name, $label, $sampleText) {
		echo '<div class="required_field">';
		echo '<tr><td>';
		createLabel($name, $label);
		echo "</td><td>";
		$value = posted_value($name);
		echo "<input type=\"text\" id=\"$name\" name=\"$name\" value=\"$value\"/ placeholder=\"$sampleText\" float:'right'>";
		errorLabel($errors, $name);
		echo '</td></tr></div>';
	}

	function selectInput($name, $values) {
		echo "<div class='styled-select'>";
		echo "<select id=\"$name\" name=\"$name\" style=\"width: 5rem\">";
		foreach ($values as $index => $value)  {
			$selected = ($value==posted_value($name))?'selected="selected"':'';
			echo "<option $selected value=\"$value\">$value</option>";
		}
		echo '</select>';
		echo "</div>";
	}

	function stateSelect($errors) {
		$name = 'state';
		$label = 'State';
		$states = array('', 'QLD', 'NSW', 'VIC', 'ACT', 'WA', 'NT', 'SA', 'TAS');
		echo '<div class="required_field">';
		echo '<tr><td>';
		createLabel($name, $label);
		echo "</td><td>";
		$value = posted_value($name);
		selectInput('state', $states);
		errorLabel($errors, $name);
		echo '</td></tr></div>';
	}

	function radioInput($name, $values) {
		foreach ($values as $value => $display) {
			if (posted_value($name) == $value) {
				echo "<input type=\"radio\" id=\"rdb$value\" name=\"$name\" value=\"$value\" checked>";
			} else {
				echo "<input type=\"radio\" id=\"rdb$value\" name=\"$name\" value=\"$value\">";
			}

			echo createLabel($value, $display);
		}
	}

	function sexInput($errors) {
		$name = 'sex';
		$label = 'Sex';
		$values = array('male' => 'Male', 'female' => 'Female');
		echo '<div class="required_field">';
		echo '<tr><td>';
		createLabel($name, $label);
		echo "</td><td>";
		$value = posted_value($name);
		radioInput($name, $values);
		errorLabel($errors, $name);
		echo '</td></tr></div>';
	}

	function passwordInput($errors, $name, $label) {
		echo '<div class="required_field">';
		echo '<tr><td>';
		createLabel($name, $label);
		echo "</td><td>";
		$value = posted_value($name);
		echo "<input type=\"password\" id=\"$name\" name=\"$name\" value=\"$value\"/>";
		errorLabel($errors, $name);
		echo '</td></tr></div>';
	}
	
	function checkBoxInput($errors, $name, $label) {
		echo '<div class="required_field">';
		echo '<tr><td>';
		createLabel($name, $label);
		echo "</td><td>";
		$value = posted_value($name);
		if ($value == NULL) {
			echo "<input type=\"checkbox\" id=\"$name\" name=\"$name\" value=1>";
		} else {
			echo "<input type=\"checkbox\" id=\"$name\" name=\"$name\" value=1 checked>";
		}
		errorLabel($errors, $name);
		echo '</td></tr></div>';
	}
?>
