<?php

class User {
    public $conn;
    public $errors = [];
    public $user = [];
    public $users = [];

    public $user_name;
    public $user_email;
    public $user_password;
    public $user_role;

    public function __construct($conn) {
        $this->conn = $conn;
    }

    public function createNewUser() {
        $sql = "INSERT INTO user (user_name, user_email, user_password, user_role) VALUES (?, ?, ?, ?)";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("ssss", $this->user_name, $this->user_email, $this->user_password, $this->user_role);
        $stmt->execute();

        if ($stmt->affected_row === 1) {
            header("Location: " . ROOT);
        }

        $stmt->close();
    }

    public function initAdmin() {
        $sql = "SELECT * FROM user WHERE user_name = 'admin'";
        $stmt = $this->conn->prepare($sql);
        $stmt->execute();
        $result = $stmt->get_result();
        if ($result->num_rows === 0) {
            // $sql = "INSERT INTO users (user_name, email, password, role) VALUES ('admin', 'admin@admin', 'admin', 'admin')";
            $this->user_name = "admin";
            $this->user_email = "admin@gmail.com";
            $this->user_password = password_hash("itec2023", PASSWORD_DEFAULT);
            $this->user_role = "1";
            $this->createNewUser();
        }
    }
}
