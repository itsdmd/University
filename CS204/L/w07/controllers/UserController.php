<?php

class UserController extends Controller {


    public function __construct() {

        parent::__construct();
    }

    public function getLogin() {
        include "views/login.php";
    }

    public function login() {
        echo "<br>logging in user<br>";
        var_dump($this->req);
    }

    public function createUser() {
        echo "<br>creating user<br>";
        var_dump($this->req);
    }
}
