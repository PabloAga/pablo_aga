package ejercicios;

import java.util.Scanner;
public class Ejercicio1 {

    public static void main(String[] args) {
        Scanner entrada= new Scanner(System.in);
        System.out.println("ingrese el factorial");
        int a=entrada.nextInt();
        double total=factor(a);
        int d=0;
        for(int c=a;c>=1;c--){
            System.out.println( c+"*"+"f("+(c-1)+")");
            
            for(int m=0;m<=d;m++){
            System.out.print("\t");
         }
            d=d+1;
        }
        System.out.println(total);
    }
    private static double factor(int b){
        if(b!=1){
            return b*factor(b-1);
            }
            return 1;
        }
     
 
        
    }

