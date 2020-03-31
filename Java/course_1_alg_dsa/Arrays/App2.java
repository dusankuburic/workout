public class App2 {
    
    public static int[] reverseArray(int[] nums)
    {
        int startIndex = 0;
        
        int endIndex = nums.length-1;
        
        while(endIndex>startIndex){
            
            swap(nums,startIndex,endIndex);
        
            startIndex++;
            endIndex--;
        }
        return nums;
    }
    
    
    private static void swap(int[] nums, int index1, int index2){
        
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
    
    
    
    public static void main(String[] args) {
        
        int[] nums = {1,2,3};
        
        int[] reversedArray = reverseArray(nums);
        
        for(int i = 0; i < reversedArray.length; i++){
            System.out.println(reversedArray[i]);
        }
    }
}
