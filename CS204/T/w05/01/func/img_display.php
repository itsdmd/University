<?php

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
