import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class PercolationTest {

    @Test
    void firstTest() {
        Percolation percolation = new Percolation(2);
        percolation.open(1, 1);
        assertEquals(true, percolation.isOpen(1, 1));
        assertEquals(true, percolation.isFull(1, 1));

        percolation.open(1, 2);
        assertEquals(true, percolation.isOpen(1, 2));
        assertEquals(true, percolation.isFull(1, 2));

        assertEquals(2, percolation.numberOfOpenSites());

        assertEquals(false, percolation.percolates());
    }
}
