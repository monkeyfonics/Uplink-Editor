<?php
$item = $_GET[item];
$section = $_GET[section];
$cat = $_GET[cat];

if (!$cat) {
	$dir = "content/templ/".$section."/";
	$imgdir = "content/images/".$section."/";
} else {
	$dir = "content/templ/".$section."/".$cat."/";
	$imgdir = "content/images/".$section."/".$cat."/";
}

/* check for head file */
if (file_exists($dir.$item."/".$loc.".head")) {
	$header = file_get_contents($dir.$item."/".$loc.".head", NULL, NULL, 0);
	
} else {
	$header = "Empty";
	
}

/* check for inc file */
if (file_exists($dir.$item."/".$loc.".inc")) {
	
	$content = file_get_contents($dir.$item."/".$loc.".inc", NULL, NULL, 0);
} else {
	
	$content =  "Empty";
}
/* check for map file */
if (file_exists($dir.$item."/".$loc.".map")) {
	$map = file_get_contents($dir.$item."/".$loc.".map", NULL, NULL, 0);
	
} else {
	$map = "Helsinki";
}


echo "
		<div>
			<div class='map_pad'>
			
";
include("includes/map.inc");


echo "
			</div>
			<div class='map_text'>
				$content
			</div>
		</div>
";
?>