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

class List;

//Define a node of a doubly linked list
class Node
{
public:
  //Constructor
  Node (vector<int> boardVal = {0}, int move = 0, Node* prevPtr = nullptr)
      : board (boardVal), moves (move), prev(prevPtr)
  {  };

  vector<int> board;

private:
    
    //Data members
    
    int moves;
    int h1;
    Node* prev; //pointer to the next Node
    
    friend class List;
    friend ostream& operator<<(ostream& os, const List& L);

};


/*
class List
{
public:

  //constructor: create an empty list
  List();

  //copy constructor
  List(const List &L);

  //destructor
  ~List();

  //assignment operator
  List& operator=(const List &L);

  //Remove all values from the list
  bool isEmpty() const;
  bool find(int x) const;

  Node* operator[](int index) const;

  void makeEmpty();

  List& insert(vector<int> x);
  List& remove(int x);

  friend ostream& operator<<(ostream& os, const List& L);

private:
  Node *front;  //first node
  Node *tail;   //last node

   //Insert a new Node storing val before the Node pointed by p
   void insert(Node *p, vector<int> val, int moves);

   //Remove the Node pointed by p
   void erase(Node *p);
};

/*******************************************
* List member functions implementation     *
********************************************/
/*
// constructor: create an empty list
List::List()
{
    vector<int> foo = {0};
    front = new (nothrow) Node();
    tail = new (nothrow) Node(foo, 0, nullptr, front);

    //for debugging, if the condition is false
    //then the the program aborts execution
    assert (front != nullptr && tail != nullptr);

    front->next = tail;
}

//copy constructor
List::List(const List &L)
{
    //ADD CODE
}

//destructor
List::~List()
{
    makeEmpty();

    delete front;
    delete tail;
}
/*

//assignment operator
List& List::operator=(const List &L)
{
    //ADD CODE
}


bool List::isEmpty() const
{
    return (front->next == tail);
}


bool List::find(int x) const
{
    //ADD CODE
    return false;
}

void List::makeEmpty()
{
    //ADD CODE
}

Node* List::operator[](int index) const
{
     Node* p = front->next;

     for(int i = 0; p != tail && i < index; i++, p = p->next) ;

     assert(p != tail);

     return p;
}


List& List::insert(vector<int> v) //list is sorted
{
    Node* p = front->next;

    //search for insertion point in the list
    while (p != tail)
        p = p->next;

     if (p == tail)
        insert(p, v, p->moves+1); //insert a new Node storing x, before p


     return *this;
}

/*
List& List::remove(int x)
{
    Node* p = front->next;

    //search for node storing x in the list
    while (p != tail && p->value < x)
        p = p->next;

    if (p != tail && p->value == x) //p points to node storing x
        erase(p); //delete the node pointed by p

    return *this;
}


//Insert a new Node storing val before the Node pointed by p
void List::insert(Node *p, vector<int> v, int moves)
{
    p->prev = p->prev->next = new (nothrow) Node(v, moves, p, p->prev);

    assert(p->prev != nullptr);
}
/*
//Remove the Node pointed by p
void List::erase(Node *p)
{
    p->prev->next = p->next;
    p->next->prev = p->prev;

    delete p;
}


ostream& operator<<(ostream& os, const List& L)
{
    int counter = 0;
    if (L.isEmpty())
        os << "List is empty!!";
    else
        os << endl;
        for(Node* p = L.front->next; p != L.tail; p = p->next) {
            for(vector<int>::iterator it = p->board.begin(); it != p->board.end(); ++it) {
                /* std::cout << *it; ... 
                if(counter == 3) {
                     counter = 1;
                    os << endl;
                } else 
                    counter++;

                os << *it << " ";
            }

            counter = 0;
            os << "moves: " << p->moves << endl << endl;
        }
         //   os << p->value << " ";

    os << endl;

    return os;
}
*/

/*******************************************
* Test: main()                             *
********************************************/

vector<int> findMoves(Node* p);

int calcH1(Node* p, vector<int> possibleMoves);

void addNewMoves(Node* currentBoard, vector<int> possibleMoves, vector<Node*> &ourHeap);

int main()
{

    vector<int> goalBoard = {1, 2, 3, 4, 5, 6, 7, 8, 0};
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

    cout << possibleMoves.size();

    // ´Calc H1(MAKE THE FUCKING MOVE BUT NOT REALLY) och add to heap
    addNewMoves(currentBoard, possibleMoves, heap);

    return 0;
}

vector<int> findMoves(Node *p) {
  
  vector<int>::iterator it;
  it = find(p->board.begin(), p->board.end(), 0);
  
  int index = std::distance(p->board.begin(), it);
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

  vector<int>::iterator it = possibleMoves.begin();
  while(it != possibleMoves.end())
  {
    cout << *it << endl;
    it++;
    
  }
}