# Write your MySQL query statement below
select p.firstname, p.lastname, a.city, a.state from person p left outer join address a 
on p.personid = a.personid;