/*
 * Creates all permutations of the supplied array
 * @param {array} array
 * @return: An array of arrays: Each array is a permutation of the given array.
 */
export default (array) => {
  if (!Array.isArray(array)) throw new Error("Argument must be of type array");

  if (array.length === 0) return [];
  if (array.length === 1) return [array];
  let result = [];
  for (const [index, item] of array.entries()) {
    const rest = [...array.slice(0, index), ...array.slice(index + 1, array.length)];

    permute(rest).forEach(permutation => result.push([item, ...permutation]));
  }

  return result;
}