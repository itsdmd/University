<?php

function postVerify($post) {
    $errors = [];

    if (empty($post['title'])) {
        $errors['title'] = "Title is required.";
    }

    if (empty($post['body'])) {
        $errors['body'] = "Body is required.";
    }

    if (count(imgValidate($_FILES['blog_img']))) {
        $errors['image'] = "Image is invalid.";
    }

    return $errors;
}

function imgValidate($img) {
    $errors = [];

    // check if file was uploaded
    if (!is_uploaded_file($img['tmp_name'])) {
        $errors["uploaded"] = "File was not uploaded";
    }

    // check if file is an image
    $img_info = getimagesize($img['tmp_name']);
    if (!$img_info) {
        $errors["img_info"] = "File is not an image";
    }

    // check if file is too large
    if ($img['size'] > 10000000) {
        $errors["size"] = "File is too large (Max: 10MB)";
    }

    // check if file is the correct type
    $allowed_types = ['image/jpeg', 'image/png', 'image/gif'];
    if (!in_array($img['type'], $allowed_types)) {
        $errors["type"] = "File is not a valid type";
    }

    return $errors;
}

function imgDisplay($file, $name = "tmp_name") {
    include "func/img_validate.php";
    $errors = imgValidate($file);

    if (count($errors) > 0) {
        print_r($errors);
    } else {
        $img = file_get_contents($file[$name]);
        echo "<img src='data:image/jpeg;base64," . base64_encode($img) . "' />";
    }
}

function upload_save($file, $target_file = "uploads/" . $file['name']) {
    if (!is_dir("uploads")) {
        mkdir("uploads");
        echo ("Created uploads directory.");
    }

    try {
        if (move_uploaded_file($file["tmp_name"], $target_file)) {
            echo ("The file " . basename($file["name"]) . " has been uploaded to " . $target_file);
            return true;
        } else {
            echo ("Error uploading file.");
            return false;
        }
    } catch (Exception $e) {
        echo ("Error uploading file.");
        return false;
    }
}
