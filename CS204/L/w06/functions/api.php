<?php

include "../classes/Blog.php";
include "db.php";

if(isset($_POST['blog_id'])) {
    $blog = new Blog($conn);
    $result = $blog->getPost($_POST['blog_id']);
    echo json_encode($result);
}