<?php

class UserController extends Controller {


    public function __construct() {

        parent::__construct();
    }

    public function getLogin() {
        $user = new User($this->conn);
        $user->initAdmin();
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
