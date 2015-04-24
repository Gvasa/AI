public class Literal {
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

}