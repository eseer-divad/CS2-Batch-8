#include "IntArray.h"
#include <iostream>
namespace ComputerScience
{
    IntArray::IntArray(int size)
    {
        //initialize
        length = 0;
        first = last = current = nullptr;
        currentIndex = -1;

        if(size < 0)
        {
            std::cout << "size of the array must be greater than 0";
        }
        else if (size == 0)
        {
            //do nothing because already initialize
        }
        else
        {
            addNodes(size); //add place holders
            //make current pointing to first node
            currentIndex = 0;
            current = first;
        }
    }

    //destructor
    IntArray::~IntArray()
    {
        removeNodes(length);
    }

    //copy constructor to initiate the instance from existing instance
    IntArray::IntArray(const IntArray & r){
        //initialize
        length = 0;
        first = last = current = nullptr;
        currentIndex = -1;

        copyContent(r);
    }
/*
    IntArray& IntArray::operator=(const IntArray& r)
    {
        if(this == &r)  //this is the pointer to itself
        {
            //the address of itself is the same as the address of object a
            //it is doing a=a. So do nothing
            return *this;
        }
        //now the right side IntArray r is not the same object
        removeNodes(length); //clean the list
        copyContent(r); //copy all
        return *this; //return the reference of the object
    }
*/
    //copy the content from another object. Internal use
    void IntArray::copyContent(const IntArray& r)
    {
        //handle array
        if(r.length == 0){
            //do nothing. Current list is already cleaned before this function is called
        }else{
            if(r.length > length){
                //add place holders
                addNodes(r.length - length);
            }else if (r.length < length){
                //remove extra nodes
                removeNodes(length - r.length);
            }
            //copy contents
            ListNode *n1 = first;
            ListNode *n2 = r.first;
            for(int i=0; i<length; i++){
                n1->value = n2->value;
                n1 = n1->next;
                n2 = n2->next;
            }
            //make current node pointing to first node
            currentIndex = 0;
            current = first;
        }
    }

    int IntArray::size() const{
        //getter function to return the size of the array
        return length;
    }

    //subscript overloading, return the reference of i th element
    int& IntArray::operator[](int i){
        if(i < 0 || i >= length){
            //out of range
            std::cout << "the index is out of range";
        }else{
            //make variable current point to the i th node
            //it is the highly possible that users move forward so we check if i == currentIndex + 1 first
            if(i == currentIndex + 1){
                current = current->next;
                currentIndex++;
            }else if(i == currentIndex - 1){ //moving backward
            current = current->previous;
            currentIndex--;
            }else{
                //find the closed node of first, current and last, the move from the closest
                if(abs(i-0) < abs(i-currentIndex)){
                    //first node is closer to i than current node
                    current = first;
                    currentIndex = 0;
                }else if(abs(i-length+1) < abs(i-currentIndex)){
                    //last node is closer
                    current = last;
                    currentIndex = length - 1;
                }
                //move to
                if(i >= currentIndex){
                    //move forward
                    while(currentIndex != i){
                        currentIndex++;
                        current = current->next;
                    }
                }else{
                    //move backward
                    while(currentIndex != i){
                        currentIndex--;
                        current = current->previous;
                    }
                }
            }
        }
        return current->value;
    }

