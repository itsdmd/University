console.log("start");
getPager();
getArticles(0, 9);

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
        <div class="card" style="width: 18rem;">
        <div class="card-body">
          <h5 class="card-title">${item.title}</h5>
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
	let xhr = new XMLHttpRequest();
	let url = `https://jsonplaceholder.typicode.com/posts?_start=0&_limit=1000`;
	xhr.open("get", url, true);
	xhr.send();
	xhr.onload = function () {
		if (this.status == 200) {
			let result = JSON.parse(this.response);
			outputPager(result);
		}
	};
}

function outputPager(result) {
	console.log(result.length);
	let numPages = Math.ceil(result.length / 9);
	let previous = document.querySelector(".pagination li.previous");
	console.log(numPages);
	let output = "";
	for (let i = 0; i < numPages; i++) {
		let pageNum = i + 1;
		output += `<li class="page-item" data-offset="${i}"><a class="page-link" href="#">${pageNum}</a></li>`;
	}
	previous.insertAdjacentHTML("afterend", output);
	console.log(output);
}
