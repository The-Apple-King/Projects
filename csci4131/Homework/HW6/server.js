const express = require('express');
const bodyParser = require('body-parser');
const basicAuth = require('express-basic-auth')
const data = require('./data.js');

const app = express();
const port = 4131;

app.set('view engine', 'pug');
app.set('views', 'templates');
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static('resources'));


//middleware
const auth = basicAuth({
    users: { 'admin': 'password' },
    challenge: true,
});

// GET requests
app.get(['/', '/main'], (req, res) => {
    res.render('mainpage');
});

app.get('/contact', (req, res) => {
    res.render('contactform');
});

app.get('/testimonies', (req, res) => {
    res.render('testimonies');
});

app.get('/admin/contactlog', auth, async (req, res) => {
    let contacts = await data.getContacts();
    console.log(contacts);
    for (let i = 0; i < contacts.length; i++) {
        const dateObject = new Date(contacts[i].time);
        contacts[i].time = dateObject.toISOString().split('T')[0];
    }
    res.render('contactlog', { contacts } );
});


app.get('/api/sale', async (req, res) => {
        const sales = await data.getRecentSales();
        let val = -1;
        for (let i = 0; i < sales.length; i++) { // find first sale that has not ended
            // Check if endTime property is null
            if (sales[i].endTime == null) {
                val = i;
                break;
            }
        }
        if (val !== -1) { // if a sale hasn't ended return it
            res.json({ message: sales[val].saleMessage });
        }
        else{ // if there is no sale then return empty string
            res.json({ message: "" });
        }
});

app.get('/admin/salelog', async (req, res) => {
    const recentSales = await data.getRecentSales();
    res.json(recentSales);
});

//POST requests
app.post('/contact', (req, res) => {
    const { name, email, date, dropdown, distributor } = req.body;

    if (name === undefined || email === undefined) {
        res.status(400).send("Required fields must be sent in");
    } else if (name === "" || email === "") {
        res.status(400).send("Required fields cannot be empty");
    } else {
        const vals = { name, email, date, dropdown, distributor: distributor == "on" };
        data.addContact(Object.values(vals));
        res.render('success');
    }
});

app.post('/api/sale', auth, (req, res) => {
    data.addSale(req.body);
    res.json();
});

//DELETE requests
app.delete('/api/sale', auth, (req, res) => {
    data.endSale();
    res.json();
});

app.delete('/api/contact', auth, (req, res) => {
    data.deleteContact(req.body.id);
    res.send('Contact deleted successfully');
});



// Catch-all route for 404
app.use((req, res) => {
    res.status(404).render('404');
});

// Start the server
app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});
