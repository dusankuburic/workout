package Singleton_Bill_Pugh_implementation;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author dusan
 */
public class Singleton {
    
    
    private int data = 0;
    
    private Singleton(){
        
    }
    
    private static class SingletonHelper {
        private static final Singleton uniqueInstance = new Singleton();
    }
    
    public static Singleton getInstance(){
       
        return SingletonHelper.uniqueInstance;
    }
    
    public void setData(int myData){
        this.data = myData;
    }
    
    public int getData(){
        return data;
    }
}
