delete p1 from Person p1, Person p2 
where p1.email = p2.email && p1.id > p2.id;