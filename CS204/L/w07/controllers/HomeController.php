<?php

class HomeController extends Controller {
    // properties


    public function __construct() {
        echo "child class instantiated";
        parent::__construct();
    }

    public function index() {
        include "views/home.php";
    }

}