<?php

class Comment {
    public $conn;
    public $text;
    public $post_id;
    public $user_id;
    public $comments = [];

    public function __construct($conn) {
        $this->conn = $conn;
        $this->user_id = 1;
    }

    public function getComments($post_id) {
        $this->post_id = $post_id;
        $sql = "SELECT * FROM comments WHERE post_id = ?";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("s", $this->post_id);
        $stmt->execute();
        $stmt = $stmt->get_result();
        $this->comments = $stmt->fetch_all(MYSQLI_ASSOC);
        return $this->comments;
    }
}