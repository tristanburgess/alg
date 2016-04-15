import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    private WeightedQuickUnionUF wq, wqBW;
    private boolean[][] grid;
    private int N, top, bottom;
    
    public Percolation(int N) // create N-by-N grid, with all sites blocked
    {
        if (N <= 0) {
            throw new IllegalArgumentException();
        }
           
        this.wq = new WeightedQuickUnionUF(N * N + 2);
        this.wqBW = new WeightedQuickUnionUF(N * N + 1);
        this.grid = new boolean[N][N]; 
        this.N = N;
        this.top = 0;
        this.bottom = N * N + 1;
    }
    
    public void open(int i, int j)          // open site (row i, column j) if it is not open already
    {
        if (!validateArgs(i, j)) {
            throw new IndexOutOfBoundsException();
        }

        if (!isOpen(i, j)) {     
            this.grid[i - 1][j - 1] = true;
            int current = xyTo1D(i, j);
            
            // top
            if (i - 1 == this.top) {
                this.wq.union(current, this.top);
                this.wqBW.union(current, this.top);
            }               
            // bottom
            if (i * i + 1 == this.bottom) {
                this.wq.union(current, this.bottom);
            }
            // left
            if (validateArgs(i, j - 1) && isOpen(i, j - 1)) {
                this.wq.union(current, xyTo1D(i, j - 1));
                this.wqBW.union(current, xyTo1D(i, j - 1));
            }
            // right
            if (validateArgs(i, j + 1) && isOpen(i, j + 1)) {
                this.wq.union(current, xyTo1D(i, j + 1));
                this.wqBW.union(current, xyTo1D(i, j + 1));
            }
            // up
            if (validateArgs(i - 1, j) && isOpen(i - 1, j)) {
                this.wq.union(current, xyTo1D(i - 1, j));
                this.wqBW.union(current, xyTo1D(i- 1, j));
            }
            // down
            if (validateArgs(i + 1, j) && isOpen(i + 1, j)) { 
                this.wq.union(current, xyTo1D(i + 1, j));
                this.wqBW.union(current, xyTo1D(i + 1, j));
            }
            
        }
    }
    
    public boolean isOpen(int i, int j)     // is site (row i, column j) open?
    {
        if (!validateArgs(i, j)) {
            throw new IndexOutOfBoundsException();
        }
        
        return this.grid[i - 1][j - 1];
    }
    
    public boolean isFull(int i, int j)     // is site (row i, column j) full?
    {
        if (!validateArgs(i, j)) {
            throw new IndexOutOfBoundsException();
        }
     
        return this.wqBW.connected(this.top, xyTo1D(i, j));
    }
    
    public boolean percolates()             // does the system percolate?
    {
        return this.wq.connected(this.top, this.bottom);
    }
    
    private boolean validateArgs(int i, int j) {
        return !(i < 1 || i > N || j < 1 || j > N);
    }
    
    private int xyTo1D(int i, int j) {
        return this.N * (i - 1) + j;
    }
    
    public static void main(String[] args)  // test client (optional)
    {
    }
}