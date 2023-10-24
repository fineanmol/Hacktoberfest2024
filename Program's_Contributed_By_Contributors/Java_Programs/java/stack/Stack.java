/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package stack;

/**
 *
 * @author Zohaib Hassan Soomro
 */
public interface Stack {
    public Object peek();
    public Object pop();
    public void push(Object obj);
    public int size();
    public boolean isEmpty();
          
}
