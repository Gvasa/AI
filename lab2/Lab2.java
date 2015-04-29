import java.util.*;
import java.util.ArrayList;

public class Lab2 {

    

    public static void main(String[] args) {

        //Klaus klaus1 = new Klaus("-A+B+C-D");
        //Klaus klaus2 = new Klaus("+A-B+K-P");

        Klaus klaus1 = new Klaus("-A+B");
        Klaus klaus2 = new Klaus("+C-D");


        System.out.println();
        System.out.print("clause 1: " );
        klaus1.printKlaus();
        System.out.print("clause 2: ");
        klaus2.printKlaus();
        
        Klaus resultKlaus = new Klaus(compareKlaus(klaus1,klaus2));
        resultKlaus.printKlaus();

    }

    public static ArrayList<Literal> compareKlaus(Klaus A, Klaus B) {
        Klaus temp = A;
        temp.getLiteralArray().addAll(B.getLiteralArray());
        System.out.println();
        System.out.println("innan borttagning");
        temp.printKlaus();
       
        int sizeBefore = temp.getLiteralArray().size(); 
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
        System.out.println();
        System.out.println("efter borttagning");

        if(temp.getLiteralArray().size() == 0 || sizeBefore == temp.getLiteralArray().size())
            return null;
        else 
            return temp.getLiteralArray();
    }
}
