SELECT Person.FirstName, Person.LastName, Address.City, Address.State from Person 
LEFT JOIN Address on Person.PersonId = Address.PersonId;