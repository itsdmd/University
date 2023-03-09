console.log("main.js loaded");

let userImg = document.querySelector(".user-img");
let userName = document.querySelector(".user-name");
let userDetails = document.querySelector(".user-details");
console.log(userDetails);

let userGender = document.querySelector(".user-gender");

let acceptBtn = document.querySelector("button.accept");

let rejectBtn = document.querySelector("button.reject");

/* on start */
fetchNextUser();

/* Event Listeners */
acceptBtn.addEventListener("click", () => {
	addFriend();
	/* fetch another randomuser from api */
	fetchNextUser();
});

rejectBtn.addEventListener("click", fetchNextUser);

/* App functions  */

function addFriend() {
	let friendList = getFriendList();
	console.log(friendList);
	let currentUser = localStorage.getItem("currentUser");
	friendList = JSON.parse(friendList);
	currentUser = JSON.parse(currentUser);
	friendList.push(currentUser);
	storeFriendList(friendList);
}

function getFriendList() {
	if (localStorage.getItem("friendList") == null) {
		localStorage.setItem("friendList", "[]");
	}
	let friendList = localStorage.getItem("friendList");
	return friendList;
}

function storeFriendList(friendList) {
	localStorage.setItem("friendList", JSON.stringify(friendList));
}

async function fetchNextUser() {
	let nextUser = await fetch("https://randomuser.me/api")
		.then((res) => res.json())
		.then((data) => data);
	console.log(nextUser.results[0]);
	let userdata = nextUser.results[0];
	/* string template literal syntax use backtick `` ~ ${varname}*/
	let user = {
		username: `${userdata.name.title} ${userdata.name.first} ${userdata.name.last}`,
		userimg: userdata.picture.large,
		usergender: userdata.gender,
		userdetails: `Age: ${userdata.dob.age} | ${userdata.email}`,
	};
	renderUser(user);
	updateCurrentUser(user);
}

function updateCurrentUser(user) {
	localStorage.setItem("currentUser", JSON.stringify(user));
}

function renderUser(user) {
	userImg.setAttribute("src", user.userimg);
	userName.textContent = user.username;
	userDetails.textContent = user.userdetails;
	userGender.textContent = user.usergender;
}
