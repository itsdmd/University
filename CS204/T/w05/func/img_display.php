<?php

function displayImg($post_field, $name = "tmp_name") {
    include "func/img_validate.php";
    $errors = validateImg($_FILES[$post_field]);

    if (count($errors) > 0) {
        print_r($errors);
    } else {
        $img = file_get_contents($_FILES[$post_field][$name]);
        echo "<img src='data:image/jpeg;base64," . base64_encode($img) . "' />";
    }
}
