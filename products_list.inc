<?php
$pathlvl = 2;
/* lists products */

$section = $_GET[section];
$cat = $_GET[cat];

if (!$cat) {
	$dir = "content/templ/".$section."/";
	$imgdir = "content/images/".$section."/";
} else {
	$dir = "content/templ/".$section."/".$cat."/";
	$imgdir = "content/images/".$section."/".$cat."/";
}

$catname = file_get_contents($dir.'def_'.$loc.'.head', NULL, NULL, 0, 45);

echo "<div>
";
		/* path stuff */
		include("includes/path.inc");

$filelist = array();

foreach (glob("$dir*", GLOB_ONLYDIR) as $filename) {
	$item = basename($filename, ".inc");
	if (file_exists($dir.$item."/".$loc.".head")) {
		$filelist[$item] = file_get_contents($dir.$item."/".$loc.".head", NULL, NULL, 0, 15);
		
	} else {
		
		
	}
}
$arrayLength = count($filelist);
natcasesort( $filelist );
foreach ($filelist as $fitem => $fheader) {
    echo "
    
    	<a href='index.php?template=".$section."_view&section=$section&cat=$cat&item=$fitem'>
			<div class='prod_list prod_spec'>
    			<span class='prod_head prod_head_spec'>$fheader</span>
    			<div>
    				";
					if (file_exists($imgdir.$fitem."/1_thumb.png")) {
						$img = $imgdir.$fitem."/1_thumb.png";
    					echo "<img class='thumb' src='$img?=".filemtime($img)."' alt=''>";
    				}
			echo "
    			</div>
    		</div>
		</a>
		";
}


echo "</div>";
?>