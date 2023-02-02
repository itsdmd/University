// Linked to: T/midterm/index.html

console.log("main.js loaded");

/* ------- Grid post generator ------ */
function generatePostItem(classes, url, imgUrl, title, text, index) {
	// Template:
	// <a href="#" class="topics content-grid-item">
	// 	<img alt="placeholder img" />
	// 	<h3>Placeholder h3</h3>
	// 	<p>Lorem ipsum...</p>;
	// </a>

	let post = document.createElement("a");
	post.classList.add(classes, "content-grid-item", "post");
	post.href = url[index];

	let postImg = document.createElement("img");
	postImg.src = imgUrl[index];
	post.appendChild(postImg);

	let postTitle = document.createElement("h3");
	postTitle.innerText = title[index];
	post.appendChild(postTitle);

	let postText = document.createElement("p");
	postText.innerText = text[index];
	post.appendChild(postText);

	return post;
}

function generatePostGrid(target, classes, url, imgUrl, title, text) {
	let targetNode = document.querySelector(target);

	// Remove all current content items
	while (targetNode.firstChild) {
		targetNode.removeChild(targetNode.firstChild);
	}

	for (let i = 0; i < url.length; i++) {
		targetNode.appendChild(generatePostItem(classes, url, imgUrl, title, text, i));
		console.log(target + "Item " + i + " generated");
	}
}

/* ---------------------------------- */
/*              Catalogue             */
/* ---------------------------------- */

/* -------- Catalogue content ------- */

/* #region   */

let catalogueContentUrl = [
	[
		"https://www.healthcare.nikon.com/en/",
		"https://industry.nikon.com/en-aom/",
		"https://www.nikon.com/products/optical-processing-machine/",
		"https://www.nikon.com/products/encoder/",
		"https://www.nikon.com/products/industrial-lenses/",
		"https://ngpd.nikon.com/en/",
		"https://www.nikon.com/products/components/",
		"https://www.nikon-trimble.co.jp/english/",
		"https://www.nikon.com/products/fpd/lineup/",
		"https://www.nikon.com/products/semi/lineup/",
		"https://www.nikonprecision.com/products-and-technology/steppers-and-metrology-solutions-for-mems-markets/",
	],
	[
		"https://imaging.nikon.com/lineup/dslr/",
		"https://imaging.nikon.com/lineup/mirrorless/",
		"https://imaging.nikon.com/lineup/compact/",
		"https://imaging.nikon.com/lineup/lens/",
		"https://imaging.nikon.com/lineup/speedlight/",
		"https://imaging.nikon.com/lineup/software/",
		"https://imaging.nikon.com/lineup/sportoptics/",
		"https://imaging.nikon.com/lineup/sportoptics/laser/",
		"https://imaging.nikon.com/lineup/accessory/",
		"https://www.nikonlenswear.com/",
	],
];
let catalogueContentTitle = [
	[
		"Healthcare Products & Solutions",
		"Industrial Metrology",
		"Optical Processing Machine",
		"Encoders",
		"Industrial Lenses",
		"Material Processing Solutions & Robot Vision",
		"Optical Components & Materials",
		"Surveying Instruments",
		"FPD Lithography Systems",
		"Semiconductor Systems",
		"MEMS Steppers & Both Side Measurement System",
	],
	[
		"Digital SLR Cameras",
		"Mirrorless Cameras",
		"Compact Digital Cameras",
		"NIKKOR Lenses",
		"Speedlights",
		"Software",
		"Sport Optics",
		"Laser Rangefinder",
		"Accessories",
		"Ophthalmic Lenses",
	],
];

const catalogueContentImgUrlPrefix = "https://www.nikon.com/img/index/pic_product_";
const catalogueContentImgUrlPrefix_tab = ["corp", "indi"];
const catalogueContentImgUrlSuffix = ".png";

function generateCatalogueContentItem(tabIndex, index) {
	let contentItem = document.createElement("a");
	contentItem.classList.add("catalogue", "content-grid-item", "card");
	contentItem.href = catalogueContentUrl[tabIndex][index];

	let contentImg = document.createElement("img");

	let imgIndex = index;
	// Weird index exceptions for tab 0's items' img
	if (tabIndex === 0) {
		index += 1;

		switch (index) {
			case 6:
				imgIndex = 13;
				break;
			case 7:
				imgIndex = 8;
				break;
			case 8:
				imgIndex = 9;
				break;
			case 9:
				imgIndex = 11;
				break;
			case 10:
				imgIndex = 12;
				break;
			case 11:
				imgIndex = 6;
				break;
		}

		index -= 1;
	}

	contentImg.src =
		catalogueContentImgUrlPrefix +
		catalogueContentImgUrlPrefix_tab[tabIndex] +
		"_" +
		(imgIndex + 1 < 10 ? "0" + String(imgIndex + 1) : String(imgIndex + 1)) +
		catalogueContentImgUrlSuffix;
	contentItem.appendChild(contentImg);

	let contentTitle = document.createElement("h3");
	contentTitle.innerText = catalogueContentTitle[tabIndex][index];
	contentItem.appendChild(contentTitle);

	return contentItem;
}

