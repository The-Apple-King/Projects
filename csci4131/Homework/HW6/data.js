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

async function addContact(data) {
  const query = "INSERT INTO Contact (name, email, time, amount, distributor) VALUES (?, ?, ?, ?, ?)";
  await connPool.awaitQuery(query, data);
}


async function deleteContact(id){
  await connPool.awaitQuery("delete from Contact where id = ?", id);
}

async function getContacts() {
  let retval = await connPool.awaitQuery("select * from Contact;")
  return retval;
}

async function addSale(saleMessage) {
    await connPool.awaitQuery("insert into Sale set ?", saleMessage);
}

async function endSale() {
  await connPool.awaitQuery("UPDATE Sale SET endTime = CURRENT_TIMESTAMP, active = 0 WHERE endTime IS NULL");
}

async function getRecentSales() {
  let retval = await connPool.awaitQuery("SELECT * from Sale ORDER BY startTime DESC LIMIT 3");
  return retval;
}

module.exports = {addContact, getContacts, deleteContact, addSale, endSale, getRecentSales}