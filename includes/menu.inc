<?php
	
	echo "
		<div class='menu_1_cont'>
			
			";
			$dir = "content/templ/pages/";
			
			foreach (glob("$dir*", GLOB_ONLYDIR) as $filename) {
					$item = basename($filename);
					
					if (file_exists($dir.$item."/".$loc.".head")) {
						$header = file_get_contents($dir.$item."/".$loc.".head", NULL, NULL, 0, 45);
					} else {
						$header = "Empty";
					}
					
			    echo "
			    	<a href='index.php?item=".$item."&section=pages'>
						<div class='menu_1_item'>
			    			$header
			    		</div>
					</a>
					";
			}
			$defpath = "content/templ/products/";
			if (file_exists($defpath."def_".$loc.".head")) {
				$prodhead = file_get_contents($defpath."def_".$loc.".head", NULL, NULL, 0, 15);
			} else {
				$prodhead = "Empty";
			}
	echo "
			
			<a href='index.php?template=products&section=products&item=prod_1'>
				<div class='menu_1_item'>
			    	$prodhead
			    </div>
			</a>
			";
			/*contact page */
			$defpath = "content/templ/contact/";
			if (file_exists($defpath."def_".$loc.".head")) {
				$conthead = file_get_contents($defpath."def_".$loc.".head", NULL, NULL, 0, 15);
			} else {
				$conthead = "Empty";
			}
			echo "
			<a href='index.php?template=contact_view&section=contact&item=cont_1'>
				<div class='menu_1_item'>
			    	$conthead
			    </div>
			</a>
			
			<div style='float:right; padding-top: 15px; padding-right: 5px;'>
				<div class='fb-like' data-href='https://www.facebook.com/schulmanantiques' data-width='The pixel width of the plugin' data-height='The pixel height of the plugin' data-colorscheme='light' data-layout='button_count' data-action='like' data-show-faces='false' data-send='false'></div>
			</div>
		</div>
		";
	
?>