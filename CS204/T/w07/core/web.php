<?php
$conn = "";

Router::get("", function () {
    $home = new Home();
    $home->index();
});

Router::get("login", function () {
    $user = new User();
    $user->getLogin();
});

Router::post("login", function () {
    $user = new User();
    $user->login();
});

Router::get("contact", function () {
    include "views/contact.php";
});

if (Router::$found === false) {
    include "views/_404.php";
}
