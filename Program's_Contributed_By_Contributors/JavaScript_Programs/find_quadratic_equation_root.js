function determinant(a, b, c){
  return b**2 - 4*a*c
}
export function rootsOfQuadraticEquation (a, b, c) {
    const D = determinant(a, b, c);
    const SQRT_D = Math.sqrt(D)
    const r1 = (-1*b + SQRT_D) / (2*a);
    const r2 = (-1*b - SQRT_D) / (2*a);
    return [r1, r2]
};
