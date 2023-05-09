<div class="jumbotron">
    <div class="row mt-4">
        <pre>
        <?php
        print_r($_POST);
        ?>
        </pre>
    </div>
</div>

<?php
if (isset($_POST["register"])) {
    $users = getUsers();

    if (!validateForm($users)) {
        echo "Form is invalid";
        return;
    }

    createUser($users);
    loginAsUser($_POST["reg-username"]);
} else if (isset($_POST["login"])) {
    $users = getUsers();

    if (checkUserLogin($users, $_POST["login-username"], $_POST["login-password"])) {
        loginAsUser($_POST["login-username"]);
    } else {
        echo "Invalid login";
    }
}

function validateForm($existing_users) {
    $errors = array();

    // check if username exists
    if (checkUsernameExists($existing_users, $_POST["reg-username"])) {
        $errors["username"] = "Username already exists";
    }

    // check password length
    if (strlen($_POST["reg-password"]) < 8) {
        $errors["password_length"] = "Password must be at least 8 characters long";
    }

    // check password match
    if ($_POST["reg-password"] != $_POST["reg-password-confirm"]) {
        $errors["password_confirm"] = "Passwords do not match";
    }

    if (count($errors) > 0) {
        return $errors;
    } else {
        return true;
    }
}

function loginAsUser($username) {
    $_SESSION["logged_in"] = true;
    $_SESSION["username"] = $username;
    header("Location: index.php");
}

function getUsers() {
    $json = file_get_contents("data/users.json");
    $users = json_decode($json, true);
    return $users;
}

function createUser($existing_users) {
    if (checkUsernameExists($existing_users, $_POST["reg-username"])) {
        echo "Username already exists";
        return false;
    }

    $f_handler = fopen("data/users.json", "w");
    if (!$f_handler) {
        echo "You do not have permission to write to this file";
        return false;
    }

    $new_user["username"] = htmlspecialchars($_POST["reg-username"]);
    $new_user["email"] = htmlspecialchars($_POST["reg-email"]);
    $new_user["password"] = password_hash(
        $_POST["reg-password"],
        PASSWORD_DEFAULT
    );

    array_push($existing_users, $new_user);


    $json = json_encode($existing_users, JSON_PRETTY_PRINT);

    file_put_contents("data/users.json", $json);
    return true;
}

function checkUsernameExists($existing_users, $username) {
    foreach ($existing_users as $user) {
        if ($user["username"] == $username) {
            return true;
        }
    }
    return false;
}

function checkUserLogin($existing_users, $username, $password) {
    foreach ($existing_users as $user) {
        if ($user["username"] == $username) {
            if (password_verify($password, $user["password"])) {
                return true;
            }
        }
    }
    return false;
}

?>