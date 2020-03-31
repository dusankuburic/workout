public class App5 {
   
    public static void repeated_numbers(int[] array){
        
        //this is why it is an O(N) running time algorithm
        for(int i = 0; i < array.length; ++i){
            
            //if this vale is positive we have to flip
            if(array[Math.abs(array[i])] > 0){
                array[Math.abs(array[i])] = -array[Math.abs(array[i])];
                //otherwise it is negative: it means repetiton
            } else {
                System.out.println(Math.abs(array[i]) + " is a repetition!");
            }
        }
    }

    
    public static void main(String[] args) {

        int[] array = {2,3,1,2,4,3};
        
        
        repeated_numbers(array);

        
    }
}