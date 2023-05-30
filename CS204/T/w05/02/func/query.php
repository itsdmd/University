<?php
function query($query, $bind_type = "", $bind_val = [""], $conn = null) {
    if ($conn == null) {
        include "func/db.php";
        $conn = $sconn;
    }

    $stmt = $conn->prepare($query);

    if ($bind_type && $bind_val) {
        $stmt = $mysqli->prepare($query);
        $stmt->execute($bind_val);
    } else {
        $stmt->execute();
    }

    $results = $stmt->get_result();
    return $results->fetch_all(MYSQLI_ASSOC);
}

function insert($query, $bind_val = [""], $conn = null) {
    if ($conn == null) {
        include "func/db.php";
        $conn = $sconn;
    }

    $stmt = $conn->prepare($query);
    $stmt->execute($bind_val);
}
