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
		$filelist[$item] = file_get_contents($dir.$item."/".$loc.".head", NULL, NULL, 0, 25);
		
	} else {
		
		
	}
	
	
	
}
$arrayLength = count($filelist);
natcasesort( $filelist );
foreach ($filelist as $fitem => $fheader) {
	
	/*test stuff*/
	/* check for head file */
	if (file_exists($dir.$fitem."/".$loc.".head")) {
		$header = file_get_contents($dir.$fitem."/".$loc.".head", NULL, NULL, 0);
		
	} else {
		$header = "Empty";
		
	}
	
	/* check for inc file */
	if (file_exists($dir.$fitem."/".$loc.".inc")) {
		
		$content = file_get_contents($dir.$fitem."/".$loc.".inc", NULL, NULL, 0);
	} else {
		
		$content =  "Empty";
	}
	
    echo "
    	<div class='prod_wrap'>
    	
			<div class='prod_list prod_spec'>
    			<span class='prod_head prod_head_spec'>$fheader</span>
    			
    				";
					
			echo "
    			
    		</div>
		
		";
		/*new*/
		echo "
		<div class='text'>
			$content
		</div>
		<div class='img_cont'>
			
			";
				
				foreach (glob("$imgdir$fitem/*_thumb.png") as $img) {
						$imglink = str_replace("thumb","big",$img);
						
	    				echo "
	    					<a href='plain.php?template=zoom_view&section=$section&cat=$cat&item=$item&currimg=$imglink'>
		    					<div class='img_item'>
		    						<img class='thumb_big' src='$img?=".filemtime($img)."' alt=''>
		    					</div>
	    					</a>
	    				";
	    				}
    		echo "	
    		
    	</div>
    </div>
";
}


echo "</div>";
?>