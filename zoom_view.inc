<?php
$pathlvl = 3;

$loc = $_SESSION['lang'];

$item = $_GET[item];
$section = $_GET[section];
$cat = $_GET[cat];

$currentimg = $_GET[currimg];


if (!$cat) {
	$dir = "content/templ/".$section."/";
	$imgdir = "content/images/".$section."/";
} else {
	$dir = "content/templ/".$section."/".$cat."/";
	$imgdir = "content/images/".$section."/".$cat."/";
}

/*fetching items*/
$getitem = glob($imgdir."*", GLOB_ONLYDIR);

/*fetching filepaths*/
$fullist = glob($imgdir."*/*_big.png");
end($fullist);
$lastkey = key($fullist);
reset($fullist);

foreach ($fullist as $imgkey => $imglist) {
	
	if ($imglist == $currentimg) {
		$lastimg = $imgkey-1;
		$nextimg = $imgkey+1;
		$currkey = $imgkey;
		
		
		/*check for item */
		foreach ($getitem as $iid => $itext) {
			$gitem = basename($itext);
			
			$itemout = strstr($imglist,$gitem);
			if ($itemout) {
				
				$item = $gitem;
			}
			
		}
		
		
		/* check if list ends*/
		if (array_key_exists($lastimg, $fullist)) {
    		
		} else {
			$lastimg = $lastkey;
		}
		if (array_key_exists($nextimg, $fullist)) {
    		
		} else {
			$nextimg = 0;
		}
		
	}
	
	
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




$lastpath = "plain.php?template=zoom_view&section=$section&cat=$cat&item=$item&currimg=$fullist[$lastimg]";
$nextpath = "plain.php?template=zoom_view&section=$section&cat=$cat&item=$item&currimg=$fullist[$nextimg]";
				

echo "<div>

			<div class='fullbutton'>
				<a href='$lastpath'>
    				<span class='left'>Back</span>
    			</a>
    			<a href='index.php?template=".$section."_list&section=$section&cat=$cat#$item'>
    				<span class='middle'>Close</span>
    			</a>
    			<a href='$nextpath'>
    				<span class='right'>Forward</span>
    			</a>
    			
    		</div>
		
	";
		
		
echo "
		
		<div class='img_cont zoom_cont'>
		
			<div class='img_item zoom_item'>
		    	<img class='img_big' src='$currentimg?=".filemtime($currentimg)."' alt=''>
		    </div>	
    	</div>
    	<div class='text'>
			$content
			
		</div>
";

echo "</div>";
?>