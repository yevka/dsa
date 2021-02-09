/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class RandomWord {
    public static void main(String[] args) {
        double i = 0.0d;
        String champion = "";
        while (!StdIn.isEmpty()) {
            i += 1.0d;
            double p = 1.0d / i;
            String newChampion = StdIn.readString();
            if (StdRandom.bernoulli(p))
                champion = newChampion;
        }
        StdOut.println(champion);
    }
}
