<?php 
    include "inc/header.php";
    include "classes/Blog.php";
    include "functions/db.php";
    $blog = new Blog($conn);
    if(isset($_POST['title'])) {
        include "functions/db.php";
    
        include "functions/blog_handler.php";
    
        $result = $blog->processNewPost($_POST, $_FILES);
        var_dump($result);
    }
?>
    <div class="jumbotron jumbotron-fluid">
        <div class="container">
        <h1 class="display-4">Create a new post</h1>
        <hr class="my-4">
        <form method="post" action="create.php" enctype="multipart/form-data">
            <div class="form-group">
                <label for="title">Post Title</label>
                <input id="title" class="form-control" type="text" name="title" placeholder="Title of your post...">
            </div>
            <div class="form-group">
                <label for="body">Post Body</label>
                <textarea id="body" class="form-control" name="body" rows=5></textarea>
            </div>
            <div class="form-group">
                <label for="blog_img">Blog Image</label>
                <input id="my-input" class="form-control" type="file" name="blog_img">
            </div>
            <button type="submit" name="create" id="" class="btn btn-primary btn-lg btn-block"><i class="fas fa-plus-circle"></i> Create Post</button>
        </form>
        </div>
    </div>
<?php
    include "inc/footer.php";
?>