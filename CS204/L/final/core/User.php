<?php

class User {
    // Status codes:
    // -10: username does not exist
    // -11: username already exist
    // -12: username invalid
    // -20: incorrect password
    // -21: password not matched
    // -22: password invalid


    public $errors = [];
    public $user = [];

    public $username;
    public $password;
    public $role;
    public $avatar_id;

    public $conn;
    public $req;

    public function __construct() {
        $this->conn = DB::getConn();
        $this->req = $_POST;
    }

    public function viewLoginPage() {
        include "views/login.php";
    }

    public function getAllUsers() {

        return $this->getAllUsers();
    }

    public function userExists() {
        $sql = "SELECT * FROM users WHERE username = ?";
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

    public function userLogin() {
        $this->username = $this->req["login-username"];

        if (isset($_SESSION["status"])) {
            self::viewLoginPage();
            return;
        } else if ($this->userExists()) {
            if (password_verify($this->req["login-pwd"], $this->password)) {
                $_SESSION = array();
                $_SESSION["username"] = $this->username;
                $_SESSION["role"] = $this->role;
                header("Location: " . ROOT . "profile");
            } else {
                // incorrect password
                $_SESSION = array();
                $_SESSION["status"] = "-20";
                header("Location: " . ROOT . "login");
            }
        } else {
            // username does not exist
            $_SESSION = array();
            $_SESSION["status"] = "-10";
            header("Location: " . ROOT . "login");
        }
    }

    public function userRegister() {
        $invalid_usernames = ["admin", "moderator", "superuser", "guest"];

        $this->username = $this->req["reg-username"];

        if ($this->userExists()) {
            // username already exists
            return "-11";
        } else if (in_array($this->req["reg-username"], $invalid_usernames)) {
            // username invalid
            return "-12";
        } else if ($this->req["reg-pwd"] !== $this->req["reg-pwd-confirm"]) {
            // password does not match
            return "-21";
        } else if (strlen($this->req["reg-pwd"]) < 3) {
            // password invalid
            return "-22";
        } else {
            $this->username = $this->req["reg-username"];
            $this->password = password_hash($this->req["reg-pwd"], PASSWORD_DEFAULT);
            $this->role = "1";


            $sql = "INSERT INTO users (username, password, role, date_created) VALUES (?, ?, ?, DEFAULT)";
            $stmt = $this->conn->prepare($sql);
            $stmt->bind_param("sss", $this->username, $this->password, $this->role);
            $stmt->execute();

            if ($stmt->affected_rows === 1) {
                header("Location: " . ROOT);
            }

            $stmt->close();

            return "1";
        }
    }
}
