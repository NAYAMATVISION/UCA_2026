import java.util.*;

class fibonacci_optimized{
     public static void main(String[] args){
       // tc-> O(logn)
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int prev = 2;
      int current = 8;
      int sum = 2; 
      int next = 0;
      while(current <= n){
        sum+=current;
        next = current*4 + prev;
        prev = current;
        current = next;
      }
       System.out.println(sum);

}
}
