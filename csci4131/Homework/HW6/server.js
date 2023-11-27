const express = require('express');
const bodyParser = require('body-parser');
const basicAuth = require('express-basic-auth')

const app = express();
const port = 4131;

app.set('view engine', 'pug');
app.set('views', 'templates');
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static('resources'));

let contacts = [];
let next_id = 0;
let sale_text = "test";
let sale = true;

//middleware
const auth = basicAuth({
    users: { 'admin': 'password' },
    challenge: true,
});

app.use((req, res, next) => {
    console.log(`${req.method} ${req.url}`);
    next();
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

app.get('/admin/contactlog', auth, (req, res) => {
    res.render('contactlog', { contacts });
});


app.get('/api/sale', (req, res) => {
    res.json({ message: sale_text });
});


//POST requests
app.post('/contact', (req, res) => {
    const { name, email, date, dropdown, checkbox } = req.body;

    if (name === undefined || email === undefined) {
        res.status(400).send("Required fields must be sent in");
    } else if (name === "" || email === "") {
        res.status(400).send("Required fields cannot be empty");
    } else {
    const contact = {
        Name: name,
        Email: email,
        Date: date,
        Dropdown: dropdown,
        Checkbox: (checkbox == true),
        Id: next_id
    };
    contacts.push(contact);
    console.log(contact);
    next_id++;
    res.render('success');
}
});

app.post('/api/sale', auth, (req, res) => {
    sale_text = req.body.message;
    sale = true;

    res.json({ message: sale_text });
});

//DELETE requests
app.delete('/api/sale', auth, (req, res) => {
    sale_text = "";
    sale = false;

    res.json();
});

app.delete('/api/contact', auth, (req, res) => {
    const contactToDelete = contacts.find(obj => obj.Id === req.body.id);
    if (!contactToDelete) {
        return res.status(404).render('404');
    }

    // Use filter to create a new array without the contact to delete
    const newContacts = contacts.filter(obj => obj.Id !== req.body.id);

    // Check if the contact was found and deleted
    if (newContacts.length === contacts.length) {
        return res.status(404).render('404');
    }

    // Update the contacts array with the new array without the deleted contact
    contacts = newContacts;

    // Send success response
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
