# Week 05

## Table of Contents

- [Table of Contents](#table-of-contents)
- [DOM](#dom)
- [JavaScript](#javascript)
	- [Basics](#basics)
		- [Traversing the DOM](#traversing-the-dom)
	- [Events](#events)
		- [Listen and catch events](#listen-and-catch-events)
			- [Inline](#inline)
			- [`on<event>` method](#onevent-method)
			- [`addEventListener()` method](#addeventlistener-method)


## DOM

- Shorthand for _Document Object Model_
- A programming interface for **web documents**
- Represents the document as nodes and objects
- Can be modified with a scripting language (such as JavaScript)

## JavaScript

- Object-oriented → access objects and methods using dot notation
- Interpreted → no compilation step

### Basics

- Link JavaScript file to HTML file using `<script>` tag
	> Always put JS file at the end of the `<body>` tag

```html
<script src="main.js"></script>
```

- Declare variable using `let` or `const`
	- JS is a _**dynamically** and **weakly**_ typed language ([MDN](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Data_structures#dynamic_and_weak_typing))
	- Variable's name should be in `camelCase`
	- List of variable types: [MDN](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Data_structures#primitive_values)

```js
let msg = "Hello there!";
const constStr = new String("String");
```

- Declare function using `function` keyword

```js
function sayHello() {
	console.log("Hello there!");
}
```

- Print pop-up message using `alert()`

```js
alert("What's up!");
```

- Select HTML elements using `querySelector(<...>)` or `querySelectorAll(<...>)`

```js
let h1 = document.querySelector("h1");	// Selects first <h1>
let p = document.querySelectorAll("p");	// Selects all <p>
let logoImg = document.querySelector("div.logo img");	// Selects first <img> inside <div.logo>

let nav = document.querySelector("nav");
let navItems = nav.querySelectorAll("li");	// Selects all li tags inside nav
```

> Alternatives: `getElementById()`, `getElementsByClassName()`, `getElementsByTagName()`. These will return an array of nodes.

- Get/Set attributes using `getAttribute(<...>)` and `setAttribute(<...>)`

```js
logoImg.getAttribute("src");
logoImg.setAttribute("alt", "Something descriptive");
```

#### Traversing the DOM

![DOM Traversing](../doc/DOM_Traversing.jpg)

### Events

- Events are actions or occurrences that happen which the system tells you about so you can respond to them in some way if desired

#### Listen and catch events

##### Inline

:no_entry_sign: _**Should be avoided**_

```html
<button onclick="alert('Hello there!')">Click me!</button>
```

##### `on<event>` method

:warning: _**Not recommended**_

```html
<button id="myBtn">Click me!</button>
<script>
	let btn = document.querySelector("#myBtn");
	
	btn.onclick = function() {
		alert("Hello there!");
	}
</script>
```

##### `addEventListener()` method

:heavy_check_mark: _**Recommended**_

```html
<button id="myBtn">Click me!</button>
<script>
	let btn = document.querySelector("#myBtn");
	
	btn.addEventListener("click", function() {
		alert("Hello there!");
	});
</script>
```
