/***************************************************************************
* TND004, Fö 2                                                             *
* Doubly linked list: nodes are sorted increasingly by the value they store*
* Repeatead values are not allowed                                         *
* **************************************************************************/

#include <iostream>
#include <iomanip>
#include <cassert>
#include <new>
#include <vector>
#include <algorithm>

using namespace std;


class Node
{
public:
  //Constructor
  Node (vector<int> boardVal = {0}, int move = 0, Node* prevPtr = nullptr)
      : board (boardVal), moves (move), prev(prevPtr)
  {  };

  vector<int> getBoard(){return board;};
  int getZeroPos(){return zeroPos;};
  int getH1(){return h1;};
  int getMoves(){return moves;};
  Node* getPrev(){return prev;};

  void setBoard(vector<int> v){board = v;};
  void setZeroPos(int i){zeroPos = i;};
  void setH1(int i){zeroPos = i;};
  void setMoves(int i){moves = i;};

private:
    
    Node* prev; //pointer to the next Node
    vector<int> board;
    int zeroPos;
    int h1;
    int moves;

};


/*******************************************
* Test: main()                             *
********************************************/

vector<int> findMoves(Node* p);
int calcH1(vector<int> v);
void addNewMoves(Node* currentBoard, vector<int> possibleMoves, vector<Node*> &ourHeap);
void printVector(vector<int> v);

vector<int> goalBoard = {1, 2, 3, 4, 5, 6, 7, 8, 0};

int main()
{

    vector<int> startBoard = {2, 3, 1, 8, 5, 7, 6, 0, 4};
    vector<Node*> heap = {};
    Node *firstNode = new Node(startBoard,0,nullptr);
    heap.push_back(firstNode);

    //Nu börjar vår whilelooooop!
    // sorterar heapen beroende på h

    //tar första boarden i heapen och hittar möjliga drag 
    /*
    *   2 3 1
    *   8 5 7
    *   6 0 2
    */  
    Node *currentBoard = heap.front();
    vector<int> possibleMoves = findMoves(currentBoard);
    cout << "zeroPos " << currentBoard->getZeroPos() << endl;

    // ´Calc H1(MAKE THE FUCKING MOVE BUT NOT REALLY) och add to heap
    addNewMoves(currentBoard, possibleMoves, heap);

    return 0;
}

vector<int> findMoves(Node *p) {
  
  vector<int>::iterator it;
  vector<int> v = p->getBoard();
  it = find(v.begin(), v.end(), 0);
  
  int index = std::distance(v.begin(), it);
  p->setZeroPos(index);
  // pos: 0 = upp, 1 = ner, 2 = höger, 3 = vänster;
  
  vector<int> possibleMoves = {};

  switch(index) {
    case 0:
        possibleMoves = {1,3};
      break;
    case 1:
        possibleMoves = {0,2,4};
      break;
    case 2:
        possibleMoves = {1,5};
      break;
    case 3:
        possibleMoves = {0,4,6};
      break;
    case 4:
        possibleMoves = {1,3,5,7};
      break;
    case 5:
        possibleMoves = {2,4,8};
      break;
    case 6:
        possibleMoves = {3,7};
      break;
    case 7:
        possibleMoves = {6,4,8};
      break;
    case 8:
        possibleMoves = {5,7};
      break;
    default:
      cout << "hannes är dum" << endl;

  }


  return possibleMoves;
}

void addNewMoves(Node* p, vector<int> possibleMoves, vector<Node*> &ourHeap) {

  vector<int> newBoard;
  
  int h1= 0;

  vector<int>::iterator it = possibleMoves.begin();
  cout << "possible moves are: ";
  printVector(p->getBoard());

  while(it != possibleMoves.end())
  {
    newBoard = p->getBoard();
   // printVector(newBoard);
    swap(newBoard[*it], newBoard[p->getZeroPos()]);
    printVector(newBoard);
    
    h1 = calcH1(newBoard);
    h1+=p->getMoves();
    cout << "h1: " << h1 << endl;

    it++;
    cout << "***********************" << endl;
  }
  cout << endl;


}

void printVector(vector<int> v) {
  cout << endl << "--- Board ----" << endl;
  int counter = 1;
  for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
  {
    if(counter == 3) {
      cout << *it << endl;
      counter = 1; 
    } else {
      cout << *it << " ";
      counter++;
    }
  }
  cout << endl;
}

int calcH1(vector<int> v) {
    int counter = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] != goalBoard[i])
          counter++;
    }
    return counter;
}