<?php
	$section = $_GET['section'];
	$item = $_GET['item'];
	$cat = $_GET['cat'];
	$header = $_GET['header'];
	$content = $_GET['content'];
	$map = $_GET['map'];
	$def_loc = $_GET['def_loc'];
	$target = $_GET['target'];
	
	$uri = $_GET['uri'];
	
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
	$dirt = '../content/templ/'.$section.'/';
	$imgdirt = '../content/images/'.$section.'/';
	
	
	
	
	$nf = 1;
	while(file_exists($dirt.$target."/".$pre.$nf."/") )
	{
		$nf++;
			
	}
	$itemt = $pre.$nf;
	
	rename($dir.$item, $dirt.$target."/".$itemt);
	rename($imgdir.$item, $imgdirt.$target."/".$itemt);
	
	echo "
		$dir$item to $dirt$target/$itemt<br/>
		$imgdir$item to $imgdirt$target/$itemt<br/>
	";
	
	header("Refresh: 0; URL=".$ret_url);
	
?>