<?php
include "includes/header.php";

$university = new University();
$uni = $university->getUniversityById($_GET['id']);
?>

<div class="container mt-5">
    <div class="row">
        <div class="col-md-12">
            <div class="card">
                <img class="card-img-top" src="<?= $uni['uni_img']; ?>" alt="Meme image">
                <div class="card-body">
                    <h5 class="card-title"><?= $uni['uni_name']; ?></h5>
                    <p class="card-text"><?= $uni['uni_summary']; ?></p>
                </div>
            </div>
        </div>
    </div>
</div>

<?php include "includes/footer.php"; ?>