    //overloading operator + to merge two IntArrays
    IntArray IntArray::operator+(const IntArray& r) const{
        //create an instance.
        IntArray merged(length + r.length);

        //copy content from this object first
        ListNode *p1 = merged.first;
        ListNode *p2 = first;
        for(int i=0; i<length; i++){
            p1->value = p2->value;
            p1 = p1->next;
            p2 = p2->next;
        }
        //copy content from r
        //p1 is at the right position, no change
        p2 = r.first;
        for(int i=0; i<r.length; i++){
            p1->value = p2->value;
            p1 = p1->next;
            p2 = p2->next;
        }
        return merged;
    }
    IntArray IntArray::operator+(int val) const
    {
        //overloading operator + to merge IntArrays and an int
        IntArray merged(length + 1); // create an array one element more than this array
        //copy content from this object first
        ListNode *p1 = merged.first;
        ListNode *p2 = first;
        for(int i=0; i<length; i++){
            p1->value = p2->value;
            p1 = p1->next;
            p2 = p2->next;
        }
        //put val to the last node
        //p1 is at last node now
        p1->value = val;
        return merged;
    }
    IntArray& IntArray::operator+=(const IntArray& r){
        //overloading operator += to append r to this array
        if(r.length == 0)
        {
            //appended array is empty, return the reference of this object directly
            return *this;
        }
        //following code works for both a += a; and a += b;
        //remember the last node before appending since last is going to be changed
        ListNode *p1 = last;
        //record r.length since it will be changed after addNodes if doing a += a
        int rLength = r.length;

        addNodes(r.length); //pointer last and member length of this object is changed within addNodes()

        //copying value
        p1 = p1->next; //let p1 starts from the first newly added node
        ListNode *p2 = r.first;
        for(int i=0; i<rLength; i++){
            p1->value = p2->value;
            p1 = p1->next;
            p2 = p2->next;
        }

        return *this;
    }
    IntArray& IntArray::operator+=(int val)
    {
        //overloading operator += to append an int to this array
        addNodes(1);
        last->value = val;
        return *this;
    }
    void IntArray::Resize(int newSize)
    {
        //Resize the array to the length of newSize. It preserves the existing values
        if(newSize <= 0)
            std::cout << "array size must be a positive number";

        if(newSize > length)
        {
            addNodes(newSize - length);
        }
        else
        {
            removeNodes(length - newSize);
        }
    }
    std::ostream& operator<<(std::ostream & out, const IntArray & r)
    {
        //friend function to overload operator << for output
        IntArray::ListNode *p = r.first;
        for(int i=0; i<r.length; i++)
        {
            out << p->value << ' ';
            p = p->next;
        }
        return out;
    }
    std::istream& operator >> (std::istream & in, IntArray& r)
    {
        //friend function to overload operator >> for input
        IntArray::ListNode *p = r.first;
        for(int i=0; i<r.length; i++)
        {
            in >> p->value;
            p = p->next;
        }
        return in;
    }
    IntArray operator+(int val, const IntArray& r)
    {
        //commutative + of IntArray operator+(int)
        IntArray merged(r.length +1); //create an array one element more than this array
        //put val to the first element
        IntArray::ListNode *p1 = merged.first;
        p1->value = val;
        p1 = p1->next; //position at the second node
        IntArray::ListNode *p2 = r.first;
        //copy content from this object
        for(int i=0; i<r.length; i++){
            p1->value = p2->value;
            p1 = p1->next;
            p2 = p2->next;
        }
        return merged;
    }

    IntArray::iterator IntArray::begin()  //return the iterator pointing to the first node
    {
        iterator it(first);
        return it;
    }
    IntArray::iterator IntArray::end()  //return the iterator pointing to an address a little more than that last node
    {
        if(last == nullptr)
        {
            iterator it;
            return it;
        }
        else
        {
            iterator it(last);
            return ++it;
        }
    }

    //**** member functions of iterator
    IntArray::ListNode* IntArray::iterator::noWhere()
    {
        //The list node contains an int (4 bytes) and two ListNode pointers (4 bytes each in 32-bits system
        //                                                                or 8 bytes each in 64-bits system).
        //So an address between &ListNode + 1 byte and &ListNode + 11 bytes serves the purpose
        //since no other list node can be allocated there.
        //We use &ListNode + 3 bytes to do so

        //In order to make an address, we advance 3 bytes from the beginning address of the list node
        //we need to convert the pointer of ListNode to char pointer first
        //the convert back to ListNode pointer after adding 3

        //Directly adding 3 to the pointer of ListNode means to advance 3 blocks of ListNode memory.
        //It does not work because the address advanced may be allocated to other ListNodes
        return (ListNode*)( (char*)p + 3); //p is the pointer to the current ListNode
                         //i.e. the address of current ListNode,
                         // or the address of the first byte of current ListNode
                         //(char*): convert to the pointer of char.
                         //(ListNode*): convert to the pointer of ListNode
    }
    IntArray::iterator::iterator(ListNode* ln) //constructor with a pointer of list node is passed in.
            //ln is default to nullptr in the prototype. So it also contains a default constructor
    {
        p = ln;
    }
    bool IntArray::iterator::operator != (const iterator &right)    //overloading !=
    {
        return !(p == right.p);
    }
    bool IntArray::iterator::operator == (const iterator& right)    //overloading ==
    {
        return p == right.p;
    }
    int & IntArray::iterator::operator*() //dereference operator.
        //It must return the reference of the member value to allow assigning values to *p
    {
        return p->value;
    }
    IntArray::iterator& IntArray::iterator::operator++() //prefix ++. Advancing iterator
    {
        if(p->next == nullptr)
        {
            //p points to the last nodes
            //set p to nowhere() of the node
            p = noWhere();
        }
        else
        {
            p = p->next; //advancing
        }
        return *this;
    }
    IntArray::iterator IntArray::iterator::operator++(int) //potfix ++, parameter is a dummy parameter. Advancing iterator
    {
        iterator it = *this;
        ++(*this); //advance current iterator by reusing prefix ++
        return it;
    }
    IntArray::iterator IntArray::iterator::operator+(int steps) //overloading +, Advancing iterator
                                                //for that many steps specified by the parameter
    {
        iterator previousIt;
        iterator it = *this;
        //advancing
        for(int i=0; i<steps && it.p != nullptr; i++)
        {
            previousIt = it;
            it.p = it.p->next;
        }
        if(it.p == nullptr)
        {
            //it reaches beyond the list range
            //previousIt now points to the last node
            return ++previousIt; //reusing prefix ++ to return an iterator pointing a little after the last node
        }
        else
        {
            return it;
        }

    }
    //*** end of iterator
}


