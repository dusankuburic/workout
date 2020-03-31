package Arrays;

import java.util.*;

/**
 *
 * @author dusan
 */
public class App1 {
    public static void main(String[] args) {
        
        List<String> list = new ArrayList<>();
        
        list.add("Adam");
        list.add("Joe");
        list.add("Kevin");
        list.add("Kevin");
        list.add("Kevin");
        list.add("Kevin");
        
        Object[] array =  list.toArray();
        
        
        for(Object s: array)
            System.out.println(s);

    }
}
