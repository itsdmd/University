<?php
include "func/secrets.php";

$sconn = new mysqli($host, $user, $pw, $db);

if ($sconn->connect_error) {
    die("Connection failed: " . $sconn->connect_error);
} else {
    // echo "Connected successfully";
}
?>

<pre>
    <?php
    print_r($sconn);
    ?>
</pre>