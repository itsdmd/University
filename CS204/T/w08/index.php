<?php
define("ROOT", substr($_SERVER['PHP_SELF'], 0, -9));
include "core/DB.php";
DB::createInstance();
DB::connect();
include "controllers/Controller.php";
include "controllers/HomeController.php";
include "controllers/UserController.php";
include "controllers/PostController.php";
include "models/Post.php";
include "models/User.php";

include "core/Router.php";
include "core/web.php";
