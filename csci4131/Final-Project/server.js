const express = require('express');
const data = require('./data.js');
const bodyParser = require('body-parser');
const cookieParser = require('cookie-parser');
const bcrypt = require('bcrypt');
const session = require("express-session");


const app = express();
const port = 4131;

app.set('view engine', 'pug');
app.set('views', 'templates');
app.use(express.static('resources'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(cookieParser());


app.use(session({
    secret: 'secret-agents-on-a-secret-mission',
    resave: false,
    saveUninitialized: false,
}));

const addUserToLocals = (req, res, next) => {
    res.locals.user = req.session.user || null;
    next();
};

app.use(addUserToLocals);


// GET requests
app.get(['/', '/main'], async (req, res) => {
    let sortBy = req.query.sortBy || 0;
    let page = parseInt(req.query.page) || 0;

    if (req.session.user) {
        posts = await data.getPosts({ user_id: req.session.user.id, sortBy: sortBy, page: page });
    } else {
        posts = await data.getPosts({ user_id: -1, sortBy: sortBy, page: page });
    }

    res.render('mainpage', { posts: posts, sortBy: sortBy, page: page });
});


app.get(['/login'], (req, res) => {
    res.render('login');
});

app.get(['/createAccount'], (req, res) => {
    res.render('createAccount');
});

//POST requests
app.post('/login', async (req, res) => {
    const { username, password } = req.body;
    try {
        const hashedPassword = await data.login({ username });
        bcrypt.compare(password, hashedPassword[0].password, function (err, result) {
            if (err) {
                // handle error
                res.status(401).render("login", {issue:"error"} )
            }
            if (result) {
                //create session here and then load mainpage
                req.session.user = {
                    id: hashedPassword[0].id,
                    name: hashedPassword[0].user_name
                };
                res.send('<script>window.location="/main";</script>');
            } else {
                // passwords do not match
                res.status(401).render("login", {issue:"incorrect password"} );
            }
        });
    } catch (error) {
        // handle database query error
        res.status(401).render("login", {issue:"incorrect username"} );
    }
});

app.post('/logout', async (req, res) => {
    req.session.destroy(async (err) => {
        if (err) {
            console.error('Error destroying session:', err);
        } else {
            res.status(403).send('<script>window.location="/login";</script>');
        }
    });
});

app.post('/CreateAccount', async (req, res) => {
    let { username, password } = req.body;
    const saltRounds = 10;

    // Generate a salt for the password
    const salt = await bcrypt.genSalt(saltRounds);

    // Hash the password using the salt
    password = await bcrypt.hash(password, salt);

    data.addUser({ username, password });
    // if we just auto login and create a session here no reason to res.send
    res.status(200).send('<script>window.location="/main";</script>');
});

app.post('/createPost', (req, res) => {
    //check if we can
    if (req.session.user) {
        const { content } = req.body;
        const user_id = req.session.user.id;
        data.addPost({ user_id: user_id, content: content });

        res.status(200).send('<script>window.location="/main";</script>');
    } else {
        res.status(401).send('<script>window.location="/login";</script>');

    }
});

app.post('/editPost', (req, res) => {
    //check if we can
    if (req.session.user) {
        const { content, post_id } = req.body;
        const user_id = req.session.user.id;
        data.editPost({ user_id: user_id, content: content, post_id: post_id });

        res.status(200).send('<script>window.location="/main";</script>');
    } else {
        res.status(401).send('<script>window.location="/login";</script>');

    }
});

app.post('/likeExists', async (req, res) => {
    const { post_id } = req.body
    if (req.session.user) {
        user_id = req.session.user.id;
        vals = { user_id, post_id };
        const result = await data.likeExists(vals);
        res.status(200).json({ liked: result });
    } else {
        res.status(401).redirect("/login");
    }
});

app.post('/like', async (req, res) => {
    const { positive, post_id } = req.body
    if (req.session.user) {
        user_id = req.session.user.id;
        vals = { positive, user_id, post_id };
        data.like(vals);
        res.status(200).send("success");
    } else {
        res.status(401).redirect("/login");
    }
});

app.post('/unlike', async (req, res) => {
    const { post_id } = req.body
    if (req.session.user) {
        user_id = req.session.user.id;
        vals = { user_id: user_id, post_id: post_id };
        data.unlike(vals);
        res.status(200).send("success");
    } else {
        res.status(401).redirect("/login");
    }
});

//DELETE requests
app.delete('/deletePost', async (req, res) => {
    if (req.session.user) {
        user_id = req.session.user.id;
        post_id = req.body.post_id;
        vals = { user_id: user_id, post_id: post_id };
        data.deletePost(vals);
        res.status(200).redirect("/main");
    } else {
        res.status(401).redirect("/login");
    }
});

// Catch-all route for 404
app.use((req, res) => {
    res.status(404).render('404');
});

// Start the server
app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});
