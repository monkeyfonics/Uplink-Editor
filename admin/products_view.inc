<?php
$item = $_GET[item];
$cat = $_GET[cat];
$section = $_GET[section];
$new_item = $_GET[ni];

$pathlvl = 2;
$locedit = 1;
$def_loc = $_GET['def_loc'];

/* path stuff */
include("includes/path.inc");

if ($cat) {
	$dir = '../content/templ/'.$section.'/'.$cat.'/';
	$imgdir = "../content/images/".$section."/".$cat."/";
} else {
	$dir = '../content/templ/'.$section.'/';
	$imgdir = "../content/images/".$section."/";
}

/* check for head file */
if (file_exists($dir.$item."/".$def_loc.".head")) {
	$header = file_get_contents($dir.$item."/".$def_loc.".head", NULL, NULL, 0);
	
} else {
	$header = "Empty";
	
}
/* check for inc file */
if (file_exists($dir.$item."/".$def_loc.".inc")) {
	
	$content = file_get_contents($dir.$item."/".$def_loc.".inc", NULL, NULL, 0);
} else {
	
	$content =  "Empty";
}

echo "
	
	<form action='transaction.php?t=item_save' method='post' id='prodsave'>
	<input type='hidden' name='item' value='$item'/>
	<input type='hidden' name='cat' value='$cat'/>
	<input type='hidden' name='section' value='$section'/>
	<input type='hidden' name='def_loc' value='$def_loc'/>
	<input type='hidden' name='new_item' value='$new_item'/>
	<input type='hidden' name='uri' value='$currentpath'/>
	<input type='submit' value='Save'>
	<div class='header_input'>
		<span class='header'>Header:</span>
		<input type='text' name='header' value='$header'></input>
	</div>
	
";

echo "
	<div class='maintext'>
		
		<textarea class='ckeditor' rows='8' name='content'>
			$content
		</textarea>
	</div>
	</form>
";	

/* image upload section */

if ($new_item == 1) {
	echo "
	<span>Save first to add images</span>
	";
} else {
	

echo "
	<div class='prodimg'>
	<span>Image:</span>
	";
	
	 
	echo "
		<form id='upload_form' enctype='multipart/form-data' method='post' action='transaction.php?t=imgupload'>
					<input type='hidden' name='item' value='$item'/>
					<input type='hidden' name='section' value='$section'/>
					<input type='hidden' name='new_item' value='$new_item'/>
					<input type='hidden' name='cat' value='$cat'/>
					
                    <div>
                        <div><label for='image_file'>Please select image file</label></div>
                        <div><input type='file' name='image_file' id='image_file' onchange='fileSelected();' /></div>
                    </div>
                    <div>
                        <input type='button' value='Upload' onclick='startUploading()' />
                    </div>
                    <div id='fileinfo'>
                        <div id='filename'></div>
                        <div id='filesize'></div>
                        <div id='filetype'></div>
                        <div id='filedim'></div>
                    </div>
                    <div id='error'>You should select valid image files only!</div>
                    <div id='error2'>An error occurred while uploading the file</div>
                    <div id='abort'>The upload has been canceled by the user or the browser dropped the connection</div>
                    <div id='warnsize'>Your file is very big. It may take a while.</div>

                    <div id='progress_info'>
                        <div id='progress'></div>
                        <div id='progress_percent'>&nbsp;</div>
                        <div class='clear_both'></div>
                        <div>
                            <div id='speed'>&nbsp;</div>
                            <div id='remaining'>&nbsp;</div>
                            <div id='b_transfered'>&nbsp;</div>
                            <div class='clear_both'></div>
                        </div>
                        <div id='upload_response'></div>
                    </div>
                </form>
			";
			/* list existing images */
			echo "
			<div class='imgstrip'>
				
				";
				
				foreach (glob("$imgdir/$item/*_thumb.png") as $img) {
						$filen = basename($img);
	    				echo "
	    				
	    					<div class='img_item'>
	    						<a href='transaction.php?t=del_img&section=$section&cat=$cat&item=$item&img=$filen' onclick='return confirm(\"Really delete?\");'>
	    							<img class='thumb' src='$img?=".filemtime($img)."' alt=''>
	    						</a>
	    					</div>
	    				";
	    				}
			echo "
			</div>
		
	</div>

	
		
";
}
//<img src='../content/templ/$_GET[section]/img/$_GET[item].jpg' alt=''>
?>