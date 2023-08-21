SELECT d.name AS Department, e.name AS Employee, e.salary Salary
FROM Department d
JOIN Employee e ON d.id = e.departmentId
JOIN (
    SELECT departmentId, MAX(salary) AS max_salary
    FROM Employee
    GROUP BY departmentId
) max_salaries
ON e.departmentId = max_salaries.departmentId AND e.salary = max_salaries.max_salary;
