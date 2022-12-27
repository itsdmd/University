# Week 02

## Table of Contents

- [Table of Contents](#table-of-contents)
- [CSS](#css)
	- [Positioning](#positioning)
		- [`position`](#position)
		- [`flex`](#flex)
		- [Center using margin](#center-using-margin)

## CSS

### Positioning

#### `position`

> [W3Schools](https://www.w3schools.com/css/css_positioning.asp)

- `static`: Default. Elements render in order as they appear in the source code.
	- Not affected by the `top`, `bottom`, `left`, and `right` properties.
- `relative`: Relative to its **normal position**.
	- _**Simplified**_: Offset.
	- Other elements will not fit into any gap left by the element.
- `fixed`: Relative to the **viewport**. [(Usage)](styles/style.css?plain=1#L16)
	- Won't be moved when page being scrolled.
- `absolute`: Relative to the **nearest positioned** ancestor. [(Usage)](styles/style.css?plain=1#L30)
	- If it has no positioned ancestors, it uses the document body, and moves along with page scrolling.
	- **Can overlap** other elements.
- `sticky`: Position based on the user's **scroll position**.
	- Have 2 states: `relative` and `fixed`.
		- `relative` when the element is within (the offset in) the viewport.
		- `fixed` is vice versa to `relative`, make it stick in place.
	- _**Simplified**_: It's a `relative` within the viewport, and `fixed` outside of it.

#### `flex`

> See the [cheatsheet](../doc/CSS_Cheatsheet_2.jpg) for more information.

- Center the element horizontally. [(Usage)](styles/style.css?plain=1#L58)

	```css
	main {
		display: flex;
		justify-content: center;
	}
	```

- `display` will also be enable `flex` context for all of the element's **direct** children. [(Usage)](styles/style.css?plain=1#L81)

	```css
	#parent {
		display: flex;
	}

	.child {
		margin: 25px;
		padding: 15px;
	}
	```

#### Center using margin

[(Usage)](styles/style.css?plain=1#L76)

_**Not reccomended.**_ Should use `flex` whenever possible.


```css
main {
	width: 80%;
	margin: auto;
}
```
