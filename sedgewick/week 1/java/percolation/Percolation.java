import edu.princeton.cs.algs4.WeightedQuickUnionUF;


public class Percolation {
    private int sizeMatrix;
    private WeightedQuickUnionUF g;
    private boolean matrix[][];
    private int openSites;
    private int rootNodes[];
    private int leafNodes[];
    private boolean isPercolate;

    // creates n-by-n grid, with all sites initially blocked
    public Percolation(int n) {
        sizeMatrix = n + 2;
        if (sizeMatrix <= 0)
            throw new IllegalArgumentException("N must be > 0");
        g = new WeightedQuickUnionUF(sizeMatrix * sizeMatrix);
        matrix = new boolean[sizeMatrix][sizeMatrix];
        openSites = 0;
        rootNodes = new int[sizeMatrix - 2];
        leafNodes = new int[sizeMatrix - 2];
        int rootSite = xyTo1D(1, 1);
        int leafSite = xyTo1D(sizeMatrix - 2, 1);
        for(int j = 0;  j < sizeMatrix - 2; ++j) {
            rootNodes[j] = rootSite++;
            leafNodes[j] = leafSite++;
        }
        isPercolate = false;
    }

    // opens the site (row, col) if it is not open already
    public void open(int row, int col) {
        checkIndex(row, col);
        if (!isOpen(row, col)) {
            matrix[row][col] = true;
            openSites += 1;
            int currSite = xyTo1D(row, col);
            if (isOpen(row, col - 1)) { // left
                int leftSite = xyTo1D(row, col - 1);
                g.union(currSite, leftSite);
            }
            if (isOpen(row, col + 1)) { // right
                int rightSite = xyTo1D(row, col + 1);
                g.union(currSite, rightSite);
            }
            if (isOpen(row - 1, col)) { // top
                int topSite = xyTo1D(row - 1, col);
                g.union(currSite, topSite);
            }
            if (isOpen(row + 1, col)) { // bottom
                int bottomSite = xyTo1D(row + 1, col);
                g.union(currSite, bottomSite);
            }
        }
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col) {
        checkIndex(row, col);
        return matrix[row][col];
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col) {
        checkIndex(row, col);
        if (isOpen(row, col)) {
            int currSite = xyTo1D(row, col);
            for(int rootNodeId = 0;  rootNodeId < sizeMatrix - 2; ++rootNodeId) {
                int rootNode = rootNodes[rootNodeId];
                if (connected(currSite, rootNode)) {
                    return true;
                }
            }
        }
        return false;
    }

    // returns the number of open sites
    public int numberOfOpenSites() {
        return openSites;
    }

    // does the system percolate?
    public boolean percolates() {
        if (isPercolate) // cached value
            return true;
        if (openSites < sizeMatrix - 2)
            return false;
        for(int leafNodeId = 0;  leafNodeId < sizeMatrix - 2; ++leafNodeId) {
            int leafNode = leafNodes[leafNodeId];
            for(int rootNodeId = 0;  rootNodeId < sizeMatrix - 2; ++rootNodeId) {
                int rootNode = rootNodes[rootNodeId];
                if (connected(leafNode, rootNode)) {
                    isPercolate = true;
                    return true;
                }
            }
        }
        return false;
    }

    // test client (optional)
    public static void main(String[] args) {

    }

    private int xyTo1D(int x, int y) {
        return (x * sizeMatrix) + y;
    }

    private void checkIndex(int row, int col) {
        if (row < 0)
            throw new IllegalArgumentException("row must be >= 1");
        if (col < 0)
            throw new IllegalArgumentException("col must be >= 1");
        if (row > sizeMatrix + 1)
            throw new IllegalArgumentException("row must be <= N");
        if (col > sizeMatrix + 1)
            throw new IllegalArgumentException("col must be <= N");
    }

    private boolean connected(int p, int q) {
        return g.find(p) == g.find(q);
    }

}