function generateCatalogueContent() {
	// Template
	// <a href="#" class="catalogue content-grid-item">
	// 		<img alt="placeholder img" />
	// 		<h3>Placeholder h3</h3>
	// 	</a>

	let catalogueContent = document.querySelector(".catalogue.content-grid");

	// Remove all current content items
	while (catalogueContent.firstChild) {
		catalogueContent.removeChild(catalogueContent.firstChild);
	}

	for (let i = 0; i < catalogueContentTitle[catalogueCurrentTab].length; i++) {
		catalogueContent.appendChild(generateCatalogueContentItem(catalogueCurrentTab, i));
		console.log("catalogueContentItem " + i + " generated");
	}
}
/* #endregion */

/* ---------- Catalogue tab --------- */

/* #region   */
let catalogueCurrentTab = 0;
let catalogueTab = document.querySelectorAll(".catalogue-tab");

// Set first tab to be selected
catalogueTab[catalogueCurrentTab].classList.add("is-selected");
generateCatalogueContent();

// Add EL to each button
catalogueTab.forEach((button) => {
	button.addEventListener("click", () => {
		// Remove all current is-selected classes
		catalogueTab.forEach((button) => {
			button.classList.remove("is-selected");
		});

		// Add is-selected class to clicked button
		button.classList.add("is-selected");

		// Get the index of the clicked button
		catalogueCurrentTab = Array.from(catalogueTab).indexOf(button);

		// Generate content
		generateCatalogueContent();
	});
});
/* #endregion */

/* ---------------------------------- */
/*               Topics               */
/* ---------------------------------- */

/* #region   */
let topicsContentClasses = ["topics"];

let topicsContentUrl = [
	"https://www.nikon.com/products/optical-processing-machine/",
	"https://www.microscope.healthcare.nikon.com/en_AOM/products/confocal-microscopes/ax",
	"https://industry.nikon.com/en-aom/products/video-measuring-systems/nexiv-vmz-s/",
];

let topicsContentImgUrl = [
	"https://www.nikon.com/img/index/pic_topics_corp_lasemeister_202106.jpg",
	"https://www.nikon.com/img/index/pic_topics_corp_ax-axr_202106.jpg",
	"https://www.nikon.com/img/index/pic_topics_corp_vmz-s_202106.jpg",
];

let topicsContentTitle = ["Lasermeister Series", "AX / AX R Confocal Microscope System", "CNC Video Measuring System VMZ-S Series"];

let topicsContentText = [
	"More convenient and easier metal modeling. Additive manufacturing with built-in measurement system.",
	"High resolution 8K x 8K images and the world's largest FOV of 25 mm enable you to obtain more data than ever, expanding the possibilities of a wide range of research fields.",
	"Assisting factory automation with high accuracy auto dimension measuring of electronic components",
];

generatePostGrid(".topics.content-grid", topicsContentClasses, topicsContentUrl, topicsContentImgUrl, topicsContentTitle, topicsContentText);
/* #endregion */

/* ---------------------------------- */
/*               Pick Up              */
/* ---------------------------------- */

/* #region   */
let pickUpContentClasses = ["pickup"];

let pickUpContentUrl = [
	"https://www.nikon.com/ces2023e/https://www.nikon.com/ces2023e/",
	"https://www.nikon.com/about/ir/ir_library/result/index.htm#y2023",
	"https://www.nikon.com/about/sustainability/report/",
];

let pickUpContentImgUrl = [
	"https://www.nikon.com/img/index/pic_pickup_ces2023_e.jpg",
	"https://www.nikon.com/img/index/pic_pickup_ir_202204.jpg",
	"https://www.nikon.com/img/index/pic_pickup_sustainability.jpg",
];

let pickUpContentTitle = ["CES 2023 Special Website", "Investor Relations", "Nikon Sustainability Report 2022"];

let pickUpContentText = [
	"Introducing Nikon's latest technologies and provided values to realize Vision 2030 (a global society where humans and machines co-create seamlessly), formulated in our Medium-Term Management Plan.",
	"Second Quarter of the Year Ending March 2023 financial results have been announced.",
	"Here you can see our latest sustainability report, which is organized according to Nikon Materiality of the Nikon Group's activities and progress clearer to readers.",
];

generatePostGrid(".pickup.content-grid", pickUpContentClasses, pickUpContentUrl, pickUpContentImgUrl, pickUpContentTitle, pickUpContentText);
/* #endregion */
