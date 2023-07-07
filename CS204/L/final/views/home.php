<?php include "includes/header.php"; ?>

<div class="jumbotron mt-4 " style="background:url(images/bg.jpg); background-size:cover; height:400px">

    <div class="container pt-5 mt-4">
        <h1 class="display-4"><i class="fas fa-exclamation-circle    "></i>
            Login to add a University</h1>
        <a href="login.php"><button class="btn btn-lg btn-primary
    "><i class="fas fa-door-open"></i> Login</button></a>

    </div>
</div>
<div class="container">
    <div class="row">

        <div class="col-md-9">
            <div class="row">
                <?php
                $uni = new University();
                $allUniIds = array_column($uni->getAllUniversities(), "id");

                $uni->printUniversities($allUniIds);
                ?>
            </div>

        </div>
        <div class="col-md-3">
            <img src="images/vn.png" width="100%" alt="">
        </div>
    </div>
</div>

<?php include "includes/footer.php"; ?>