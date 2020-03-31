package Arrays;

/**
 *
 * @author dusan
 */
public class App {
    public static void main(String[] args) {
        
        int[] nums = new int[5];
        
        for(int i = 1; i < nums.length; ++i)
            nums[i] = 2*i;
        
        //O(1) random index
        int num = nums[2];
        System.out.println(num);
        
        //O(n) linear search -> O(logN) Binary Search Trees -> O(1) hashtables
        for(int i = 0; i < nums.length; ++i)
            if(nums[i] == 4)
                System.out.println("Index found, " + i);
        
        nums[5] = 10;
    }
}
