<?php
$q1 = "SELECT post_title, display_name
    FROM wp_posts
    JOIN wp_users ON wp_users.ID = wp_posts.post_author
    WHERE post_type = 'post'
    LIMIT 20";
