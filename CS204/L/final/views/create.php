<?php include "views/includes/header.php"; ?>

<div class="jumbotron jumbotron-fluid">
    <div class="container">
        <h1 class="display-4">Create a new University</h1>
        <hr class="my-4">
        <form method="post" action="create" enctype="multipart/form-data">
            <div class="form-group">
                <label for="title">University Name</label>
                <input id="uni_name" class="form-control" type="text" name="uni_name" placeholder="Name of your university...">
            </div>
            <div class="form-group">
                <label for="body">University Summary</label>
                <textarea id="uni_summary" class="form-control" name="uni_summary" rows="5"></textarea>
            </div>
            <div class="form-group">
                <label for="location">University Location</label>
                <input id="uni_location" class="form-control" type="text" name="uni_location" placeholder="Location of your university...">
            </div>
            <div class="form-group">
                <label for="count">University Student Count</label>
                <input id="uni_students" class="form-control" type="number" name="uni_students" placeholder="Number of students in your university...">
            </div>
            <div class="form-group">
                <label for="meme_img">University Image</label>
                <input id="uni_img" class="form-control" type="file" name="file">
            </div>
            <button type="submit" name="create" id="" class="btn btn-primary btn-lg btn-block">
                <i class="fas fa-plus-circle"></i> Create University
            </button>
        </form>
    </div>
</div>

<?php include "views/includes/footer.php"; ?>