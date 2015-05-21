<?php
echo header("Content-type: text/html; charset=utf-8"); 

echo "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";

echo "
<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"
\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">

<html>
<head>
	<link href='../layout/style.css' rel='stylesheet'>
	<link href='../layout/style_small.css' rel='stylesheet' type='text/css' media='screen and (max-device-width: 800px)' />
	<link href='layout/style.css' rel='stylesheet'>
	
	<link href='layout/upload.css' rel='stylesheet'>
	<title>$websitename - Admin</title>
	<link rel='shortcut icon' href='layout/img/icon.png' type='image/x-icon' />
	
	<script src='ckeditor/ckeditor.js'></script>
	<script src='js/upscript.js'></script>
	
	<script src='js/main.js'></script>
	<script>

		// Uncomment the following code to test the 'Timeout Loading Method'.
		// CKEDITOR.loadFullCoreTimeout = 5;

		window.onload = function() {
			// Listen to the double click event.
			if ( window.addEventListener )
				document.body.addEventListener( 'dblclick', onDoubleClick, false );
			else if ( window.attachEvent )
				document.body.attachEvent( 'ondblclick', onDoubleClick );

		};

		function onDoubleClick( ev ) {
			// Get the element which fired the event. This is not necessarily the
			// element to which the event has been attached.
			var element = ev.target || ev.srcElement;

			// Find out the div that holds this element.
			var name;

			do {
				element = element.parentNode;
			}
			while ( element && ( name = element.nodeName.toLowerCase() ) &&
				( name != 'div' || element.className.indexOf( 'editable' ) == -1 ) && name != 'body' );

			if ( name == 'div' && element.className.indexOf( 'editable' ) != -1 )
				replaceDiv( element );
		}

		var editor;

		function replaceDiv( div ) {
			if ( editor )
				editor.destroy();

			editor = CKEDITOR.replace( div );
		}

	</script>
	
</head>
";

echo "
	<body>
		<div class='container'>
";


?>