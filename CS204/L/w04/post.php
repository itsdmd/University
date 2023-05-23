<?php
include "inc/header.php";

$posts = [];

if (isset($_GET["id"])) {
    include "func/query.php";
    $posts = getPosts($_GET["id"], 1);
} else {
    header("Location: index.php");
}
?>

<?php
include "func/footer.php";
?>