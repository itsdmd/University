<!doctype html>
<html lang="en">

<?php
include "secrets.php";
include "func/form_proc.php";
include "func/query.php";

if (isset($_POST['add_student'])) {
    add_student($sconn);
} else if (isset($_POST['add_teacher'])) {
    add_teacher($sconn);
} else if (isset($_POST['add_class'])) {
    add_class($sconn);
} else if (isset($_POST['add_enrollment'])) {
    add_enrollment($sconn);
} else {
    echo "No form submitted.";
}
?>

<head>
    <title>Week 04</title>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS v5.2.1 -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-iYQeCzEYFbKjA/T2uDLTpkwGzCiq6soy8tYaI1GyVh/UjpbCx/TYkiZhlZB6+fzT" crossorigin="anonymous">

</head>

<body>
    <div class="container">
        <div class="row">
            <!-- Add Student -->
            <div class="col-md-6">
                <div class="card">
                    <div class="card-body">
                        <h2>Add Student</h2>
                        <form action="index.php" method="POST">
                            <div class="form-group">
                                <label for="student_name">Student Name</label>
                                <input type="text" class="form-control" id="student_name" name="student_name" required>
                            </div>
                            <div class="form-group">
                                <label for="gender">Gender</label>
                                <select class="form-control" id="gender" name="gender" required>
                                    <option value="">Select Gender</option>
                                    <option value="m">Male</option>
                                    <option value="f">Female</option>
                                </select>
                            </div>
                            <button type="submit" class="btn btn-primary" name="add_student">Add Student</button>
                        </form>
                    </div>
                </div>
            </div>

            <!-- Add Teacher -->
            <div class="col-md-6">
                <div class="card">
                    <div class="card-body">
                        <h2>Add Teacher</h2>
                        <form action="index.php" method="POST">
                            <div class="form-group">
                                <label for="teacher_name">Teacher Name</label>
                                <input type="text" class="form-control" id="teacher_name" name="teacher_name" required>
                            </div>
                            <div class="form-group">
                                <label for="gender">Gender</label>
                                <select class="form-control" id="gender" name="gender" required>
                                    <option value="">Select Gender</option>
                                    <option value="m">Male</option>
                                    <option value="f">Female</option>
                                </select>
                            </div>
                            <button type="submit" class="btn btn-primary" name="add_teacher">Add Teacher</button>
                        </form>
                    </div>
                </div>
            </div>
        </div>
        <div class="row">
            <!-- Add Class -->
            <div class="col-md-6">
                <div class="card">
                    <div class="card-body">
                        <h2>Add Class</h2>
                        <form action="index.php" method="POST">
                            <div class="form-group">
                                <label for="class_name">Class Name</label>
                                <input type="text" class="form-control" id="class_name" name="class_name" required>
                            </div>
                            <button type="submit" class="btn btn-primary" name="add_class">Add Class</button>
                        </form>
                    </div>
                </div>
            </div>

            <!-- Add Enrollment -->
            <div class="col-md-6">
                <div class="card">
                    <div class="card-body">
                        Add Enrollment</h2>
                        <form action="index.php" method="POST">
                            <div class="form-group">
                                <label for="class_id">Class ID</label>
                                <input type="text" class="form-control" id="class_id" name="class_id" required>
                            </div>
                            <div class="form-group">
                                <label for="teacher_id">Teacher ID</label>
                                <input type="text" class="form-control" id="teacher_id" name="teacher_id" required>
                            </div>
                            <div class="form-group">
                                <label for="student_id">Student ID</label>
                                <input type="text" class="form-control" id="student_id" name="student_id" required>
                            </div>
                            <button type="submit" class="btn btn-primary" name="add_enrollment">Add Class</button>
                        </form>
                    </div>
                </div>
            </div>

        </div>
    </div>

    <!-- Bootstrap JavaScript Libraries -->
    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.6/dist/umd/popper.min.js" integrity="sha384-oBqDVmMz9ATKxIep9tiCxS/Z9fNfEXiDAYTujMAeBAsjFuCZSmKbSSUnQlmh/jp3" crossorigin="anonymous">
    </script>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/js/bootstrap.min.js" integrity="sha384-7VPbUDkoPSGFnVtYi0QogXtr74QeVeeIs99Qfg5YCF+TidwNdjvaKZX19NZ/e6oz" crossorigin="anonymous">
    </script>
</body>

</html>