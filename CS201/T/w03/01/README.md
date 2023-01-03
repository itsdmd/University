# Week 03

## Table of Contents

- [Table of Contents](#table-of-contents)
- [Responsive Design](#responsive-design)
	- [Responsive vs Adaptive](#responsive-vs-adaptive)
	- [Media Queries](#media-queries)
	- [Layouts](#layouts)
		- [Flexbox](#flexbox)
- [Psuedo Classes](#psuedo-classes)


## Responsive Design

### Responsive vs Adaptive

- **Responsive**: Flexible, change with the container/context.
- **Adaptive**: Only change when a breakpoint is reached.

Both use [media queries](#media-queries) to trigger the change.

### Media Queries

Media queries is a CSS technique. They are used to change the style of the page based on the size of the viewport/container when a certain **breakpoint** value is reached.

```css
@media only screen and (max-width: 600px) {
  body {
	background-color: lightblue;
  }
}
```

`only` is a _media feature_ that specifies that the media query should only apply to the _media type_ `screen`.

`max-width` is a _media feature_ with a _breakpoint_ value of `600px`. It is used to set a minimum width for the _media type_. In this case, the media type is `screen`. The `body` element will have a light blue background color if the screen width is at most 600 pixels (meaning it won't be triggered when the viewport's width is greater than 600px).

### Layouts

- **Table**: Not responsive, not adaptive, antiquated.
- **Floats**: Out of favour.
- **CSS Flexbox**: Single direction layout. Simple, easy to use, responsive.
- **CSS Grid**: Two dimensional layout. More complex, but more powerful and flexible.

#### Flexbox

- `flex-direction`: Defines the direction of the flexbox's main axis.
	- Possible values: `row` (default), `row-reverse`, `column`, `column-reverse`
- `flex-wrap`: Whether the flexbox should placed its items on multiple lines or not.
	- Possible values: `nowrap` (default), `wrap`, `wrap-reverse`
- `justify-content`: Defines how the flexbox's items are aligned along the main axis. Similar to how text are aligned in a paragraph (left, center, etc.).
	- Possible values: `flex-start` (default), `flex-end`, `center`, `space-between`, `space-around`, `space-evenly`
- `align-items`: Aligns the flex container's lines within when there is extra space in the cross-axis, similar to how `justify-content` aligns individual items along the main-axis.
	- Possible values: `flex-start`, `flex-end`, `center`, `baseline`, `stretch` (default)
- `flex-basis`: Defines the initial size of the flexbox's items.
	- Possible values: `auto` (default), `length`, `percentage`
- `gap`: Defines the space between the flexbox's items.
	- Possible values: `length`, `percentage`, `auto`

## Psuedo Classes

A psuedo class is a keyword added to a selector that specifies a special state of the selected element(s).

A single colon (`:`) is used to specify a psuedo class. [Usage](styles/style.css?plain=1#L82).

```css
button:hover {
  background-color: red;
}
```

A double colon (`::`) is used to specify a psuedo element. [Usage](styles/style.css?plain=1#L86).

```css
p::first-line {
  color: red;
}
```
