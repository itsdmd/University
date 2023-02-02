// Linked to: T/midterm/index.html

console.log("main.js loaded");

/* ---------------------------------- */
/*              Catalogue             */
/* ---------------------------------- */

/* -------- Catalogue content ------- */

let catalogueContentTitle = [["Healthcare Products & Solutions", "Industrial Metrology", "Optical Processing Machine", "Encoders", "Industrial Lenses", "Material Processing Solutions & Robot Vision", "Optical Components & Materials", "Surveying Instruments", "FPD Lithography Systems", "Semiconductor Systems", "MEMS Steppers & Both Side Measurement System"], ["Digital SLR Cameras", "Mirrorless Cameras", "Compact Digital Cameras", "NIKKOR Lenses", "Speedlights", "Software", "Sport Optics", "Laser Rangefinder", "Accessories", "Ophthalmic Lenses"]];

let catalogueContentUrl = [["https://www.healthcare.nikon.com/en/", "https://industry.nikon.com/en-aom/", "https://www.nikon.com/products/optical-processing-machine/", "https://www.nikon.com/products/encoder/", "https://www.nikon.com/products/industrial-lenses/", "https://ngpd.nikon.com/en/", "https://www.nikon.com/products/components/", "https://www.nikon-trimble.co.jp/english/", "https://www.nikon.com/products/fpd/lineup/", "https://www.nikon.com/products/semi/lineup/", "https://www.nikonprecision.com/products-and-technology/steppers-and-metrology-solutions-for-mems-markets/"], ["https://imaging.nikon.com/lineup/dslr/", "https://imaging.nikon.com/lineup/mirrorless/", "https://imaging.nikon.com/lineup/compact/", "https://imaging.nikon.com/lineup/lens/", "https://imaging.nikon.com/lineup/speedlight/", "https://imaging.nikon.com/lineup/software/", "https://imaging.nikon.com/lineup/sportoptics/", "https://imaging.nikon.com/lineup/sportoptics/laser/", "https://imaging.nikon.com/lineup/accessory/", "https://www.nikonlenswear.com/"]];

const catalogueContentImgUrlPrefix = "https://www.nikon.com/img/index/pic_product_";
const catalogueContentImgUrlPrefix_tab = ["corp", "indi"];
const catalogueContentImgUrlSuffix = ".png";

function generatecatalogueContentItem(tabIndex, index) {
	let contentItem = document.createElement('a');
	contentItem.classList.add('catalogue-content-item');
	contentItem.href = catalogueContentUrl[tabIndex][index];
	
	let contentImg = document.createElement('img');
	
	let imgIndex = index;
	// Weird index exceptions for tab 0's items' img
	if (tabIndex === 0) {
		index += 1;
		
		switch (index) {
			case 6: imgIndex = 13; break;
			case 7: imgIndex = 8; break;
			case 8: imgIndex = 9; break;
			case 9: imgIndex = 11; break;
			case 10: imgIndex = 12; break;
			case 11: imgIndex = 6; break;
		}
		
		index -= 1;
	}
	
	contentImg.src = catalogueContentImgUrlPrefix + catalogueContentImgUrlPrefix_tab[tabIndex] + "_" + ((imgIndex + 1) < 10 ? "0" + String(imgIndex + 1) : String(imgIndex + 1)) + catalogueContentImgUrlSuffix;
	contentItem.appendChild(contentImg);
	
	let contentTitle = document.createElement('h3');
	contentTitle.innerText = catalogueContentTitle[tabIndex][index];
	contentItem.appendChild(contentTitle);
	
	return contentItem;
}

function generatecatalogueContent() {
	let catalogueContent = document.querySelector('.content-grid');
	
	// Remove all current content items
	while (catalogueContent.firstChild) {
		catalogueContent.removeChild(catalogueContent.firstChild);
	}
	
	for (let i = 0; i < catalogueContentTitle[catalogueCurrentTab].length; i++) {
		catalogueContent.appendChild(generatecatalogueContentItem(catalogueCurrentTab, i));
		console.log("catalogueContentItem " + i + " generated");
	}
}

/* ---------- Catalogue tab --------- */

let catalogueCurrentTab = 0;
let catalogueTab = document.querySelectorAll('.catalogue-tab');

// Set first tab to be selected
catalogueTab[catalogueCurrentTab].classList.add('is-selected');
generatecatalogueContent();

// Add EL to each button
catalogueTab.forEach(button => {
	  button.addEventListener('click', () => {
		// Remove all current is-selected classes
		catalogueTab.forEach(button => {
			button.classList.remove('is-selected');
		});
		
		// Add is-selected class to clicked button
		button.classList.add('is-selected');
		
		// Get the index of the clicked button
		catalogueCurrentTab = Array.from(catalogueTab).indexOf(button);
		
		// Generate content
		generatecatalogueContent();
	});
});
