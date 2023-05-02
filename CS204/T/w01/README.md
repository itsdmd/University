# Intro to Server Side Scripting with PHP + MySQL

## Install stack (LAMP)

- [Installation guide](https://www.digitalocean.com/community/tutorials/how-to-install-lamp-linux-apache-mysql-php-on-fedora)
- The core of the web stack involves handling incoming requests using Apache, processing & interact with database using PHP and generating responses.

## PHP

### Variable scope
- `local`: declared inside a function, only accessible within the function
- `global`: declared outside a function, accessible anywhere in the script
- `static`: declared inside a function, accessible within the function, but retain its value after the function is executed

```php
<?php
    $x = 5; // global scope

    function myTest() {
        $y = 10; // local scope
        static $z = 0; // static scope
        echo "<p>Variable x inside function is: $x</p>"; // x is 5
        echo "<p>Variable y inside function is: $y</p>"; // y is 10
        echo "<p>Variable z inside function is: $z</p>"; // z is 0
    }

    myTest();

    echo "<p>Variable x outside function is: $x</p>"; // x is still 5
    echo "<p>Variable y outside function is: $y</p>"; // y is undefined
    echo "<p>Variable z outside function is: $z</p>"; // z is still 0
?>
```

### Arrays

#### Numerics

```php
<?php
    $cars = array("Volvo", "BMW", "Toyota");
    echo "I like " . $cars[0] . ", " . $cars[1] . " and " . $cars[2] . ".";
?>
```

#### Associative

```php
<?php
    $age = array("Peter"=>"35", "Ben"=>"37", "Joe"=>"43");
    echo "Peter is " . $age['Peter'] . " years old.";
    
    $people = [
        [
            "name" => "Peter",
            "age" => 35
        ],
        [
            "name" => "Ben",
            "age" => 37
        ]
    ]
    foreach ($people as $person) {
        echo "Name: " . $person["name"] . ", Age: " . $person["age"];
    }
?>
```

### Superglobals

- Superglobals are built-in variables that are always available in all scopes
    - **`$_ENV`**: environment variables
    - **`$_GET`**: HTTP GET variables
    - **`$_POST`**: HTTP POST variables
    - **`$_COOKIE`**: HTTP Cookies
    - **`$_SESSION`**: Session variables
    - **`$_FILES`**: File upload variables
    - **`$_SERVER`**: Server information
    - **`$_REQUEST`**: HTTP Request variables
    - **`$GLOBALS`**: Global variables
