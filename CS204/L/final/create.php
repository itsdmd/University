<div class="jumbotron jumbotron-fluid">
        <div class="container">
        <h1 class="display-4">Create a new University</h1>
        <hr class="my-4">
        <form method="post" action="create.php" enctype="multipart/form-data">
            <div class="form-group">
                <label for="title">University Title</label>
                <input id="title" class="form-control" type="text" name="title" placeholder="Title of your meme...">
            </div>
            <div class="form-group">
                <label for="body">University Body</label>
                <textarea id="body" class="form-control" name="body" rows=5></textarea>
            </div>
            <div class="form-group">
                <label for="body">University Location</label>
                <input id="location" class="form-control" type="text" name="location" placeholder="">            </div>
            <div class="form-group">
                <label for="body">University Student Count</label>
                <input id="count" class="form-control" type="number" name="count" placeholder="">            </div>
            <div class="form-group">
                <label for="meme_img">meme Image</label>
                <input id="my-input" class="form-control" type="file" name="meme_img">
            </div>
            <button type="submit" name="create" id="" class="btn btn-primary btn-lg btn-block"><i class="fas fa-plus-circle"></i> Create University</button>
        </form>
        </div>
</div>