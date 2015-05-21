<?php
$loc = $_SESSION['lang'];
	echo "
		<div class='topcontainer'>
			<a href='$sitepath'>
				<div class='logo'>
					
						<img src='layout/img/logo_ex.png' alt='logo'>
					
				</div>
			</a>
		
			
			<div class='admin'>
				<a href='$adminpath'>
					<img src='layout/img/admin.png' alt='admin'>
				</a>
			</div>
			
			
			<div class='lang'>
				<form action='transaction.php?t=user_lang' method='post' id='lang'>
				<input type='hidden' name='uri' value='$currentpath'/>
				";
			
			foreach ($langlist as $lang) {
				if ($loc == $lang) {
					$lsel = "_sel";
				} else {
					$lsel = "";
				}
				echo "
				
				<button class='langsel $lsel' name='lang' value='$lang'>
					
					<img src='layout/img/locale/loc_".$lang.$lsel.".png' alt='$lang'>
				</button>
				";
				
			}
			
				
		echo "		
				</form>	
			</div>
			
		</div>
	
	";
	
?>