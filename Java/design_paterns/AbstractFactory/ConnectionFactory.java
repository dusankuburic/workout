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
public class ConnectionFactory extends AbstractFactory{

    @Override
    IPhone getPhone(String phoneType) {
        return null;
    }

    @Override
    IConnection getConnection(String connectionType) {
        if(connectionType == null)
            return null;
        else if(connectionType.equalsIgnoreCase("UDP"))
            return new UDPConnection();
        else if(connectionType.equalsIgnoreCase("TCP"))
            return new TCPConnection();
        
        return null;
    }
    
}
