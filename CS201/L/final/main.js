console.log("welcome to ITEC final store");
/* Here are the endpoints you need to hit */
/* https://dummyjson.com/products/  for all products*/
/* https://dummyjson.com/products/category/smartphones an example of a filter category (choose 4-5) */
/* declare your global vars here */
let _ctgs = [];
let _cart = [];

let e_ctgBtnContainer = document.querySelector(".category-selectors");
let e_cardContainer = document.querySelector(".card-container");
let e_cartTotal = document.querySelector(".cart-total");
let e_infoModal = document.querySelector("#info-modal");
let e_infoModalTitle = document.querySelector(".modal-title");
let e_infoModalBody = document.querySelector(".modal-body");

/* call your start up functions here */
main(5, 6);

/* add your event listeners here */

e_ctgBtnContainer.addEventListener("click", (e) => {
	console.log("e_ctgBtnContainer clicked");
	console.log("e.target:", e.target);

	let ctgName = e.target.innerText;
	populateProductCatalog(ctgName);
});

e_cardContainer.addEventListener("click", (e) => {
	console.log("e_cardContainer clicked");
	console.log("e.target:", e.target);

	if (e.target.classList.contains("btn-more")) {
		console.log("btn-more clicked");
		populateModalContent(e.target);
	} else if (e.target.classList.contains("btn-purchase")) {
		console.log("btn-purchase clicked");
		addToLocalCart(e.target.parentElement.parentElement.querySelector(".metadata").querySelector(".prod-id").innerText);
	}
});

/* create script functions here (remember to use async + await where needed) */

async function main(ctgLimit = -1, prodLimit = -1) {
	console.log("main called");
	console.log("ctgLimit:", ctgLimit);
	console.log("prodLimit:", prodLimit);

	_cart = localStorage.getItem("cart");
	if (_cart == null) {
		_cart = [];
	} else {
		_cart = JSON.parse(_cart);
	}
	e_cartTotal.innerHTML = _cart.length;

	await populateCategoriesGlobalVar(ctgLimit);
	await populateCategoryButtons();

	await initialPopulateProductCatalog();
}

async function populateCategoriesGlobalVar(limit = -1) {
	console.log("populateCategoriesGlobalVar called");
	_ctgs = await fetchCategories(limit);
	return;
}

async function populateCategoryButtons() {
	console.log("populateCategoryButtons called");

	e_ctgBtnContainer.innerHTML = "";

	_ctgs.forEach((ctg) => {
		let ctgBtn = `
			<a href="#" class="badge badge-primary p-2 mr-1">${ctg}</a>
		`;

		e_ctgBtnContainer.innerHTML += ctgBtn;
	});

	return _ctgs;
}

async function initialPopulateProductCatalog() {
	console.log("initialPopulateProductCatalog called");

	e_cardContainer.innerHTML = "";

	url = "https://dummyjson.com/products?limit=6";

	let products = await fetch(url)
		.then((res) => res.json())
		.then((data) => {
			console.log("data:", data);
			return data;
		})
		.catch((err) => console.log(err));
	console.log("products:", products);

	products.products.forEach((prod) => {
		let card = `
			<div class="col-lg-4 col-sm-1 mb-5 align-items-stretch">
				<div class="card">
					<img src="${prod.thumbnail}" class="card-img-top" />
					<div class="card-body">
						<h5 class="card-title">${prod.title}</h5>
						<p class="card-text">$${prod.price}</p>
						<div class="btn btn-outline-primary btn-more" data-toggle="modal" data-target="#info-modal">
							Read More
						</div>
						<div class="btn btn-primary btn-purchase">
							<i class="fas fa-plus"></i> Purchase
						</div>
						<div class="metadata d-none">
							<p class="prod-id">${prod.id}</p>
							<p class="prod-desc">${prod.description}</p>
							<p class="prod-brand">${prod.brand}</p>
							<p class="prod-rating">${prod.rating}</p>
							<p class="prod-stock">${prod.stock}</p>
						</div>
					</div>
				</div>
			</div>
		`;

		e_cardContainer.innerHTML += card;
	});
}

async function populateProductCatalog(ctgName = 0, limit = -1) {
	console.log("populateProductCatalog called");

	e_cardContainer.innerHTML = "";

	let products = await fetchProdByCtg(ctgName, limit);
	console.log("products:", products);

	products.products.forEach((prod) => {
		let card = `
			<div class="col-lg-4 col-sm-1 mb-5 align-items-stretch">
				<div class="card">
					<img src="${prod.thumbnail}" class="card-img-top" />
					<div class="card-body">
						<h5 class="card-title">${prod.title}</h5>
						<p class="card-text">$${prod.price}</p>
						<div class="btn btn-outline-primary btn-more" data-toggle="modal" data-target="#info-modal">
							Read More
						</div>
						<div class="btn btn-primary btn-purchase">
							<i class="fas fa-plus"></i> Purchase
						</div>
						<div class="metadata d-none">
							<p class="prod-id">${prod.id}</p>
							<p class="prod-desc">${prod.description}</p>
							<p class="prod-brand">${prod.brand}</p>
							<p class="prod-rating">${prod.rating}</p>
							<p class="prod-stock">${prod.stock}</p>
						</div>
					</div>
				</div>
			</div>
		`;

		e_cardContainer.innerHTML += card;
	});
}

async function fetchCategories(limit = -1) {
	console.log("fetchCategories called");

	let resp = await fetch("https://dummyjson.com/products/categories")
		.then((res) => res.json())
		.then((data) => {
			data = data.slice(0, limit);
			console.log("data:", data);
			return data;
		})
		.catch((err) => console.log(err));

	return resp;
}

async function fetchProdByCtg(ctg, limit = -1) {
	console.log("fetchProdByCtg called");

	url = `https://dummyjson.com/products/category/${ctg}` + (limit > 0 ? `?limit=${limit}` : "");
	console.log("url:", url);

	let resp = await fetch(url)
		.then((res) => res.json())
		.then((data) => {
			console.log("data:", data);
			return data;
		})
		.catch((err) => console.log(err));

	return resp;
}

function populateModalContent(target) {
	console.log("populateModalContent called");

	let title = target.parentElement.querySelector(".card-title").innerHTML;

	let metadata = target.parentElement.parentElement.querySelector(".metadata");

	let prodId = metadata.querySelector(".prod-id").innerHTML;
	let prodDesc = metadata.querySelector(".prod-desc").innerHTML;
	let prodBrand = metadata.querySelector(".prod-brand").innerHTML;
	let prodRating = metadata.querySelector(".prod-rating").innerHTML;
	let prodStock = metadata.querySelector(".prod-stock").innerHTML;

	e_infoModalTitle.innerHTML = title;

	e_infoModalBody.innerHTML = `
		<p>${prodDesc}</p>
		<p>Brand: ${prodBrand}</p>
		<p>ID: ${prodId}</p>
		<p>Rating: ${prodRating}</p>
		<p>Stock: ${prodStock}</p>
	`;
}

function addToLocalCart(prodId) {
	console.log("addToLocalCart called");

	_cart.push(prodId);
	localStorage.setItem("cart", JSON.stringify(_cart));

	e_cartTotal.innerHTML = _cart.length;

	console.log("cart:", _cart);
}
