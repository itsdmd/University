<?php

function query($conn, $query, $bind = "") {
    $statement = $conn->prepare($query);

    if ($bind) {
        $statement->bind_param("s", $bind);
    }

    $statement->execute();
    return $statement->get_result();
}
