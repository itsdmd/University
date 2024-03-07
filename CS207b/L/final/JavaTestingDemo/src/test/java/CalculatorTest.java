import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

import static org.junit.jupiter.api.Assertions.*;

@DisplayName("Kiểm thử package Calculator")
class CalculatorTest {
    private Calculator calculator;

    // Hàm setUp chạy trước khi thực hiện mỗi test
    @BeforeEach
    void setUp() {
        calculator = new Calculator();
    }

    // Test với tham số được truyền vào từ nguồn csv
    @ParameterizedTest
    @CsvSource({ "10, 10, 20",
                 "20, 20, 40",
                 "10, 30, 40",
                 "-25, -25, -50",
                 "-25, 25, 0" })
//    @Disabled
    @DisplayName("Cộng 2 số nguyên trong giới hạn")
    void testAddTwoIntegers(double op1, double op2, double expected) {
        double sum = calculator.add(op1, op2);
        assertEquals(expected, sum, 0);
    }

    // @DisplayName("tên hiển thị của test")
    @DisplayName("Cộng 2 số thực trong giới hạn")
    @Test
    void testAddTwoDoubles() {
        double sum = calculator.add(-1.5, 2.5);
        assertEquals(1, sum, 0);
    }

    @DisplayName("Cộng 2 số thực dương lớn nhất")
    @Test
    void testAddTwoLargePositiveDoubles() {
        double sum = calculator.add(Double.MAX_VALUE, Double.MAX_VALUE);
        assertEquals(Double.POSITIVE_INFINITY, sum, 0);
    }

    @DisplayName("Cộng 2 số thực âm nhỏ nhất")
    @Test
    void testAddTwoLargeNegativeDoubles() {
        double sum = calculator.add(-Double.MAX_VALUE, -Double.MAX_VALUE);
        assertEquals(Double.NEGATIVE_INFINITY, sum, 0);
    }

    @DisplayName("Cộng số thực dương lớn nhất và số thực âm nhỏ nhất")
    @Test
    void testAddLargestPositiveDoubleToSmallestNegativeDouble() {
        double sum = calculator.add(Double.MAX_VALUE, -Double.MAX_VALUE);
        assertEquals(0, sum);
    }

    @DisplayName("Cộng số thực âm nhỏ nhất và số thực dương lớn nhất")
    @Test
    void testAddSmallestNegativeDoubleToLargestPositiveDouble() {
        double sum = calculator.add(-Double.MAX_VALUE, Double.MAX_VALUE);
        assertEquals(0, sum);
    }

    @Test
    @DisplayName("Trừ 2 số nguyên trong giới hạn")
    void testSubtractTwoIntegers() {
        double difference = calculator.subtract(5, 2);
        assertEquals(3, difference, 0);
    }

    @DisplayName("Trừ 2 số thực trong giới hạn")
    @Test
    void testSubtractTwoDoubles() {
        double difference = calculator.subtract(1.5, -1.5);
        assertEquals(3, difference, 0);
    }

    @DisplayName("Trừ 2 số thực dương lớn nhất")
    @Test
    void testSubtractTwoLargePositiveDoubles() {
        double difference = calculator.subtract(Double.MAX_VALUE, Double.MAX_VALUE);
        assertEquals(0, difference);
    }

    @DisplayName("Trừ 2 số thực âm nhỏ nhất")
    @Test
    void testSubtractTwoLargeNegativeDoubles() {
        double difference = calculator.subtract(-Double.MAX_VALUE, -Double.MAX_VALUE);
        assertEquals(0, difference);
    }

    @DisplayName("Trừ số thực dương lớn nhất và số thực âm nhỏ nhất")
    @Test
    void testSubtractSmallestNegativeDoubleFromLargestPositiveDouble() {
        double difference = calculator.subtract(Double.MAX_VALUE, -Double.MAX_VALUE);
        assertEquals(Double.POSITIVE_INFINITY, difference);
    }

    @DisplayName("Trừ số thực âm nhỏ nhất và số thực dương lớn nhất")
    @Test
    void testSubtractLargestPositiveDoubleFromSmallestNegativeDouble() {
        double difference = calculator.subtract(-Double.MAX_VALUE, Double.MAX_VALUE);
        assertEquals(Double.NEGATIVE_INFINITY, difference);
    }

    @DisplayName("Căn bậc 2 của số dương không chính phương")
    @Test
    void testSqrtPositiveNonSquareNumber() {
        double sqrt = calculator.sqrt(2);
        assertEquals(1.41421356, sqrt, 0.000001);
    }

