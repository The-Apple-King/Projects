

CREATE TABLE Sale (
    saleID INT NOT NULL AUTO_INCREMENT,
    startTime TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    endTime TIMESTAMP,
    saleMessage VARCHAR(128) NOT NULL,
    active BOOLEAN NOT NULL DEFAULT true,
    PRIMARY KEY (saleID)
);

CREATE TABLE Contact (
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(256),
    email VARCHAR(256),
    time DATETIME,
    amount VARCHAR(10),
    distributor bool
);
