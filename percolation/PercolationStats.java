import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.StdOut;

public class PercolationStats {
    private double[] thresholds;
    private int N;
    private int T;
    
    public PercolationStats(int N, int T)     // perform T independent experiments on an N-by-N grid
    {
        if (N <= 0 || T <= 0) {
            throw new IllegalArgumentException();
        }
        
        this.N = N;
        this.T = T; 
        this.thresholds = new double[T];
        
        for (int i = 0; i < T; i++) {
            double currentResult = runPercolationExperiment();
            this.thresholds[i] = currentResult;
        }
    }
    
    public double mean()                      // sample mean of percolation threshold
    {
        return StdStats.mean(this.thresholds);
    }
    
    public double stddev()                    // sample standard deviation of percolation threshold
    {
        return StdStats.stddev(this.thresholds);
    }
    
    public double confidenceLo()              // low  endpoint of 95% confidence interval
    {
        return this.mean() - ((1.96 * this.stddev()) / Math.sqrt(this.T));
    }
    
    public double confidenceHi()              // high endpoint of 95% confidence interval
    {
        return this.mean() + ((1.96 * this.stddev()) / Math.sqrt(this.T));
    }
    
    private double runPercolationExperiment() 
    {
        int openSites = 0;
        Percolation experiment = new Percolation(this.N);
        
        while (!experiment.percolates()) {
            int siteI = StdRandom.uniform(this.N) + 1;
            int siteJ = StdRandom.uniform(this.N) + 1;
            
            if (!experiment.isOpen(siteI, siteJ)) {
                experiment.open(siteI, siteJ);
                openSites++;
            }
            
        }
        
        return (double) openSites / (this.N * this.N);
    }
    
    public static void main(String[] args)    // test client (described below)
    {
        int N = Integer.parseInt(args[0]);
        int T = Integer.parseInt(args[1]);
        PercolationStats percResult = new PercolationStats(N, T);

        StdOut.println("mean                    = " + percResult.mean());
        StdOut.println("stddev                  = " + percResult.stddev());
        StdOut.println("95% confidence interval = " + percResult.confidenceLo() + ", " + percResult.confidenceHi());
    }
}