console.log("hello world");

/* Declare vars: get name, age, gender, major  */
let submitBtn = document.querySelector("form button");
let classmateName = document.querySelector("form input#classmate-name");
let age = document.querySelector("form input#age");
let genderMale = document.querySelector("form input.male");
let genderFemale = document.querySelector("form input.female");
let major = document.querySelector("form select#major");
let tbody = document.querySelector("table tbody");
/* Event Listeners */

submitBtn.addEventListener("click", function(event) {
    event.preventDefault();
    console.log("submit clicked!");
    let nameVal = classmateName.value; 
    let ageVal = age.value;
    let majorVal = major.value;
    let genderVal = "NA"
    if(genderMale.checked) {
        genderVal = "M";
    } else if (genderFemale.checked) {
        genderVal = "F"
    }
    createClassmate(nameVal, ageVal, majorVal, genderVal);
});

function createClassmate(nameVal, ageVal, majorVal, genderVal) {
    console.log("create function called!");
    let output = `
        <tr>
            <td>${nameVal}</td>
            <td>${ageVal}</td>
            <td>${genderVal}</td>
            <td>${majorVal}</td>
        </tr>
    `;
    console.log(output);
    tbody.insertAdjacentHTML("beforeend", output);
}
