<?php
include "func/init.php";
include "inc/header.php";
include "func/form_handler.php";
include "func/todos_handler.php";
?>

<div class="jumbotron mt-5 pt-5">
    <div class="row">
        <div class="col-md-6">
            <h2>
                <i class="fa fa-user-plus"></i> Register
            </h2>

            <!-- Registration form -->
            <form action="login.php" method="post">
                <div class="form-group">
                    <label for="username">Username</label>
                    <input type="text" class="form-control" id="username" placeholder="Enter username" name="reg-username">
                </div>
                <div class="form-group">
                    <label for="email">Email address</label>
                    <input type="email" class="form-control" id="email" placeholder="Enter email" name="reg-email">
                </div>
                <div class="form-group">
                    <label for="password">Password</label>
                    <input type="password" class="form-control" id="password" placeholder="Password" name="reg-password">
                </div>
                <div class="form-group">
                    <label for="confirm-password">Confirm Password</label>
                    <input type="password" class="form-control" id="confirm-password" placeholder="Confirm Password" name="reg-password-confirm">
                </div>
                <button type="submit" class="btn btn-lg btn-block btn-primary" name="register">Create account</button>
            </form>
        </div>
        <div class="col-md-6">
            <h2>
                <i class="fa fa-user"></i> Login
            </h2>
            <form action="login.php" method="post">
                <div class="form-group">
                    <label for="username">Username or Email</label>
                    <input type="text" class="form-control" id="username" placeholder="Enter username or email" name="login-username">
                </div>
                <div class="form-group">
                    <label for="password">Password</label>
                    <input type="password" class="form-control" id="password" placeholder="Password" name="login-password">
                </div>
                <button type="submit" class="btn btn-lg btn-block btn-primary" name="login">Login</button>
            </form>
        </div>
    </div>
</div>

<?php
include "inc/footer.php";
?>