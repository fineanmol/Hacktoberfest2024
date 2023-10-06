export const FarenheitToCelcius = (num: number): number => {
  const res = (num - 32) / 1.8;

  return parseFloat(res.toFixed(2));
};
