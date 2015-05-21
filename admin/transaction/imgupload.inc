<?php
/*wide image script */
include 'includes/wideimage/WideImage.php';

$item = $_POST[item];
$imgnr = $_POST[imgnr];
$section = $_POST[section];
$cat = $_POST[cat];


if($cat) {
		$filepath = '../content/images/'.$section.'/'.$cat.'/';
		$temppath = '../content/tmp/images/'.$section.'/';
	} else {
		$filepath = '../content/images/'.$section.'/';
		$temppath = '../content/tmp/images/'.$section.'/';
	}
	
/* checks for free number */
$it = 1;
while(file_exists($filepath.$item."/".$it."_thumb.png") )
	{
		$it++;
	}
	$imgnr = $it;

function bytesToSize1024($bytes, $precision = 2) {
    $unit = array('B','KB','MB');
    return @round($bytes / pow(1024, ($i = floor(log($bytes, 1024)))), $precision).' '.$unit[$i];
}
$tmp_name = $_FILES["image_file"]["tmp_name"];
$sFileName = $_FILES['image_file']['name'];
$sFileType = $_FILES['image_file']['type'];
$sFileSize = bytesToSize1024($_FILES['image_file']['size'], 1);

if ($sFileType == "image/gif") {
	$ext = ".gif";
} elseif ($sFileType == "image/jpeg") {
	$ext = ".jpg";
} elseif ($sFileType == "image/png")  {
	$ext = ".png";
}

if (!empty($_FILES)) {
    $tempFile =  $temppath.$cat."_".$sFileName;
    
    move_uploaded_file($tmp_name, $tempFile);
	
	$plainpath = $filepath.$item."/";
	$filename = $imgnr;
	$newFile =  $temppath.$cat."_".$filename.$ext;
    rename($tempFile, $newFile);
	
	/*wideimage stuff*/
    $image = WideImage::load($newFile);
	$back = $image->allocateColor(255, 255, 255);
    $resized = $image->resizeDown(800,800);
    $resized->saveToFile($plainpath.$filename."_big.png");
	/* check size */
	$sizeh = $resized->getHeight();
	$sizew = $resized->getWidth();
	
	/*make thumb*/
	$thumb = $image->resizeDown(125,125,'outside');
	
	/* check size */
	$sizeth = $thumb->getHeight();
	$sizetw = $thumb->getWidth();
	
	/* make thumb with cropped size as square */
	if ($sizeh<=$sizew) {
		$thumb = $thumb->resizeCanvas($sizeth,$sizeth,center,center,$back);
	} else {
		$thumb = $thumb->resizeCanvas($sizetw,$sizetw,center,center,$back);
	}
	
    $thumb->saveToFile($plainpath.$filename."_thumb.png");
	
	/*output */
	echo "
	<p>Your file: {$sFileName} has been successfully received.</p>
	<p>Type: {$sFileType}</p>
	<p>Size: {$sFileSize}</p>
	";
}



?>