/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dsa;

/**
 *
 * @author dusan
 */
public class Program {
    public static void main(String[] args) {
        
        LinkedList list = new LinkedList();
        
        list.insertAtBegin(new ListNode(20));
        list.insertAtBegin(new ListNode(10));
        
        System.out.println(list);
    }
}
