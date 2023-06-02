<?php
include "functions/secrets.php";

$conn = new mysqli($host, $user, $pw, $db);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} else {
    // echo "Connected successfully";
}
