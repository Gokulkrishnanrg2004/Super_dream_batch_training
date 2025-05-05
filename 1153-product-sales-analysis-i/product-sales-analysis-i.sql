SELECT product_name, year, price
FROM Sales a
JOIN Product b
ON a.product_id = b.product_id;