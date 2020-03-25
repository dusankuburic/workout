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
public class HomePhone implements IPhone{

    @Override
    public void make_call() {
        System.out.println("Home phone making call");
    }

    @Override
    public void break_call() {
        System.out.println("Home phone breaking  call");
    }
    
}
