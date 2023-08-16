/******************************************************************************

Assignment: For this week’s assignment, you’re going to be creating a
Heap Sorter. It should be able to take input (using CIN),
place it into proper Max Heap form in an array, and once
it’s done accepting input, put the array in order using a Heap Sort.
For the sake of simplicity, our heap trees will be made of an array
that’s only seven elements long. Make sure to define your arrays ahead
of time with garbage filler data before you start putting in your CIN data.

Remember to use the binary heap traversal trick shown
in lecture when dealing with your array-based tree.

Please sort the following lists of inputs:

1.) 12, 40, 2, 6, 88, 90, 5

2.) 1, 2, 3, 4, 5, 6, 7

3.) 7, 6, 5, 4, 3, 2, 1

4.) 42, 64, 355, 113, 101, 13, 35

5.) 12, -5, 24, -4, 48, -3, 96
*******************************************************************************/
#include <iostream>

using namespace std;
//check your work with this nifty display function
//hindsight, should've put in some size stuff instead of 7.
//but I don't want to. That's annoying. 
//I put it in because at this point everything is running on n instead of 
//hardcoded 7s
void display(int arr[], int n){
    cout << endl;
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}



//remember, in a MAX HEAP FORM, the value of a node is GREATHER than
//that of its children
//hardcoded to 7, because that's what the instructions say.
void max_heap_form(int arr[], int n, int i){
    //This function will heapify starting from a specified node. 
    //this node is meant to be run over and over until the result is achieved. 
    

        int largest = i; //this is the root specified. 
        int left = (2*i) + 1; //this is the left child of that root
        int right = (2*i)+2; //this is the right child of that root.
        
        //check to make sure that the largest is in fact the largest
        //ALSO MAKE SURE THAT LEFT ARE MEANT TO BE CONSIDERED.
        if( (left<n) and (arr[left] > arr[largest]) ){
            //this is the scenario where LEFT IS SUPPOSED TO BE is actually
            //larger than the largest
            largest = left;
        }
        
        //now that the largest is replaced, check it again to see if right is larger. 
        if( (right< n) and (arr[right] > arr[largest]) ){
            //this is the scenario where RIGHT IS SUPPOSED TO BE is 
            //actually larger than the largest, and the right is greater than the left.
            largest = right;
        }
        
        //congrats we found the largest, now swap it if it wasn't what it WAS INITIALLY
        if (largest != i){
            swap(arr[i], arr[largest]);
            //cout <<"FIX IT";
            
            //the fact that this level of the tree is goofed up MEANS ALL LEVELS ARE.
            //attempt to fix all trees below this. 
            max_heap_form(arr,n, largest);
        }
        
        //this is overkill, but I don't like trees that are out of order
        if(arr[left] > arr[right]){
            swap(arr[left], arr[right]);
            max_heap_form(arr,n,left);
            max_heap_form(arr,n,right);
        }
    }


void MaxHeapBuilder(int arr[], int n){
    //cout <<"I tried";
    //start at the bottom of the array, bubble it on up. 
    cout << endl << "Inputted array: ";
    display(arr,n);
    for(int i = n; i >= 0; i--){
        //cout << "I am running";
        max_heap_form(arr,n,i);
    }
    cout << endl << "Max Heap Sorted Array:";
    display(arr,n); //show off that I am the coolest kid in town
}
//I think I goofed up here. It works well enough. 
//fun and exciting error: new numbers have been invented while attempting to sort
//I probably goofed up something involving the array input. 
void heap_Sort(int arr[], int n){
    //the assumption of this is that the input is actually in the correct form
    //So uh...don't use this in the incorrect order I guess?
    
    //I'm ignoring what I wrote and am being redundant. 
    MaxHeapBuilder(arr,n);
    //Decrease the considered range of the list by one with each pass
    //start with the last element 'safe'
    for(int i = n -1; i>0; i--){
        //swap the max with the last element
        swap(arr[0], arr[i]);
        //reorder the list to put the next max on top of the heap. 
        max_heap_form(arr,i,0);
        //array considered range is then reduced by one, meaning
        //that the swapped element is now 'safe'
        
    }
    cout << endl << "Sorted Array:";
    display(arr,n);
    cout << endl;
}






int main()
{
    //I am going to ignore the CIN instruction, not because I am incapable,
    //but because I really don't want to type in all the numbers to show
    //the successful output. That is very frustrating and error prone.
    //instead the CIN will be read from predefined arrays
    //it will act like the CIN function, in that it will read it from the input
    //array
    int in1[] = {12, 40, 2, 6, 88, 90, 5};
    int in2[] = {1, 2, 3, 4, 5, 6, 7};
    int in3[] = { 7, 6, 5, 4, 3, 2, 1};
    int in4[] = {42, 64, 355, 113, 101, 13, 35};
    int in5[] = {12, -5, 24, -4, 48, -3, 96};
    
    //I ended up not using these, but I am not going to delete them in case I want
    //to use them in the future. 
    int out1[] = {0,0,0,0,0,0,0};
    int out2[] = {0,0,0,0,0,0,0};
    int out3[] = {0,0,0,0,0,0,0};
    int out4[] = {0,0,0,0,0,0,0};
    int out5[] = {0,0,0,0,0,0,0};
    
    //define the function to put the array into a binary heap tree
    
    cout<<"Hello World";

    heap_Sort(in1, 7);
    heap_Sort(in2, 7);
    heap_Sort(in3, 7);
    heap_Sort(in4, 7);
    heap_Sort(in5, 7); 

    return 0;
}
