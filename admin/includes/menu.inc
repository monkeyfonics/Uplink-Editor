<?php
	if (!$_GET['def_loc']) {
		$def_loc = $langlist[0];
	} else {
		$def_loc = $_GET['def_loc'];
	}
	$pagepath = "../content/templ/pages/";
			if (file_exists($pagepath."def_".$def_loc.".head")) {
				$pagehead = file_get_contents($pagepath."def_".$def_loc.".head", NULL, NULL, 0, 15);
			} else {
				$pagehead = "Empty";
			}
	echo "
		<div class='menu_1_cont'>
			<a href='index.php?section=pages'>
				<div class='menu_1_item'>
					$pagehead
				</div>
			</a>
		";	
		$defpath = "../content/templ/products/";
			if (file_exists($defpath."def_".$def_loc.".head")) {
				$prodhead = file_get_contents($defpath."def_".$def_loc.".head", NULL, NULL, 0, 15);
			} else {
				$prodhead = "Empty";
			}
		
		echo "
			<a href='index.php?section=products&template=catlist'>
				<div class='menu_1_item'>
					$prodhead
				</div>
			</a>
		";
			$contpath = "../content/templ/contact/";
			if (file_exists($contpath."def_".$def_loc.".head")) {
				$conthead = file_get_contents($contpath."def_".$def_loc.".head", NULL, NULL, 0, 15);
			} else {
				$conthead = "Empty";
			}
			/*directly to contact template*/
		echo "
			<a href='index.php?template=contact_view&section=contact&item=cont_1'>
				<div class='menu_1_item'>
					$conthead
				</div>
			</a>
		</div>
		";
	
?>