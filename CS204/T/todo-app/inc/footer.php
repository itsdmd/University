<footer class="bg-dark text-light mt-4 pb-5 pt-5">
        <div class="container pb-4">
            <h2><i class="fa fa-check-circle" aria-hidden="true"></i> ITEC Todo <?php echo Date("Y"); ?></h2>
        </div>
    </footer>

<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.5.1/jquery.slim.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.1/umd/popper.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.6.0/js/bootstrap.min.js"></script>
<script>
    let lg = document.querySelector(".list-group");
    lg.addEventListener("click", (e) => {
        console.log("click");
        console.log(e.target);
        if(e.target.classList.contains("edit")) {
            let els = e.target.closest("li").children;
            console.log(els);
            if(e.target.classList.contains("btn-success")) {
                els[1].submit();
            } else {
                e.target.classList.toggle("btn-success");
                e.target.classList.toggle("btn-primary");
            }

            e.target.textContent = "Save";
            els[0].classList.toggle("d-none");
            els[1].classList.toggle("d-none");
        }
    })
</script>
</body>
</html>
<?php

var_dump($_SESSION);

?>