<?php
$def_loc = $_GET['def_loc'];

$section = $_GET[section];
$dir = '../content/templ/'.$section.'/';
$nr = 1;
$pathlvl = 3;
/* path stuff */
include("includes/path.inc");


foreach (glob("$dir*", GLOB_ONLYDIR) as $category) {
	$nr++;
	$cat = basename($category);
		
	if (file_exists($dir.$cat."/def_".$def_loc.".head")) {
		$header = file_get_contents($dir.$cat."/def_".$def_loc.".head", NULL, NULL, 0, 45);
	} else {
		$header = "Empty";
	}
	
    echo "
    	
			<div class='list_item'>
				<a href='index.php?template=list&section=$section&cat=$cat&def_loc=$def_loc'>
    				<span class='main'>$header</span>
    			</a>
    			<a href='transaction.php?t=del_cat&section=$section&cat=$cat' onclick='return confirm(\"Really delete?\");'>
    				<span class='rbutton'>Del</span>
    			</a>
    			<a href='index.php?template=cat_view&section=$section&cat=$cat&def_loc=$def_loc'>
    				<span class='rbutton'>Edit</span>
    			</a>
    			
    		</div>
		
		
		";
}

/* new item */
if ($section == 'products') {
	$cat = 'cat_'.$nr;
}


 echo "
    	<a href='index.php?template=cat_view&section=$section&ni=1'>
			<div class='list_button'>
    			New category
    		</div>
		</a>
		";


?>