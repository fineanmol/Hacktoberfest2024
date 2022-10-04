// Create a Promise for the Students who will score A+ Grade, they will get a IceCream for their choice..
const { orderIceCream } = require("./utils/stall");
const { listOfStudents: queue } = require("./student_list");

// Request is Resolved only if Eligibility Criteria is Met... else Rejected
const processRequest = (student, marks) => {
  return new Promise((resolve, reject) => {
    // Initial Message
    console.log(
      `${student} SCORED ${marks}/100 in Maths -> PROCESSING your Request..`
    );

    // Processing the eligibility for IceCream takes 1 sec.
    setTimeout(() => {
      if (marks >= 90) {
        resolve(`Great Job !! Ice-cream on the Way !!`);
      } else {
        reject("Better Luck Next-time..");
      }
    }, 1000);
  });
};

const checkMarksForReward = async (student, marks, iceCream) => {
  try {
    const response = await processRequest(student, marks);
    console.log("Request resolved , Deserves an IceCream !!");

    const processed_Buy = await orderIceCream(response, iceCream);
    console.log(processed_Buy);
  } catch (err) {
    console.error(`SORRY !! ${err}`);
  }
};

const taskForEachStudent = (name) =>
  checkMarksForReward(name, queue[name][0], queue[name][1]);

async function task() {
  for (const studentName in queue) {
    console.log("\n---------- NEW ORDER -----------");
    await taskForEachStudent(studentName);
    console.log("--------------------------------");
  }
}

task();
