import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

import static org.junit.jupiter.api.Assertions.*;

@DisplayName("Kiểm thử package FactorialCalculator")
class FactorialCalculatorTest {
    private FactorialCalculator factorial;

    // Hàm setUp chạy trước khi thực hiện mỗi test
    @BeforeEach
    void setUp() {
        factorial = new FactorialCalculator();
    }

    @DisplayName("Kiểm thử phương thức calculateFactorial với n = 0")
    @Test
    public void testCalculateFactorialForZero() {
        assertEquals(1, FactorialCalculator.calculateFactorial(0));
    }

    @DisplayName("Kiểm thử phương thức calculateFactorial với n = 1")
    @Test
    public void testCalculateFactorialForOne() {
        assertEquals(1, FactorialCalculator.calculateFactorial(1));
    }

    @DisplayName("Kiểm thử phương thức calculateFactorial với n > 1")
    @Test
    public void testCalculateFactorialForPositiveNumber() {
        assertEquals(120, FactorialCalculator.calculateFactorial(5));
    }

    @DisplayName("Kiểm thử phương thức calculateFactorial với n < 0")
    @Test
    public void testCalculateFactorialForNegativeNumber() {
        assertThrows(IllegalArgumentException.class, () -> {
            FactorialCalculator.calculateFactorial(-5);
        });
    }

    @DisplayName("Kiểm thử phương thức calculateFactorial với n lớn")
    @Test
    public void testCalculateFactorialForLargeNumber() {
        assertEquals(3628800, FactorialCalculator.calculateFactorial(10));
    }

    @DisplayName("Kiểm thử phương thức calculateFactorial với n là số thập phân")
    @Test
    public void testCalculateFactorialForDecimalNumber() {
        assertThrows(IllegalArgumentException.class, () -> {
            FactorialCalculator.calculateFactorial(1.5);
        });
    }
}