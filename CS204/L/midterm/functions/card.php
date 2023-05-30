<?php

// <div class="container">
//     <div class="row">
//         <div class="col-md-4 col-sm-6 mt-4">
//             <div class="card">
//                 <img class="card-img-top" src="images/meme1.jpg" alt="">
//                 <div class="card-body">
//                     <h5 class="card-title"><a href="meme.php?id=1">What do
//                             you meme?</a></h5>
//                     <p>Author: admin</p>
//                     <p class="card-text">Lorem ipsum dolor sit, amet
//                         consectetur adipisicing elit.</p>
//                 </div>
//             </div>
//         </div>
//     </div>
// </div>

function generateCard($card) {

    $output = '<div class="col-md-4 col-sm-6 mt-4">';
    $output .= '<div class="card">';
    $output .= '<img class="card-img-top" src="images/' . $card['img_file'] . '" alt="">';
    $output .= '<div class="card-body">';
    $output .= '<h5 class="card-title"><a href="meme.php?id=' . $card['id'] . '">' . $card['title'] . '</a></h5>';
    $output .= '<p>Author: ' . $card['author'] . '</p>';
    $output .= '<p class="card-text">' . $card['body'] . '</p>';
    $output .= '</div></div></div>';

    return $output;
}

function generateCardRows($cards) {
    // $cards is an array
    // for every 3 cards, put it inside a row

    $output = '<div class="container">';

    for ($i = 0; $i < count($cards); $i++) {
        if ($i % 3 == 0) {
            $output .= '<div class="row">';
        }

        $output .= generateCard($cards[$i]);

        if ($i % 3 == 2) {
            $output .= '</div>';
        }
    }

    $output .= '</div>';

    return $output;
}

function generateCardsFromQuery($query) {
    include "functions/query.php";
    return generateCardRows(query($query));
}
