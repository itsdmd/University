// Linked to: T/midterm/index.html

/* ---------------------------------- */
/*              Catalogue             */
/* ---------------------------------- */

/* ---------- Catalogue tab --------- */

let currentTab = 0;
let ctlTab = document.querySelectorAll('.ctl-tab');

// Set first tab to be selected
ctlTab[currentTab].classList.add('is-selected');

// Add EL to each button
ctlTab.forEach(button => {
	  button.addEventListener('click', () => {
		// Remove all current is-selected classes
		ctlTab.forEach(button => {
			button.classList.remove('is-selected');
		});
		
		// Add is-selected class to clicked button
		button.classList.add('is-selected');
		
		// Get the index of the clicked button
		currentTab = Array.from(ctlTab).indexOf(button);
	});
});

/* -------- Catalogue content ------- */

let contentArray_0 = ["Healthcare Products & Solutions", "Industrial Metrology", "Optical Processing Machine", "Encoders", "Industrial Lenses", "Material Processing Solutions & Robot Vision", "Optical Components & Materials", "Surveying Instruments", "FPD Lithography Systems", "Semiconductor Systems", "MEMS Steppers & Both Side Measurement System"]
