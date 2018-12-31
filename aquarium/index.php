<!DOCTYPE html>
<html>
<head>
</head>
<body>
<title> ARDUINO ETHERNET SHIELD</title>
	<h1 style="color:green;"> Aquarium Steuerung</h1>
<hr>
<?php
	fetch();
	$db=mysqli_connect("localhost","root","wutZ25Ba","aquarium");
	if($db->connect_error)
	{
	 	exit("Verbindungsfehler: ".mysqli_connect_error());
	}
	$val = "select * from light_onoff order by id desc limit 1";
	$v = $db->query($val);
        $row = $v->fetch_assoc();
        $weekAn1 = $row['weekday_on1'];
        $weekAn2 = $row['weekday_on2'];
        $weekOff1 = $row['weekday_off1'];
        $weekOff2 = $row['weekday_off2'];
        $weekendAn1 = $row['weekend_on1'];
        $weekendAn2 = $row['weekend_on2'];
        $weekendOff1 = $row['weekend_off1'];
        $weekendOff2 = $row['weekend_off2'];
?> 
<br>
<p></p>
<p></p>
<p></p>
<p></p>
<form action="index.php" method="get">
	<input type="submit" name="fetchDataValue" value="refresh">
</form>
<p></p>
<p></p>
<form action="http://192.168.0.22" method="get">
<input type="submit" name="sync" value="sync">
</form>
<p></p>
<p></p>
<label>
	Uhrzeit Woche An1 :
	<input type="time" name="Uhrzeit Woche An1" value="<?php echo $weekAn1;?>"/>
</label>
<label>
        Uhrzeit Woche An2 :
        <input type="time" name="Uhrzeit Woche An2" value="<?php echo $weekAn2;?>"/>
</label>
<p></p>
<p></p>
<label>
	Uhrzeit Woche Aus1 :
	<input type="time" name="Uhrzeit Woche Aus1" value="<?php echo $weekOff1;?>"/>
</label>
<label>
        Uhrzeit Woche Aus2 :
        <input type="time" name="Uhrzeit Woche Aus2" value="<?php echo $weekOff2;?>"/>
</label>
<p></p>
<p></p>
<label>
	Uhrzeit Wochenende An1 :
	<input type="time" name="Uhrzeit Wocheende An1" value="<?php echo $weekendAn1;?>"/>
</label>
<label>
        Uhrzeit Wocheende An2 :
        <input type="time" name="Uhrzeit Wocheende An2" value="<?php echo $weekendAn2;?>"/>
</label>
<p></p>
<p></p>
<label>
	Uhrzeit Wochenende Aus1 :
	<input type="time" name="Uhrzeit Wocheende Aus1" value="<?php echo $weekendOff1;?>"/>
</label>
<label>
        Uhrzeit Wochenende Aus2 :
        <input type="time" name="Uhrzeit Wocheende Aus2" value="<?php echo $weekendOff2;?>"/>
</label>
</hr>
</br>
</body>
<?php
	if(isset($_GET['fetchDataValue']))
	{
		fetch();
	}
	
	function fetch()
        {
	    $db=mysqli_connect("localhost","root","wutZ25Ba","aquarium");
	    if($db->connect_error)
	    {
	     	exit("Verbindungsfehler: ".mysqli_connect_error());
	    }
	    $values = "select * from aqua_val order by value_id  desc limit 1";
	   $v = $db->query($values); 
	    if($v->num_rows > 0)
            {
	    }
	    else
	    {
		echo "Error: $db->error()";
	    } 
	    $row=$v->fetch_assoc();
	    echo "<br /><br />Temperatur = ";
	    echo $row['temperature'];
	    echo "<br />Licht = ";
	    echo $row['light'];
	    echo "<br />Pumpe = ";
	    echo $row['pump'];
	    echo "<br />Heizung = ";
            echo $row['heating'];		 
	}
	function fetchTimes()
	{
	    $db=mysqli_connect("localhost","root","wutZ25Ba","aquarium");
	    if($db->connect_error)
	    {
	     	exit("Verbindungsfehler: ".mysqli_connect_error());
	    }
	    $val = "select * from light_onoff";
	    $v = $db->query($val);
            $row = $v->fetch_assoc();
            $weekAn1 = $row['weekday_on1'];
            $weekAn2 = $row['weekday_on2'];
            $weekOff1 = $row['weekday_off1'];
            $weekOff2 = $row['weekday_off2'];
            $weekendAn1 = $row['weekend_on1'];
            $weekendAn2 = $row['weekend_on2'];
            $weekendOff1 = $row['weekend_off1'];
            $weekendOff2 = $row['weekend_off2'];
	}
?>
</html>

