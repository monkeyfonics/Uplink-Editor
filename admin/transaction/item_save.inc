<?php
	$section = $_POST['section'];
	$item = $_POST['item'];
	$cat = $_POST['cat'];
	$header = $_POST['header'];
	$content = $_POST['content'];
	$map = $_POST['map'];
	$def_loc = $_POST['def_loc'];
	$new_item = $_POST['new_item'];
	
	$uri = $_POST['uri'];
	
	if ($section == 'pages') {
		$pre = "page_";
		$ret_url = '/admin/index.php?section=pages';
	} elseif ($section == 'products') {
		$pre = "prod_";
		$ret_url = '/admin/index.php?section='.$section.'&cat='.$cat;
	} elseif ($section == 'contact') {
		$pre = "cont_";
		$ret_url = '/admin/index.php?section=contact';
	}
	
	
	if($cat) {
		$dir = '../content/templ/'.$section.'/'.$cat.'/';
		$imgdir = '../content/images/'.$section.'/'.$cat.'/';
	} else {
		$dir = '../content/templ/'.$section.'/';
		$imgdir = '../content/images/'.$section.'/';
	}
	
	if ($new_item == 1) {
		/* checks for free number */
		$nf = 1;
		while(file_exists($dir.$pre.$nf."/") )
		{
			$nf++;
			
		}
		$item = $pre.$nf;
		$file = $def_loc.'.inc';
		$head = $def_loc.'.head';
		$mapf = $def_loc.'.map';
		mkdir($dir.$item, 0777);
		chmod($dir.$item, 0777);
		/*make img dir*/
		mkdir($imgdir.$item, 0777);
		chmod($imgdir.$item, 0777);
		
		$uri = $uri."&item=".$item;
	} else {
		$file = $def_loc.'.inc';
		$head = $def_loc.'.head';
		$mapf = $def_loc.'.map';
	}
	
	$item = $item."/";
	/*write info to file */
	

	/* header content */
	file_put_contents($dir.$item.$head, $header);
	
	/* main content */
	file_put_contents($dir.$item.$file, $content);
	
	if ($section == "contact") {
		/* map content */
		file_put_contents($dir.$item.$mapf, $map);
		
	}
	
	
	
	
	header("Refresh: 0; URL=".$uri);

?>