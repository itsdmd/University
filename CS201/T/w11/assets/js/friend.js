let outputDiv = document.querySelector("div.output");

outputDiv.addEventListener("click", (event) => {
	event.preventDefault();
	let targ = event.target;
	if (targ.classList.contains("btn-outline-danger")) {
		removeUser(targ.getAttribute("data-username"));
	}
});

outputFriends();

function removeUser(val) {
	let friendsList = JSON.parse(getFriendList());
	console.log(friendsList);
	let filteredFriends = friendsList.filter((friend) => {
		if (friend.username.includes(val) === false) {
			return friend;
		}
	});
	console.log(filteredFriends);
	localStorage.setItem("friendList", JSON.stringify(filteredFriends));
	outputFriends();
}

function getFriendList() {
	if (localStorage.getItem("friendList") == null) {
		localStorage.setItem("friendList", "[]");
	}
	let friendList = localStorage.getItem("friendList");
	return friendList;
}

function outputFriends() {
	let friends = JSON.parse(getFriendList());
	let output = "";
	friends.forEach((friend) => {
		output += `
            <div class="col-md-4">
            <div class="card m-2">
                <img class="card-img-top" src="${friend.userimg}" alt="Card image cap">
                <div class="card-body">
                    <h5 class="card-title">${friend.username}</h5>
                    <button class="btn btn-outline-danger btn-block" data-username="${friend.username}"> Delete</button>
                </div>
                </div>
            </div>
        `;
	});
	document.querySelector(".output").innerHTML = output;
}
