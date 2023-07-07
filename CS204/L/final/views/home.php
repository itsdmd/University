<?php include "includes/header.php"; ?>

<div class="jumbotron">
    <div class="container pt-4">
        <h1 class="display-4"><i class="fas fa-exclamation-circle    "></i>
            Login to create a meme</h1>
        <a href="login.php"><button class="btn btn-lg btn-primary
    "><i class="fas fa-door-open    "></i> Login</button></a>

    </div>
</div>
<div class="container">
    <div class="row">
        <?php
        // $MemeCtrl = new MemeCtrl();
        // $posts = $MemeCtrl->getAllMemes();

        // foreach ($posts as $post) : ?>
        <!-- <div class="col-md-4 mt-3">
            <div class="card">
                <img class="card-img-top" src="<?= $post["meme_img"] ?>" alt="">
                <div class="card-body">
                    <a href="single_meme.php?id=<?= $post["id"] ?>">
                        <h5 class="card-title"><?= $post["meme_title"] ?></h5>
                    </a>
                    <p class="card-text"><?= $post["meme_text"] ?></p>
                </div>
            </div>
        </div> -->
        <?php // endforeach; ?>

    </div>
</div>

<?php include "includes/footer.php"; ?>