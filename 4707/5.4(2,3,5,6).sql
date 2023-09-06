SELECT e.ename, e.age
FROM Employees e
JOIN Works w ON e.eid = w.eid
JOIN Dept d ON w.did = d.did
WHERE d.dname = 'Hardware' OR d.dname = 'Software';


SELECT w.did, COUNT(*) AS num_employees
FROM Works w 
GROUP BY w.did 
HAVING SUM(w.pct_time) >= 2000 

HAVING SUM(w.pct_time) >= 100 AND COUNT(*) > 20 

SELECT e.name
FROM Employees e
JOIN Works w ON e.eid = w.eid
JOIN Dept d ON w.did = d.did 
Group By e.name
HAVING e.salary > ALL (SELECT d.budget FROM Dept d WHERE d.did = w.did);

SELECT e.ename
FROM Employees e 
JOIN Department d ON e.eid = d.managerid
ORDER BY d.budget DESC

SELECT d.managerid
FROM Dept d 
GROUP BY d.managerid
HAVING SUM(d.budget) > 5000000