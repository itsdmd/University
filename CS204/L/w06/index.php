<?php
include "inc/header.php";
include "classes/Blog.php";
include "classes/Comment.php";
include "functions/db.php";
$blog = new Blog($conn);
$blogs = $blog->getPosts();
$comment = new Comment($conn);
$comments = $comment->getComments(6);

if (isset($_POST['comment'])) {
  var_dump($_POST);
}

?>
<div class="jumbotron jumbotron-fluid">
    <div class="container">
        <h1 class="display-4">Welcome to ITEC Blog</h1>
        <p class="lead">Login to create or edit a post</p>
        <hr class="my-4">
    </div>
</div>
<div class="container">
    <div class="row blog-posts">
        <?php foreach ($blogs as $b) : ?>
        <div class="col-md-4">
            <div class="card">
                <img class="card-img-top" src="<?php echo $b['img_url']; ?>"
                    alt="">
                <div class="card-body">
                    <a href="#" class="blog_title"
                        data-id="<?php echo $b['id']; ?>">
                        <h5 class="card-title"><?php echo $b['title']; ?></h5>
                    </a>
                    <p class="card-text"><?php echo $b['body']; ?></p>
                </div>
            </div>
        </div>
        <?php endforeach; ?>
    </div>
</div>
<!-- Button trigger modal -->
<button type="button" class="btn btn-primary modal_btn" data-toggle="modal"
    data-target="#blogModal">
    Launch demo modal
</button>

<!-- Modal -->
<div class="modal fade" id="blogModal" tabindex="-1" role="dialog"
    aria-labelledby="blogModalLabel" aria-hidden="true">
    <div class="modal-dialog modal-dialog-centered modal-lg" role="document">
        <div class="modal-content">
            <img src="" class="modal-img" alt="" width="100%" height="300px"
                style="object-fit:cover">
            <div class="modal-header d-flex justify-content-between">

                <h5 class="modal-title" data-id="" id="blogModalLabel">Modal
                    title</h5>
                <div class="thumbs d-flex ml-auto">

                </div>
                <!-- <button type="button" class="close" data-dismiss="modal" aria-label="Close">
          <span aria-hidden="true">&times;</span>
        </button> -->
            </div>
            <div class="modal-body">
                ...
            </div>
            <div class="modal-footer">
                <button type="button" class="btn btn-secondary"
                    data-dismiss="modal">Close</button>
                <button type="button" class="btn btn-primary">Save
                    changes</button>
            </div>
            <div class="container comments">
                <hr class="m-3">
                <h3>Comments</h3>
                <form action="index.php" method="post">
                    <textarea name="comment" class="form-control comment-text"
                        rows="2"></textarea>
                    <input type="hidden" name="post_id" value=""
                        class="comment_post_id">
                    <button type="submit" class="btn btn-primary mt-3 mb-3"
                        name="submit"><i class="fas fa-check-circle    "></i>
                        Submit</button>
                </form>
                <hr>
            </div>
        </div>
    </div>
</div> <!-- end of modal -->
<script>
let commentPostId = document.querySelector(".comment_post_id");
let modalImg = document.querySelector(".modal-img");
let modalTitle = document.querySelector(".modal-title");
let modalBody = document.querySelector(".modal-body");
let blogPosts = document.querySelector(".blog-posts");
let modalBtn = document.querySelector(".modal_btn");
blogPosts.addEventListener("click", (event) => {
    console.log(event.target);
    event.preventDefault();
    if (event.target.classList.contains("card-title")) {
        let anchor = event.target.closest("a");
        let id = anchor.getAttribute("data-id");
        console.log(id);

        fetch("functions/api.php", {
                method: "POST",
                headers: {
                    "Content-Type": "application/x-www-form-urlencoded"
                },
                body: "blog_id=" + id
            })
            .then(response => response.json())
            .then((data) => {
                //output blog to the page
                console.log(data);
                modalTitle.innerText = data.title;
                modalBody.innerText = data.body;
                commentPostId.setAttribute("value", data.id);
                modalImg.setAttribute("src", data.img_url);
                modalBtn.click();
            })

    }
});
</script>
<?php
include "inc/footer.php";
?>