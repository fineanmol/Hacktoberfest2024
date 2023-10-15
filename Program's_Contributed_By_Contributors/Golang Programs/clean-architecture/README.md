## Whats Clean Architecture?

Rule of Clean Architecture by Uncle Bob

- Independent of Frameworks. The architecture does not depend on the existence of some library of feature laden software. This allows you to use such frameworks as tools, rather than having to cram your system into their limited constraints.
- Testable. The business rules can be tested without the UI, Database, Web Server, or any other external element.
- Independent of UI. The UI can change easily, without changing the rest of the system. A Web UI could be replaced with a console UI, for example, without changing the business rules.
- Independent of Database. You can swap out Oracle or SQL Server, for Mongo, BigTable, CouchDB, or something else. Your business rules are not bound to the database.
- Independent of any external agency. In fact your business rules simply don’t know anything at all about the outside world.

More at https://8thlight.com/blog/uncle-bob/2012/08/13/the-clean-architecture.html

## What S.O.L.I.D Principle is?

SOLID is an acronym representing five essential design principles for writing maintainable and scalable software. These principles were introduced by Robert C. Martin (Uncle Bob) and have become fundamental guidelines for good software design.

### SOLID Principles

#### Single Responsibility Principle (SRP)

The SRP states that a class should have only one reason to change, meaning it should have a single, well-defined responsibility. This principle encourages the separation of concerns, making code more modular and easier to maintain.

#### Open/Closed Principle (OCP)

The OCP emphasizes that software entities (classes, modules, functions) should be open for extension but closed for modification. To achieve this, use abstractions (e.g., interfaces, abstract classes) and dependency injection to allow adding new functionality without altering existing code.

#### Liskov Substitution Principle (LSP)

The LSP states that objects of a derived class should be substitutable for objects of the base class without affecting the correctness of the program. In other words, derived classes must adhere to the contract defined by their base classes.

#### Interface Segregation Principle (ISP)

The ISP suggests that clients should not be forced to depend on interfaces they do not use. Create smaller, more focused interfaces rather than large, monolithic ones. This avoids unnecessary dependencies and promotes flexibility.

#### Dependency Inversion Principle (DIP)

The DIP promotes high-level modules (e.g., use cases) to depend on abstractions (e.g., interfaces) rather than concrete implementations. This inversion of dependencies allows for flexibility and testability by injecting dependencies from external sources.

### Benefits of SOLID Principles

- Improved code maintainability and readability.
- Easier collaboration among developers on large projects.
- Reduced code duplication.
- Better testability and test coverage.
- Increased adaptability to changing requirements.

## Example Implementation Of Clean Architecture with S.O.L.I.D Principles in Go 

- [Example Project](https://github.com/DoWithLogic/golang-clean-architecture/)
