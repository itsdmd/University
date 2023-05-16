<?php
include "func/init.php";
include "inc/header.php";
include "func/functions.php";
?>
    <div class="jumbotron jumbotron-fluid mt-5">
        <div class="container">
            <?php if(!empty($msg)):?>
                <div class="alert alert-<?php echo $msg['class'];?>" role="alert">
                    <?php $msg["text"]; ?>
                </div>
            <?php endif;?>
            <div class="row">
            <div class="col-md-6 offset-md-3">
            <h1 class="display-4"><i class="fa fa-check" aria-hidden="true"></i> ITEC Todo</h1>
            <p class="lead">Add a todo below:</p>
            <hr class="my-4">
            <form action="<?php echo $_SERVER["PHP_SELF"];?>" method="post">
                <div class="form-group">
                    <input id="my-input" class="form-control" type="text" name="todo" placeholder="Todo here...">
                    <button type="submit" class="btn btn-primary btn-block btn-lg mt-3"><i class="fa fa-plus" aria-hidden="true"></i> Add Todo</button>
                </div>
        
            </form>
            </div>
            </div>
        </div>
    </div>
    <div class="container">
        <h2>Todos Here:</h2>

        <?php if($_SESSION['logged_in']): ?>
        <div class="row">

        <ul class="list-group w-100">
            <?php foreach($todos as $todo): ?>
            <li class="list-group-item d-flex justify-content-between align-items-center w-100 <?php 
                if($todo['status']) { 
                    echo "complete";}
                    ?>">

                <div class="todo-text">
                <?php echo htmlspecialchars($todo['todo']);?>
                </div>

                <form action="index.php" method="post" class="d-none">
                <input type="text" value="<?php echo filter_var($todo['todo'], FILTER_SANITIZE_SPECIAL_CHARS);?>"
                class="form-control" name="update">
                <input type="hidden" name="id" value="<?php echo $todo['id'];?>">
                </form>

                <div class="d-flex">
    
                    <button class="btn btn-primary edit"><i class="fa fa-pencil-square" aria-hidden="true"></i> Edit</button>
                    <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
                    <button type="submit" class="btn btn-danger mr-2 ml-2" name="delete" value="<?php echo $todo['id']; ?>"><i class="fa fa-trash" aria-hidden="true"></i> Delete</button>
                </form>
                <form method="post" action="index.php">
                    <button type="submit" class="btn 
                    <?php 
                if($todo['status']) { 
                    echo "btn-warning";} else { echo "btn-outline-warning";}
                    ?>" name="status" value="<?php echo $todo['id'];?>"> <?php 
                    if($todo['status']) { 
                        echo "Undo";} else { echo "Done";}
                        ?></button>
                </form>
                </div>
            </li>
            <?php endforeach;?>
        </ul>
            
        </div>
        <?php else: ?>
            <div class="alert alert-warning">
                You must <a href="login.php">login</a> to see todos!
            </div>
        <?php endif;?>
    </div>
<?php
    include "inc/footer.php";
?>