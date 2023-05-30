<?php
// Create a simple contact page in "contact.php". Embed a google map and create a contact form with the following fields: name, email, textarea. Have a button in the form that is name="submit". If the $_POST['submit'] is set var_dump the form values (don't need to save)

include "includes/header.php";
include "includes/jumbo.php";
?>

<div class="container md-6">
    <form method="post" action="contact.php">
        <div class="mb-3">
            <label for="name" class="form-label">Name:</label>
            <input type="text" class="form-control" id="name" name="name" required>
        </div>
        <div class="mb-3">
            <label for="email" class="form-label">Email:</label>
            <input type="email" class="form-control" id="email" name="email" required>
        </div>
        <div class="mb-3">
            <label for="message" class="form-label">Message:</label>
            <textarea class="form-control" id="message" name="message" rows="5" required></textarea>
        </div>
        <button type="submit" class="btn btn-primary" name="submit">Submit</button>
    </form>
</div>

<?php
if (isset($_POST['submit'])) {
    var_dump($_POST['name']);
    var_dump($_POST['email']);
    var_dump($_POST['message']);
}

$_POST = array();

include "includes/footer.php";
?>