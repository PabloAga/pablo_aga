package ejercicios;

import java.util.Scanner;

public class Ejercicio3 {

    public static void main(String[] args) {
         Scanner entrada= new Scanner(System.in);
        System.out.println("ingrese  primer numero");
        int a=entrada.nextInt();
        System.out.println("ingrese segundo numero");
        int b=entrada.nextInt();
        double total=multiplicacion(a,b);
        System.out.println(total);
    }
    private static double multiplicacion(int a,int b) {
        if(b==1){
            return a;
        }
                return (a+multiplicacion(a,b-1));
    }
}
