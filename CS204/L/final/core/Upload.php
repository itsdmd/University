<?php

class Upload {
    public $conn;
    public $req;
    public $params;
    public $files;

    public function __construct() {
        $this->conn = DB::getConn();
        $this->req = $_POST;
        $this->params = $_GET;
        $this->files = $_FILES;
    }

    public function uploadMedia($dest) {
        if (isset($_FILES["file"])) {
            $file = $_FILES["file"];
            $file_name = $file["name"];
            $file_tmp_name = $file["tmp_name"];
            $file_size = $file["size"];
            $file_error = $file["error"];

            $file_ext = explode(".", $file_name);
            $file_actual_ext = strtolower(end($file_ext));

            $allowed = array("jpg", "jpeg", "png");

            if (in_array($file_actual_ext, $allowed)) {
                if ($file_error === 0) {
                    if ($file_size < 1000000) {
                        $file_new_name = uniqid("", true) . "." . $file_actual_ext;
                        $file_destination = $dest . $file_new_name;
                        move_uploaded_file($file_tmp_name, $file_destination);

                        // $this->addNewUploadFileEntry($file_new_name, $_SESSION['username']);

                        // echo "File uploaded successfully!";
                        return $file_new_name;
                    } else {
                        echo "File is too big!";
                    }
                } else {
                    echo "There was an error uploading your file!";
                }
            } else {
                echo "You cannot upload files of this type!";
            }
        }

        return null;
    }

    public function addNewUploadFileEntry($path, $uploader) {
        $sql = "INSERT INTO media (path, uploader) VALUES (?, ?)";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("ss", $path, $uploader);
        $stmt->execute();

        if ($stmt->affected_rows === 1) {
            return $stmt->insert_id;
        }

        $stmt->close();
    }

    public function getFilePathById($id) {
        $sql = "SELECT path FROM media WHERE id = ?";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("i", $id);
        $stmt->execute();
        $result = $stmt->get_result()->fetch_assoc();

        if (!empty($result)) {
            return $result["path"];
        }

        $stmt->close();
    }

    public function getFileIdByPath($path) {
        $sql = "SELECT id FROM media WHERE path = ?";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("s", $path);
        $stmt->execute();
        $result = $stmt->get_result()->fetch_assoc();

        if (!empty($result)) {
            return $result["id"];
        }

        $stmt->close();
    }
}
