<?php

class Controller {
    public $conn;
    public $req;
    public $params;
    public $files;

    public function __construct() {

        $this->req = $_POST;
        $this->params = $_GET;
        $this->files = $_FILES;
        echo "Parent Conroller class instantiated.";
    }
}