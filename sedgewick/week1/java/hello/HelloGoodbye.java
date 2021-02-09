/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

import edu.princeton.cs.algs4.StdOut;

public class HelloGoodbye {
    public static void main(String[] args) {
        String name1 = args[0];
        String name2 = args[1];
        StdOut.printf("Hello %s and %s.\n", name1, name2);
        StdOut.printf("Goodbye %s and %s.\n", name2, name1);
    }
}
