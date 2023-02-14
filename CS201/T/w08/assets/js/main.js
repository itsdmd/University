console.log("main.js loaded");

/* ---------- querySelector --------- */
let qs_username = document.querySelector(".username");
let qs_contact = document.querySelector(".contact");
let qs_userImg = document.querySelector(".user-img");
let qs_nextUserBtn = document.querySelector(".next-user-btn");

/* --------- eventListeners --------- */
// Fetch on page loaded
window.addEventListener("load", function () {
	console.log("window loaded");
	fetchNewUser();
});

// EL for next-user-btn
qs_nextUserBtn.addEventListener("click", function () {
	console.log("next-user-btn clicked");
	fetchNewUser();
});

/* ---------- functions ---------- */
function fetchNewUser() {
	let url = "https://randomuser.me/api/";

	// XMLHttpRequest
	let xhr_newUser = new XMLHttpRequest();
	xhr_newUser.open("GET", url);
	xhr_newUser.send();

	xhr_newUser.onload = function () {
		if (this.status == 200) {
			let data = JSON.parse(this.response);
			console.log(data);

			updatePageContent(data.results[0]);
		} else {
			console.log("Error: " + this.status);
		}
	};
}

function updatePageContent(data) {
	qs_username.innerHTML = "<i>" + data.name.title + ".</i> <b>" + data.name.first + " " + data.name.last + "</b>";
	qs_contact.textContent = "Email: " + data.email;
	qs_userImg.setAttribute("src", data.picture.medium);
}
