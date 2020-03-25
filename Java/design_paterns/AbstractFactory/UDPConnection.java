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
public class UDPConnection implements IConnection{

    @Override
    public void connect() {
        System.out.println("UDP making connection");
    }

    @Override
    public void disconnect() {
        System.out.println("UDP disconnecting");
    }
    
}
