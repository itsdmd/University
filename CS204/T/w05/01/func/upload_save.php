<?php

function upload_save($file, $target_file = "uploads/" . $file['name']) {
    if (!is_dir("uploads")) {
        mkdir("uploads");
        echo ("Created uploads directory.");
    }

    try {
        if (move_uploaded_file($file["tmp_name"], $target_file)) {
            echo ("The file " . basename($file["name"]) . " has been uploaded to " . $target_file);
            return true;
        } else {
            echo ("Error uploading file.");
            return false;
        }
    } catch (Exception $e) {
        echo ("Error uploading file.");
        return false;
    }
}
