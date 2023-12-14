const x = require('express');

const website = x();
const port = 4131;

website.set('view engine', 'pug');
website.set('views', 'pug files');

website.use("/", (req, res) =>{
    res.render("dad.pug");
});

website.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});