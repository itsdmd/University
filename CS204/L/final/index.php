<?php
include "core/DB.php";
include "core/University.php";

define("ROOT", substr($_SERVER['PHP_SELF'], 0, -9));
DB::createInstance();
DB::connect();

foreach (glob("controllers/*.php") as $filename) {
    include $filename;
}

session_start();
// if (!isset($_SESSION['username'])) {
// session_destroy();
// }

include "core/Router.php";
include "core/web.php";

echo "<h3>GET</h3>";
echo "<pre>", var_dump($_GET), "</pre>";
echo "<h3>POST</h3>";
echo "<pre>", var_dump($_POST), "</pre>";
echo "<h3>SESSION</h3>";
echo "<pre>", var_dump($_SESSION), "</pre>";
echo "<h3>FILES</h3>";
echo "<pre>", var_dump($_FILES), "</pre>";
