<?php
	if (!$_GET['def_loc']) {
		$def_loc = $langlist[0];
	} else {
		$def_loc = $_GET['def_loc'];
	}
	$template = $_GET['template'];
	
	$sdir = "../content/templ/".$section."/";
	$cdir = "../content/templ/".$section."/".$cat."/";
	
	/*section*/
	if (file_exists($sdir."def_".$def_loc.".head")) {
		$secthead = file_get_contents($sdir."def_".$def_loc.".head", NULL, NULL, 0, 15);
	} else {
		$secthead = "Empty";
	}
	/*cat*/
	if (file_exists($cdir."def_".$def_loc.".head")) {
		$cathead = file_get_contents($cdir."def_".$def_loc.".head", NULL, NULL, 0, 15);
	} else {
		$cathead = "Empty";
	}
	/*item*/
	if (file_exists($cdir.$item.$def_loc.".head")) {
		$itemhead = file_get_contents($cdir.$item.$def_loc.".head", NULL, NULL, 0, 15);
	} else {
		$itemhead = "Empty";
	}
	
	echo "
		<div class='path'>
	";
	
	if ($pathlvl == 1) {
		/* pages and contact */
		echo "
			
				<a href='index.php?section=$section'>
					$secthead
				</a>
			
		";
	} elseif ($pathlvl == 2) {
		/* product special */
		echo "
			
				<a href='index.php?template=catlist&section=$section'>
					$secthead
				</a>
				 - 
				<a href='index.php?template=list&section=$section&cat=$cat'>
					$cathead
				</a>
			
		";
	} else {
		/* product special */
		echo "
			
				<a href='index.php?template=catlist&section=$section'>
					$secthead
				</a>
				
			
		";
	}
	$it = 0;
	
		echo "
			<div class='loc_cont'>
				
			";
				foreach ($langlist as $le) {
					if ($def_loc == $le) {
						$locsel = "loc_sel";
					} else {
						$locsel = " ";
					}
					/*different paths for categories and items
					if ($locedit == 1) {
						$path = "index.php?template=".$section."_view&section=$section&cat=$cat&item=$item&def_loc=$le";
					} elseif ($locedit == 2) {
						$path = "index.php?template=cat_view&section=$section&cat=$cat&item=$item&def_loc=$le";
					} else {
						$path = "index.php?template=list&section=$section&cat=$cat&item=$item&def_loc=$le";
					}
					 */
					$combpath = "index.php?template=".$template."&section=$section&cat=$cat&item=$item&def_loc=$le";
					$path = $combpath;
					
				echo "
					<div class='loc_item $locsel'>
						<a href='$path'>
							<img class='flag' src='layout/img/flag_".$le.".png' alt='$le'>
						</a>
					</div>
				";
				$it++;
				}
			echo "
				
			</div>
			
		";
	
		
	/*path end*/
	echo "
		</div>
		";
		
	
?>