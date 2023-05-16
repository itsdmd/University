<?php
    include "func/init.php";
    include "func/form_handler.php";
    include "inc/header.php";
    include "func/functions.php";
?>
<div class="jumbotron container mt-5 pt-5">
    <div class="row">
        <div class="col-md-6 pr-4">
            <h2><i class="fa fa-user-plus" aria-hidden="true"></i> Register</h2>
        <form action="login.php" method="post">
        <div class="form-group">
          <label for="username">Username:</label>
          <input type="text" class="form-control" id="username" placeholder="Enter username" autocomplete="off" name="username">
        </div>
        <div class="form-group">
          <label for="email">Email:</label>
          <input type="text" class="form-control" id="email" placeholder="Enter email" autocomplete="off" name="email">
        </div>
        <div class="form-group">
          <label for="password">Password:</label>
          <input type="password" class="form-control" id="password" placeholder="Enter password" autocomplete="off" name="password">
        </div>
        <div class="form-group">
          <label for="confirm_password">Confirm Password:</label>
          <input type="password" class="form-control" id="confirm_password" placeholder="Confirm password" autocomplete="off" name="confirm_password">
        </div>
        <button type="submit" class="btn btn-success btn-block btn-lg" name="register"><i class="fa fa-play-circle" aria-hidden="true"></i> Register</button>
      </form>
        </div> <!-- end col-6 -->
        <div class="col-md-6 pl-4">
            <h2><i class="fa fa-plus-circle" aria-hidden="true"></i> Login</h2>
            <form action="login.php" method="post">
                <div class="form-group">
                    <label for="username">Username</label>
                    <input id="username" class="form-control" type="text" name="username" autocomplete="off">
                </div>
                <div class="form-group">
                    <label for="password">Password</label>
                    <input id="password" class="form-control" type="password" name="password" autocomplete="off">
                </div>
                <button type="submit" name="login" class="btn btn-outline-primary btn-lg btn-block"><i class="fa fa-user-circle" aria-hidden="true" name="login"></i> Login</button>
            </form>
        </div> <!-- end col-6 -->
    </div>
</div>


<?php
    include "inc/footer.php";
?>