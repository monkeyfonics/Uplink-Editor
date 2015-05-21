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
	$_GET[template] = "list";
} 
/* for files */
echo "<div class='content'>";
include("$_GET[template].inc");
echo "</div>";

echo "</div>";
include("../includes/footer.inc");