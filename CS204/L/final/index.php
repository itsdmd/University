<?php
session_start();
if (!isset($_SESSION['logged_in'])) {
    $_SESSION['logged_in'] = false;
}

include "core/DB.php";
include "core/University.php";

define("ROOT", substr($_SERVER['PHP_SELF'], 0, -9));
DB::createInstance();
DB::connect();

include "core/Router.php";
include "core/web.php";
