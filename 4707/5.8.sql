CREATE TABLE Student (
    snum INTEGER,
    sname STRING,
    major STRING,
    level STRING,
    age INTEGER
);

CREATE TABLE Class(
    name STRING PRIMARY KEY
    meets_at TIME,
    room STRING,
    fid INTEGER,
    FOREIGN KEY (fid) REFERENCES Faculty(fid)
);

CREATE TABLE Enrolled(
    snum INTEGER,
    cname STRING,
    PRIMARY KEY (snum, cname),
    FOREIGN KEY (snum) REFERENCES Student(snum),
    FOREIGN KEY (cname) REFERENCES Class(name)
);

CREATE TABLE Faculty(
    fid INTEGER PRIMARY KEY,
    fname STRING,
    deptid INTEGER,
    FOREIGN KEY (deptid) REFERENCES Department(deptid)
);


a)

b)
c)
d)
e)
f)
g)
h)
i)
j)
k)
l)
m)
n)
o)
