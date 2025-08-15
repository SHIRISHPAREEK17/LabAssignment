import java.util.Scanner;

public class QuadraticEquation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        //  inputs
        System.out.print("Enter coefficient a: ");
        int a = sc.nextInt();

        System.out.print("Enter coefficient b: ");
        int b = sc.nextInt();

        System.out.print("Enter coefficient c: ");
        int c = sc.nextInt();

        // Calculate discriminant
        int discriminant = (b * b) - (4 * a * c);

        if (discriminant > 0) {
            System.out.println("Equation has two distinct real roots");

            double sqrtD = Math.sqrt(discriminant);
            double root1 = (-b + sqrtD) / (2.0 * a);
            double root2 = (-b - sqrtD) / (2.0 * a);

            System.out.println("Roots are: " + root1 + " and " + root2);

        } 
         else if (discriminant == 0) {
            System.out.println("Equation has one repeated real root");

            double root = (-b) / (2.0 * a);
            System.out.println("Root is: " + root);

        } 
         else {
            System.out.println("Equation has two complex roots");

            double realPart = (-b) / (2.0 * a);
            double imaginaryPart = Math.sqrt(-discriminant) / (2.0 * a);

            System.out.println("Root 1: " + realPart + " + " + imaginaryPart + "i");
            System.out.println("Root 2: " + realPart + " - " + imaginaryPart + "i");
        }
 
    }
}
