import java.util.*;
import java.util.ArrayList;
import java.io.Console;

public class KnowledgeBase {
    private ArrayList<Klaus> KB;

    public KnowledgeBase() {
        KB = new ArrayList<Klaus>();
    }

    public void addKlaus(Klaus theKlaus) {
        KB.add(theKlaus);
    }

    public void checkKB() {
    	int sizeOfKB = KB.size();
    	int index = 0;

    	//System.out.println("SIZE KB: " + sizeOfKB);

    	while(index < (sizeOfKB-1)) {
    		//System.out.println("SIZE KB: " + sizeOfKB);
    		for(int i = index+1; i < sizeOfKB; i++) {
    			Klaus newK = KB.get(index).compareKlaus(KB.get(i));
		    	if(newK != null && !checkIfExist(newK)) {
		    		//System.out.print("Add to KB");
		    		//System.console().readLine();
		    		//newK.printKlaus();
		    		KB.add(newK);
		    		index = 0;
		    		sizeOfKB = KB.size();
		    	}
    		}
    		index++;
    	}
    }

    private boolean checkIfExist(Klaus checkKlaus) {
    	//System.out.println("CHECK");
 			
    	ArrayList<Literal> checkList = checkKlaus.getLiteralArray();
    	int sizeCL = checkList.size();

    	for(int i = 0; i < KB.size(); i++) {

    		ArrayList<Literal> tempList = KB.get(i).getLiteralArray();
    		int sizeTL = tempList.size();
    		if(sizeTL != sizeCL){

    			//System.out.println("False - storlek");
    			continue;
    		} else {
    			//System.console().readLine();
    			// System.out.println("-------------NEW----------------");
    			// System.out.println("KLAUS A");
    			// checkKlaus.printKlaus();
    			// System.out.println("KLAUS B");
    			// KB.get(i).printKlaus();
    			// System.out.println();
    			int counter = 0;
    			for(int j = 0; j < sizeTL; j++) {
    				// System.out.println("SizeTL = " + tempList.get(j).getValue());
    				// System.out.println("SizeCL = " + checkList.get(j).getValue());
    				// System.out.println("-----------------------------");

    				if(tempList.get(j).getValue() == checkList.get(j).getValue()) {
    					
    					counter++;
    				}
    				if(counter == sizeCL) {
    					//System.out.println("True");
    					return true;
    				}
    			}
    		}
    	}
    	//System.out.println("False");
    	return false;
    }

    public void printKB() {
    	for (int i = 0; i < KB.size(); i++) {
    		System.out.print("Klaus " + (i+1)+": ");
	      ((Klaus)KB.get(i)).printKlaus(); 
	    }
    }

}