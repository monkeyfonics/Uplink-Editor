<?php

$item = $_GET['item'];
$cat = $_GET['cat'];
$section = $_GET['section'];

$file = $item.'.inc';
$head = $item.'.head';
	
	if($cat) {
		$dir = "../content/templ/".$section."/".$cat."/";
		$imgdir = "../content/images/".$section."/".$cat."/";
	} 


	// When the directory is not empty:
	$files = $dir;
	  if (is_dir($files)) {
	     $objects = scandir($files);
	     foreach ($objects as $object) {
	       if ($object != "." && $object != "..") {
	         if (filetype($files."/".$object) == "dir") {
	         	$sub = scandir($files."/".$object);
				foreach ($sub as $subdir) {
					if ($subdir != "." && $subdir != "..") {
	         			if (filetype($files."/".$object."/".$subdir) == "dir") rmdir($files."/".$object."/".$subdir); else unlink($files."/".$object."/".$subdir);
	       			}
				}
				
	         	rmdir($files."/".$object);
	         } else {
	         	unlink($files."/".$object);
	         } 
	       }
	     }
	     reset($objects);
	     rmdir($files);
	   } 
	    
	   
	   // for images linked to cat
		$files2 = $imgdir;
		  if (is_dir($files2)) {
		     $objects = scandir($files2);
		     foreach ($objects as $object) {
		       if ($object != "." && $object != "..") {
		         if (filetype($files2."/".$object) == "dir") {
		         	$sub = scandir($files2."/".$object);
					foreach ($sub as $subdir) {
						if ($subdir != "." && $subdir != "..") {
		         			if (filetype($files2."/".$object."/".$subdir) == "dir") rmdir($files2."/".$object."/".$subdir); else unlink($files2."/".$object."/".$subdir);
		       			}
					}
					
		         	rmdir($files2."/".$object);
		         } else {
		         	unlink($files2."/".$object);
		         } 
		       }
		     }
		     reset($objects);
		     rmdir($files2);
		   } 
	  
	   
	$ret_url = "/admin/index.php?template=catlist&section=".$section;
	

	header("Refresh: 0; URL=".$ret_url);

?>