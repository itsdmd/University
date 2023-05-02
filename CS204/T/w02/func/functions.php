<?php
echo "hello world";
$msg = [];
if(!file_exists("todos.json")) {
    $todos = [];
    $json = json_encode($todos);
    file_put_contents("todos.json", $json);
} else {
    $todos = getTodos();
}

if(isset($_POST['delete'])) {
    var_dump($_POST);
    deleteTodo($_POST['delete'], $todos);
}

if(isset($_POST['status'])) {
    updateStatus($_POST['status'], $todos);
}

$todos = sortTodos($todos);

if(isset($_POST['update'])) {
    updateTodo($todos, $_POST['update'], $_POST['id']);
}

function updateTodo(&$todos, $text, $id) {
    $todos[$id]['todo'] = $text;
    storeTodos($todos);
}

function sortTodos($todos) {
    $new_todos = [];
    foreach ($todos as $todo) {
        if($todo['status']) {
            array_push($new_todos, $todo);
        } else {
            array_unshift($new_todos, $todo);
        }
    }
    for ($i=0; $i < count($new_todos); $i++) { 
        $new_todos[$i]['id'] = $i;
    }
   return $new_todos;
}

function updateStatus($index, &$todos) {
    $status = true;
    if($todos[$index]['status'] == true) {
        $status = false;
    }
    $todos[$index]['status'] = $status;
    storeTodos($todos);
}

function deleteTodo($index, &$todos) {
    // remove the array item using the 'id' as index
    array_splice($todos, $index, 1);
    // reindex before storing
    for ($i=0; $i < count($todos); $i++) { 
        $todos[$i]['id'] = $i;
    }
    // store in file to persist changes
    storeTodos($todos);
    $msg = ["text" => "item deleted", "class" => "danger"];
}

if(isset($_POST["todo"])) {
    $new_todo = ["id" => 0, "todo" => $_POST['todo'], "status" => false];
    array_push($todos, $new_todo);
    for ($i=0; $i < count($todos); $i++) { 
        $todos[$i]['id'] = $i;
    }
    storeTodos($todos);
}

function storeTodos($todos) {
    // convert to json
    $json = json_encode($todos, JSON_PRETTY_PRINT);
    // store in file
    file_put_contents("todos.json", $json);
}

function getTodos() {
 // access the todos.json
 $data = file_get_contents("todos.json");
 // convert json to assoc array
 $todos = json_decode($data, true);
 // return array
 return $todos;
};


?>