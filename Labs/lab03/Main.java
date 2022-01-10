import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

// Java program for Knight Tour problem
class Main {
    static int N = 8;
 
    static int[] getPawnsPostions(Scanner s, int numberOfPawns){
        int [] pawnsPositionsArray = new int[numberOfPawns];

        int i;
        for(i=0; i<numberOfPawns; i++){
            pawnsPositionsArray[i] = s.nextInt();
        }
        return pawnsPositionsArray;
    }

    static int getKnightPosition(Scanner s){
        int position = s.nextInt();
        return position;
    }

    /* A utility function to check if i,j are
       valid indexes for N*N chessboard */
    static boolean isSafe(int x, int y, int sol[][])
    {
        return (x >= 0 && x < N && y >= 0 && y < N
                && sol[x][y] == -1);
    }
 
    /* A utility function to print solution
       matrix sol[N][N] */
    static void printSolution(int sol[][])
    {
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++)
                System.out.print(sol[x][y] + " ");
            System.out.println();
        }
    }
 
    /* This function solves the Knight Tour problem
       using Backtracking.  This  function mainly
       uses solveKTUtil() to solve the problem. It
       returns false if no complete tour is possible,
       otherwise return true and prints the tour.
       Please note that there may be more than one
       solutions, this function prints one of the
       feasible solutions.  */
    static boolean solveKT(int [] pawnsInitialPositionsArray, int knightInitialPosition)
    {
        int sol[][] = new int[8][8];
 
        /* Initialization of solution matrix */
        int counter = 0;
        int knightX = 0;
        int knightY = 0;
        for (int x = 0; x < N; x++){
            for (int y = 0; y < N; y++){
                if(Arrays.asList(pawnsInitialPositionsArray).contains(counter)){
                    sol[x][y] = 1;
                }
                if(counter == knightInitialPosition-1){
                    sol[x][y] = 0;
                    knightX = x;
                    knightY = y;
                }
                // else{
                //     sol[x][y] = -1;
                // }
                sol[x][y] = -1;
                counter++;
            }
        }
 
        /* xMove[] and yMove[] define next move of Knight.
           xMove[] is for next value of x coordinate
           yMove[] is for next value of y coordinate */
        int xMove[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
        int yMove[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 
        // Since the Knight is initially at the first block
        // sol[0][0] = 0;
 
        /* Start from 0,0 and explore all tours using
           solveKTUtil() */
        if (!solveKTUtil(knightX, knightY, 1, sol, xMove, yMove)) {
            System.out.println("Solution does not exist");
            return false;
        }
        else
            printSolution(sol);
 
        return true;
    }
 
    /* A recursive utility function to solve Knight
       Tour problem */
    static boolean solveKTUtil(int x, int y, int movei,
                               int sol[][], int xMove[],
                               int yMove[])
    {
        int k, next_x, next_y;
        if (movei == N * N)
            return true;
 
        /* Try all next moves from the current coordinate
            x, y */
        for (k = 0; k < 8; k++) {
            next_x = x + xMove[k];
            next_y = y + yMove[k];
            if (isSafe(next_x, next_y, sol)) {
                sol[next_x][next_y] = movei;
                if (solveKTUtil(next_x, next_y, movei + 1,
                                sol, xMove, yMove))
                    return true;
                else
                    sol[next_x][next_y]
                        = -1; // backtracking
            }
        }
 
        return false;
    }
 
    /* Driver Code */
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);

        int numberOfPawns = scanner.nextInt();

        int [] pawnsInitialPositionsArray = getPawnsPostions(scanner, numberOfPawns);

        int knightInitialPosition = getKnightPosition(scanner);

        solveKT(pawnsInitialPositionsArray, knightInitialPosition);
    }
}
// This code is contributed by Abhishek Shankhadhar