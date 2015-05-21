<?php
	$section = $_POST['section'];
	$cat = $_POST['cat'];
	$header = $_POST['header'];
	$new_item = $_POST['new_item'];
	$def_loc = $_POST['def_loc'];
	
	$uri = $_POST['uri'];
	
	$file = "def_".$def_loc.".head";
	$dir1 = '../content/templ/products/';
	$imgdir = '../content/images/products/';
	
	
	
	if ($new_item == 1) {
		/* checks for free number */
		$nf = 1;
		while(file_exists($dir1.'cat_'.$nf) )
		{
			$nf++;
			
		}
		$item = "cat_".$nf."/";
		mkdir($dir1.$item, 0777);
		chmod($dir1.$item, 0777);
		
		mkdir($imgdir.$item, 0777);
		chmod($imgdir.$item, 0777);
		
		$uri = '/admin/index.php?section=products&template=cat_view&cat='.$item."&def_loc=".$def_loc;
		
		
		 /*for safety only */
		$cat = "cat_".$nf;
		
	} else {
		$item = $cat."/";
		
		
	}

	/* Only write if the category is defined */
		if ($cat) {
			/* header content */
			file_put_contents($dir1.$item.$file, $header);
		}
	
	
	
	
	
	
	$ret_url = '/admin/index.php?section=products&template=catlist';
	
	header("Refresh: 0; URL=".$ret_url);

?>