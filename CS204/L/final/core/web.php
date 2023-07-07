<?php
$conn = "";

Router::get("", function () {
    include "views/home.php";
});

Router::get("university", function () {
    include "views/uni.php";
});

Router::get("create", function () {
    include "views/create.php";
});

Router::get("login", function () {
    include "views/login.php";
});

Router::get("login", function () {
    $user = new UserCtrl();
    $user->viewLoginPage();
});

Router::post("login", function () {
    if (isset($_SESSION["role"]) && $_SESSION["role"] != "-1") {
        header("Location: " . ROOT);
        exit();
    }

    if (isset($_SESSION["status"])) {
        header("Location: " . ROOT . "login");
        exit();
    }

    $user = new UserCtrl();
    $user->userLogin();
});

Router::post("register", function () {
    $user = new UserCtrl();
    $_SESSION = array();
    $_SESSION["status"] = $user->userRegister();

    header("Location: " . ROOT . "login");
});

Router::get("logout", function () {
    session_destroy();
    header("Location: " . ROOT);
});

if (Router::$found === false) {
    // include "views/_404.php";
}
