/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package queue;

/**
 *
 * @author Zohaib Hassan Soomro
 */
public interface Queue {
    public  Object first();
    public  Object remove();
    public  void add(Object obj);
    public  int size();
    public boolean isEmpty();
}
