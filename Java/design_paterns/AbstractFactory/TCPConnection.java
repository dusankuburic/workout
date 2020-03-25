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
public class TCPConnection implements IConnection {

    @Override
    public void connect() {
        System.out.println("TCP making connection");
    }

    @Override
    public void disconnect() {
        System.out.println("TCP disconnecting");
    }
    
}
