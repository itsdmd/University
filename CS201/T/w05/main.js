console.log("main.js loaded");

/* ---------------------------------- */
/*              Variables             */
/* ---------------------------------- */

let frontBlocks = document.querySelectorAll(".front-block");
let nav = document.querySelector("nav");
let hamburger = document.querySelector(".hamburger");

/* ---------------------------------- */
/*           EventListeners           */
/* ---------------------------------- */

frontBlocks.forEach(function(block) {
	block.addEventListener("mouseover", function() {
		// console.log("front-block mouseover");
		block.style.background = "aliceblue";
	});
	
	block.addEventListener("mouseout", function() {
		// console.log("front-block mouseout");
		block.style.background = "white";
	});
});

hamburger.addEventListener("click", function() {
	console.log("hamburger click");
	nav.classList.toggle("nav-slide");
});
