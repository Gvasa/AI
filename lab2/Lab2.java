import java.util.*;
import java.util.ArrayList;

public class Lab2 {

    public static void main(String[] args) {

        //Klaus klaus1 = new Klaus("-A+B+C-D");
        //Klaus klaus2 = new Klaus("+A-B+K-P");

        KnowledgeBase kb = new KnowledgeBase();

        Klaus klaus1 = new Klaus("+A+B+C");
        Klaus klaus2 = new Klaus("-B");
        Klaus klaus3 = new Klaus("-C+D");
        //Klaus klaus4 = new Klaus("+A-D");

        kb.addKlaus(klaus1);
        kb.addKlaus(klaus2);
        kb.addKlaus(klaus3);
        //kb.addKlaus(klaus4);

        System.out.println("Before:");
        kb.printKB();

        kb.checkKB();


        System.out.println("After:");
        kb.printKB();

    }
}
