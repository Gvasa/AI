import java.util.*;
import java.util.ArrayList;

public class Lab2 {

    

    public static void main(String[] args) {
        System.out.println("Hello, World newbs");


        Klaus foo = new Klaus("-A+B+C-D");
        Klaus bar = new Klaus("+A-B+K-P");
        foo.printKlaus();
        bar.printKlaus();
        
        Klaus temp = new Klaus(compareKlaus(foo,bar));
        
        //temp.getLiteralArray().remove(bar.getLiteralArray())
        //temp.printKlaus();

    }

    public static ArrayList<Literal> compareKlaus(Klaus A, Klaus B) {
        Klaus temp = A;
        temp.getLiteralArray().addAll(B.getLiteralArray());
        System.out.println("innan borttagning");
        temp.printKlaus();
       
        
        int index = 0;
        boolean done = false;
        while(index != temp.getLiteralArray().size()) {

            Literal currentLiteral = temp.getLiteralArray().get(index);
          
            for(int i = index + 1; i < temp.getLiteralArray().size(); i++) {
                if(currentLiteral.getValue() == temp.getLiteralArray().get(i).getValue() &&
                   currentLiteral.getPositive() != temp.getLiteralArray().get(i).getPositive() ) {
                    temp.getLiteralArray().remove(i);
                    temp.getLiteralArray().remove(index);
                    index = -1;
                    break;
                }
            }
        index++;

        }
        System.out.println("efter borttagning");
        temp.printKlaus();
        return temp.getLiteralArray();
    }
}
