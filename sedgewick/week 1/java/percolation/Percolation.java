import edu.princeton.cs.algs4.WeightedQuickUnionUF;

// 0 - open  - white
// 1 - block - black
// 2 - full  - blue

class Point
{
    public int x;
    public int y;
};

public class Percolation {
    private WeightedQuickUnionUF g;
    private int matrix[][];
    private int openSites;
    private int sizeMatrix;
    private boolean isPercolates;

    private int rootNode[];

    // creates n-by-n grid, with all sites initially blocked
    public Percolation(int n) {
        sizeMatrix = n + 2;
        if (sizeMatrix <= 0) throw new IllegalArgumentException("N must be > 0");
        g = new WeightedQuickUnionUF(sizeMatrix * sizeMatrix);
        matrix = new int[sizeMatrix][sizeMatrix];
        for (int i = 0; i < sizeMatrix; ++i)
            for (int j = 0; j < sizeMatrix ; ++j)
                matrix[i][j] = 1;
        openSites = 0;
        isPercolates = false;

        rootNode = new int[sizeMatrix - 2];
        for(int j = 1;  j < sizeMatrix - 1; ++j) {
            int currSite = xyTo1D(1, j);
            rootNode[0] = currSite;
        }
    }

    // opens the site (row, col) if it is not open already
    public void open(int row, int col) {
        checkIndex(row, col);

        if (matrix[row][col] == 1) {
            matrix[row][col] = 0;
            for (int i = 1; i < sizeMatrix - 1; ++i) {
                for (int j = 1; j < sizeMatrix - 1; ++j) {
                    if (isOpen(i, j)) {
                        int currSite = xyTo1D(i, j);
                        // left
                        if (isOpen(i, j - 1)) {
                            int leftSite = xyTo1D(i, j - 1);
                            g.union(currSite, leftSite);
                        }
                        // right
                        if (isOpen(i, j + 1)) {
                            int rightSite = xyTo1D(i, j + 1);
                            g.union(currSite, rightSite);
                        }
                        // top
                        if (isOpen(i + 1, j)) {
                            int topSite = xyTo1D(i + 1, j);
                            g.union(currSite, topSite);

                        }
                        // bottom
                        if (isOpen(i - 1, j)) {
                            int bottomSite = xyTo1D(i - 1, j);
                            g.union(currSite, bottomSite);
                        }
                    }
                }
            }

            for(int i = 1;  i < sizeMatrix - 1; ++i) {
                for(int j = 1;  j < sizeMatrix - 1; ++j) {
                    int currSite = xyTo1D(i, j);
                    for(int k = 0;  k < sizeMatrix - 2; ++k) {
                        if (g.connected(currSite, rootNode[k])) {
                            matrix[i][j] = 2;
                        }
                    }
                }
            }
        }
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col) {
        // checkIndex(row, col);
        return matrix[row][col] == 0;
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col) {
        // checkIndex(row, col);
        return matrix[row][col] == 2;
    }

    // returns the number of open sites
    public int numberOfOpenSites() {
        return openSites;
    }

    // does the system percolate?
    public boolean percolates() {
        return isPercolates;
    }

    // test client (optional)
    public static void main(String[] args) {

    }

    private int xyTo1D(int x, int y) {
        return x * sizeMatrix + y + 1;
    }

    private Point nToXy(int n) {
        Point p = new Point();
        p.x = 0;
        p.y = 0;
        return p;
    }

    private void checkIndex(int row, int col) {
        if (row < 1) throw new IllegalArgumentException("row must be >= 1");
        if (col < 1) throw new IllegalArgumentException("col must be >= 1");
        if (row > sizeMatrix - 2) throw new IllegalArgumentException("row must be <= N");
        if (col > sizeMatrix - 2) throw new IllegalArgumentException("col must be <= N");
    }

}
