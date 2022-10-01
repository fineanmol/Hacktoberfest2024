//cheatsheet for all the *IMPORTANT* Math functions in java which are imported automatically along with the java.lang package.
public class MathFunctions {
    void main(double a, double b){
        double result=0;

        //Math functions start here

        double smaller = Math.min(a, b);//to find out the smaller number between the two.
        double larger = Math.max(a, b);//to find out the greater between the two numbers.
        double absoluteValue = Math.abs(b);//to find out the absolute value of a double.
        double squareRoot = Math.sqrt(a);//to find the square root of a number.
        double cubeRoot =  Math.cbrt(b);//to find the cube root of a given number.
        double power = Math.pow(a, b);//to raise a to the power of b;
        double pi = Math.PI;//returns the value of pi(~ 22/7).
        double tangent = Math.tan(b);//find the mathematical tangent of an angle.
        double sin = Math.sin(a);//to find the mathematical sine of a given angle.
        double cos = Math.cos(b);//to find the mathematical cos of an angle.
        double cosec = Math.asin(b);//to find the sine inverse aka. cosec of an angle.
        double acos = Math.acos(a);//to find the cos inverse aka. sec of an angle.
        double atan = Math.atan(a);//to find the tan inverse of cot on a given angle.
        double upperRoundOff = Math.ceil(a);//to find the upper rounded double, eg.- 3.2 will return 4.0
        double lowerRoundOff = Math.floor(a);//to find the lower rounded double, eg.- 3.2 will return 3.0
        double rounded = Math.round(a);//returns the mathematical rounded off value.
        double exponentialValue = Math.exp(a);//to find the exponential value of a number.
        double radians = Math.toRadians(b);//to convert a given angle in degrees to angle in radians.
        double random = Math.random();//to get eith 0 or 1 randomly, to get random within a set of numbrs, use the util.Random package.

        //Math functions end here
    }
}

/**********************************************
 * @INFO
 * Author = programmer-offbeat
 * @ INFO
 * Discord = Astrexx.jar#4035
 *********************************************/
