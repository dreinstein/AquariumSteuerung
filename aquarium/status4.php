<?php
$temp = $_GET["Temperature"];
$light = $_GET["Light"];
$pump = $_GET["Pump"];
$heating = $_GET["Heating"];
$db=mysqli_connect("localhost","root","wutZ25Ba","aquarium");
if($db->connect_error)
{
	exit("Verbindungsfehler: ".mysqli_connect_error());
	echo "Fehler in der Verbindung";
}
if($db->query($insert)==TRUE)
	{
		echo "New record created";
	}
	else
	{
		echo "Error: $temp $light $pump $heating" ;
	}
?>