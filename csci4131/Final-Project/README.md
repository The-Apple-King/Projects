the following are a list of nodejs modules used
    bcrypt 
        used for encrypting passwords
    cookie-parser
        used to parse the session from express session
    express
        basic express to run server
    express-session
        used to make a session so the user can sign in and stay signed in
    mysql-await
        used to connect to the database
    pug
        used to make website
    tunnel-ssh
        used to make the tunnel through school firewall


# Urls
/ or /main
    this is the homepage, it will display posts even if you aren't signed in

/login
    this is the login page allows users to login and has the link to create an account
## currently there is a single account user with the password: password

/createAccount
    this is the create account page in order to make new accounts

there is a 404 page when an incorrect url is sent


# Features
* Users can create text posts up to 240 characters
* text posts can be viewed with latests first 5 posts at a time with multiple pages for other posts
* Text posts can be edited and deleted, (if you are signed in and you posted it)
* posts can be both liked and disliked and these are handled separately. likes and dislikes don't require a page reload.
* posts can be sorted by most recent. most likes, and most dislikes
* account creation
* logged-in vs not-logged-in. website will store a session if you logged in.
* passwords are stored in a salted hash, the hash is salted 10 times. used bcrypt for this
* only posts created by the user can be edited or deleted
