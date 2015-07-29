function getLocation() {
	if (navigator.geolocation) {
        navigator.geolocation.getCurrentPosition(setLocation);
    }
}

function setLocation(pos) {
	var latitude = pos.coords.latitude;
	var longitude = pos.coords.longitude;
	var form = document.getElementById('geolocationSearch');
	document.getElementById("geolocationError").innerHTML = null;
	document.getElementById("geolocationError").style.visibility = "hidden";
	form.lat.value = latitude;
	form.lon.value = longitude;
	form.locationSubmit.style.visibility = "visible";
}