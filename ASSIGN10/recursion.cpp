/*
   COPYRIGHT (C) 2022 David Reese (dcr54@uakron.edu) All rights reserved.
   CS assignment 10
*/

#include <iostream>

// prototypes
template <class T>
void printarray(const T[], int);
void chew_system_stack();

/*
 * Recursive version of fibonacci
 */
int fibrecurse(int n) {
    if(n<=1)
    return n;
    return fibrecurse(n-1) + fibrecurse(n-2);
}

/*
 * Iterative (loop) version of fibonacci
 */
int fibiterate(int n) {
    while(n >= 1)
    {
        &n 
    }
}

/*
 * Recursive quicksort
 */
template <class T>
void quicksort(T ar[], int first, int last) {
    if(first < last)
    {
        // partitioning stage
        int k = ar[last];
        int i = first - 1;
        int temp;

        for (int j=first; j<=(last-1); j++)
        {
           if(ar[j] <= x)
           {
            i++;
            //swap array values
            temp = ar[i];
            ar[i] = ar[j];
            ar[j] = temp;
           }
        }
        //swap array values
        temp = ar[i+1];
        ar[i+1] = ar[last];
        ar[last] = temp; 
        i++;
        
        //revursive call
        quicksort(arr, first, i-1);
        quicksort(arr, i+1, last);
    }
}

int main() {
    const int FIBLOOPS = 10;
    const int ARSIZ = 16;
    int ar[ARSIZ];

    std::cout << "Recursive fib: ";
    for(int i = 0; i < FIBLOOPS; ++i)
    {
        std::cout << fibrecurse(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Iterative fib: ";
    for(int i = 0; i < FIBLOOPS; ++i)
    {
        std::cout << fibiterate(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Quicksort:" << std::endl;
    // populate random array
    for(int i = 0; i < ARSIZ; ++i)
    {
        ar[i] = (i * 3037) % 2099;  // prime numbers! again!
    }
    printarray(ar, ARSIZ);
    quicksort(ar, 0, ARSIZ-1);
    printarray(ar, ARSIZ);

    //std::cout << "Chewing system stack:" << std::endl;
    //chew_system_stack();

    return 0;
}

/*  utility functions, do not modify  */
template <class T>
void printarray(const T ar[], int s)
{
    for(int i = 0; i < s; ++i)
    {
        std::cout << ar[i] << " ";
    }
    std::cout << std::endl;
}

void printstackpointer()
{
    void * stack_pointer;
    // inline assembly language to get stack pointer
    __asm__ __volatile__("movl  %%esp,%%eax"
                             :"=a"(stack_pointer)
                             );
    std::cout << stack_pointer << std::endl;
}

void chew_system_stack()
{
    // Feel free to play with this, but please
    // do NOT enable this for your final commit!
    printstackpointer();
    chew_system_stack();
}
/* end utilities */
