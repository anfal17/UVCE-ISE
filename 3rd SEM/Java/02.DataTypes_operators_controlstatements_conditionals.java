public class DataTypesOperatorsControlStatementsConditionals {

    public static void main(String[] args) {
        // Data Types
        int intValue = 10;
        float floatValue = 10.07;
        double doubleValue = 3.15;
        char charValue = 'A';
        boolean boolValue = true;
        String stringValue = "Hello, Java!";

        // Operators

        /* 1.Arithmetic Operators */
        int result = 10 + 5; // Addition
        int difference = 20 - 8; // Subtraction
        int product = 4 * 6; // Multiplication
        double quotient = 12.0 / 4; // Division
        int remainder = 15 % 7; // Modulus

        // 2.Comparison Operators (Relational Operators)
        boolean isEqual = (5 == 5); // Equal to
        boolean isNotEqual = (10 != 7); // Not equal to
        boolean isLessThan = (3 < 7); // Less than
        boolean isGreaterThan = (9 > 4); // Greater than
        boolean isLessOrEqual = (2 <= 2); // Less than or equal to
        boolean isGreaterOrEqual = (8 >= 8); // Greater than or equal to

        // 3.Logical Operators
        boolean andResult = true && false; // Logical AND
        boolean orResult = true || false; // Logical OR
        boolean notResult = !true; // Logical NOT

        // 4.Assignment Operators
        int x = 10; // Assignment
        x += 5; // Addition assignment (Equivalent to x = x + 5)
        x -= 3; // Subtraction assignment (Equivalent to x = x - 3)
        x *= 2; // Multiplication assignment (Equivalent to x = x * 2)
        x /= 4; // Division assignment (Equivalent to x = x / 4)
        x %= 3; // Modulus assignment (Equivalent to x = x % 3)

        // 5.Unary Operators
        int a = 5;
        a++; // Increment (a is now 6)
        a--; // Decrement (a is now 5)
        int b = +a; // Unary plus (no change)
        int c = -a; // Unary minus (c is -5)
        int d = ~5; // Bitwise NOT (d is -6)

        // 6.Conditional (Ternary) Operator
        int max = (a > b) ? a : b; // If a > b, max is a; otherwise, max is b.

        // 7.Bitwise Operators (for integers)
        int p = 5 & 3; // Bitwise AND
        int q = 5 | 3; // Bitwise OR
        int r = 5 ^ 3; // Bitwise XOR
        int s = 8 << 2; // Left shift (32)
        int t = 16 >> 2; // Right shift (4)
        int u = -8 >>> 1; // Right shift (zero fill, 2147483644)

        // Control Statements
        if (boolValue) {
            System.out.println("boolValue is true.");
        } else {
            System.out.println("boolValue is false.");
        }

        switch (charValue) {
            case 'A':
                System.out.println("charValue is 'A'.");
                break;
            case 'B':
                System.out.println("charValue is 'B'.");
                break;
            default:
                System.out.println("charValue is not 'A' or 'B'.");
        }

        // while loop
        int count = 1;
        while (count <= 5) {
            System.out.println("Count: " + count);
            count++;
        }

        // do while loop
        int num = 1;
        do {
            System.out.println("Number: " + num);
            num++;
        } while (num <= 5);


        // for loop
        for (int i = 0; i < 5; i++) {
            System.out.println("Iteration " + (i + 1));
        }

        //for each
        int[] numbers = { 1, 2, 3, 4, 5 };
        for (int number : numbers) {
            System.out.println("Number: " + number);
        }

        // Output
        System.out.println("intValue: " + intValue);
        System.out.println("doubleValue: " + doubleValue);
        System.out.println("charValue: " + charValue);
        System.out.println("boolValue: " + boolValue);
        System.out.println("stringValue: " + stringValue);
        System.out.println("result: " + result);
        System.out.println("divisionResult: " + divisionResult);
        System.out.println("isEqual: " + isEqual);
    }
}
