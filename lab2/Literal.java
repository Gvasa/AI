import java.util.*;
import java.util.ArrayList;

public class Literal implements Comparable<Literal> {
    private char value;
    private boolean positive;

    // CONNSTRUCTOR
    public Literal(char theValue, boolean isPositive) {
        value = theValue;
        positive = isPositive;
    }


    //CLASS MEATHODS
    void printLiteral() {
        System.out.print(positive + "" + value + ", ");
    }

    char getValue() {
        return value;
    }

    boolean getPositive() {
        return positive;
    }

    @Override
    public int compareTo(Literal literal) {
        if(literal.getValue() < this.getValue()) {
            return 1;
        } else if(literal.getValue() == this.getValue()) {
            return 0;
        } else {
            return -1;
        }
    }

}