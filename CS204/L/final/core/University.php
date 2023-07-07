<?php

class University {
    protected $conn;

    public function __construct() {
        $this->conn = DB::getConn();
    }

    public function getAllUniversities() {
        $sql = "SELECT * FROM universities";
        $stmt = $this->conn->prepare($sql);
        $stmt->execute();

        return $stmt->get_result()->fetch_all(MYSQLI_ASSOC);
    }

    public function getUniversityById($id) {
        $sql = "SELECT * FROM universities WHERE id = ?";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("i", $id);
        $stmt->execute();

        return $stmt->get_result()->fetch_assoc();
    }

    public function printUniversities($ids) {
        include "views/includes/uniCard.php";

        $universities = array();

        foreach ($ids as $id) {
            $universities[] = $this->getUniversityById($id);
        }

        foreach ($universities as $uni) {
            generateCard($uni['id'], $uni['uni_name'], $uni['uni_students'], $uni['uni_location'], $uni['uni_summary'], $uni['uni_img']);
        }
    }
}
