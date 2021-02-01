import edu.princeton.cs.algs4.WeightedQuickUnionUF;

// 0 - open  - white
// 1 - block - black
// 2 - full  - blue

public class Percolation {
    private WeightedQuickUnionUF g;
    private int matrix[][];
    private int openSites;
    private int sizeMatrix;
    private boolean isPercolates;

    private int rootNodes[];
    private int leafNodes[];

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

        rootNodes = new int[sizeMatrix - 2];
        int i = 0;
        for(int j = 1;  j < sizeMatrix - 1; ++j) {
            int currSite = xyTo1D(1, j);
            rootNodes[i] = currSite;
            i += 1;
        }

        i = 0;
        leafNodes = new int[sizeMatrix - 2];
        for(int j = 1;  j < sizeMatrix - 1; ++j) {
            int currSite = xyTo1D(sizeMatrix - 1, j);
            leafNodes[i] = currSite;
            i += 1;
        }
    }

    // opens the site (row, col) if it is not open already
    public void open(int row, int col) {
        checkIndex(row, col);

        if (matrix[row][col] == 1) {
            matrix[row][col] = 0;
            openSites += 1;
            int currSite = xyTo1D(row, col);
            g.union(currSite, currSite);
            if (isOpen(row, col - 1) || isFull(row, col - 1)) { // left
                int leftSite = xyTo1D(row, col - 1);
                g.union(currSite, leftSite);
            }
            if (isOpen(row, col + 1) || isFull(row, col + 1)) { // right
                int rightSite = xyTo1D(row, col + 1);
                g.union(currSite, rightSite);
            }
            if (isOpen(row - 1, col) || isFull(row -1, col)) { // top
                int topSite = xyTo1D(row - 1, col);
                g.union(currSite, topSite);
            }
            if (isOpen(row + 1, col) || isFull(row + 1, col)) { // bottom
                int bottomSite = xyTo1D(row + 1, col);
                g.union(currSite, bottomSite);
            }

            for(int i = 1;  i < sizeMatrix - 1; ++i) {
                for(int j = 1;  j < sizeMatrix - 1; ++j) {
                    currSite = xyTo1D(i, j);
                    for(int k = 0;  k < sizeMatrix - 2; ++k) {
                        int rootNode = rootNodes[k];
                        if (isOpen(i, j) && g.connected(currSite, rootNode)) {
                            matrix[i][j] = 2;
                            openSites -= 1;
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
        for(int leafNodeId = 0;  leafNodeId < sizeMatrix - 2; ++leafNodeId) {
            int leafNode = leafNodes[leafNodeId];
            for(int rootNodeId = 0;  rootNodeId < sizeMatrix - 2; ++rootNodeId) {
                int rootNode = rootNodes[rootNodeId];
                if (g.connected(rootNode, leafNode)) {
                    isPercolates = true;
                    break;
                }
            }
        }
        return isPercolates;
    }

    // test client (optional)
    public static void main(String[] args) {

    }

    private int xyTo1D(int x, int y) {
        return (x * sizeMatrix) + y;
    }

    private void checkIndex(int row, int col) {
        if (row < 1) throw new IllegalArgumentException("row must be >= 1");
        if (col < 1) throw new IllegalArgumentException("col must be >= 1");
        if (row > sizeMatrix - 2) throw new IllegalArgumentException("row must be <= N");
        if (col > sizeMatrix - 2) throw new IllegalArgumentException("col must be <= N");
    }

}