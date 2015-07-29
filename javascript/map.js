var map;

function map_at(lat, lon, zoom, geolocation) {
	
	map = L.map('map').setView([lat, lon], zoom);

	L.tileLayer('https://{s}.tiles.mapbox.com/v3/{id}/{z}/{x}/{y}.png', {
		attribution: 	'Map data &copy; <a href="http://openstreetmap.org">OpenStreetMap</a> contributors, ' +
						'<a href="http://creativecommons.org/licenses/by-sa/2.0/">CC-BY-SA</a>, ' +
						'Imagery © <a href="http://mapbox.com">Mapbox</a>',
		maxZoom: 18,
		id: 'examples.map-i875mjb7'
	}).addTo(map);
}

function marker(lat, lon, place, id) {
	var marker = L.marker([lat, lon]).addTo(map);
	
	marker.bindPopup("<a href='parkResult.php?id=" + id + "'>" + place + "</a>");
	
}