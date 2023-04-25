<?php
$company_name = "ITEC Import/Export";

$menu_items = ["home", "features", "products", "contact"];

?>
<div class="d-flex flex-column flex-md-row align-items-center p-3 px-md-4 mb-3 bg-white border-bottom box-shadow">
  <h5 class="my-0 mr-md-auto font-weight-normal">
    <?php echo $company_name; ?>
  </h5>
  <nav class="my-2 my-md-0 mr-md-3">
    <?php
    // loop to output menu items

    foreach ($menu_items as $item) {
      echo "<a class='p-2 text-dark' href='" . ($item === "home" ? "index" : $item) . ".php'>" . ucfirst($item) . "</a>";
    }
    ?>
  </nav>
  <a class="btn btn-outline-primary" href="#">Sign up</a>
</div>