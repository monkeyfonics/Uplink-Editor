<?php
$def_loc = $_GET['def_loc'];


$section = $_GET[section];
$cat = $_GET[cat];

if ($section == 'products') {
	$pathlvl = 2;
} else {
	$pathlvl = 1;
}


/* path stuff */
include("includes/path.inc");

if ($cat) {
	$dir = '../content/templ/'.$section.'/'.$cat.'/';
} else {
	$dir = '../content/templ/'.$section.'/';
}

$filelist = array();

foreach (glob("$dir*", GLOB_ONLYDIR) as $filename) {
	
	$item = basename($filename);
		
	if (file_exists($dir.$item."/".$def_loc.".head")) {
		$filelist[$item] = file_get_contents($dir.$item."/".$def_loc.".head", NULL, NULL, 0, 45);
	} else {
		
		$filelist[$item] = "Empty";
	}
	
}

$arrayLength = count($filelist);

/* pages gets sorted wrong if asort*/
uksort( $filelist, "strnatcasecmp" );
foreach ($filelist as $fitem => $fheader) {
    echo "
    	
			<div class='list_item'>
				<a href='index.php?template=".$section."_view&section=$section&cat=$cat&item=$fitem&def_loc=$def_loc'>
    				<span class='main'>$fheader</span>
    			</a>
    			
    			<a href='transaction.php?t=del_item&section=$section&cat=$cat&item=$fitem' onclick='return confirm(\"Really delete?\");'>
    				<span class='rbutton'>Del</span>
    			</a>
    			";
    			if ($section == 'products') {
    				echo "
					<a href='index.php?template=".$section."_move&section=$section&cat=$cat&item=$fitem&def_loc=$def_loc'>
    					<span class='rbutton'>Move</span>
    				</a>
    				";
				}
    		echo "
    		</div>
		
		";
}

/* new item */
if ($section == 'pages') {
	$item = 'page_'.$nr;
} elseif ($section == 'products') {
	$item = 'prod_'.$nr;
} elseif ($section == 'contact') {
	$item = 'cont_'.$nr;
}


/* hiding new item from contacts so far */

if ($section == 'pages' or $section == 'products') {
 echo "
    	<a href='index.php?template=".$section."_view&section=$section&cat=$cat&ni=1&def_loc=$def_loc'>
			<div class='list_button'>
    			New Item
    		</div>
		</a>
		";
		}

?>