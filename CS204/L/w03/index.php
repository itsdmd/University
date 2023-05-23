<?php
include "secrets.php";

$conn = new mysqli($host, $user, $password, $db);
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$query_string = "";
$query_bind = "";

// if the author name is set in the form, use it in the query
if (isset($_POST['author'])) {
    $query_string = "SELECT post_title, display_name
        FROM wp_posts
        JOIN wp_users ON wp_users.ID = wp_posts.post_author
        WHERE post_type = 'post'
            AND display_name = ?
        LIMIT 20";
    $query_bind = $_POST['author'];
}
// else show all
else {
    $query_string = "SELECT post_title, display_name
        FROM wp_posts
        JOIN wp_users ON wp_users.ID = wp_posts.post_author
        WHERE post_type = 'post'
        LIMIT 20";
    $query_bind = "";
}

function query($conn, $query, $bind = "") {
    $statement = $conn->prepare($query);

    if ($bind) {
        $statement->bind_param("s", $bind);
    }

    $statement->execute();
    return $statement->get_result();
}

?>

<h1>Posts</h1>
<!-- form to search by author name -->
<form action="index.php" method="post">
    <input type="text" name="author" placeholder="Author name">
    <input type="submit" value="Search">
</form>

<ul>
    <?php
    $posts = query($conn, $query_string, $query_bind)->fetch_all(MYSQLI_ASSOC);

    foreach ($posts as $post) :
    ?>
        <li>
            <h2><?= $post['post_title'] ?></h2>
            <p>by <b><?= $post['display_name'] ?></b></p>
        </li>
    <?php endforeach; ?>
</ul>