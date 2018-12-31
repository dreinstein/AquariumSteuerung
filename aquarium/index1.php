<!DOCTYPE html>
<html>
<head>
<script type="text/javascript">
	function fetchValues()
	{
		alert('temp holen');
	}
</script>
</head>
<body>
<title> aaaARDUINO ETHERNET SHIELD</title>
	<h1 style="color:green;"> Aquarium Steuerung</h1>
<hr> 
<br>
<input type=button value="werte holen" onclick="fetchValues()">
<p></p>
<input type=button value="setze Sommerzeit" onClick="setSummertime()">
<p></p>
<input type=button value="setze Winterzeit" onClick="setWintertime()">
<p></p>
<label for="Temperatur">Temperatur:</label>
<input type="number" id="temperature" value="0">
<p></p>
<label for="Licht">Licht:</label>
<input type="text" id="lichtAnAus" value="An">
<p></p>
<label for="Heizung">Heizung:</label>
<input type="tex" id="HeizungAnAus" value="An">
<p></p>
<label for="Service">Service:</label>
<input type="text" id=ServiceAnAus" value="An">
<p></p> 
<label for="Licht">Licht:</label>
<input type="text" id=LichtAnAus" value="An">
<p></p> 
</hr>
</br>
</body>
<?php
	function fetch()
        {
	    $db=mysqli_connect("localhost","root","wutZ25Ba","aquarium");
	}
?>
</html>
