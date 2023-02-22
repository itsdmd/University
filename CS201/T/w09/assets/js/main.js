console.log("main.js loaded");
getPager();
getArticles(0, 9);
let articlesDiv = document.querySelector("div.articles");
let pager = document.querySelector("ul.pagination");

pager.addEventListener("click", function (event) {
	let targ = event.target;
	event.preventDefault();
	if (targ.classList.contains("pager-number")) {
		console.log(targ.getAttribute("data-offset"));
		let offset = targ.getAttribute("data-offset") * 9;
		console.log(offset);
		getArticles(offset, 9);
		/* find li.active in pager, remove .active */
		let currentActive = pager.querySelector("li.active");
		currentActive.classList.remove("active");
		/* go to event.target and add .active to the parent li*/
		let parentli = event.target.parentElement;
		parentli.classList.add("active");
	} else if (targ.classList.contains("next")) {
		let currentActive = pager.querySelector("li.active");
		currentActive.classList.remove("active");

		if (currentActive.nextElementSibling.classList.contains("next")) {
			pager.children[1].classList.add("active");
		} else {
			currentActive.nextElementSibling.classList.add("active");
		}
	} else if (targ.classList.contains("previous")) {
		let currentActive = pager.querySelector("li.active");
		currentActive.classList.remove("active");
		if (currentActive.previousElementSibling.classList.contains("previous")) {
			pager.lastElementChild.previousElementSibling.classList.add("active");
		} else {
			currentActive.previousElementSibling.classList.add("active");
		}
	}
});

articlesDiv.addEventListener("click", function (event) {
	console.log("articles clicked");
	console.log(event);
	console.log(event.target);
	if (event.target.classList.contains("title-link")) {
		getArticle(event.target.getAttribute("data-id"));
	} else {
		console.log("not the link");
	}
});

function getArticle(id) {
	console.log("get article number: " + id);
	let url = `https://jsonplaceholder.typicode.com/posts/${id}`;
	/*1)create XMLHttpRequest obj  */
	let xhr = new XMLHttpRequest();
	/*2) call open method on xhr  */
	xhr.open("get", url, true);
	/*3) call send method on xhr  */
	xhr.send();
	/*4) use xhr.onload = fucntion() {} to log response  */
	xhr.onload = function () {
		if (this.status == 200) {
			console.log(this.response);
			let result = JSON.parse(this.response);
			outputArticle(result);
		}
	};
}

function outputArticle(data) {
	let title = document.querySelector(".jumbotron h1");
	let body = document.querySelector(".jumbotron p.body");
	title.innerText = data.title;
	body.innerText = data.body;
}

function getArticles(start = 0, limit = 10) {
	let xhr = new XMLHttpRequest();
	let url = `https://jsonplaceholder.typicode.com/posts?_start=${start}&_limit=${limit}`;

	xhr.open("get", url, true);
	xhr.send();
	xhr.onload = function () {
		if (this.status == 200) {
			let results = JSON.parse(this.response);
			outputArticles(results);
		}
	};
}

function outputArticles(results) {
	let output = "";
	let articleDiv = document.querySelector("div.articles");
	results.forEach(function (item) {
		output += `<div class="col-md-4">
        <div class="card m-1">
        <div class="card-body">
          <a href="#"><h5 class="title-link" data-id="${item.id}">${item.title}</h5></a>
          <p class="card-text">${item.body}</p>
          <a href="#" class="card-link">Card link</a>
          <a href="#" class="card-link">Another link</a>
        </div>
      </div>
      </div>`;
	});
	console.log(output);
	articleDiv.innerHTML = output;
}

function getPager() {
	// let xhr = new XMLHttpRequest();
	// let url = `https://jsonplaceholder.typicode.com/posts?_start=0&_limit=1000`;
	// xhr.open("get", url, true);
	// xhr.send();
	// xhr.onload = function() {
	//     if(this.status == 200) {
	//         let result = JSON.parse(this.response);
	//         outputPager(result);
	//     }
	// }
	outputPager(10);
}

function outputPager(result) {
	console.log(result.length);
	let numPages = 12;
	let previous = document.querySelector(".pagination li.previous");
	console.log(numPages);
	let output = "";
	for (let i = 0; i < numPages; i++) {
		let pageNum = i + 1;
		let active = "";
		if (i == 0) {
			active = "active";
		}
		output += `<li class="page-item ${active}"><a class="page-link pager-number" data-offset="${i}" href="#">${pageNum}</a></li>`;
	}
	previous.insertAdjacentHTML("afterend", output);
	console.log(output);
}
