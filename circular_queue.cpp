#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

class CircularQueue {

    public:
        CircularQueue(int cap = 10);
        ~CircularQueue();
        void enqueue(int val);
        void dequeue();
        bool isFull() const;
        bool isEmpty() const;
        void expand();
        friend ostream & operator<<(ostream & out, const CircularQueue & cQ);
        int getCapacity() const;
        int getSize() const;
        int getFront() const;
        int getBack() const;

    private:
        int currentSize;
        int *theArray;
        int capacity;
        int front;
        int back;

};

CircularQueue::CircularQueue(int cap)// constructor
{
    capacity= cap;
    front =0;
    back=-1;
    theArray= new int[cap]; // creating a dynamic arry.
    
}

CircularQueue::~CircularQueue() // deleting the arry.
{
    delete [] theArray;
    
}

int CircularQueue::getCapacity() const // returning the capacity.
{
    return capacity;
}

int CircularQueue::getSize() const
{
    return currentSize;
}

bool CircularQueue::isFull() const
{
    if (currentSize==capacity)
        return true;
    else
        return false;
}

bool CircularQueue::isEmpty() const
{
    if(currentSize==0)
        return true;
    else
        return false;
}

int CircularQueue::getFront() const
{
    return front;
}

int CircularQueue::getBack() const
{
    return back;
}

void CircularQueue::expand()
{

    int old_capacity= capacity;
    capacity= capacity*2; // expanding the capacity.
    int* newArry= new int [capacity];
    int i=0;
    int j=0;
    
    if ( front==0 && back==old_capacity-1) // case#1: when front index is before the back index
    {
        for (int i=0; i<=back; i++)
        {
            newArry[i]= theArray[i];
        }
    }
    else    // case#2: when back index is before the front index.
    {
    
        while (front<=old_capacity-1) // copying from front index to the end of the arry.
        {
            newArry[i]= theArray[front];
            front++;
            i++;
        }
        while (j<=back)  // Then, copying from index=0 to back index.
        {
            newArry[i]= theArray[j];
            j++;
            i++;
        }
    }
    
    front= 0; // after expanding, assigning the front to 0 index.
    back= old_capacity-1; // after expanding, assigning the back index to old_capacity-1
    delete [] theArray; // deleting the adress that theArry was pointing to.
    theArray= newArry; //  assigning the address of the newArr to theArray.
}

void CircularQueue::enqueue(int val)
{
    int old_capacity= (capacity/2)-1;
    if (isFull()==true) // case#1 : if the enque is full, expand it.
    {
        expand();
        back++;
        theArray[back]= val;
        currentSize++;
    }
    
    else if ((back==capacity-1) && (front!=0)) // case#2 : when back is at the last index but the front is not in the 0 index.
    {
        back=0;
        theArray[back]= val;
        currentSize++;
    }
    else // case#3: otherwise
    {
        back++;
        theArray[back]= val;
        currentSize++;
    }
       
}
void CircularQueue::dequeue()
{
    if (isEmpty()==true) // case#1: when the queue is empty, returns 0.
    {
        cout<< "The Queue is empty so deque() operation can not be performed." <<endl;
    }
    
    if ( front==capacity-1) // case#2: when front is at the last index.
    {
        front=0;
        currentSize--;
    }
    
    else //case#3: otherwise.
    {
        front++;
        currentSize--;
    }
        
}


ostream & operator<<(ostream & out, const CircularQueue & cQ) {
    if(cQ.isEmpty()) {
        cout << "The queue is empty." << endl;
    }

    else {
        cout << "The queue is ";
        int i = cQ.front;
        while(i != cQ.back) {
            out << cQ.theArray[i] << " ";
            i = (i + 1) % (cQ.capacity);
        }
        out << cQ.theArray[i] << endl;
    }

    cout << "currentSize = " << cQ.getSize() << endl;
    cout << "front = " << cQ.getFront() << endl;
    cout << "back = " << cQ.getBack() << endl;
    cout << "capacity = " << cQ.getCapacity() << endl;
    return out;
}

int main()
{
    CircularQueue cq(10);
   
    cq.enqueue(8);
    cout<< cq <<endl;
    cq.enqueue(5);
    cout<< cq <<endl;
    cq.dequeue();
    cout<< cq <<endl;
    cq.dequeue();
    cout<< cq <<endl;
    cq.enqueue(7);
    cout<< cq <<endl;
    cq.enqueue(8);
    cout<< cq <<endl;
    cq.enqueue(9);
    cout<< cq <<endl;
    cq.enqueue(11);
    cout<< cq <<endl;
    cq.dequeue();
    cout<< cq <<endl;
    cq.dequeue();
    cout<< cq <<endl;
    cq.dequeue();
    cout<< cq <<endl;
    cq.enqueue(3);
    cout<< cq <<endl;
    cq.enqueue(4);
    cout<< cq <<endl;
    cq.enqueue(18);
    cout<< cq <<endl;
    cq.enqueue(21);
    cout<< cq <<endl;
    cq.enqueue(13);
    cout<< cq <<endl;
    cq.enqueue(15);
    cout<< cq <<endl;
    cq.dequeue();
    cout<< cq <<endl;
    cq.dequeue();
    cout<< cq <<endl;
    
}

