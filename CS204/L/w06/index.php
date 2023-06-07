<?php 
    include "inc/header.php";
    include "classes/Blog.php";
    include "functions/db.php";
    $blog = new Blog($conn);
    $blogs = $blog->getPosts();

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
          <?php foreach ($blogs as $b):?>
            <div class="col-md-4">
              <div class="card">
                <img class="card-img-top" src="<?php echo $b['img_url']; ?>" alt="">
                <div class="card-body">
                  <a href="#" class="blog_title" data-id="<?php echo $b['id']; ?>"><h5 class="card-title"><?php echo $b['title'];?></h5></a>
                  <p class="card-text"><?php echo $b['body']; ?></p>
                </div>
              </div>
            </div>
          <?php endforeach;?>
        </div>
    </div>
    <!-- Button trigger modal -->
<button type="button" class="btn btn-primary modal_btn" data-toggle="modal" data-target="#blogModal">
  Launch demo modal
</button>

<!-- Modal -->
<div class="modal fade" id="blogModal" tabindex="-1" role="dialog" aria-labelledby="blogModalLabel" aria-hidden="true">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <img src="" class="modal-img" alt="" width="100%">
        <h5 class="modal-title" id="blogModalLabel">Modal title</h5>
        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
          <span aria-hidden="true">&times;</span>
        </button>
      </div>
      <div class="modal-body">
        ...
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-secondary" data-dismiss="modal">Close</button>
        <button type="button" class="btn btn-primary">Save changes</button>
      </div>
    </div>
  </div>
</div>
<script>
  let modalImg = document.querySelector(".modal-img");
  let modalTitle = document.querySelector(".modal-title");
  let modalBody = document.querySelector(".modal-body");
  let blogPosts = document.querySelector(".blog-posts");
  let modalBtn = document.querySelector(".modal_btn");
  blogPosts.addEventListener("click", (event) => {
    console.log(event.target);
    event.preventDefault();
    if(event.target.classList.contains("card-title")) {
      let anchor = event.target.closest("a");
      let id = anchor.getAttribute("data-id");
      console.log(id);

      fetch("functions/api.php", 
      {
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
        modalImg.setAttribute("src", data.img_url);
        modalBtn.click();
      })
    
    }
  });

</script>
<?php
    include "inc/footer.php";
?>