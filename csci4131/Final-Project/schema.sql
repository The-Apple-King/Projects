CREATE TABLE Users (
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    user_name VARCHAR(120),
    password VARCHAR(120)
);

CREATE TABLE Posts (
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    creator_id INT,
    content VARCHAR(240),
    FOREIGN KEY (creator_id) REFERENCES Users(id)
);

CREATE TABLE Likes (
    user_id INT,
    post_id INT,
    positive BOOL,
    FOREIGN KEY (user_id) REFERENCES Users(id),
    FOREIGN KEY (post_id) REFERENCES Posts(id),
    CONSTRAINT unique_constraint_name UNIQUE (user_id, post_id)
);
