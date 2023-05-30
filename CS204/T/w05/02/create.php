<?php
include "inc/header.php";

if (isset($_POST['title'])) {
    include "func/blog_handler.php";
    $errors = processNewPost($_POST, $_FILES['blog_img']);

    // print_r(insertBlog($_POST['title'], $_POST['body'], $_FILES['blog_img']['name'])->fetch_all(MYSQLI_ASSOC));

    // print_r($_POST);
    // print_r($_FILES);
}
?>
<div class="jumbotron jumbotron-fluid">
    <div class="container">
        <h1 class="display-4">Create a new post</h1>
        <hr class="my-4">
        <form action="create.php" method="post" enctype="multipart/form-data">
            <div class="form-group">
                <label for="title">Post title</label>
                <input type="text" class="form-control" id="title" name="title" placeholder="Enter post title">
            </div>
            <div class="form-group">
                <label for="body">Post content</label>
                <textarea name="body" id="body" class="form-control" cols="30" rows="5"></textarea>
            </div>
            <div class="form-group">
                <label for="blog_img">Post image</label>
                <input type="file" name="blog_img" id="blog_img" class="form-control">
            </div>
            <button type="submit" class="btn btn-primary">Submit</button>
        </form>
    </div>
</div>

<?php
include "inc/footer.php";
?>