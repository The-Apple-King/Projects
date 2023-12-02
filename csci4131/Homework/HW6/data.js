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

async function addContact(name, email, time, amount, distributor) {
  await connPool.awaitQuery("INSERT INTO ContactLog (name, email, time, amount, distributor) VALUES (?, ?, ?, ?, ?)", name, email, time, amount, distributor);
}

async function deleteContact(id){
  await connPool.awaitQuery("delete from ContactLog where id = ?", id);
}

async function getContacts() {
  let retval = await connPool.awaitQuery("select * from ContactLog;")
  return retval;
}

async function addSale(message) {
    await connPool.awaitQuery("insert into Sale set ?", message);
}

async function endSale() {
  await connPool.awaitQuery("update Sale SaleEnd = CURRENT_TIMESTAMP Where Active = true");
}

async function getRecentSales() {
  let retval = await connPool.awaitQuery("SELECT saleMessage from Sale ORDER BY startTime DESC LIMIT 3");
  return retval;
}

module.exports = {addContact, getContacts, deleteContact, addSale, endSale, getRecentSales}