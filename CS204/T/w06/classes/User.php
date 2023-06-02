<?php

class User {
    public $conn;
    public $user_id;
    public $user_name;
    public $user_role;
    private $password;
    protected $user;
    protected $users;

    public function __construct($conn) {
        $this->conn = $conn;
        $this->getAllUsers();
        if(empty($this->users)) {

        }
    }

    public function checkLogin($user) {
        $this->user_name = $user['user_name'];
        $this->password = $user['password'];
    }
    public function getUserByName() {
        $sql = "SELECT * FROM users WHERE user_name = ?";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("s", $this->user_name);
        $stmt->execute();
        $result = $stmt->get_result();
        $this->user = $result->fetch_assoc();
    }

    public function getAllUsers() {
        $sql = "SELECT * FROM user";
        $stmt = $this->conn->prepare($sql);
        $stmt->execute();
        $result = $stmt->get_result();
        $this->users = $result->fetch_all(MYSQLI_ASSOC);
    }

    public function createUser() {
        $sql = "INSERT INTO user(user_name, user_role, user_password) VALUES(?,?,?)";
        $stmt = $this->conn->prepare($sql);
        $stmt->execute();
        $result = $stmt->get_result();
        $this->users = $result->fetch_all(MYSQLI_ASSOC);
    }
}