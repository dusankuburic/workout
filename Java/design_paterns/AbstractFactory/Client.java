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
public class Client {
    public static void main(String[] args) {
        
        AbstractFactory phoneFact = FactoryProducer.getFactory("PHONE");
        
        IPhone phone1 = phoneFact.getPhone("MOBILE");
        phone1.make_call();
        phone1.break_call();
        
        IPhone phone2 = phoneFact.getPhone("HOME");
        phone2.make_call();
        phone2.break_call();
        
        
        AbstractFactory connectionFact = FactoryProducer.getFactory("CONNECTION");
        
        IConnection conn1 = connectionFact.getConnection("TCP");
        conn1.connect();
        conn1.disconnect();
        
        IConnection conn2 = connectionFact.getConnection("UDP");
        conn2.connect();
        conn2.disconnect();
        
    }
}
