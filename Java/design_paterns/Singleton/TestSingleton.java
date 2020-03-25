/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Singleton_Bill_Pugh_implementation;

/**
 *
 * @author dusan
 */
public class TestSingleton {
    
    public static void main(String[] args) {
        
        Singleton  s = Singleton.getInstance();
        
        //set the data 
        s.setData(55);
        
        System.out.println("First reference: " +s);
        System.out.println("Singleton data value is: " + s.getData());
        
        
        s = null;
        
        s = Singleton.getInstance();
        
        System.out.println("\nSecond reference: " +s);
        System.out.println("Singleton data value is: " + s.getData());
    }
    
}
