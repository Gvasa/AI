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
#include <math.h>

using namespace std;


class Node
{
public:
  //Constructor
  Node (vector<int> boardVal = {-1}, int move = -1, Node* prevPtr = nullptr, int h = -1)
      : board (boardVal), moves (move), prev(prevPtr), h1(h)
  {  };

  vector<int> getBoard(){return board;};
  int getZeroPos(){return zeroPos;};
  int getH1(){return h1;};
  int getMoves(){return moves;};
  Node* getPrev(){return prev;};

  void setBoard(vector<int> v){board = v;};
  void setZeroPos(int i){zeroPos = i;};
  void setH1(int i){h1 = i;};
  void setMoves(int i){moves = i;};

private:
    
    Node* prev;
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
int calcMan(vector<int> v);
void addNewMoves(Node* currentBoard, vector<int> possibleMoves, vector<Node*> &ourHeap);
void printVector(vector<int> v);
bool compare(Node* p1, Node* p2);
void printHeap(vector<Node*> theHeap);

vector<int> goalBoard = {1, 2, 3, 4, 5, 6, 7, 8, 0};

int main()
{

    vector<int> startBoard = {5, 4, 0, 1, 2, 3, 7, 6, 8};

    for(int lvl = 19; lvl < 30; lvl+=2) {
      cout << "Lvl: " << lvl << endl;
      vector<Node*> heap = {};
      Node *firstNode = new Node(startBoard,0,nullptr);
      heap.push_back(firstNode);
      Node *currentBoard = heap.front();
      int counter = 0;
      bool stop = false;

      while(currentBoard->getBoard() != goalBoard && !stop) {

        vector<int> possibleMoves = findMoves(currentBoard);
        
        // Calc H1(MAKE THE FUCKING MOVE BUT NOT REALLY) och add to heap
        heap.erase(heap.begin());
        addNewMoves(currentBoard, possibleMoves, heap);
        sort(heap.begin(),heap.end(), compare);

        currentBoard = heap.front();

        while(currentBoard->getMoves() > lvl && !stop) {
          //cout << "Tar ny: " << currentBoard->getMoves() << endl;
          heap.erase(heap.begin());
          currentBoard = heap.front();
          if(heap.size() == 0) {
            cout << "Börja om från början"<< endl;
            stop = true;
          }
            
        }

        counter++;
        if(counter%1000 == 0)
          cout << counter << endl;
      }
      if(currentBoard->getBoard() == goalBoard) {
        cout << "lyckades... mby : antal moves" << currentBoard->getMoves() << "antal loops" << counter;
        break;
      }
    }

    cout << "NOPE, fanns inga under 30 drag" << endl;
    return 0;
}


void addNewMoves(Node* p, vector<int> possibleMoves, vector<Node*> &ourHeap) {

  vector<int> newBoard;
  
  int h1= 0;

  vector<int>::iterator it = possibleMoves.begin();
//  cout << "possible moves are: ";
//  printVector(p->getBoard());

  while(it != possibleMoves.end())
  {

    newBoard = p->getBoard();
    swap(newBoard[*it], newBoard[p->getZeroPos()]);
  //  printVector(newBoard);
    
    //Om vi inte är på första steget och föregående board skulle vara samma så lägg inte till den (hoppa skiten)
  //  cout << "innan contiune" << endl;
    if(p->getMoves() != 0 && newBoard == p->getPrev()->getBoard()) {
      it++;
      continue;
    }
   // cout << "efter continue" << endl;
    //Number of wrong tiles + number of steps taken

    //h1 = calcH1(newBoard) + p->getMoves();
    h1 = calcMan(newBoard) + p->getMoves();

    //cout << "h1: " << h1 << endl;

    ourHeap.push_back(new Node(newBoard, p->getMoves()+1, p, h1));

    it++;
  }
}

int calcH1(vector<int> v) {
    int counter = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] != goalBoard[i])
          counter++;
    }
    return counter;
}

int calcMan(vector<int> v) {
  int counter;
  int xPosV, xPosReal;
  int yPosV, yPosReal;
  for(int i = 0; i < v.size(); i++) {
    xPosV = ((v[i]-1) % 3);    
    yPosV = floor(v[i] / 3);

    xPosReal = i%3;    
    yPosReal = floor(i/3);

    counter += abs(xPosV - xPosReal) + abs(yPosV - yPosReal);
  }
  return counter;
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


bool compare(Node* p1, Node* p2) {
  return (p1->getH1() < p2->getH1());
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

void printHeap(vector<Node*> theHeap) {
  cout << "Current heap: ";
  for(vector<Node*>::iterator it = theHeap.begin(); it != theHeap.end(); it++) {
    cout << (*it)->getH1() << " ";
  }
  cout << endl;

}

