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

    public function addUniversity() {
        $uni_name = $_POST['uni_name'];
        $uni_students = $_POST['uni_students'];
        $uni_location = $_POST['uni_location'];
        $uni_summary = $_POST['uni_summary'];
        $uni_img = $_POST['uni_img'];

        $sql = "INSERT INTO universities (uni_name, uni_students, uni_location, uni_summary, uni_img) VALUES (?, ?, ?, ?, ?)";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("sssss", $uni_name, $uni_students, $uni_location, $uni_summary, $uni_img);
        $stmt->execute();

        header("Location: " . ROOT . "home");
    }

    public function deleteUniversity($id) {
        $sql = "DELETE FROM universities WHERE id = ?";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("i", $id);
        $stmt->execute();
    }
}
