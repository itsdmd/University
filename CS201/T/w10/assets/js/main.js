console.log("main.js loaded.");

const searchInput = document.querySelector(".search-input");
const searchBtn = document.querySelector(".search-btn");
const searchAlert = document.querySelector(".search-alert");

/* Event listeners  */

searchBtn.addEventListener("click", function () {
	let searchVal = searchInput.value;
	console.log("Keyword: ", searchVal);
	searchApi(searchVal);
});

async function searchApi(val) {
	let posts = await getPosts();
	let filteredPosts = posts.filter((post) => {
		if (post.title.includes(val) || post.body.includes(val)) {
			return post;
		}
	});

	console.log("Matches: ", filteredPosts);
	let numArticles = filteredPosts.length;
	searchAlert.textContent = `${numArticles} articles were found!`;
	searchAlert.classList.add("show");

	let users = await getUsers();
	let combinedArray = await combineArray(filteredPosts, users);

	outputSearchResult(combinedArray);
}

function outputSearchResult(res) {
	let output = "";
	res.forEach((post) => {
		output += `
			<div class="post">
				<h3>${post.title}</h3>
				<p>${post.body}</p>
				<p><b>Author:</b> ${post.username}</p>
			</div>
		`;
	});

	document.querySelector(".search-results").innerHTML = output;
}

async function combineArray(articles, users) {
	let results = articles.map((post) => {
		let username = users.filter((user) => {
			if (user.id == post.userId) {
				return user;
			}
		});
		post.username = username[0].name;
		return post;
	});
	return results;
}

async function getPosts() {
	let posts = await fetch("https://jsonplaceholder.typicode.com/posts")
		.then((res) => res.json())
		.then((json) => json);
	return posts;
}

async function getUsers() {
	let users = await fetch("https://jsonplaceholder.typicode.com/users")
		.then((res) => res.json())
		.then((json) => json);
	return users;
}

joinArrays();
async function joinArrays() {
	let users = await getUsers();
	let posts = await getPosts();

	let completePosts = posts.map((post) => {
		let postAuthors = users.filter((user) => {
			if (post.userId == user.id) {
				return user;
			}
		});
		post.username = postAuthors[0].name;
		return post;
	});
}
