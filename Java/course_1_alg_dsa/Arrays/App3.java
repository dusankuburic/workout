public class App3 {
    
    public static boolean is_anagram(char[] s1, char[] s2){
        if(s1.length != s2.length){
            return false;
        }
        //bottleneck because it has O(NlogN) runnig time
        Arrays.sort(s1);
        Arrays.sort(s2);
        
        //running time is O(N)
        //O(NlogN) + O(N) = O(NlogN)
        for(int i = 0; i < s1.length; i++){
            if(s1[i] != s2[i])
                return false;
        }
        
        return true;
    }
    
    public static void main(String[] args) {

        char[] s1 = {'r','e','s','t','f','u','l'};
        char[] s2 = {'f','l','t','s','t','e','r'};
        
        System.out.println(is_anagram(s1,s2));
        
    }
}
