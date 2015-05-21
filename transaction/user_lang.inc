<?php
$lang = $_POST['lang'];
$currentpath = $_POST['uri'];

$_SESSION['lang'] = $lang;

$ret_url = $currentpath;


header("Refresh: 0; URL=".$ret_url);



?>