
import java.util.Scanner;

public class Program {
    



    public static void main(String[] args) {
        
        int[][] matrix = new int[10][10];
        
        Scanner input = new Scanner(System.in);
        System.out.println("Enter " + matrix.length + " rows and " + matrix[0].length + " columns: ");
        for(int row = 0; row < matrix.length; row++){
            for(int column = 0; column < matrix[row].length; column++){
                matrix[row][column] = input.nextInt();
            }
        }
        
        for(int row = 0; row < matrix.length; row++){
            for(int column = 0; column < matrix[row].length; column++){
                matrix[row][column] = (int)(Math.random()*100);
            }
        }
        
        for(int row = 0; row < matrix.length; row++){
            for(int column = 0; column < matrix[row].length; column++){
                System.out.println(matrix[row][column]);
            }
            System.out.println();
        }
        
        
        int total = 0;
        for(int row = 0; row < matrix.length; row++){
            for(int column = 0; column < matrix[row].length; column++){
                total += matrix[row][column];
            }
        }
        
        int Total = 0;
        for(int column = 0; column < matrix[0].length; column++){
           
            for(int row = 0; row < matrix.length; row++){
                Total += matrix[row][column];
            }
            System.out.println("Sum for column " + column + " is " + Total);
            Total = 0;
        }

        
        int maxRow = 0;
        int indexOfMaxRow = 0;
        
        for(int column = 0; column < matrix[0].length; column++){
            maxRow += matrix[0][column];
        }
        
        for(int row = 1; row < matrix.length; row++){
            int totalOfThisRow = 0;
            for(int column = 0; column < matrix[row].length; column++)
                totalOfThisRow += matrix[row][column];
            
            if(totalOfThisRow > maxRow){
                maxRow = totalOfThisRow;
                indexOfMaxRow = row;
            }
        }
        
        System.out.println("Row " + indexOfMaxRow + " has the maximum sum of " + maxRow);
        
    }
}
