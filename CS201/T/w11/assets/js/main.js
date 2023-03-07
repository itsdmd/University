console.log("main.js loaded");

let userName = document.querySelector(".user-name");
let userDetails = document.querySelector(".user-details");
let userGender = document.querySelector(".user-gender");

let addBtn = document.querySelector(".btn.add");
let rejectBtn = document.querySelector(".btn.reject");

addBtn.addEventListener("click", function (e) {
	e.preventDefault();
	console.log("addBtn clicked");

	addFriend();
	fetchUser();
});

function addFriend() {
	// Add current user to friends list in localStorage
}

function retrieveFriends() {
	// Retrieve the friends list from localStorage
}

async function fetchUser() {
	// Fetch another user using the API from randomuser.me
}

function updateInfo() {
	// Update the user info in the DOM
}
