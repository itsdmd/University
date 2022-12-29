# Week 02

## Table of Contents

- [Table of Contents](#table-of-contents)
- [CSS](#css)
	- [Positioning](#positioning)
		- [`position`](#position)
		- [Flexbox](#flexbox)
		- [Center using margin](#center-using-margin)
	- [:memo: Notes from Lab](#memo-notes-from-lab)
		- [Parralax effect for image](#parralax-effect-for-image)
		- [Units](#units)
		- [Grid](#grid)

## CSS

### Positioning

#### `position`

- Basic/default, position elements based on relativity.

> Source: [W3Schools](https://www.w3schools.com/css/css_positioning.asp)

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

#### Flexbox

- More flexible	way to position elements using box model.

> See the [cheatsheet](../doc/CSS_Cheatsheet_2.jpg) for more details.

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

:no_entry_sign: _**Not reccomended.**_ `flex` should be used whenever possible.

```css
main {
	width: 80%;
	margin: auto;
}
```

### :memo: Notes from Lab

#### Parralax effect

- Use `background-attachment: fixed;` to make the background image fixed when scrolling.

#### Units

> Source: [W3Schools](https://www.w3schools.com/cssref/css_units.php)

Some basic units:

- `%`: Relative to the **parent** element.
- `px`: 1px = **1/96in**. 1in = 2.54cm.
- `em`: Relative to the **font-size** of the element.
- `rem`: Relative to the **font-size** of the **root** element.
- `vh`: Relative to 1% of the **viewport's height**.

#### Grid

- To use grid template, the parent element must have `display: grid;` set.
- Set the number and size of columns using `grid-template-columns`.
	- `fr`: Fractional unit. Relative to the **available space**.
	- Example: `grid-template-columns: 1fr 2fr 1fr;` will create 3 columns, with the first and last column having the same size, and the middle column twice as big.
		- `1fr` = `1/3`, `2fr` = `2/3`.
	- `auto`: Automatically set the size of the column based on the content.
	- [Usage](../../L/w02/styles/style-lec.css?plain=1#L96)
