<?php
$item = $_GET[item];
$section = $_GET[section];
$new_item = $_GET[ni];

$pathlvl = 1;
$locedit = 1;
$def_loc = $_GET['def_loc'];


/* path stuff */
include("includes/path.inc");

$dir = '../content/templ/'.$section.'/';

/* check for head file */
if (file_exists($dir.$item."/".$def_loc.".head")) {
	$header = file_get_contents($dir.$item."/".$def_loc.".head", NULL, NULL, 0);
	
} else {
	$header = "Empty";
	
}
/* check for inc file */
if (file_exists($dir.$item."/".$def_loc.".inc")) {
	
	$content = file_get_contents($dir.$item."/".$def_loc.".inc", NULL, NULL, 0);
} else {
	
	$content =  "Empty";
}


echo "
	<form action='transaction.php?t=item_save' method='post' id='pagesave'>
	<input type='hidden' name='item' value='$item'/>
	<input type='hidden' name='section' value='$section'/>
	<input type='hidden' name='def_loc' value='$def_loc'/>
	<input type='hidden' name='new_item' value='$new_item'/>
	<input type='hidden' name='uri' value='$currentpath'/>
	<input type='submit' value='Save'>
	<div class='header_input'>
		<span class='header'>Header:</span>
		<input type='text' name='header' value='$header'></input>
	</div>
	
";

echo "
	<div class='body_input'>
		<span class='header'>Body:</span>
		
		<textarea class='ckeditor' rows='10' name='content'>
			$content
		</textarea>
	
	</div>
	</form>		
";
?>