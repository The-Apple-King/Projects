const express = require('express')
const app = express()
const port = 4131

app.get('/', (req , res) => {
  res.send(`<head><title>Title of the Page</title></head>
  <body><h1>Title of the Page</h1>
  <p>this is an example of the test</p>
  <form action="submit.php" method="post">
        <label for="name">name:</label>
        <input type="name" id="name" name="name" required>
        <br><br>
        <input type="submit" value="Submit">
    </form></body>`)
})

app. listen (port , () => {
  console.log(`Example app listening on port ${port}`)
})