console.log("main.js loaded");

/*  Global variables: current price/prev price/current pair/dom el   */
let pairEl = document.querySelector("p.pair");
let pairValEl = document.querySelector("p.pair-value");
let currentPrice = getCurrentPrice();
let alertDiv = document.querySelector("div.pair-alert");
let prevPrice;

/*  Event Listeners      */

/* app functions    */

/* getCurrentPrice(symbol = 'BTCUSDT') async fn, return the price data   */
updatePrices();

async function updatePrices() {
	prevPrice = currentPrice;
	currentPrice = await getCurrentPrice();
	pairEl.textContent = currentPrice.symbol;
	pairValEl.textContent = currentPrice.price;
	alertDiv.textContent = parseInt(currentPrice.price) - parseInt(prevPrice.price);
	if (currentPrice.price > prevPrice.price) {
		alertDiv.classList.add("alert-success");
		alertDiv.classList.remove("alert-danger");
	} else if (currentPrice.price < prevPrice.price) {
		alertDiv.classList.add("alert-danger");
		alertDiv.classList.remove("alert-success");
	} else {
		alertDiv.classList.add("alert-secondary");
		alertDiv.classList.remove("alert-danger");
		alertDiv.classList.remove("alert-success");
	}
}

async function getCurrentPrice(symbol = "BTCUSDT") {
	let url = "https://www.binance.com/api/v3/ticker/price?symbol=" + symbol;
	let result = await fetch(url)
		.then((res) => res.json())
		.then((data) => data);
	console.log(result);
	return result;
}
