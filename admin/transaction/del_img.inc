<?php

$item = $_GET['item'];
$cat = $_GET['cat'];
$section = $_GET['section'];

$targetimg =  $_GET['img'];

$imgthumb = $targetimg;

$imgbig = str_replace("thumb", "big", $targetimg);

	
	if($cat) {
		$dir = "../content/templ/".$section."/".$cat."/";
		$imgdir = "../content/images/".$section."/".$cat."/";
	} else {
		$dir = "../content/templ/".$section."/";
		$imgdir = "../content/images/".$section."/";
	}
// Target path
$files = $imgdir.$item."/";
	//Delete selected images
	unlink($files."/".$imgthumb);
	unlink($files."/".$imgbig);
	 
	
	
	$ret_url = '/admin/index.php?template=products_view&section='.$section.'&cat='.$cat.'&item='.$item;
	
	echo "$files - $imgthumb - $imgbig";
	
	header("Refresh: 0; URL=".$ret_url);
	  
?>