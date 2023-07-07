<?php
$conn = "";

Router::get("", function () {
    include "views/home.php";
});

Router::get("university", function () {
    include "views/uni.php";
});

Router::get("create", function () {
    if (!isset($_SESSION["role"]) || $_SESSION["role"] != "1") {
        header("Location: " . ROOT . "university?id=" . $_GET["id"]);
        exit();
    }

    include "views/create.php";
});

Router::post("create", function () {
    if (isset($_FILES["file"])) {
        include "core/Upload.php";
        $upload = new Upload();
        $_POST["uni_img"] = "images/" . $upload->uploadMedia("images/");
    } else {
        $_POST["uni_img"] = "";
    }

    $uni = new University();
    $uni->addUniversity();

    header("Location: " . ROOT);
});

Router::get("edit", function () {
    if (!isset($_SESSION["role"]) || $_SESSION["role"] != "1") {
        header("Location: " . ROOT . "university?id=" . $_GET["id"]);
        exit();
    }

    include "views/edit.php";
});

Router::post("edit", function () {
    if (isset($_FILES["file"])) {
        include "core/Upload.php";
        $upload = new Upload();
        $_POST["uni_img"] = "images/" . $upload->uploadMedia("images/");
    } else {
        $_POST["uni_img"] = "";
    }

    $uni = new University();
    $uni->updateUniversity($_POST["id"]);

    header("Location: " . ROOT . "university?id=" . $_POST["id"]);
});

Router::get("delete", function () {
    if (!isset($_SESSION["role"]) || $_SESSION["role"] != "1") {
        header("Location: " . ROOT . "university?id=" . $_GET["id"]);
        exit();
    }

    $uni = new University();
    $uni->deleteUniversity($_GET["id"]);

    header("Location: " . ROOT);
});

Router::get("login", function () {
    include "views/login.php";
});

Router::get("login", function () {
    $user = new User();
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

    $user = new User();
    $user->userLogin();
});

Router::post("register", function () {
    $user = new User();
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
