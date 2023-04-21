<?php
include "includes/header.php";
?>

<div class="container mt-4 mb-4">
    <iframe
        src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d4718.144710051965!2d106.68259686675994!3d10.762517030618126!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x31752f194dae00e5%3A0x4b90c5d0bd96fe63!2sNOWZONE%20Fashion%20Mall!5e0!3m2!1sen!2s!4v1682066769071!5m2!1sen!2s"
        width="100%" height="450" style="border:0;" allowfullscreen=""
        loading="lazy" referrerpolicy="no-referrer-when-downgrade"></iframe>
</div>

<div class="container">
    <div class="row">
        <div class="col-md-6">
            <h2>Contact Us</h2>
            <form action="contact.php" method="post">
                <div class="form-group">
                    <label for="my-select">Your Gender</label>
                    <select id="my-select" class="form-control" name="gender">
                        <option value="male">Male</option>
                        <option value="female">Female</option>
                    </select>
                </div>
                <div class="form-group">
                    <label for="">Your Name</label>
                    <input type="text"
                        class="form-control mt-3 mb-3 form-control-sm"
                        name="name" id="" />
                </div>
                <button type="submit" class="btn btn-primary">Submit</button>
            </form>
        </div>
        <div class="col-md-6">
            <img src="https://img.freepik.com/free-vector/hand-painted-watercolor-pastel-sky-background_23-2148902771.jpg?w=2000"
                alt="" width="100%">
        </div>
    </div>
</div>

<?php
if (isset($_POST['name'])) {
    echo "<h2>Hello " . $_POST['name'] . "</h2>";
    echo "<pre>";
    print_r($_POST);
    echo "</pre>";
} else {
    echo "<h2>Nothing to show</h2>";
}
?>

<?php
include "includes/footer.php";
?>