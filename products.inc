<?php
$pathlvl = 1;
/* lists product categories */
$section = $_GET[section];
$dir = "content/templ/".$section."/";

$imgdir = "content/images/".$section."/";
if (file_exists($dir."def_".$loc.".head")) {
		$secthead = file_get_contents($dir."def_".$loc.".head", NULL, NULL, 0, 15);
	} else {
		$secthead = "Empty";
	}

echo "<div>
	";
		/* path stuff */
		include("includes/path.inc");
		
foreach (glob($dir.'*', GLOB_ONLYDIR) as $category) {
	$cate = basename($category);
	if (file_exists($dir.$cate."/def_".$loc.".head")) {
		$header = file_get_contents($dir.$cate."/def_".$loc.".head", NULL, NULL, 0, 15);
	} else {
		$header = "Empty";
	}
	
	/*fetching filepaths*/
	$imglist = glob($imgdir.$cate."/*/1_thumb.png");
	
	
	echo "
		<div class='prod_cont'>
    	<a href='index.php?template=".$section."_list&section=$section&cat=$cate'>
			<div class='prod_list cat_spec'>
    			<span class='prod_head cat_head_spec'>$header</span>
    			<div>
    				";
					/*amount of thumbs */
					for ($i = 0; $i <= 3; $i++) {
						echo "
							
								<div class='imgloop'>
									<img class='thumb' src='$imglist[$i]?=".filemtime($imglist[$i])."' alt=''>
								</div>
							";
							
						
					}
				echo "
    			</div>
    		</div>
		</a>
		</div>
		";
}



echo "</div>";
?>