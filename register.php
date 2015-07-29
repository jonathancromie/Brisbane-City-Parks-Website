<?php
  session_start();
  date_default_timezone_set('Australia/Brisbane');
  $errors = array();
  $validate = false;

  if ($_POST) {
    require 'includes/validate.inc';
    validate($errors);

    if ($errors){

      // redisplay the form
      include 'includes/form.inc';

    } else {
      include "processData.php";
    }

  } else {
    include 'includes/form.inc';
  }

?>
