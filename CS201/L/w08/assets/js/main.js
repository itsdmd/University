console.log("async example loading");

/* Select elements  */
let searchInput = document.querySelector("input");
let searchBtn = document.querySelector("button");
let alertDiv = document.querySelector(".alert");
let createForm = document.querySelector("form/create-post");

/* Event listeners  */

searchBtn.addEventListener("click", function () {
	let searchVal = searchInput.value;
	console.log(searchVal);
	searchApi(searchVal);
});

createForm.addEventListener("submit", (e) => {
	e.preventDefault();
	let title = document.querySelector("#title").value;
	let body = document.querySelector("#body").value;
	let userId = document.querySelector("#userId").value;
	let post = { title, body, userId };
	console.log(post);
	createPost(post);
});

startBlog();

async function startBlog() {
	let posts = await getPosts();
	let users = await getUsers();

	let results = await combineArray(posts, users);
	console.log(results);
	storePosts(results);
	outputPosts(12, results);
}

function storePosts(arr) {
	let jsonData = JSON.stringify(arr);
	localStorage.setItem("posts", jsonData);
}

function fetchPostsData() {
	let jsonData = localStorage.getItem("posts");
	let posts = JSON.parse(jsonData);
	console.log(posts);
	return posts;
}

function outputPosts(num = 12, arr) {
	let output = "";
	for (let i = 0; i < num; i++) {
		output += `<div class="col-md-4">
                    <div class="card p-3">
                    <img src="https://picsum.photos/100/100">
                    <a href="post/${arr[i].id}" data-post-id="${arr[i].id}">
                        <h4> ${arr[i].title}</h4></a>
                        <p> ${arr[i].body}</p>
                        </div></div>`;
	}
	document.querySelector(".search-output").innerHTML = output;
}

async function searchApi(val) {
	let posts = await getPosts();
	let filteredPosts = posts.filter((post) => {
		if (post.title.includes(val) || post.body.includes(val)) {
			return post;
		}
	});
	console.log(filteredPosts);
	let numArticles = filteredPosts.length;
	alertDiv.textContent = `${numArticles} articles were found!`;
	alertDiv.classList.add("show");
	let users = await getUsers();
	let combinedArray = await combineArray(filteredPosts, users);
	console.log(combinedArray);
	outputSearchResults(combinedArray);
}
