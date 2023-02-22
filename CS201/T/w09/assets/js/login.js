console.log("login.js loaded");

/* Script Global Variables  */
let theForm = document.querySelector("form");
let username = document.querySelector("#username");
let email = document.querySelector("#email");
let pw1 = document.querySelector("#pw1");
let pw2 = document.querySelector("#pw2");

/* Event Listeners*/
theForm.addEventListener("submit", (event) => {
	checkUsername(username.value);
	checkEmail(email.value);
	checkPw1(pw1.value);
	checkPw2(pw1.value, pw2.value);
	let errors = document.querySelectorAll(".error");
	if (errors.length == 0) {
		alert("form accepted");
	} else {
		alert("form has errors!");
	}
	event.preventDefault();
});
username.addEventListener("focusout", () => {
	checkUsername(username.value);
});
email.addEventListener("focusout", () => {
	checkEmail(email.value);
});
pw1.addEventListener("focusout", () => {
	checkPw1(pw1.value);
});
pw2.addEventListener("focusout", () => {
	checkPw2(pw1.value, pw2.value);
});

/* Functions */

function checkEmail(val) {
	let error = false;
	if (val.includes("@") != true) {
		error = true;
	}
	if (error == true) {
		addErr(".email-error");
	} else {
		removeErr(".email-error");
	}
}
function checkPw1(val) {
	let error = false;
	if (val.length < 5 || val.length > 20) {
		error = true;
	}
	if (error == true) {
		addErr(".pw1-error");
	} else {
		removeErr(".pw1-error");
	}
}

function checkPw2(val1, val2) {
	let error = false;
	if (val1 != val2) {
		error = true;
	}
	if (error == true) {
		addErr(".pw2-error");
	} else {
		removeErr(".pw2-error");
	}
}
function checkUsername(val) {
	let error = false;
	console.log("checking username " + val);
	if (val.length < 5 || val.length > 20) {
		error = true;
	}
	if (error == true) {
		addErr(".username-error");
	} else {
		removeErr(".username-error");
	}
	console.log("error status = " + error);
}

function addErr(className) {
	document.querySelector(className).classList.add("error");
}

function removeErr(className) {
	document.querySelector(className).classList.remove("error");
}
