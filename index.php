<?php
include("includes/init.inc");
include("includes/header.inc");

echo "<div class='ribbon'>";
include("includes/top.inc");
include("includes/menu.inc");

if (!$_GET[section]) {
	$_GET[section] = "pages";
}
if (!$_GET[template]) {
	$_GET[template] = "pages_view";
}
if (!$_GET[item]) {
	$_GET[item] = "page_1";
}
	echo "<div class='main_area'>";
		echo "<div class='content'>";
		
			include("$_GET[template].inc");
		
		echo "</div>";
	echo "</div>";

echo "</div>";
include("includes/footer.inc");

?>