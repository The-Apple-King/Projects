const express = require ('express')
const app = express()
const port = 4131

app.get('/', (req, res) => {
    res.send('Hello World !')
});

app.use(express.urlencoded({ extended: true }));
app.use((req, res, next()) => {
    
}))


let count = 0;

app.get('/count', (req, res) => {
    count++;
    res.send(`
    <!DOCTYPE html>
    <html lang="en">
        <head><meta charset="UTF-8">
            <title>TEMPLATE</title>
            </head>
            <body>
                ${count}
            </body>
    </html>
    `);
});

app.get('/throw', (req, res) => {
    count++;
    res.send(`
    <!DOCTYPE html>
    <html lang="en">
        <head><meta charset="UTF-8">
            <title>TEMPLATE</title>
        </head>
        <body>
            <form action="/catch" method="GET">
                <input placeholder="type a name" name="name">
                <input type="submit">
            </form>
        </body>
    </html>
    `);
});

app.get("/catch", (req, res) =>{
    const name = req.query.name ??  "Joe, mighty of cards";
    res.send(`
    <!DOCTYPE html>
    <html lang="en">
        <head><meta charset="UTF-8">
            <title>TEMPLATE</title>
        </head>
        <body>
            <h1>HQ ${name} </h1>
        </body>
    </html>
    `);
});


app.listen(port , () => {
    console.log(`example of app listening on port ${port}`);
});