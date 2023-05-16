<?php
include "secrets.php";

$conn = new mysqli($host, $user, $password, $db);
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

include "query.php";

$statement = $conn->prepare($sql);
$statement->execute();
$results = $statement->get_result();
?>

<pre>
    <?php
    print_r($results->fetch_all(MYSQLI_ASSOC));
    ?>
</pre>