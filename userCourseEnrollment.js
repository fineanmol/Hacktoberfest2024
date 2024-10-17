class Course {
    constructor(title, instructor, duration, rating) {
        this.title = title;
        this.instructor = instructor;
        this.duration = duration; // duration in hours
        this.rating = rating; // rating out of 5
    }

    getDetails() {
        return `${this.title} by ${this.instructor}, Duration: ${this.duration} hours, Rating: ${this.rating}/5`;
    }
}

class User {
    constructor(name, email) {
        this.name = name;
        this.email = email;
        this.enrolledCourses = [];
    }

    enroll(course) {
        this.enrolledCourses.push(course);
        console.log(`${this.name} has enrolled in ${course.title}`);
    }

    listEnrolledCourses() {
        if (this.enrolledCourses.length === 0) {
            console.log(`${this.name} is not enrolled in any courses.`);
            return;
        }
        console.log(`${this.name}'s Enrolled Courses:`);
        this.enrolledCourses.forEach(course => {
            console.log(course.getDetails());
        });
    }

    totalLearningHours() {
        let totalHours = this.enrolledCourses.reduce((acc, course) => acc + course.duration, 0);
        console.log(`${this.name} has a total of ${totalHours} learning hours.`);
    }
}

const course1 = new Course("JavaScript Basics", "John Doe", 5, 4.5);
const course2 = new Course("React Development", "Jane Smith", 8, 4.8);
const course3 = new Course("Data Structures & Algorithms", "Alex Johnson", 10, 4.9);

const user1 = new User("Alice", "alice@example.com");
const user2 = new User("Bob", "bob@example.com");

user1.enroll(course1);
user1.enroll(course2);
user2.enroll(course3);

user1.listEnrolledCourses();
user2.listEnrolledCourses();

user1.totalLearningHours();
user2.totalLearningHours();
