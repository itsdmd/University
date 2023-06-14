<?php


Router::get("hello", function() {
    echo "<h1>hello world<h1>";
});

Router::get("", function() {
    $home = new HomeController;

    $home->index();
    var_dump($home->req);
    var_dump($home->params);
});

Router::get("login", function() {
   $user = new UserController;
   $user->getLogin();
});

Router::post("create_user", function() {
    $user = new UserController;
    $user->createUser();
});

Router::get("contact", function() {
    include "views/contact.php";
});

Router::post("login", function() {
    $user = new UserController;
    $user->login();

});

Router::get("post/get/{id}", function($id) {
    $post = new PostController;
    $post->getPost($id);
});

Router::get("post/all", function() {
    $post = new PostController;
    $post->getAllPosts();
});

if(Router::$found === false) {
    include "views/_404.php";
}