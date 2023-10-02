/**
 * Checks if a given year, month, and day form a plausible date.
 *
 * @param {number} year - The year of the date.
 * @param {number} month - The month of the date (1-12).
 * @param {number} day - The day of the date (1-31).
 * @returns {boolean} - True if the date is plausible, false otherwise.
 */
function isPlausibleDate(year, month, day) {
  // Check if the year, month, and day are within valid ranges
  if (
    year < 0 || // Year cannot be negative
    month < 1 ||
    month > 12 || // Month should be between 1 and 12
    day < 1 ||
    day > 31 // Day should be between 1 and 31
  ) {
    return false;
  }

  function isLeapYear(year) {
    // Leap year is divisible by 4, but not divisible by 100
    // unless it is also divisible by 400
    return (year % 4 === 0 && year % 100 !== 0) || year % 400 === 0;
  }

  // Check for February and leap years
  if (month === 2) {
    // February has 28 or 29 days
    if (isLeapYear(year)) {
      return day <= 29;
    } else {
      return day <= 28;
    }
  }

  // Check for months with 30 days
  if ([4, 6, 9, 11].includes(month)) {
    return day <= 30;
  }

  // For all other months with 31 days
  return day <= 31;
}

// Example usage:
const year = 2023;
const month = 2;
const day = 29;

if (isPlausibleDate(year, month, day)) {
  console.log("The date is plausible.");
} else {
  console.log("The date is not plausible.");
}
