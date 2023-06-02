<?php

class Blog {
    // properties
    public $id;
    public $conn;
    public $blog = [];
    public $blogs = [];
    public $errors = [];
    public $title;
    public $body;
    public $author;
    public $author_id;

    // constructor
    public function __construct($conn) {
        $this->conn = $conn;
    }

    public function getPosts() {
        $sql = "SELECT * FROM posts";
        $stmt = $this->conn->prepare($sql);
        $stmt->execute();
        $stmt = $stmt->get_result();
        $this->blogs = $stmt->fetch_all(MYSQLI_ASSOC);
        return $this->blogs;
    }
}
