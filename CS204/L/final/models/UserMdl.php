<?php

class User {
    public $errors = [];
    public $user = [];

    public $username;
    public $password;
    public $role;
    public $avatar_id;

    protected $conn;

    public function __construct($conn) {
        $this->conn = $conn;
    }

    public function userExists() {
        $sql = "SELECT * FROM user WHERE username = ?";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("s", $this->username);
        $stmt->execute();
        $result = $stmt->get_result()->fetch_assoc();

        if (!empty($result)) {
            $this->password = $result["password"];
            $this->role = $result["role"];
            // var_dump($this);
            return true;
        } else {
            return false;
        }
    }

    public function getAllUsers() {
        $sql = "SELECT * FROM user";
        $stmt = $this->conn->prepare($sql);
        $stmt->execute();
        $result = $stmt->get_result()->fetch_all(MYSQLI_ASSOC);

        return $result;
    }

    public function deleteUser($username) {
        $sql = "DELETE FROM user WHERE username = ?";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("s", $username);
        $stmt->execute();

        if ($stmt->affected_rows === 1) {
            header("Location: " . ROOT . "profile");
        }

        $stmt->close();
    }

    public function createNewUser() {
        $sql = "INSERT INTO user (username, password, role, avatar_id, date_created) VALUES (?, ?, ?, NULL, DEFAULT)";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("sss", $this->username, $this->password, $this->role);
        $stmt->execute();

        if ($stmt->affected_rows === 1) {
            header("Location: " . ROOT);
        }

        $stmt->close();
    }
}
