const objects = [
  {
    id: 2,
    name: "Fizz",
    age: 24
  },
  {
    id: 1,
    name: "Buzz",
    age: 13
  },
  {
    id: 3,
    name: "Antonio",
    age: 32
  },
  {
    id: 4,
    name: "Albert",
    age: 7
  }
]


/**
 * This function is to sort array objects depends with
 * the options you provided.
 *
 * @typedef {{id: number, name: string, age: number}[]} ArrayObjects
 * @param {ArrayObjects} data
 * @param {{by: "id" | "name" | "age"}} opts
 * @returns {ArrayObjects} sorted object arrays
 */
const sortObject = (data, opts = {by: "id" | "name" | "age"}) => {
  const { by } = opts;

  switch(by) {
    case "id":
      return data.sort((prev, next) => {
        return prev.id - next.id;
      })
    case "name":
      return data.sort((prev, next) => {
        let prevName = prev.name.toLowerCase();
        let nextName = next.name.toLowerCase();

        return (prevName < nextName) ? -1 : (prevName > nextName) ? 1 : 0;
      });
    case "age":
      return data.sort((prev, next) => {
        return prev.age - next.age;
      })
  }
}

console.log(sortObject(objects, { by: "id" }));
console.log(sortObject(objects, { by: "name" }));
console.log(sortObject(objects, { by: "age" }));
