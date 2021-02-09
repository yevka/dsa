import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    private final int sizeMatrix;
    private boolean[][] matrix;
    private final WeightedQuickUnionUF g;
    private final WeightedQuickUnionUF g2;
    private int openSites;
    private final int virtualTopSite;
    private final int virtualBottomSite;

    // creates n-by-n grid, with all sites initially blocked
    public Percolation(int n) {
        if (n <= 0)
            throw new IllegalArgumentException("N must be > 0");
        sizeMatrix = n;
        matrix = new boolean[sizeMatrix][sizeMatrix];
        int sizeMatrixPow2 = sizeMatrix * sizeMatrix;
        g = new WeightedQuickUnionUF(sizeMatrixPow2 + 2);
        g2 = new WeightedQuickUnionUF(sizeMatrixPow2 + 1);
        openSites = 0;
        virtualTopSite = sizeMatrixPow2;
        virtualBottomSite = sizeMatrixPow2 + 1;
    }

    // opens the site (row, col) if it is not open already
    public void open(int row, int col) {
        checkIndex(row, col);
        openPrivate(row - 1, col - 1);
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col) {
        checkIndex(row, col);
        return isOpenPrivate(row - 1, col - 1);
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col) {
        checkIndex(row, col);
        return isFullPrivate(row - 1, col - 1);
    }

    // returns the number of open sites
    public int numberOfOpenSites() {
        return numberOfOpenSitesPrivate();
    }

    // does the system percolate?
    public boolean percolates() {
        return percolatesPrivate();
    }

    // test client (optional)
    public static void main(String[] args) {
        Percolation percolation = new Percolation(2);
        percolation.open(1, 1);
        if (!percolation.isOpen(1, 1))
            StdOut.printf("test failed: percolation.isOpen(1, 1) != true\n");
        if (!percolation.isFull(1, 1))
            StdOut.printf("test failed: percolation.isOpen(1, 1) != true\n");
        percolation.open(1, 2);
        if (!percolation.isOpen(1, 2))
            StdOut.printf("test failed: percolation.isOpen(1, 2) != true\n");
        if (!percolation.isFull(1, 2))
            StdOut.printf("test failed: percolation.isOpen(1, 2) != true\n");
        if (percolation.numberOfOpenSites() != 2)
            StdOut.printf("test failed: percolation.numberOfOpenSites() != 2\n");
        if (percolation.percolates())
            StdOut.printf("test failed: percolation.percolates() != false\n");
    }

    // opens the site (row, col) if it is not open already
    private void openPrivate(int row, int col) {
        if (!isOpenPrivate(row, col)) {
            matrix[row][col] = true;
            openSites += 1;
            int currSite = xyTo1D(row, col);
            if (row == 0) {
                g.union(currSite, virtualTopSite);
                g2.union(currSite, virtualTopSite);
            }
            if (row == sizeMatrix - 1) {
                g.union(currSite, virtualBottomSite);
            }
            if (col - 1 >= 0 && isOpenPrivate(row, col - 1)) { // left
                int leftSite = xyTo1D(row, col - 1);
                g.union(currSite, leftSite);
                g2.union(currSite, leftSite);
            }
            if (col + 1 < sizeMatrix && isOpenPrivate(row, col + 1)) { // right
                int rightSite = xyTo1D(row, col + 1);
                g.union(currSite, rightSite);
                g2.union(currSite, rightSite);
            }
            if (row - 1 >= 0 && isOpenPrivate(row - 1, col)) { // top
                int topSite = xyTo1D(row - 1, col);
                g.union(currSite, topSite);
                g2.union(currSite, topSite);
            }
            if (row + 1 < sizeMatrix && isOpenPrivate(row + 1, col)) { // bottom
                int bottomSite = xyTo1D(row + 1, col);
                g.union(currSite, bottomSite);
                g2.union(currSite, bottomSite);
            }
        }
    }

    // is the site (row, col) open?
    private boolean isOpenPrivate(int row, int col) {
        return matrix[row][col];
    }

    // is the site (row, col) full?
    private boolean isFullPrivate(int row, int col) {
        if (isOpenPrivate(row, col)) {
            int currSite = xyTo1D(row, col);
            return g2.find(currSite) == g2.find(virtualTopSite);
        }
        return false;
    }

    // returns the number of open sites
    private int numberOfOpenSitesPrivate() {
        return openSites;
    }

    // does the system percolate?
    private boolean percolatesPrivate() {
        return g.find(virtualTopSite) == g.find(virtualBottomSite);
    }

    private int xyTo1D(int x, int y) {
        return (x * sizeMatrix) + y;
    }

    private void checkIndex(int row, int col) {
        if (!(row >= 1))
            throw new IllegalArgumentException("row must be >= 1");
        if (!(col >= 1))
            throw new IllegalArgumentException("col must be >= 1");
        if (!(row <= sizeMatrix))
            throw new IllegalArgumentException("row must be <= N");
        if (!(col <= sizeMatrix))
            throw new IllegalArgumentException("col must be <= N");
    }
}