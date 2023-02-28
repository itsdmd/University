# Week 10

## Table of Contents

## Fetch API

- Interface for accessing and manipulating parts of the HTTP pipeline, such as _requests and responses_.
- Help fetch resources **asynchronously** across the network.

```js
fetch("http://jsonplaceholder.typicode.com/users/")
  .then(response => response.json())	// parse response as JSON
  .then(data => console.log(data))		// log data to console
  .catch(err => console.log(err));		// log error to console
```

- To assign the value of the response to a variable, use `await`.

```js
const response = await fetch("http://jsonplaceholder.typicode.com/users/");

const data = await response.json();
console.log(data);
```

> `await` can only be used inside an `async` function.
