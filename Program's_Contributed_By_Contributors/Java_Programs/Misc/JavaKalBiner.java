/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javakalbiner;

import java.util.Scanner;

/**
 *
 * @author thinkpad
 */
public class JavaKalBiner {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String desimal = "";
        String nol = "00000000";
        
        System.out.print("Masukkan angka desimal : ");
        desimal = sc.nextLine();
        System.out.println("Masukan anda adalah : " + desimal);
        Integer angka = Integer.valueOf(desimal);
        String biner = Integer.toBinaryString(angka);
        biner = nol.substring(desimal.length()) + biner;
        System.out.println("Nilai biner adalah : " + biner);
    }

}
