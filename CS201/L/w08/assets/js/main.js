console.log("async example loading");

/* Select elements  */
let searchInput = document.querySelector("input");
let searchBtn = document.querySelector("button");
let alertDiv = document.querySelector(".alert");
let createForm = document.querySelector("form.create-post");

/* Event listeners  */
createForm.addEventListener("submit", (e) => {
    e.preventDefault();
    let postTitle = document.querySelector("input.post-title").value;
    let postBody = document.querySelector("textarea.post-body").value;
    console.log("create form submitted");
    console.log(postTitle + postBody);
    createPost(postTitle, postBody);
    document.querySelector(".create-close").click();
});

searchBtn.addEventListener("click", function() {
    let searchVal = searchInput.value;
    console.log(searchVal);
    searchApi(searchVal);
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
        output+= `<div class="col-md-4">
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
        if(post.title.includes(val) || post.body.includes(val)) {
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

function outputSearchResults(arr) {
    console.log(arr);
    let output = "<ul>";
    arr.forEach((item) => {
        output+= `<li>${item.title} | ${item.username} </li>`;
    });
    output+= "</ul>";
    document.querySelector(".search-output").innerHTML = output;
}

async function combineArray(articles, users) {
    let results = articles.map((post)=> {
        let username = users.filter((user) => {
            if(user.id == post.userId) {
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
    .then(res => res.json())
    .then(json => json);
    return posts;
}

async function getUsers() {
    let users = await fetch("https://jsonplaceholder.typicode.com/users")
    .then(res => res.json())
    .then(json => json);
    return users;
}