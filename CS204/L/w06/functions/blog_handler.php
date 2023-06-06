<?php

function processNewPost($post, $post_img) {
    $title = $post['title'];
    $body = $post['body'];
    $img = $post_img['blog_img'];
    $errors = []; 
    // check title and body input fields
    if(empty($title) || empty($body)) {
        $errors['empty_text'] = "Text fields cannot be empty!";
    }
    // get file details
    $file_name = $img['name'];
    $file_ext = explode(".", $file_name);
    $file_ext = end($file_ext);
    $tmp = $img['tmp_name'];
    $file_size = $img['size'];
    $allowed_ext = ['png', 'jpg', 'jpeg', 'gif'];
    $file_error = $img['error'];

    if($file_error == 0) {
        if(!in_array(strtolower($file_ext), $allowed_ext)) {
            $errors['file_ext'] = "Improper file extension!";
        }
        if($file_size > 5000000) {
            $errors['file_size'] = "Files must be smaller than 5mb!";
        }

    } else {
        $errors['img_error'] = "There was a problem with the image!";
    }

    if(empty($errors)) {
        // move file to dest
        if(!is_dir("images/")) {
            mkdir("images", 0777, true);
        }
        $new_file_name = random_int(100,100000) . "_itec_" . $file_name;
        $dest = "images/" . $new_file_name;
        move_uploaded_file($tmp, $dest);
        // call insertBlog() fn, pass the title, body and img_url
        $results = [];
        $results['result'] = insertBlog($title, $body, $dest);
        return $results;
     } else {
        return $errors;
     }

}

function insertBlog($title, $body, $img) {
    global $conn;
    $id = "1";
    $sql = "INSERT INTO posts (id, body, title, img_url, post_author, tags, date_updated, date_created) VALUES (NULL,?,?,?,?, NULL, NULL, CURRENT_TIMESTAMP);";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("ssss", $body, $title, $img, $id);
    $stmt->execute();
    if($stmt->affected_rows == 1) {
        $new_id = $stmt->insert_id;
        header("Location: post.php?id=" . $new_id);
    } else {
        return "fail";
    }

}

function getPost($id) {
    global $conn;
    $sql = "SELECT * FROM posts WHERE id = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("s", $id);
    $stmt->execute();
    $stmt = $stmt->get_result();
    $result = $stmt->fetch_assoc();
    return $result;
}