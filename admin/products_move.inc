<?php
$item = $_GET[item];
$cat = $_GET[cat];
$section = $_GET[section];
$new_item = $_GET[ni];

$pathlvl = 2;
$locedit = 1;
$def_loc = $_GET['def_loc'];

/* path stuff */
include("includes/path.inc");

if ($cat) {
	$dir = '../content/templ/'.$section.'/'.$cat.'/';
	$imgdir = "../content/images/".$section."/".$cat."/";
} else {
	$dir = '../content/templ/'.$section.'/';
	$imgdir = "../content/images/".$section."/";
}

$catdir = '../content/templ/'.$section.'/';

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
	<h2>$header</h2>

	

		
	Move $header to: 
	
";

foreach (glob("$catdir*", GLOB_ONLYDIR) as $category) {
	
	$catt = basename($category);
		
	if (file_exists($catdir.$catt."/def_".$def_loc.".head")) {
		$header = file_get_contents($catdir.$catt."/def_".$def_loc.".head", NULL, NULL, 0, 45);
	} else {
		$header = "Empty";
	}
	
    echo "
    	
			<div class='list_item'>
				<a href='transaction.php?t=move_item&section=$section&cat=$cat&item=$item&target=$catt'>
    				<span class='main'>$header</span>
    			</a>
    			
    			
    		</div>
		
		
		";
}



?>