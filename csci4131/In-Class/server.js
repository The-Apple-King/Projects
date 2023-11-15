const express = require('express')
const app = express()
const port = 4131

app.set("views", "not_node_modues");
app.set("view engine", "pug");

app.use(express .urlencoded({ extended: true }))
app.use(express.json())
app.use("/blog", express.static("blog"))


guest = []

app.get('/', (req , res) => {
  res.send(`<head><title>Guest List</title></head>
  <body><h1>Guest List</h1>
  <p>this is an example of the test</p>
  <form action="submit.php" method="post">
        <label for="name">name:</label>
        <input type="name" id="name" name="name" required>
        <br><br>
        <input type="submit" value="Submit">
    </form>
    
    </body>`)
})

app.post("/name", (req, res) =>{
  const name = req.body();
  guest.push(name);
});

app.listen (port , () => {
  console.log(`Example app listening on port ${port}`)
})