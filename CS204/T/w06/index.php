<?php
include "inc/header.php";
include "classes/Blog.php";

$blog = new Blog($conn);
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

  </div>
</div>
<!-- Button trigger modal -->
<button type="button" class="btn btn-primary" data-toggle="modal" data-target="#blogModal">
  Launch demo modal
</button>

<!-- Modal -->
<div class="modal fade" id="blogModal" tabindex="-1" role="dialog" aria-labelledby="blogModalLabel" aria-hidden="true">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
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
        <button type="button" class="btn btn-primary">Save
          changes</button>
      </div>
    </div>
  </div>
</div>
<?php
include "inc/footer.php";
?>