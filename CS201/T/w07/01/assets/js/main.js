// Linked to T/w07/index.html

console.log("main.js is linked");

// Image carousel

carouselImgs = document.querySelectorAll(".carousel img");

carouselImgs[0].classList.add("active");
activeImg = 0;

function next() {
	if (activeImg < carouselImgs.length - 1) {
		activeImg++;
	} else {
		activeImg = 0;
	}

	console.log("next clicked, activeImg = " + activeImg);

	carouselImgs.forEach((img) => {
		img.classList.remove("active");
	});

	carouselImgs[activeImg].classList.add("active");
}

function prev() {
	if (activeImg > 0) {
		activeImg--;
	} else {
		activeImg = carouselImgs.length - 1;
	}

	console.log("prev clicked, activeImg = " + activeImg);

	carouselImgs.forEach((img) => {
		img.classList.remove("active");
	});

	carouselImgs[activeImg].classList.add("active");
}

prevBtn = document.querySelector(".prev");
nextBtn = document.querySelector(".next");

prevBtn.addEventListener("click", prev);
nextBtn.addEventListener("click", next);
