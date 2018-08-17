package ejercicios;
import java.util.Scanner;

public class Ejercicio4 {
    
    public static void main(String[] args) {
        Scanner entrada= new Scanner(System.in);
        System.out.println("ingrese  primer numero");
        int a=entrada.nextInt();
        System.out.println("ingrese segundo numero que divide al primero");
        int b=entrada.nextInt();
        double total=division(a,b);
        System.out.println(total);
       
    }
    private static double division(int a,int b){
        if(a-b<=0){
            return 1;
        }
        return (division(a-b,b)+1); 
    }
    
}
