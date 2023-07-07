<?php

define("ROOT", substr($_SERVER['PHP_SELF'], 0, -9));

include "core/DB.php";
DB::createInstance();
DB::connect();

foreach (glob("models/*.php") as $filename) {
    include $filename;
}

include "controllers/Controller.php";
foreach (glob("controllers/*.php") as $filename) {
    if ($filename != "controllers/Controller.php") {
        include $filename;
    }
}


session_start();
// if (!isset($_SESSION['logged_in'])) {
//     $_SESSION['logged_in'] = false;
// }

include "core/Router.php";
include "core/web.php";

// echo "<h3>GET</h3>";
// echo "<pre>", var_dump($_GET), "</pre>";
// echo "<h3>POST</h3>";
// echo "<pre>", var_dump($_POST), "</pre>";
// echo "<h3>SESSION</h3>";
// echo "<pre>", var_dump($_SESSION), "</pre>";
// echo "<h3>FILES</h3>";
// echo "<pre>", var_dump($_FILES), "</pre>";