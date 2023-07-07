<?php

class UserCtrl extends Controller {
    // Status codes:
    // -10: username does not exist
    // -11: username already exist
    // -12: username invalid
    // -20: incorrect password
    // -21: password not matched
    // -22: password invalid

    public function __construct() {
        parent::__construct();
    }

    public function viewLoginPage() {
        include "views/login.php";
    }

    public function getAllUsers() {
        $user = new User($this->conn);
        return $user->getAllUsers();
    }

    public function deleteUser($username) {
        $user = new User($this->conn);
        $user->deleteUser($username);
    }

    public function userLogin() {
        $user = new User($this->conn);
        $user->username = $this->req["login-username"];

        if (isset($_SESSION["status"])) {
            self::viewLoginPage();
            return;
        } else if ($user->userExists()) {
            if (password_verify($this->req["login-pwd"], $user->password)) {
                $_SESSION = array();
                $_SESSION["username"] = $user->username;
                $_SESSION["role"] = $user->role;
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

        $user = new User($this->conn);
        $user->username = $this->req["reg-username"];

        if ($user->userExists()) {
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
            $user->username = $this->req["reg-username"];
            $user->password = password_hash($this->req["reg-pwd"], PASSWORD_DEFAULT);
            $user->role = "1";
            $user->createNewUser();

            return "1";
        }
    }
}
