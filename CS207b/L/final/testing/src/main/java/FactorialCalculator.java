public class FactorialCalculator {
    public static int calculateFactorial(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("Input must be a non-negative integer");
        }

        if (n == 0 || n == 1) {
            return 1;
        }

        int result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }

        return result;
    }
}