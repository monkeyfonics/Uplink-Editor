<?php
echo header("Content-type: text/html; charset=utf-8"); 

echo "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";

echo "
<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"
\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">

<html>
<head>
	<link href='layout/style.css' rel='stylesheet'>
	<link href='layout/style_small.css' rel='stylesheet' type='text/css' media='screen and (max-device-width: 800px)' />
	<title>$websitename</title>
	<link rel='shortcut icon' href='layout/img/icon.png' type='image/x-icon' />
	
	
	<script src='https://maps.googleapis.com/maps/api/js?v=3.exp&sensor=false'></script>
	<script src='js/main.js'></script>
	
	
	<script>
	  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
	  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
	  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
	  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');
	
	  ga('create', 'UA-44338612-1', 'uplink-data.fi');
	  ga('send', 'pageview');
	
	</script>
	
	<script type='text/javascript'>

    </script>
	
	
</head>
";

echo "
	<body>
		<div class='container'>
";


?>