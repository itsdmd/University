<?php
function query($query, $bind_type = "", $bind_val = "", $conn = null) {
    if ($conn == null) {
        include "db.php";
        $conn = $sconn;
    }

    $statement = $conn->prepare($query);

    if ($bind_type && $bind_val) {
        $statement->bind_param($bind_type, $bind_val);
    }

    $statement->execute();
    $results = $statement->get_result();
    return $results->fetch_all(MYSQLI_ASSOC);
}

function getPosts($id = null, $limit = 10) {
    // sql query
    $sql = "SELECT * 
        FROM wp_posts wp
        JOIN wp_users wu ON wu.ID = wp.post_author
        WHERE post_type = 'post'" .
        ($id ? " AND wp.ID = " . strval($id)
            : "") .
        " LIMIT " . strval($limit);

    return query($sql);
}
