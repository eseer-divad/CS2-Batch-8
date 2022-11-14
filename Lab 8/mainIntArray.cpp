#include <iostream>
#include <algorithm>

using namespace std;
#include "IntArray.h"
int main()
{
    using namespace ComputerScience;
    IntArray a(3);
    //test >>
    cout << "test operator >>" << endl;
    cout << "enter " << a.size() << " integers se[arated by empty space: ";
    cin >> a;

    //test <<
    cout << endl;
    cout << "test operator <<" << endl;
    cout << "echo entered values: " << a << endl;

    //test [] operator
    cout << endl;
    cout << "test operator [] by setting the first element to 22" << endl;
    //set first element to 22
    a[0] = 22;
    cout << "after first element changed to 22, the array is " << a << endl;

    //test copy constructor
    cout << endl;
    cout << "test copy constructor." << endl;
    cout << "IntArray b(a)" << endl;
    IntArray b(a);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    //test assignment
    cout << endl;
    cout << "test assignment c = a:" << endl;
    IntArray c(1);
    c = a;
    cout << "a: " << a << endl;
    cout << "c: " << c << endl;

    //test "IntArray operator+(const IntArray& r) const;"
    cout << endl;
    cout << "test c = a + b;" << endl;
    b[2] = 100;
    c = a + b;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;

    //test "IntArray operator+(int) const;"
    cout << endl;
    cout << "test c = a + 230" << endl;
    c = a + 230;
    cout << "a: " << a << endl;
    cout << "c = a + 230: " << c << endl;

    // test "IntArray& operator+=(const IntArray& r);"
    cout << endl;
    cout << "test a += c" << endl;
    cout << "a: " << a << endl;
    a += 600;
    cout << "after a += 600, a is " << a << endl;

    //test "friend IntArray operator+(int, const IntArray&);"
    cout << endl;
    cout << "test c = 710 + a" << endl;
    cout << "a: " << a << endl;
    c = 710 + a;
    cout << "after c = 710 + a, c is " << c << endl;

    //test a += a;
    cout << endl;
    cout << "test a += a" << endl;
    cout << "a: " << a << endl;
    a += a;
    cout << "after a += a, a is " << a << endl;

    //test member function Resize;
    cout << endl;
    cout << "test a.Resize[5]" << endl;
    cout << "a: " << a << endl;
    a.Resize(5);
    cout << "after a.Resize(5), a is " << a << endl;

    //test traverse by iterator
    cout << endl;
    cout << "test traverse by iterator" << endl;

    for(IntArray::iterator it = a.begin(); it != a.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;

    //test data modification through iterator
    cout << endl;
    cout << "test data modification by iterator" << endl;
    int x = 100;
    for(IntArray::iterator it = a.begin(); it != a.end(); it++)
    {
        *it = x++;
        cout << *it << ' ';
    }
    cout << endl;

    //test operator + of iterator
    cout << endl;
    cout << "test operator + of iterator" << endl;
    int i=0;
    for(IntArray::iterator it = a.begin(); it + i != a.end(); i++)
    {
        cout << *(it+i) << ' ';
    }
    cout << endl;

    IntArray largeArray(120);
    for(int i=0; i<120; i++)
    {
        largeArray[i] = i;
    }

    //fill first 5 values to -3
    fill(largeArray.begin(), largeArray.begin()+5, -3);
    IntArray::iterator position97, positionOfa;
    position97 = find(largeArray.begin(),largeArray.end(), 97);
    positionOfa = search(largeArray.begin(),largeArray.end(),a.begin(),a.end());
    cout << endl << "test using algorith fill, find, search" << endl;
    cout << "values before value 97: ";
    for(IntArray::iterator it = largeArray.begin(); it != position97; ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;
    cout << "values from value 97 to the match point of another IntArray a: ";
    for(IntArray::iterator it = position97; it != positionOfa; ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;
    cout << "values after the match point of another IntArray a: ";
    for(IntArray::iterator it = positionOfa; it != largeArray.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}
