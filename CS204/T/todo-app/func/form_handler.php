<?php

if (isset($_POST['register'])) {
    var_dump($_POST);
    $errors = [];
    $users = getUsers();
    // check if username exists (should not)
    if (checkUserExists($users, $_POST["username"]) === true) {
        $errors['username'] = "This username is taken!";
    }
    // check username len
    if (strlen($_POST['username']) < 5) {
        $errors['username_len'] = "Username is too short!";
    }
    // validate email
    if (!filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)) {
        $errors['email'] = "Email is invalid!";
    }
    // check pw len
    if (strlen($_POST['password']) < 5) {
        $errors['password'] = "Password must be greater than 5 characters!";
    }
    // confirm pw
    if ($_POST['password'] != $_POST['confirm_password']) {
        $errors['password_confirm'] = "Passwords don't match!";
    }

    if (empty($errors)) {
        createUser($_POST, $users);
        loginUser($_POST);
    }
} else if (isset($_POST['login'])) {
    $errors = [];
    $users = getUsers();
    // get all users and check if user submitted username ==
    // to a username in the data/users.json (convert to assoc arr)
    if (checkUserExists($users, $_POST['username'])) {
        foreach ($users as $user) {
            if ($user['username'] == $_POST['username']) {
                if (!password_verify($_POST['password'], $user['password'])) {
                    $errors['password'] = 'Invalid password!';
                }
            }
        }
    } else {
        $errors['username'] = "User not found";
    }
    // check the user submitted password string against
    // the hash of the associated user

    // if no errors then login
    if (empty($errors)) {
        loginUser($_POST);
    }
}

function loginUser($user) {
    $_SESSION['logged_in'] = true;
    $_SESSION['username'] = $user['username'];
    $_SESSION['role'] = 2;
    header("Location: index.php");
}

function createUser($user, $users) {
    $new_user = [];
    $new_user['id'] = count($users) + 1;
    $new_user['username'] = htmlspecialchars($user['username']);
    $new_user['email'] = $user['email'];
    $new_user['password'] = password_hash($user['password'], PASSWORD_DEFAULT);
    $new_user['role'] = "2";
    array_push($users, $new_user);
    $json = json_encode($users, JSON_PRETTY_PRINT);
    file_put_contents("data/users.json", $json);
}

function checkUserExists($users, $username) {
    $arr = [];
    foreach ($users as $user) {
        if ($user['username'] == $username) {
            array_push($arr, $username);
        }
    }
    if (empty($arr)) {
        return false;
    } else {
        return true;
    }
}

function getUsers() {
    // get file contents
    $json = file_get_contents("data/users.json");
    // convert to assoc array
    $arr = json_decode($json, true);
    // return the arr
    return $arr;
}
