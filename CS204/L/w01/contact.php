<?php
include "includes/header.php";
?>
<div class="container map">
    <!-- embed a map -->
    <iframe src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d45043.33882836775!2d106.668790643217!3d10.757858508323014!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x31752f1c06f4e1dd%3A0x43900f1d4539a3d!2sUniversity%20of%20Science%20-%20VNUHCM!5e0!3m2!1sen!2s!4v1682406249617!5m2!1sen!2s" width="100%" height="350" style="border:0;" allowfullscreen="" loading="lazy" referrerpolicy="no-referrer-when-downgrade"></iframe>
</div>
<main>
    <div class="container mt-4 mb-4">
        <hr class="mt-4 mb-4">
        <div class="row">
            <div class="col-md-6">
                <!-- company img -->
                <img src="https://phys.hcmus.edu.vn/uploads/khoa-vat-ly/Trang%20ch%E1%BB%A7/Gi%E1%BB%9Bi%20thi%E1%BB%87u%20khoa/bn2%20(1)-min.png" alt="" style="object-fit:cover;width:100%; height:100%;">
            </div>
            <div class="col-md-6">
                <!-- contact form -->
                <h2>Contact Us</h2>
                <form action="contact.php" method="post">
                    <div class="form-group">
                        <label for="name">Name</label>
                        <input id="name" class="form-control" type="text" name="name" placeholder="Your name...">
                    </div>
                    <div class="form-group">
                        <label for="email">Email</label>
                        <input id="email" class="form-control" type="email" name="email" placeholder="Your email...">
                    </div>
                    <div class="form-group">
                        <label for="reason">Reason for Contact</label>
                        <select name="reason" id="">
                            <option value="complain">Complaint</option>
                            <option value="feedback">Feedback</option>
                            <option value="praise">Praise</option>
                        </select>
                    </div>
                    <div class="form-group">
                        <label for="message">Message</label>
                        <textarea name="message" id="" class="form-control" rows="10"></textarea>
                    </div>
                    <button type="submit" class="btn btn-outline-primary btn-block btn-lg">Submit
                        Feedback</button>
                </form>

            </div>
        </div>
    </div>

</main>
<div class="container">
    <?php

    $form_received = false;
    $form_errors = [];

    if (isset($_POST['name'])) {
        $form_received = true;
        if (!filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)) {
            $error = "Invalid email";
            array_push($form_errors, $error);
        }
    }

    if (!empty($form_errors)) {
        var_dump($form_errors);
    }

    ?>

    <?php if ($form_received == true && empty($form_errors)) : ?>
        <div class="alert alert-success" role="alert">
            Form success, received!
        </div>
    <?php elseif ($form_received == true && empty($form_errors) == false) : ?>
        <div class="alert alert-danger" role="alert">
            Form error!
        </div>
    <?php endif; ?>


</div>

<?php
include "includes/footer.php";
?>