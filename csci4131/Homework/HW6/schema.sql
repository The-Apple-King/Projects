

CREATE TABLE Sale (

    saleID INT NOT NULL AUTO_INCREMENT,

    startTime TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,

    endTime TIMESTAMP,

    saleMessage VARCHAR(128) NOT NULL,

    PRIMARY KEY (saleID)

);


insert INTO Sale (saleMessage) VALUES('Hello get 10% off now');

INSERT Into Sale (saleMessage) Values("Another 20% off will stack with 10% off if you use code 111");

update Sale set endTime=CURRENT_TIMESTAMP where endTime is NULL;


SELECT saleMessage from Sale ORDER BY startTime DESC LIMIT 3;


CREATE TABLE ContactLog (
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(256),
    email VARCHAR(256),
    time DATETIME,
    amount VARCHAR(10),
    distributor bool
);
