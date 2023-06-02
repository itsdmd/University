<?php

class Blog {
    // properties
    public $id;
    public $conn;
    public $blog = [];
    public $blogs = [];
    public $errors = [];
    public $title;
    public $body;
    public $author;
    public $author_id;
    public $img;

    // constructor
    public function __construct($conn) {
        $this->conn = $conn;
    }

    public function getPost($id) {
        $this->id = $id;
        $sql = "SELECT * FROM posts WHERE id = ?";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("s", $this->id);
        $stmt->execute();
        $stmt = $stmt->get_result();
        $this->blog = $stmt->fetch_assoc();
        return $this->blog;
    }

    public function getPosts() {
        $sql = "SELECT * FROM posts";
        $stmt = $this->conn->prepare($sql);
        $stmt->execute();
        $stmt = $stmt->get_result();
        $this->blogs = $stmt->fetch_all(MYSQLI_ASSOC);
        return $this->blogs;
    }

    public function processNewPost($post, $post_img) {
        $this->title = $post['title'];
        $this->body = $post['body'];
        $this->img = $post_img['blog_img'];
        $errors = []; 
        // check title and body input fields
        if(empty($this->title) || empty($this->body)) {
            $errors['empty_text'] = "Text fields cannot be empty!";
        }
        // get file details
        $file_name = $this->img['name'];
        $file_ext = explode(".", $file_name);
        $file_ext = end($file_ext);
        $tmp = $this->img['tmp_name'];
        $file_size = $this->img['size'];
        $allowed_ext = ['png', 'jpg', 'jpeg', 'gif'];
        $file_error = $this->img['error'];
    
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
            $results['result'] = $this->insertBlog($dest);
            return $results;
         } else {
            return $errors;
         }
    
    }

    public function insertBlog($img) {
        $id = 1;
        $sql = "INSERT INTO posts (body, title, img_url, post_author) VALUES (?,?,?, ?);";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("ssss", $this->body, $this->title, $img, $id);
        $stmt->execute();
        var_dump($stmt);
        if($stmt->affected_rows == 1) {
            $new_id = $stmt->insert_id;
            header("Location: post.php?id=" . $new_id);
        } else {
            return "fail";
        }
    
    }
}