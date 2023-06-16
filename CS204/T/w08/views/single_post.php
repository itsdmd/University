<?php include "views/includes/header.php";?>

    <div class="jumbotron">
        <div class="container">
        <h1 class="display-4"><?php echo $post['title'];?></h1>
        <p class="lead"><?php echo $post['body'];?></p>
        <hr class="my-4">
        <p>return <a href="<?php echo ROOT; ?>">home</a></p>
        </div>
    </div>

<?php include "views/includes/footer.php"; ?>