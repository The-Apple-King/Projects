CREATE TABLE Expert (
    ssn CHAR(11),
    model_no INTEGER,
    PRIMARY KEY (ssm, model_no),
    FOREIGN KEY (ssn) REFERENCES Technician
    FOREIGN KEY (model_no) REFERENCES Models 
)

participation constaint cant be shown in the table

CREATE TABLE Models (
    model_no INTEGER,
    capacity INTEGER,
    weight INTEGER,
    PRIMARY KEY (model_no)
)

CREATE TABLE Employees (
    ssn Char(11)
    union_mem_no INTEGER,
    PRIMARY KEY (ssn)
)

CREATE TABLE Technician_emp (
    ssn CHAR(11),
    name CHAR(20),
    address CHAR(20),
    phone_no CHAR(14),
    PRIMARY KEY (ssn),
    FOREIGN KEY (ssn),
    REFERENCES Employees
        ON DELETE CASCADE
)

CREATE TABLE Traffic_control_emp (
    ssn CHAR(11),
    exam_date DATE,
    PRIMARY KEY (ssn),
    FOREIGN KEY (ssn),
    REFERENCES Employees
        ON DELETE CASCADE
)

CREATE TABLE Plane_Type (
    reg_no INTEGER,
    model_no INTEGER,
    PRIMARY KEY (reg_no),
    FOREIGN KEY (model_no) REFERENCES Models
)

CREATE TABLE Test_info (
    FAA_no INTEGER,
    ssn CHAR(11),
    reg_no INTEGER,
    hours INTEGER,
    date DATE,
    score INTEGER,
    PRIMARY KEY (ssn, reg_no, FAA_no),
    FOREIGN KEY(reg_no) REFERENCES Plane_Type,
    FOREIGN KEY(FAA_no) REFERENCES Test,
    FOREIGN KEY(ssn) REFERENCES Employees
)

CREATE TABLE Test(
    FAA_no INTEGER,
    name CHAR(10),
    score INTEGER,

    max_score INTEGER,
    hours INTEGER,
    date DATE,

    PRIMARY KEY (FAA_no)
)

the constaint of only experts conducting tests can be shown in SQL as

CREATE TABLE Test_info (
    FAA_no INTEGER,
    ssn CHAR(11),
    reg_no INTEGER,
    hours INTEGER,
    date DATE,
    score INTEGER,
    PRIMARY KEY (ssn, reg_no, FAA_no),
    FOREIGN KEY(reg_no) REFERENCES Plane_Type(reg_no),
    FOREIGN KEY(FAA_no) REFERENCES Test(FAA_no),
    FOREIGN KEY(ssn) REFERENCES Technician_emp(ssn),
    CONSTRAINT MODEL
    CHECK ( SELECT * FROM Expert, Plane_Type
    WHERE Expert.ssn = Technician_emp.ssn AND
        Expert.model_no = Plane_Type.model_no AND
        Plane_Type.reg_no = reg_no)
)