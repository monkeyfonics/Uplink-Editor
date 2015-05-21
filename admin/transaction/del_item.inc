<?php

$item = $_GET['item'];
$cat = $_GET['cat'];
$section = $_GET['section'];

$file = $item.'.inc';
$head = $item.'.head';
	
	if($cat) {
		$dir = "../content/templ/".$section."/".$cat."/";
		$imgdir = "../content/images/".$section."/".$cat."/";
	} else {
		$dir = "../content/templ/".$section."/";
		$imgdir = "../content/images/".$section."/";
	}

$files = $dir.$item."/";
	// When the directory is not empty:
	
	   if (is_dir($files)) {
	     $objects = scandir($files);
	     foreach ($objects as $object) {
	       if ($object != "." && $object != "..") {
	         if (filetype($files."/".$object) == "dir") rmdir($files."/".$object); else unlink($files."/".$object);
	       }
	     }
	     reset($objects);
	     rmdir($files);
	   } 
	
	
	// for images linked to files
	$filesimg = $imgdir.$item."/";
	   if (is_dir($filesimg)) {
	     $objects = scandir($filesimg);
	     foreach ($objects as $object) {
	       if ($object != "." && $object != "..") {
	         if (filetype($filesimg."/".$object) == "dir") rmdir($filesimg."/".$object); else unlink($filesimg."/".$object);
	       }
	     }
	     reset($objects);
	     rmdir($filesimg);
	   }
	
	
	$ret_url = '/admin/index.php?template=list&section='.$section.'&cat='.$cat;
	
	echo "$filesimg $object";
	
	header("Refresh: 0; URL=".$ret_url);
	  
?>