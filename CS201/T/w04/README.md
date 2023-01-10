# Week 04

## Table of Contents

- [Table of Contents](#table-of-contents)
- [Bootstrap 4](#bootstrap-4)
	- [Container](#container)
	- [Rows](#rows)
	- [Columns](#columns)
- [HTML Forms](#html-forms)

## Bootstrap 4

> Official documentation: [getbootstrap.com](https://getbootstrap.com/docs/4.6)

The general structure of a Bootstrap grid is: **`Container (Row [Column] )`**.

```html
<div class="container">
  <div class="row">
	<div class="col-6">...</div>
	<div class="col-6">...</div>
  </div>
</div>
```

### Container

The container is the most basic layout element in Bootstrap and is required when using the default grid system. It provides a responsive fixed width container.

```html
<div class="container">...</div>
```

By default, the container has margins on the left and right sides. To remove the margins, use the class `container-fluid` instead. However, the padding still exists. Remove this by adding the class `p-0`.

### Rows

A row must be placed within a container. It provides a way to horizontally align columns. It also provides negative margins on the left and right sides of the container to offset the padding on the columns.

```html
<div class="container">
  <div class="row">...</div>
</div>
```

By default, a row is a flex component with wrap enabled.

### Columns

Each row consists of **12 columns**. The total width of the columns is 100% of the container. To indicate that an element will have a certain number of columns, you need to add the class `col-` and the number of columns.

For example, if you want to have an element that occupies 6 columns (which means <sup>6</sup>/<sub>12</sub> = <sup>1</sup>/<sub>2</sub> of the screen), you need to use the class `col-6`.

```html
<div class="row">
	<div class="col-6">1/2 of the left side</div>
	<div class="col-6">1/2 of the right side</div>
</div>
```

To change the number of columns that an element take for different screen sizes, add additional classes. For example, if you want to have 6 columns for small screens, 4 columns for medium screens and 3 columns for large screens:

```html
<div class="col-sm-6 col-md-4 col-lg-3">
	Content
</div>
```

Breakpoints:

Class | Screen size
:---: | ---
`xs` | Default
`sm` | > 576px
`md` | > 768px
`lg` | > 992px
`xl` | > 1200px

## HTML Forms


