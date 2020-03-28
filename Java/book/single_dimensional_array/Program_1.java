
import java.util.Scanner;

public class Program_1 {
    public static void main(String[] args) {
        

        
        char[] city = {'D','a','l','l','a','s'};
        System.out.println(city);
        
        
        double[] myList = new double[10];
        
        Scanner input = new Scanner(System.in);
        System.out.println("Enter" + myList.length + " values:");
        for(int i = 0; i < myList.length; i++)
            myList[i] = input.nextDouble();
        
                
        for(int i = 0; i < myList.length; i++){
            System.out.println(myList[i] + " ");
        }
        
        for(int i = 0; i < myList.length; i++){
            myList[i] = Math.random()*100;
        }
        
        for(int i = 0; i < myList.length; i++){
            System.out.println(myList[i] + " ");
        }
        
                
        double total = 0;
        for(int i = 0; i < myList.length; i++){
            total+=myList[i];
        }
        
        
        double max = myList[0];
        for(int i = 1; i < myList.length; i++){
            if(myList[i] > max)
                max = myList[i];
        }
        
        double max_n = myList[0];
        int indexOfMax = 0;
        for(int i = 1; i < myList.length; i++){
            if(myList[i] > max_n){
                max = myList[i];
                indexOfMax = i;
            }
        }
        
        
        
        for(int i = 1; i < myList.length; i++){
            myList[i-1] = myList[i];
        }
        
        for(double e: myList){
            System.out.println(e);
        }
        
        
       
    }
}