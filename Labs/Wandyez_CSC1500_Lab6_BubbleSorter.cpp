/******************************************************************************

For this assignment, you’ll be creating a Bubble Sort algorithm.
This algorithm is capable of taking a list of numbers and placing them in order,
however it is also known as one of the least efficient means of doing so.

For your assignment, you’ll need to not only sort the given input
(and display it in its final sorted form) but you’ll also need to keep track of how many comparisons,
and reassignments happen. So comparing two numbers will be counted as a SINGLE action.
Swapping the location of two variables will meanwhile be considered THREE actions,
one to store a variable to be swapped in a temporary storage location, 
another to swap the first of the variables to the second location,
and a third to move the variable from the temporary storage location back to where it’s going to go.

So to summarize, comparing two objects in the array will count as ONE action,
and swapping two objects in the array will count as THREE actions.

Your results should not only display the sorted version of the array
, but also a count of the total number of actions that took place while sorting.
Please sort the following three lists.

{1,3,7,5,2,4,6,8,9,10}

{10,9,8,7,6,5,4,3,2,1}

{1,10,2,9,3,8,4,7,5,6}

An example output might look like:

Sorted List: (1,2,3,4,5,6,7,8,9,10) 124 Actions Performed.

(100 pts total: 40 points for code, 20 points for each sorted list plus action count)

*******************************************************************************/
#include <iostream>
using namespace std;

void bubbleSorter(int array[] ){
    //get the array length, if this doesn't work, hardcode it. 
    int arrayLength = 10;
    int steps = 0;
    for(int i=0; i< arrayLength; i++){
        
        for(int j=0; j<(arrayLength - 1 - i); j++) //compare array element to next array element
        //stop compariing when reaching already sorted elements i. (also do not compare +1 beyond bounds)
            if(array[j] > array[j+1]){
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                steps += 4; //comparison and swap
            }else{
                steps += 1; // just comparison. 
                continue;
            }

    }
    cout << endl << "( ";
    for(int i=0; i< arrayLength; i++){
        cout << array[i] << ", ";
    }
    cout << ")";
    
    cout << endl << "Sorting this array took: " << steps << " steps";
}

int main()
{
    int array1[] = {1,3,7,5,2,4,6,8,9,10};
    int array2[] = {10,9,8,7,6,5,4,3,2,1};
    int array3[] = {1,10,2,9,3,8,4,7,5,6};
    bubbleSorter(array1);
    bubbleSorter(array2);
    bubbleSorter(array3);
    return 0;
}



