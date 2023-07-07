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

    <?php if (isset($_SESSION["role"]) && $_SESSION["role"] == "1") : ?>
        <!-- delete button -->
        <div class="row mt-3">
            <div class="col-md-12">
                <a href="delete?id=<?= $uni['id']; ?>" class="btn btn-danger">Delete</a>
            </div>
        </div>

        <!-- edit button -->
        <div class="row mt-3">
            <div class="col-md-12">
                <a href="edit?id=<?= $uni['id']; ?>" class="btn btn-primary">Edit</a>
            </div>
        </div>
    <?php endif; ?>
</div>

<?php include "includes/footer.php"; ?>