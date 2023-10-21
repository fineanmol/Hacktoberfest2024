import java.util.Arrays;

public class DFTandCyclicPolynomialMultiplication {

    // Compute the Discrete Fourier Transform (DFT) of the given complex input
    public static Complex[] computeDFT(Complex[] input) {
        int n = input.length;
        Complex[] output = new Complex[n];
        for (int k = 0; k < n; k++) {
            output[k] = new Complex(0, 0);
            for (int t = 0; t < n; t++) {
                double angle = 2 * Math.PI * t * k / n;
                Complex complexExp = new Complex(Math.cos(angle), -Math.sin(angle));
                output[k] = output[k].plus(input[t].times(complexExp));
            }
        }
        return output;
    }

    // Perform cyclic polynomial multiplication using DFT
    public static int[] multiplyPolynomials(int[] poly1, int[] poly2) {
        int n = Math.max(poly1.length, poly2.length);
        int m = 1;
        while (m < n) {
            m *= 2;
        }
        m *= 2;

        Complex[] complexPoly1 = new Complex[m];
        Complex[] complexPoly2 = new Complex[m];

        for (int i = 0; i < poly1.length; i++) {
            complexPoly1[i] = new Complex(poly1[i], 0);
        }
        for (int i = poly1.length; i < m; i++) {
            complexPoly1[i] = new Complex(0, 0);
        }

        for (int i = 0; i < poly2.length; i++) {
            complexPoly2[i] = new Complex(poly2[i], 0);
        }
        for (int i = poly2.length; i < m; i++) {
            complexPoly2[i] = new Complex(0, 0);
        }

        Complex[] dftPoly1 = computeDFT(complexPoly1);
        Complex[] dftPoly2 = computeDFT(complexPoly2);

        Complex[] product = new Complex[m];
        for (int i = 0; i < m; i++) {
            product[i] = dftPoly1[i].times(dftPoly2[i]);
        }

        Complex[] invDFT = computeDFTInverse(product);

        int[] result = new int[m];
        for (int i = 0; i < m; i++) {
            result[i] = (int) Math.round(invDFT[i].getReal() / m);
        }

        return result;
    }

    // Compute the inverse Discrete Fourier Transform (DFT) of the given complex input
    public static Complex[] computeDFTInverse(Complex[] input) {
        int n = input.length;
        Complex[] output = new Complex[n];
        for (int t = 0; t < n; t++) {
            output[t] = new Complex(0, 0);
            for (int k = 0; k < n; k++) {
                double angle = 2 * Math.PI * t * k / n;
                Complex complexExp = new Complex(Math.cos(angle), Math.sin(angle));
                output[t] = output[t].plus(input[k].times(complexExp));
            }
            output[t] = output[t].divides(n);
        }
        return output;
    }

    public static void main(String[] args) {
        // Example usage
        int[] poly1 = {1, 2, 3};
        int[] poly2 = {4, 5, 6};
        int[] result = multiplyPolynomials(poly1, poly2);
        System.out.println("Result of cyclic polynomial multiplication: " + Arrays.toString(result));
    }

    // Complex number class
    static class Complex {
        private final double real;
        private final double imag;

        public Complex(double real, double imag) {
            this.real = real;
            this.imag = imag;
        }

        public double getReal() {
            return real;
        }

        public double getImag() {
            return imag;
        }

        public Complex plus(Complex other) {
            return new Complex(this.real + other.real, this.imag + other.imag);
        }

        public Complex times(Complex other) {
            return new Complex(this.real * other.real - this.imag * other.imag,
                    this.real * other.imag + this.imag * other.real);
        }

        public Complex divides(double divisor) {
            return new Complex(this.real / divisor, this.imag / divisor);
        }
    }
}
