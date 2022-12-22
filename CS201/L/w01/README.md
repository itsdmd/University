# Week 01 #

## Table of Contents ##

- [Table of Contents](#table-of-contents)
- [Exercises](#exercises)
- [Notes](#notes)
	- [HTML](#html)
		- [Anchor's dead link](#anchors-dead-link)
		- [Input](#input)
			- [Text input](#text-input)
			- [Radio button](#radio-button)
		- [Form](#form)
	- [CSS](#css)



## Exercises ##

- [HTML](https://www.freecodecamp.org/learn/responsive-web-design/#basic-html-and-html5)
- [CSS](https://www.freecodecamp.org/learn/responsive-web-design/basic-css)



## Notes ##

### HTML ###

#### Anchor's dead link ####

Dead link is a type of **placeholder** for a link that is not yet available/defined. It is used to reserve a space for a link that will be available in the future.

```html
<a href="#">This is a dead link</a>
```

#### Input ####

```html
<input type="...">
```

List of of input types: [W3Schools](https://www.w3schools.com/html/html_form_input_types.asp)

The default value is `text`.

##### Text input #####

```html
<input type="text" placeholder="Enter your name">
```

`required`: make it a required input. If the user does not enter any value, the form will not be submitted.

```html
<input type="text" placeholder="Enter your name" required>
```

##### Radio button #####

```html
<label for="indoor">
	<input id="indoor" value="indoor" type="radio" name="place">Indoor
</label>

<label for="outdoor">
	<input id="outdoor" value="outdoor" type="radio" name="place" checked>Outdoor
</label>
```

- `label`'s `for` should be the same as `input`'s `id` to **bind** them together.
- `name`: A unique name for a **group** of related inputs.
	- Only 01 radio button in a group can be selected at a time.
- `value`: The value that will be **sent** to the server when the [form](#form) it belongs to is submitted.
	- The default value is `on`.
- `checked`: **pre-select** a radio button.

> _Personal reference:_ `for`, `id` and `value` attributes should have the value of the input label text in lowercase.

#### Form ####

Forms are used to collect user input. The user input is sent to a server for processing.

```html
<form action="servers-url">
	<input type="text" placeholder="Enter your name">
	<input type="email" placeholder="Enter your email" required>
	
	<p>Do you want to receive promotional content?</p>
	<label for="yes">
		<input id="yes" value="yes" type="radio" name="promo">Yes
	</label>
	<label for="no">
		<input id="no" value="no" type="radio" name="promo">No
	</label>
	<button type="submit">Submit</button>
</form>
```


### CSS ###

- Use **`:root { }`** to select all elements.
- Use **`[type='...'] { }`** to select a specific type of element. For example, `[type='text'] { }` will select all `input` elements with `type="text"`.