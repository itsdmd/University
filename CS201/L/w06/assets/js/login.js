console.log("login.js loaded");

let minUsernameLength = 5;
let maxUsernameLength = 20;
let minPasswordLength = 5;
let emailRequiredChars = ["@", "."];

let usernameLengthErrorText = "Username must be between 5 and 20 characters long";
let usernameExistsErrorText = "Username is already taken";

let username = document.querySelector("#username");
let email = document.querySelector("#email");
let pw1 = document.querySelector("#pw1");
let pw2 = document.querySelector("#pw2");
let signupForm = document.querySelector("form");
let submitBtn = document.querySelector("#submit-btn");
let usernameSpinner = document.querySelector(".username img");

let usernameError = document.querySelector(".username-error");
let emailError = document.querySelector(".email-error");
let pw1Error = document.querySelector(".pw1-error");
let pw2Error = document.querySelector(".pw2-error");

username.addEventListener("focusout", () => {
	usernameSpinner.classList.add("show");
	validateUsername(username.value);
	validateForm();
});

email.addEventListener("focusout", () => {
	validateEmail(email.value);
	validateForm();
});

pw1.addEventListener("focusout", () => {
	validatepw1(pw1.value);
	validateForm();
});

pw2.addEventListener("focusout", () => {
	validatepw2(pw2.value);
	validateForm();
});

function validateUsername(input) {
	console.log("searchUserName: " + input);
	let url = "https://dummyjson.com/users";

	usernameSpinner.classList.add("show");

	if (input === "" || input === null || input.length < minUsernameLength || input.length > maxUsernameLength) {
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

			if (existingFirstName.indexOf(input.toLowerCase()) !== -1) {
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

function validateEmail(input) {
	if (input === "" || input === null) {
		emailError.classList.add("show");
		email.classList.add("border-danger");
		email.classList.remove("border-success");
		return;
	}

	let valid = true;

	emailRequiredChars.forEach((char) => {
		if (input.indexOf(char) === -1) {
			valid = false;
		}
	});

	if (valid) {
		emailError.classList.remove("show");
		email.classList.remove("border-danger");
		email.classList.add("border-success");
	} else {
		emailError.classList.add("show");
		email.classList.add("border-danger");
		email.classList.remove("border-success");
	}
}

function validatepw1(input) {
	if (input === "" || input === null || input.length < minPasswordLength) {
		pw1Error.classList.add("show");
		pw1.classList.add("border-danger");
		pw1.classList.remove("border-success");
		return;
	}

	pw1Error.classList.remove("show");
	pw1.classList.remove("border-danger");
	pw1.classList.add("border-success");
}

function validatepw2(input) {
	if (input === "" || input === null || input != pw1.value) {
		pw2Error.classList.add("show");
		pw2.classList.add("border-danger");
		pw2.classList.remove("border-success");
		return;
	}

	pw2Error.classList.remove("show");
	pw2.classList.remove("border-danger");
	pw2.classList.add("border-success");
}

function validateForm() {
	let fields = document.querySelectorAll(".form-control");
	let valid = true;

	fields.forEach((field) => {
		if (field.classList.contains("border-danger")) {
			valid = false;
		}
	});

	if (valid) {
		// signupForm.submit();
		submitBtn.removeAttribute("disabled");
	} else {
		submitBtn.setAttribute("disabled", true);
	}
}
