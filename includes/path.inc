<?php
	$sdir = "content/templ/".$section."/";
	$cdir = "content/templ/".$section."/".$cat."/";
	
	/*section*/
	if (file_exists($sdir."def_".$loc.".head")) {
		$secthead = file_get_contents($sdir."def_".$loc.".head", NULL, NULL, 0, 15);
	} else {
		$secthead = "Empty";
	}
	/*cat*/
	if (file_exists($cdir."def_".$loc.".head")) {
		$cathead = file_get_contents($cdir."def_".$loc.".head", NULL, NULL, 0, 15);
	} else {
		$cathead = "Empty";
	}
	/*item*/
	if (file_exists($cdir.$item."/".$loc.".head")) {
		$itemhead = file_get_contents($cdir.$item."/".$loc.".head", NULL, NULL, 0, 15);
	} else {
		$itemhead = "Empty";
	}
	
	if ($pathlvl == 1) {
		echo "
			<div class='path'>
				<a href='index.php?template=".$section."&section=$section'>
					$secthead
				</a>
			</div>
		";
	} elseif ($pathlvl == 2) {
		
		echo "
			<div class='path'>
				<a href='index.php?template=".$section."&section=$section'>
					$secthead
				</a>
				 - 
				<a href='index.php?template=".$section."_list&section=$section&cat=$cat'>
					$cathead
				</a>
			</div>
		";
	} else {
		echo "
			<div class='path'>
				<a href='index.php?template=".$section."&section=$section'>
					$secthead
				</a>
				 - 
				<a href='index.php?template=".$section."_list&section=$section&cat=$cat'>
					$cathead
				</a>
				 - 
				<a href='index.php?template=".$section."_view&section=$section&cat=$cat&item=$item'>
					$itemhead
				</a>
			</div>
		";
	}
	
?>