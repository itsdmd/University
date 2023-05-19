<?php

function add_student($conn) {
    // Get the values from the form
    $studentName = $_POST['student_name'];
    $gender = $_POST['gender'];

    // Prepare the SQL statement with placeholders
    $stmt = $conn->prepare("INSERT INTO students (s_name, gender, date_created) VALUES (?, ?, default)");

    // Bind the parameters to the statement
    $stmt->bind_param("ss", $studentName, $gender);

    // Execute the prepared statement
    if ($stmt->execute()) {
        echo "Student created successfully.";
    } else {
        echo "Error: " . $stmt->error;
    }

    // Close the statement
    $stmt->close();
}

function add_teacher($conn) {
    // Get the values from the form
    $teacherName = $_POST['teacher_name'];
    $gender = $_POST['gender'];

    // Prepare the SQL statement with placeholders
    $stmt = $conn->prepare("INSERT INTO teachers (t_name, gender, date_created) VALUES (?, ?, default)");

    // Bind the parameters to the statement
    $stmt->bind_param("ss", $teacherName, $gender);

    // Execute the prepared statement
    if ($stmt->execute()) {
        echo "Teacher created successfully.";
    } else {
        echo "Error: " . $stmt->error;
    }

    // Close the statement
    $stmt->close();
}

function add_class($conn) {
    // Get the values from the form
    $className = $_POST['class_name'];

    // Prepare the SQL statement with placeholders
    $stmt = $conn->prepare("INSERT INTO classes (c_name, t_id, date_created) VALUES (?, ?, default)");

    // Bind the parameters to the statement
    $stmt->bind_param("si", $className);

    // Execute the prepared statement
    if ($stmt->execute()) {
        echo "Class created successfully.";
    } else {
        echo "Error: " . $stmt->error;
    }

    // Close the statement
    $stmt->close();
}

function add_enrollment($conn) {
    // Get the values from the form
    $classId = $_POST['class_id'];
    $teacherId = $_POST['teacher_id'];
    $studentId = $_POST['student_id'];

    // Prepare the SQL statement with placeholders
    $stmt = $conn->prepare("INSERT INTO enrollment (c_id, t_id, s_id, date_created) VALUES (?, ?, ?, default)");

    // Bind the parameters to the statement
    $stmt->bind_param("iii", $classId, $teacherId, $studentId);

    // Execute the prepared statement
    if ($stmt->execute()) {
        echo "Enrollment created successfully.";
    } else {
        echo "Error: " . $stmt->error;
    }

    // Close the statement
    $stmt->close();
}
