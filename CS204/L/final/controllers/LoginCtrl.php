<?php

class LoginCtrl extends Controller {
    public function __construct() {
        parent::__construct();
    }

    public function index() {
        include "views/login.php";
    }
}
