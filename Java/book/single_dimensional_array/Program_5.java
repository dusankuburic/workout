
public class Program_5 {
    

    public static int linearSearch(int[] list, int key){
        
        for(int i = 0; i < list.length; i++){
            if(key == list[i])
                return i;
        }
        return -1;
    }
    
    public static int binarySearch(int[] list, int key){
        
        int low = 0;
        int high = list.length -1;
        
        while(high >= low){
        int mid = (low+high)/2;
        if(key < list[mid])
            high = mid-1;
        else if(key == list[mid])
            return mid;
        else
            low = mid+1;
        }
        return -1;
    }
    
    public static void selectionSort(double[] list){
        
        for(int i = 0; i < list.length-1; i++){
            double currentMin = list[i];
            int currentMinIndex = i;
            
            for(int j = i +1; j < list.length; j++){
                if(currentMin > list[j]){
                    currentMin = list[j];
                    currentMinIndex = j;
                }
            }
            
            if(currentMinIndex != i){
                list[currentMinIndex] = list[i];
                list[i] = currentMin;
            }
        }
    }
    
    
    public static void main(String[] args) {

       
    }
}
