
const mysql = require('mysql-await');
const { get } = require('prompt');

var connPool = mysql.createPool({
    connectionLimit: 5, // it's a shared resource, let's not go nuts.
    host: "localhost",// this will work
    user: "C4131F23U204",
    database: "C4131F23U204",
    password: "41666",
});

async function getCategories() {
    let retval = await connPool.awaitQuery("select distinct category from todo;")
    for (let i = 0; i < retval.length; i++){
        retval[i] = retval[i].category
    }
    return retval;
}

async function getTodoItems() {
    return await connPool.awaitQuery("select * from todo")
}

async function getTodoItemsByCategory(category) {
    
}

async function getTodoById(id) {
    return await connPool.awaitQuery("select * from todo where id=?", [id])
}

async function addTodo(newTodo) {
    
    
}

async function updateOrAddTodo(id, newTodo) {
    //https://dev.mysql.com/doc/refman/8.2/en/insert-on-duplicate.html
    
    
}

async function deleteTodo(id) {
    
    
}
getTodoItems().then(console.log);

// This is an important line of code! It's a key part of the javascript modules
// system and it defines what will actually be "public" from this file when 
// imported by others. This is a javascript object using the "shortcut" syntax
// we talked about in class.
module.exports = {getCategories, getTodoItems, getTodoItemsByCategory, getTodoById, addTodo, updateOrAddTodo, deleteTodo }