SELECT unique_id, name
FROM Employees a
LEFT JOIN EmployeeUNI b
ON a.id = b.id;