SELECT name, bonus
FROM Employee a
LEFT JOIN Bonus b
ON a.empId = b.empId
WHERE bonus < 1000 OR bonus IS NULL;