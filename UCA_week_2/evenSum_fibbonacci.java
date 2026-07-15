// sum of even numbers in a fibonacci
//using brute force
import java.util.*; 
public class evenSum_fibbonacci{
     public static void main(String[] args){
       Scanner sc = new Scanner(System.in);
       int n = sc.nextInt();
       int sum=0;
       int a = 1;
       int b = 1;
       int c = 0;
      while(c<=n){
       c = a+b;
       if(c>n){
       System.out.println(sum);
       break;
      }
       //System.out.println("c is"+c);
       if(c%2==0) {
       sum+=c;
       //System.out.println("sum is"+sum);
       }      
       a = b;
       b = c;
       //System.out.println("a is" + a);
       //System.out.println("b is " + b);
     }
      System.out.println(sum);
   }
}
