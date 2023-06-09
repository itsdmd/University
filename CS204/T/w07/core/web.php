<?php
$conn = "";

Router::get("", function () {
    $home = new Home();
    $home->index();
});

Router::get("login", function () {
    include "views/login.php";
});

Router::get("contact", function () {
    include "views/contact.php";
});

if (Router::$found === false) {
    include "views/_404.php";
}
