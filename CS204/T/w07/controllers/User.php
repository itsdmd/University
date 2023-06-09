<?php

class User extends Controller {
    public function __construct() {
        parent::__construct();
    }

    public function getLogin() {
        include "views/login.php";
    }

    public function login() {
        echo "<br>Logging in...</br>";
        echo "<pre>", var_dump($this->req), "</pre>";
    }

    public function createUser() {
        echo "<br>Creating user...</br>";
        echo "<pre>", var_dump($this->req), "</pre>";
    }
}
