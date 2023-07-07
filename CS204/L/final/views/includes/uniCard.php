<?php function generateCard($id, $name, $students, $location, $desc, $img) { ?>
<div class="col-md-6 mt-3">
    <div class="card">
        <img class="card-img-top" src="<?= $img ?>" alt=""
            style="height:250px;object-fit:cover;">
        <div class="card-body">
            <a href="university.php?id=<?= $id ?>">
                <h5 class="card-title"><?= $name ?></h5>
            </a>
            <p class="card-text">
                <?= $desc ?>
            </p>
        </div>
        <div class="card-footer">
            <i class="fas fa-users"></i> Students :
            <?= $students ?>
            <i class="fas fa-map-marker"></i> Location :
            <?= $location ?>
        </div>
        <a href="university.php?id=<?= $id ?>">
            <button class="btn btn-primary btn-block"
                href="university.php?id=<?= $id ?>"> Learn
                more</button>
        </a>
    </div>
</div>
<?php } ?>