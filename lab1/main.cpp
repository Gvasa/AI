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

using namespace std;

class List;

//Define a node of a doubly linked list
class Node
{
    //Constructor
    Node (vector<int> boardVal = {0}, int move = 0, Node* nextPtr = nullptr, Node* prevPtr = nullptr)
        : board (boardVal), moves (move), next (nextPtr), prev(prevPtr)
    {  };

    //Data members
    vector<int> board;
    int moves;
    Node* next; //pointer to the next Node
    Node* prev; //pointer to the previous Node

    friend class List;
    friend ostream& operator<<(ostream& os, const List& L);

};



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

  int operator[](int index) const;

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

*/
bool List::isEmpty() const
{
    return (front->next == tail);
}
/*s

bool List::find(int x) const
{
    //ADD CODE
    return false;
}
*/
void List::makeEmpty()
{
    //ADD CODE
}
/*
int List::operator[](int index) const
{
     Node* p = front->next;

     for(int i = 0; p != tail && i < index; i++, p = p->next) ;

     assert(p != tail);

     return p->value;
}

*/
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
*/

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
*/

ostream& operator<<(ostream& os, const List& L)
{
    int counter = 0;
    if (L.isEmpty())
        os << "List is empty!!";
    else
        os << endl;
        for(Node* p = L.front->next; p != L.tail; p = p->next) {
            for(vector<int>::iterator it = p->board.begin(); it != p->board.end(); ++it) {
                /* std::cout << *it; ... */
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


/*******************************************
* Test: main()                             *
********************************************/

int main()
{
    List L;

    cout << "L: " << L << endl;

    vector<int> goalBoard = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    vector<int> startBoard = {2, 3, 1, 8, 5, 7, 6, 0, 4};
    L.insert(startBoard).insert(goalBoard);

    cout << "L: " << L << endl;



/*
    cout << "Inserting ..." <<endl;
   // L.insert(10).insert(5).insert(15).insert(8).insert(5);

    cout << "L: " << L << endl;

    cout << "L[0] = " << L[0] << endl;
    cout << "L[1] = " << L[1] << endl;
    cout << "L[2] = " << L[2] << endl;
    cout << "L[3] = " << L[3] << endl;

    cout << "\nRemoving ..." <<endl;
    L.remove(8).remove(10).remove(20);

    cout << "L: " << L << endl;
*/
    return 0;
}





