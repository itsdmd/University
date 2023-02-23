console.log("login.js loaded");

let minUsernameLength = 5;
let maxUsernameLength = 20;
let usernameLengthErrorText = "Username must be between 5 and 20 characters long";
let usernameExistsErrorText = "Username is already taken";

let username = document.querySelector("#username");
let email = document.querySelector("#email");
let pwd1 = document.querySelector("#pwd1");
let pwd2 = document.querySelector("#pwd2");
let signupForm = document.querySelector("form");
let usernameSpinner = document.querySelector(".username img");
let usernameError = document.querySelector(".username-error");

username.addEventListener("focusout", () => {
	usernameSpinner.classList.add("show");
	searchUserName(username.value);
});

username.addEventListener("keyup", () => {
	setTimeout(() => {
		searchUserName(username.value);
	}, 1000);
});

function searchUserName(toSearch) {
	console.log("searchUserName: " + toSearch);
	let url = "https://dummyjson.com/users";

	usernameSpinner.classList.add("show");

	if (toSearch === "" || toSearch === null || toSearch.length < minUsernameLength || toSearch.length > maxUsernameLength) {
		usernameSpinner.classList.remove("show");

		username.classList.add("border-danger");

		usernameError.innerHTML = usernameLengthErrorText;
		usernameError.classList.add("show");
		return;
	}

	username.classList.remove("border-danger");

	let xhr = new XMLHttpRequest();
	xhr.open("GET", url, true);
	xhr.send();
	xhr.onload = function () {
		if (this.status === 200) {
			let results = JSON.parse(this.responseText);
			console.log(results);

			let existingFirstName = results.users.map((item) => {
				return item.firstName.toLowerCase();
			});
			console.log(existingFirstName);

			if (existingFirstName.indexOf(toSearch.toLowerCase()) !== -1) {
				console.log("Username is taken");
				username.classList.add("border-danger");

				usernameError.innerHTML = usernameExistsErrorText;
				usernameError.classList.add("show");

				usernameSpinner.classList.remove("show");
			} else {
				console.log("Username is available");
				username.classList.add("border-success");

				usernameError.classList.remove("show");

				usernameSpinner.classList.remove("show");
			}
		} else {
			console.log("Error fetching data from ", url);
		}

		usernameSpinner.classList.remove("show");
	};
}
