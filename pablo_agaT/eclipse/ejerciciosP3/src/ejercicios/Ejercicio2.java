package ejercicios;

import java.util.Scanner;

public class Ejercicio2 {

    public static void main(String[] args) {
        Scanner entrada= new Scanner(System.in);
        System.out.println("ingrese la base");
        int a=entrada.nextInt();
        System.out.println("ingrese el exponente");
        int b=entrada.nextInt();
        double total=power(a,b);
        System.out.print("power ("+a+","+b+")=");//+a+"^"+b+"=");
        for(int i=b; i<=0; i--) {
        	System.out.print(b+"^"+i+"="+b+"*("+b);
        }
        System.out.println(total);
    }
     private static double power(int a,int b) {
         if(b==1){
             return a; 
         }
         return power(a,b-1)*a;
        
     }
}
