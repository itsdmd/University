console.log("main.js loaded");

const FETCH_URL = "https://api.binance.com/api/v3/ticker/price?symbol=";

let g_prevPrice = 0;

// - Tasks:
// + Fetch currency pair data from Binance API
// + Output the current price (compared to previous)
// + Give some indication if the price went up down
// + Have a select options list to allow users to pick other currency pairs

// fetchCurrencyPairData("BTCUSDT");

function updatePrevPrice(price) {
	g_prevPrice = price;
}

function comparePriceDiff(price) {
	if (price > g_prevPrice) {
		return "up";
	} else if (price < g_prevPrice) {
		return "down";
	} else {
		return "equal";
	}
}

async function fetchCurrencyPairData(symbol) {
	await fetch(FETCH_URL + symbol)
		.then((response) => response.json())
		.then((data) => {
			console.log(data);
			return data;
		})
		.catch((error) => {
			console.log(error);
		});
}
