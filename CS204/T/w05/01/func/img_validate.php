<?php

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
