<?php
$conn = "";

Router::get("", function () {
    include "views/home.php";
});

Router::get("university.php", function () {
    include "views/uni.php";
});

if (Router::$found === false) {
    // include "views/_404.php";
}
