// Linked to: T/midterm/index.html

console.log("main.js loaded");

let productsUrl = [
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
let productsTitle = [
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

let aboutUrl = [
	"https://www.nikon.com/about/corporate/",
	"https://www.nikon.com/about/technology/",
	"https://www.nikon.com/about/sustainability/",
	"https://www.nikon.com/about/ir",
];
let aboutTitle = ["Corporate Information", "Technology & Design", "Sustainability", "Investor Relations"];

/* ------- Grid post generator ------ */
function populatePostItem(classes, url, imgUrl, title, text, index) {
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

function populatePostGrid(target, classes, url, imgUrl, title, text) {
	let targetNode = document.querySelector(target);

	// Remove all current content items
	while (targetNode.firstChild) {
		targetNode.removeChild(targetNode.firstChild);
	}

	for (let i = 0; i < url.length; i++) {
		targetNode.appendChild(populatePostItem(classes, url, imgUrl, title, text, i));
		console.log(target + " Item " + i + " populated");
	}
}

/* ---------------------------------- */
/*           Navbar dropdown          */
/* ---------------------------------- */

/* #region   */
/* --------- Populate items --------- */
function populateNavDropProdTabItems() {
	// Template:
	// <a href="url">
	//     <p>Title</p>
	// </a>

	let navDropProdTabContent1 = document.querySelector(".nav-dropdown .prod-tab .itm1");

	// Remove all current content items
	while (navDropProdTabContent1.firstChild) {
		navDropProdTabContent1.removeChild(navDropProdTabContent1.firstChild);
	}

	for (let i = 0; i < productsUrl[0].length; i++) {
		let contentItem = document.createElement("a");
		contentItem.href = productsUrl[0][i];

		let contentItemTitle = document.createElement("p");
		contentItemTitle.innerText = productsTitle[0][i];

		contentItem.appendChild(contentItemTitle);
		navDropProdTabContent1.appendChild(contentItem);
	}

	// Exception: remove last item
	navDropProdTabContent1.removeChild(navDropProdTabContent1.lastChild);

	// let navDropProdTabContent2 = document.querySelector(".nav-dropdown .prod-tab .itm2");

	// while (navDropProdTabContent2.firstChild) {
	// 	navDropProdTabContent2.removeChild(navDropProdTabContent2.firstChild);
	// }

	// for (let i = 0; i < productsUrl[1].length; i++) {
	// 	let contentItem = document.createElement("a");
	// 	contentItem.href = productsUrl[1][i];

	// 	let contentItemTitle = document.createElement("p");
	// 	contentItemTitle.innerText = productsTitle[1][i];

	// 	contentItem.appendChild(contentItemTitle);
	// 	navDropProdTabContent2.appendChild(contentItem);
	// }
}

function populateNavDropAboutTabItems() {
	// Template:
	// <a href="url">
	//     <p>Title</p>
	// </a>

	let navDropAboutTabContent = document.querySelector(".nav-dropdown .about-tab .itm");

	// Remove all current
	while (navDropAboutTabContent.firstChild) {
		navDropAboutTabContent.removeChild(navDropAboutTabContent.firstChild);
	}

	for (let i = 0; i < aboutUrl.length; i++) {
		let contentItem = document.createElement("a");
		contentItem.href = aboutUrl[i];

		let contentItemTitle = document.createElement("p");
		contentItemTitle.innerText = aboutTitle[i];

		contentItem.appendChild(contentItemTitle);
		navDropAboutTabContent.appendChild(contentItem);
	}
}

populateNavDropProdTabItems();
populateNavDropAboutTabItems();

/* ---------- Show/Hide tab --------- */
let navProdBtn = document.querySelector("#nav-prod-btn");
let navAboutBtn = document.querySelector("#nav-about-btn");

let navDropProdTab = document.querySelector(".nav-dropdown .prod-tab");
let el_navProdBtn = navProdBtn.addEventListener("click", function () {
	console.log("navProdBtn clicked");

	navAboutBtn.classList.remove("active");
	navDropAboutTab.classList.remove("active");

	navProdBtn.classList.toggle("active");
	navDropProdTab.classList.toggle("active");
});

let navDropAboutTab = document.querySelector(".nav-dropdown .about-tab");
let el_navAboutBtn = navAboutBtn.addEventListener("click", function () {
	console.log("navAboutBtn clicked");

	navProdBtn.classList.remove("active");
	navDropProdTab.classList.remove("active");

	navAboutBtn.classList.toggle("active");
	navDropAboutTab.classList.toggle("active");
});

let navProdCloseBtn = document.querySelector(".nav-dropdown .prod-tab .nav-dropdown-close-btn");
let el_navProdCloseBtn = navProdCloseBtn.addEventListener("click", function () {
	console.log("navProdCloseBtn clicked");

	navProdBtn.classList.remove("active");
	navDropProdTab.classList.remove("active");
});

let navAboutCloseBtn = document.querySelector(".nav-dropdown .about-tab .nav-dropdown-close-btn");
let el_navAboutCloseBtn = navAboutCloseBtn.addEventListener("click", function () {
	console.log("navAboutCloseBtn clicked");

	navAboutBtn.classList.remove("active");
	navDropAboutTab.classList.remove("active");
});

/* #endregion */

/* ---------------------------------- */
/*              Catalogue             */
/* ---------------------------------- */

/* -------- Catalogue content ------- */

/* #region   */

const productsImgUrlPrefix = "https://www.nikon.com/img/index/pic_product_";
const productsCtg = ["corp", "indi"];
const productsImgUrlSuffix = ".png";

function populateCatalogueContentItem(tabIndex, index) {
	let contentItem = document.createElement("a");
	contentItem.classList.add("catalogue", "content-grid-item", "card");
	contentItem.href = productsUrl[tabIndex][index];

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
		productsImgUrlPrefix + productsCtg[tabIndex] + "_" + (imgIndex + 1 < 10 ? "0" + String(imgIndex + 1) : String(imgIndex + 1)) + productsImgUrlSuffix;
	contentItem.appendChild(contentImg);

	let contentTitle = document.createElement("h3");
	contentTitle.innerText = productsTitle[tabIndex][index];
	contentItem.appendChild(contentTitle);

	return contentItem;
}

function populateCatalogueContent() {
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

	for (let i = 0; i < productsTitle[catalogueCurrentTab].length; i++) {
		catalogueContent.appendChild(populateCatalogueContentItem(catalogueCurrentTab, i));
		console.log("catalogueContentItem " + i + " populated");
	}
}
/* #endregion */

/* ---------- Catalogue tab --------- */

/* #region   */
let catalogueCurrentTab = 0;
let catalogueTab = document.querySelectorAll(".catalogue-tab");

// Set first tab to be selected
catalogueTab[catalogueCurrentTab].classList.add("is-selected");
populateCatalogueContent();

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

		// populate content
		populateCatalogueContent();
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

populatePostGrid(".topics.content-grid", topicsContentClasses, topicsContentUrl, topicsContentImgUrl, topicsContentTitle, topicsContentText);
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

populatePostGrid(".pickup.content-grid", pickUpContentClasses, pickUpContentUrl, pickUpContentImgUrl, pickUpContentTitle, pickUpContentText);
/* #endregion */

/* ---------------------------------- */
/*             Latest News            */
/* ---------------------------------- */

/* #region   */
let newsDates = ["Feb. 1, 2023", "Jan. 31, 2023", "Jan. 20, 2023", "Jan. 20, 2023", "Jan. 6, 2023", ""];

let newsTitle = [
	"Notice Regarding the Status of Repurchase of Shares of Common Stock(PDF:158KB)",
	"Nikon introduces the Digital Sight 50M Monochrome Camera",
	"Notice of Implementation of Settlement relating to Public Takeover Offer for Shares of SLM and SLM becoming a Consolidated Subsidiary of Nikon",
	"Nikon's Public Takeover Offer for SLM Successful",
	"Nikon Exhibits at CES® 2023",
	"more News",
];

let newsUrl = [
	"https://www.nikon.com/news/2023/20230201_e.pdf",
	"https://www.nikon.com/news/2023/0131_digital-sight-50m_01.htm",
	"https://www.nikon.com/news/2022/slm/",
	"https://www.nikon.com/news/2022/slm/",
	"https://www.nikon.com/news/2023/0106_ces_01.htm",
	"https://www.nikon.com/news/",
];

function populateNewsItem(date, title, url) {
	// Template
	// <div class="news content-list-item">
	// 	<p class="date">Feb. 1, 2023</p>
	// 	<p>></p>
	// 	<a href="#">Placeholder</a>
	// </div>

	let newsItem = document.createElement("div");
	newsItem.classList.add("news", "content-list-item");

	if (date == "") {
		newsItem.classList.add("more");
	}

	let newsDate = document.createElement("p");
	newsDate.classList.add("date");
	newsDate.textContent = date;

	let newsArrow = document.createElement("p");
	newsArrow.classList.add("arrow");
	newsArrow.textContent = ">";

	let newsLink = document.createElement("a");
	newsLink.href = url;
	newsLink.textContent = title;

	newsItem.appendChild(newsDate);
	newsItem.appendChild(newsArrow);
	newsItem.appendChild(newsLink);

	return newsItem;
}

function populateNewsList() {
	let newsList = document.querySelector(".news.content-list");

	while (newsList.firstChild) {
		newsList.removeChild(newsList.firstChild);
	}

	for (let i = 0; i < newsDates.length; i++) {
		let newsItem = populateNewsItem(newsDates[i], newsTitle[i], newsUrl[i]);
		newsList.appendChild(newsItem);
		console.log(".news.content-list Item " + i + " populated");
	}
}

populateNewsList();

/* #endregion */

/* ---------------------------------- */
/*            Footer Links            */
/* ---------------------------------- */

/* #region   */
function populateFooterLinks(target, url, title) {
	// target: HTMLNode
	// url: stringList
	// title: stringList

	// Template:
	// <a href="url">Title</a>
	// <span> | </span>

	for (let i = 0; i < url.length; i++) {
		// Create separator
		let separator = document.createElement("span");
		separator.textContent = " | ";
		target.appendChild(separator);

		// Create link
		let link = document.createElement("a");
		link.href = url[i];
		link.textContent = title[i];
		target.appendChild(link);
	}
}

let footerLinks_prods = document.querySelector(".footer.url-list.products");
let footerLinks_about = document.querySelector(".footer.url-list.about");

populateFooterLinks(footerLinks_prods, productsUrl[0], productsTitle[0]);
populateFooterLinks(footerLinks_about, aboutUrl, aboutTitle);
/* #endregion */
