# Week 03

## PHP Filtering

- `filter_var(string, FILTER)` function both validate and sanitize data.
    - _Data sanitization_ means cleaning up data by removing invalid characters and preventing code injection.
    - [List of filters](https://www.php.net/manual/en/filter.filters.php)

```php
<?php
// Sample data
$str = "<h1>Hello World!</h1>";
// Remove HTML tags
$newstr = filter_var($str, FILTER_SANITIZE_STRING);
echo $newstr;    // Hello World!

// Validate integer
$int = 100;

if (!filter_var($int, FILTER_VALIDATE_INT) === false) {
  echo("Integer is valid");
} else {
  echo("Integer is not valid");
}
?>
```

- `htmlspecialchars(string)` function converts some predefined characters to HTML entities.
    - `&` (ampersand) becomes `&amp;`
    - `"` (double quote) becomes `&quot;`
    - `'` (single quote) becomes `&#039;`
    - `<` (less than) becomes `&lt;`
    - `>` (greater than) becomes `&gt;`

```php
<?php
$str = "<h1>Hello World!</h1>";

echo htmlspecialchars($str);    // &lt;h1&gt;Hello World!&lt;/h1&gt;
?>
```


## Password hashing

- `password_hash(string, algorithm)` function creates a password hash.
    - [List of algorithms](https://www.php.net/manual/en/function.password-hash.php)

```php
<?php
$password = "123456";

// Hashing algorithm
$hash = password_hash($password, PASSWORD_DEFAULT);
?>
```

- `password_verify(string, hash)` function verifies that a password matches a hash.
    - Returns `true` if the password and hash match, or `false` otherwise.

```php
<?php
$pwd_matched = password_verify($password, $hash);
?>
```

## PHP Sessions

- A session is a way to store information (in variables) to be used across multiple pages.
- Data is stored on the server, not in the user's computer.
- Stored in `$_SESSION` variable.

```php
<?php
// Start the session
session_start();

// Set session variables
$_SESSION["favcolor"] = "green";

// Access session variables
echo "Favorite color is " . $_SESSION["favcolor"] . ".<br>";

// Stop the session
session_destroy();
?>
```
