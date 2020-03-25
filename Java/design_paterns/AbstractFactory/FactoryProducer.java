/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package zift;

/**
 *
 * @author dusan
 */
public class FactoryProducer {
    public static AbstractFactory getFactory(String factoryType){
        
        if(factoryType == null)
            return null;
        else if(factoryType.equalsIgnoreCase("PHONE"))
            return new PhoneFactory();
        else if(factoryType.equalsIgnoreCase("CONNECTION"))
            return new ConnectionFactory();
        
        return null;
    }
}
