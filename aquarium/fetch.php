<?php
$db=mysqli_connect("localhost","root","wutZ25Ba","aquarium");
if($db->connect_error)
{
	exit("Verbindungsfehler; ".mysqli_connect_error());
        alert("Verbindungsfehler");	
}
alert("Verbunden");
?>	
