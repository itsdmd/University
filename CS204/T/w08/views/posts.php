<?php include "views/includes/header.php";?>

<div class="container mt-5">
    <div class="row pt-5">
    <?php if(!empty($posts)): ?>
        <?php foreach ($posts as $post): ?>
       
            <div class="col-md-4">
                <div class="card">
                    <img class="card-img-top" src="<?php echo ROOT . "public/" . $post['img_url'];?>" alt="">
                    <div class="card-body">
                        <h5 class="card-title"><a href="<?php echo ROOT . "post/get/" . $post['id']?>"><?php echo $post['title'];?></a></h5>
                        <p class="card-text"><?php echo $post['body'];?></p>
                    </div>
                </div>
            </div>

        <?php endforeach;?>
    <?php endif;?>
    </div>
</div>
<?php include "views/includes/footer.php"; ?>