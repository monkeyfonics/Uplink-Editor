<?php
	session_start();
	
	include("includes/settings.inc");
	
	$abpath = "/var/www/web/editor/demo/";
	$sitepath = "/";
	$domainpath = "demo.uplink.fi";
	$adminpath = "admin/";
	$contentpath = "content/";
	
	$currentpath = "$_SERVER[REQUEST_URI]";
	
	if (empty($_SESSION['lang'])) {
   		$_SESSION['lang'] = $langlist[0];
	}
    

	
	
?>