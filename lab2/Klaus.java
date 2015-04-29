import java.util.*;
import java.util.ArrayList;

public class Klaus {
    private ArrayList<Literal> literalArray;

    //CONSTRUCTORS
    public Klaus() {
        literalArray = new ArrayList<Literal>();
    }

    public Klaus(String theLiterals) {
        literalArray = new ArrayList<Literal>();
        boolean positive;
        for(int i = 0; i < theLiterals.length(); i += 2) {
            if(theLiterals.charAt(i) == '+')
                positive = true;
            else
                positive = false;

            literalArray.add(new Literal(theLiterals.charAt(i+1), positive));
        } 
        
    }

    public Klaus(Klaus theKlaus) {
        literalArray = theKlaus.getLiteralArray();
    }

    public Klaus(ArrayList<Literal> theArrayList) {
        literalArray = theArrayList;
    }

    //CLASS METHDOS
    void printKlaus() {
        if(literalArray == null) {
            System.out.println("Det verkar som du har inte har något i din literalarray");
            return;
        }
        for (int i = 0; i < literalArray.size(); i++) {
            ((Literal)literalArray.get(i)).printLiteral(); 
        }
          System.out.println();
    } 

    void addLiteralArray(ArrayList<Literal> theLiteralArray) {

    }

    ArrayList<Literal> getLiteralArray() {
        return literalArray;
    }


}