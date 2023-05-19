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
