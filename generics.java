class Demo <T>{
            T val ;
        void display (T val) {
            this.val = val ;
            System.out.println(val) ;
        }
}
class Demo2{
     public <T> void display  ( T data) {
        System.out.println(data) ;
     }
}

public class generics  {
    public static void main (String args[])  {
        Demo <Integer>a   = new Demo<>() ; 
        a.display(3) ; 
        Demo <String> b  = new Demo() ; 
        b.display("hello") ;
        
        Demo2 c = new Demo2() ; 
        c.<Integer>display(100) ; 
        Demo2 d = new Demo2() ; 
        c.<String>display("HEllo") ; 
    }
}