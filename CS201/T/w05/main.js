console.log("main.js loaded");

/* ---------------------------------- */
/*              Variables             */
/* ---------------------------------- */

let frontBlocks = document.querySelectorAll(".front-block");
let hamburger = document.querySelector(".hamburger");
let header = document.querySelector("header");
let nav = document.querySelector("nav");

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
	
	header.classList.toggle("black");
	nav.classList.toggle("nav-slide");
	hamburger.classList.toggle("invert");
});
