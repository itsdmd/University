<?php
include "includes/header.php";
include "includes/jumbo.php";

include "functions/card.php";
$query_str = "SELECT memes.*, users.user_name AS author
    FROM memes
    JOIN users
    ON memes.author = users.id";
echo generateCardsFromQuery($query_str);
?>

<?php
include "includes/footer.php";
?>