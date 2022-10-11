package com.sharan;

import java.util.Arrays;

public class AverageSalary {
    public static void main(String[] args) {
        int[] arr = {6000,5000,4000,3000,2000,1000};
        average(arr);
    }
    public static double average(int[] salary) {
        Arrays.sort(salary);
        double a = Arrays.stream(salary).sum();
        double b = salary[0] + salary[salary.length - 1];
        double n = salary.length - 2;
        return (a - b) / n;
    }
}
