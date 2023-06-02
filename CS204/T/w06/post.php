<?php 
include "inc/header.php";
$post = [];
if(isset($_GET['id'])) {
    include "functions/db.php";
    include "functions/blog_handler.php";
    $post = getPost($_GET['id']);
    var_dump($post);
}
?>

<div class="jumbotron">
    <div class="container">
    <?php if(!empty($post)): ?>
    <img src="<?php echo $post['img_url'];?>" width="100%" alt="">
    <h1 class="display-4"><?php echo $post['title']; ?></h1>
    <p class="lead"><?php $post['date_created'];?></p>
    <hr class="my-4">
    <p><?php echo $post['body'] ?></p>
    <?php else: ?>
        <h1 class="display-4">No post found!</h1>  
    <?php endif;?>
    </div>
</div>

<?php
include "inc/footer.php"
?>