    @DisplayName("Căn bậc 2 của số dương chính phương")
    @Test
    void testSqrtSquareNumber() {
        double sqrt = calculator.sqrt(49);
        assertEquals(7, sqrt);
    }

    // assertThrows
    @DisplayName("Căn bậc 2 của số âm, quăng ngoại lệ IllegalArgumentException")
    @Test
    void testSqrtNegativeNumberExpectIllegalArgumentException() {
        assertThrows(IllegalArgumentException.class, () -> calculator.sqrt(-1));
    }

    @DisplayName("Chia số nguyên dương cho số nguyên dương")
    @Test
    void testDividePositiveIntegerByPositiveInteger() {
        double quotient = calculator.divide(1, 3);
        assertEquals(0.33333333, quotient, 0.000001);
    }

    @DisplayName("Chia số nguyên dương cho số nguyên âm")
    @Test
    void testDividePositiveIntegerByNegativeInteger() {
        double quotient = calculator.divide(1, -3);
        assertEquals(-0.33333333, quotient, 0.000001);
    }

    @DisplayName("Chia số thực dương cho số thực dương")
    @Test
    void testDividePositiveDoubleByPositiveDouble() {
        double quotient = calculator.divide(1.5, 4.5);
        assertEquals(0.33333333, quotient, 0.000001);
    }

    @DisplayName("Chia số thực dương cho số thực âm")
    @Test
    void testDividePositiveDoubleByNegativeDouble() {
        double quotient = calculator.divide(1.5, -4.5);
        assertEquals(-0.33333333, quotient, 0.000001);
    }

    @DisplayName("Chia số thực dương lớn nhất cho số thực âm nhỏ nhất")
    @Test
    void testDividePositiveLargestDoubleByNegativeSmallestDouble() {
        double quotient = calculator.divide(Double.MAX_VALUE, -Double.MAX_VALUE);
        assertEquals(-1, quotient);
    }

    @DisplayName("Chia với tử số là 0")
    @Test
    void testDivideZeroByANumber() {
        double quotient = calculator.divide(0, 1);
        assertEquals(0, quotient);
    }

    @DisplayName("Chia cho 0, quăng ngoại lệ ArithmeticException")
    @Test
    void testDivideByZeroExpectArithmeticException() {
        assertThrows(ArithmeticException.class, () -> calculator.divide(1, 0));
    }

    @DisplayName("Nhân số nguyên dương cho số nguyên dương")
    @Test
    void testMultiplyPositiveIntegerByPositiveInteger() {
        double product = calculator.multiply(2, 3);
        assertEquals(6, product);
    }

    @DisplayName("Nhân số nguyên dương cho số nguyên âm")
    @Test
    void testMultiplyPositiveIntegerByNegativeInteger() {
        double product = calculator.multiply(2, -3);
        assertEquals(-6, product);
    }

    @DisplayName("Nhân số thực dương cho số thực dương")
    @Test
    void testMultiplyPositiveDoubleByPositiveDouble() {
        double product = calculator.multiply(1.5, 4.5);
        assertEquals(6.75, product);
    }

    @DisplayName("Nhân số thực dương cho số thực âm")
    @Test
    void testMultiplyPositiveDoubleByNegativeDouble() {
        double product = calculator.multiply(1.5, -4.5);
        assertEquals(-6.75, product);
    }

    @DisplayName("Nhân số thực dương lớn nhất cho số thực âm nhỏ nhất")
    @Test
    void testMultiplyPositiveLargestDoubleByNegativeSmallestDouble() {
        double product = calculator.multiply(Double.MAX_VALUE, -Double.MAX_VALUE);
        assertEquals(Double.NEGATIVE_INFINITY, product);
    }

    @DisplayName("Nhân 2 số thực dương lớn nhất")
    @Test
    void testMultiplyTwoPositiveLargestDoubles() {
        double product = calculator.multiply(Double.MAX_VALUE, Double.MAX_VALUE);
        assertEquals(Double.POSITIVE_INFINITY, product);
    }

    @DisplayName("Nhân 2 số thực âm nhỏ nhất")
    @Test
    void testMultiplyTwoNegativeDoubles() {
        double product = calculator.multiply(-Double.MAX_VALUE, -Double.MAX_VALUE);
        assertEquals(Double.POSITIVE_INFINITY, product);
    }

    @DisplayName("Nhân với một thừa số là 0")
    @Test
    void testMultiplyZeroByANumber() {
        double product = calculator.divide(0, 1);
        assertEquals(0, product);
    }
}