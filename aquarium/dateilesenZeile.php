<?php
$timing = file("timing.txt");
echo count $timing
for($i=0;$i < count($timing); $i++){
   echo $i.": ".$timing[$i]."<br><br>";
}
?>