# HTML

- All HTML documents starts with `<!DOCTYPE html>`.

- Overall structure of an HTML document ([details](https://developer.mozilla.org/en-US/docs/Learn/HTML/Introduction_to_HTML/Document_and_website_structure#html_layout_elements_in_more_detail)):
	```mermaid
	graph TB
		html --- head
		html --- body
		
		head --- meta
		head --- title
		head --- link
		
		body --- header
		body --- main
			main --- article
				article -.- header
				article --- heading
					heading --- paragraph
						paragraph --- aside
							aside -.- span
						paragraph -.- span
					heading -.- span
			main --- section
				section -.- header
				section --- heading
			main -.- div
				div -.- header
				div --- heading
	```
	- `head` vs `header` vs `heading`:
    	- `head` contains the metadata of the page.
    	- `header` appears on the top of a section.
    	- `heading` is a part of the page's content, eg. `h1`, `h2`, etc.

- Example
	```html
	<!-- index.html -->

	<!DOCTYPE html>
	<html>
		<head>
			<title>Hello there!</title>
		</head>
		<body>
			<h1>Welcome!</h1>
			<p>This is an <span>example</span>.</p>
		</body>
	</html>
	```

## Block level
- Each block level element will start on a new line and span the full width available (100% of the parent element).
- Levels: `margin{ border[ padding( element ) ] }`
- To make an element to be a part of a block element, use `<span>` tag. [(?)](index.html?plain=1#L37)

# CSS

- **Basic structure**: `h1{color: red;}`
	- `h1` is the selector
	- `color` is the property
	- `red` is the value

- **Conventions**:
  - All lowercase
  - Separated by `-` if there are multiple words
  - Examples:
  	- `education`
  	- `content-block`

## `!important`
- The lower rules will override the ones before it (cascading).
- `!important` will override all other rules.
> :no_entry_sign: _**Should be avoided**_

## Implement to HTML

- **Inline**
	> :no_entry_sign: _**Should be avoided**_
	```html
	<h1 style="color: red;">
		Hello there!
	</h1>
	```
	
- **Head**
	> :warning: _**Not recommended**_
	```html
	...
	<head>
		<style>
			div#education { color: red; } 		/* id */
			div.content-block { color: blue; }	/* class */
		</style>
	</head>
	...
	```

- **External**
	> :heavy_check_mark: _**Recommended**_
	- Create a new `.css` file
    	- _**Personal reference**_: All the `.css` files should be inside a folder named `styles`. If there are multiple file types used for styling, each types should be in their own folder.
	- Put all the CSS code in the file.
	- Link the CSS file to the HTML file:
		```html
		<head>
			<link rel="stylesheet" href="styles/style.css">
		</head>
		```