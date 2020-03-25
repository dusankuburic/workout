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
public class PhoneFactory extends AbstractFactory {

    @Override
    IPhone getPhone(String phoneType) {
        if(phoneType == null)
            return null;
        else if(phoneType.equalsIgnoreCase("MOBILE"))
            return new MobilePhone();
        else if(phoneType.equalsIgnoreCase("HOME"))
            return new HomePhone();
        
        return null;
    }

    @Override
    IConnection getConnection(String connectionType) {
        return null;
    }
    
}
