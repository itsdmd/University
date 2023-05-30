<?php
// In the meme.php file set up an if statement to see if the $_GET super global "id" is set. If it is, pass that value to a prepared statement that fetches that meme based on the memes.id column. Output the single meme any way you like. Make sure to include a "back" button that links back to the "index.php".

include "includes/header.php";
include "includes/jumbo.php";
?>

<a href="index.php" class="btn btn-primary">Back</a>

<?php
if (isset($_GET['id'])) {
    include "functions/query.php";

    $query_str = "SELECT memes.*, users.user_name AS author
        FROM memes
        JOIN users
        ON memes.author = users.id
        WHERE memes.id = " . $_GET['id'];

    $cards = query($query_str);

    if (count($cards) > 0) {
        include "functions/card.php";
        foreach ($cards as $card) {
            // var_dump($card);
            echo generateCard($card);
        }
    } else {
        echo "No meme found";
    }
} else {
    echo "No meme found";
}

// clear get
$_GET = array();
?>

<?php
include "includes/footer.php";
?>