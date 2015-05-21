<?php
$item = $_GET[item];
$section = $_GET[section];
$cat = $_GET[cat];
$new_item = $_GET[ni];

$pathlvl = 3;
$locedit = 2;
$def_loc = $_GET['def_loc'];

/* path stuff */
include("includes/path.inc");


$dir = '../content/templ/'.$section.'/';

if (file_exists($dir.$cat."/def_".$def_loc.".head") and !$new_item == 1) {
	$header = file_get_contents($dir.$cat."/def_".$def_loc.".head", NULL, NULL, 0);
	
} else {
	$header = "Empty";
	
}


echo "
	<form action='transaction.php?t=catsave' method='post' id='catsave'>
	<input type='hidden' name='cat' value='$cat'/>
	<input type='hidden' name='def_loc' value='$def_loc'/>
	<input type='hidden' name='new_item' value='$new_item'/>
	<input type='hidden' name='uri' value='$currentpath'/>
	<input type='submit' value='Save'>
	<div class='header_input'>
		<h3>Header:</h3>
		<input type='text' name='header' value='$header'></input>
	</div>
";

echo"
	
	</form>		
";
?>