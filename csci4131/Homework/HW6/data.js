// this package behaves just like the mysql one, but uses async await instead of callbacks.
const mysql = require(`mysql-await`); // npm install mysql-await

// first -- I want a connection pool: https://www.npmjs.com/package/mysql#pooling-connections
// this is used a bit differently, but I think it's just better -- especially if server is doing heavy work.
var connPool = mysql.createPool({
  connectionLimit: 5, // it's a shared resource, let's not go nuts.
  host: "localhost",// this will work
  user: "C4131F23U204",
  database: "C4131F23U204",
  password: "41666",
});

// later you can use connPool.awaitQuery(query, data) -- it will return a promise for the query results.

async function addContact(data){
    // you CAN change the parameters for this function. please do not change the parameters for any other function in this file.
    await connPool.awaitQuery("insert into Contacts values (?, ?, ?, ?, ?)");
}

async function deleteContact(id){
  await connPool.awaitQuery("delete from Contacts where id = ?", id);
}

async function getContacts() {
  let retval = await connPool.awaitQuery("select * from Contacts;")
  return retval;
}

async function addSale(message) {
    await connPool.awaitQuery("insert into Sale set ?", message);
}

async function endSale() {
  await connPool.awaitQuery("update Sale SaleEnd = CURRENT_TIMESTAMP Where Active = true");
}

async function getRecentSales() {
  let retval = await connPool.awaitQuery("Select * from Sale");
  return retval;
}

module.exports = {addContact, getContacts, deleteContact, addSale, endSale, getRecentSales}