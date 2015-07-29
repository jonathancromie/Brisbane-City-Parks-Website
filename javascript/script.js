function search() {
	window.open("Results.php","_self");
}

function login() {
	var username = document.forms["login"]["username"].value;
	var password = document.forms["login"]["password"].value;

	if ((username == "admin") && (password == "admin")) {
		window.location = "index.php";
		document.getElementById('lblWelcome').innerHTML = username;
		return false;
	}

	else {
		alert("no");
		return false;
	}
}
/*
$(':radio').change(
  function(){
    $('.choice').text( this.value + ' stars' );
  } 
)
*/