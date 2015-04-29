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

        sortKlaus();
    }

    public Klaus(Klaus theKlaus) {
        literalArray = new ArrayList<Literal> (theKlaus.getLiteralArray());
    }

    public Klaus(ArrayList<Literal> theArrayList) {
        literalArray = theArrayList;
    }

    public void printKlaus() {
        if(literalArray == null) {
            System.out.println("Det verkar som du har inte har något i din literalarray");
            return;
        }
        for (int i = 0; i < literalArray.size(); i++) {
            ((Literal)literalArray.get(i)).printLiteral(); 
        }
          System.out.println();
    } 

    public void addLiteralArray(ArrayList<Literal> theLiteralArray) {

    }

    public void sortKlaus() {
        Collections.sort(literalArray);
    }

    public ArrayList<Literal> getLiteralArray() {
        return literalArray;
    }

    public Klaus compareKlaus(Klaus B) {
        //Klaus A = literalarray;
        Klaus temp = new Klaus(this);
        temp.getLiteralArray().addAll(B.getLiteralArray());
        
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

        temp.sortKlaus();
        if(temp.getLiteralArray().size() == 0 || sizeBefore == temp.getLiteralArray().size()) {
            return null;
        } else {
            return temp;
        }
            
    }


}