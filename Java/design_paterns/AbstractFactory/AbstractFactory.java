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
public abstract class AbstractFactory {
    abstract IPhone getPhone(String phoneType);
    abstract IConnection getConnection(String connectionType);
}
