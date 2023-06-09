<?php
define("ROOT", substr($_SERVER['PHP_SELF'], 0, -9));

include "controllers/Controller.php";
include "controllers/Home.php";

include "core/Router.php";
include "core/web.php";

echo "<pre>", var_dump($_GET), "</pre>";
echo "<pre>", var_dump($_POST), "</pre>";
