<?php
$pathlvl = 3;

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
echo "<div>
	";
		/* path stuff */
		include("includes/path.inc");
		
echo "
		<div class='text'>
			$content
		</div>
		<div class='img_cont'>
			
			";
				
				foreach (glob("$imgdir$item/*_thumb.png") as $img) {
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
";

echo "</div>";
?>