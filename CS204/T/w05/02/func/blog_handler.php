<?php

function processNewPost($post, $img) {
    // get title and body from $post
    $title = $post['title'];
    $body = $post['body'];
    // get file details from $post_img
    $file_name = $img['name'];
    $file_ext = explode(".", $file_name);
    $file_ext = end($file_ext);
    $tmp = $img['tmp_name'];
    $file_size = $img['size'];
    $allowed_ext = ['png', 'jpg', 'jpeg', 'gif'];
    $file_error = $img['error'];

    // check for empty text fields
    if (empty($title) || empty($body)) {
        $errors['empty_text'] = "Text fields cannot be empty!";
    }

    // check for proper file extension
    if ($file_error == 0) {
        if (!in_array(strtolower($file_ext), $allowed_ext)) {
            $errors['file_ext'] = "Improper file extension!";
        }
        // check file size
        if ($file_size > 5000000) {
            $errors['file_size'] = "Files must be smaller than 5MB!";
        }
    } else {
        $errors['img_error'] = "There was a problem with the image!";
    }

    // if no errors, move file to dest and call insertBlog()
    if (empty($errors)) {
        if (!is_dir("uploads/")) {
            mkdir("uploads", 0777, true);
        }
        $new_file_name = random_int(100, 100000) . "_" . $file_name;
        $dest = "uploads/" . $new_file_name;
        move_uploaded_file($tmp, $dest);
        insertBlog($title, $body, $dest);
    } else {
        return $errors;
    }
}

function insertBlog($title, $body, $img) {
    include "func/query.php";

    $query = "INSERT INTO posts (id, title, body, img_url, post_author, tags, date_updated, date_created) VALUES (NULL, ?, ?, ?, NULL, NULL, NULL, CURRENT_TIMESTAMP)";
    $bind_val = [$title, $body, $img];

    return insert($query, $bind_val);
}
