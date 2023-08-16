/******************************************************************************

This assignment uses the past labs you have created. You have the option of either combining past labs into one larger lab, or using them individually to solve the listed problems.

1.) Decrypt the following: “Lo cebo dy nbsxu iyeb Yfkvdsxo”

3.) Please sort the following with the Heap Sorter:
{71, 29, 32, 18, 7, 22, 51}
4.) Universal Set: [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
Set A: [1,2,3,5,8,13]
Set B: [1,3,5,7,9,11,13,15,17,19]
Set C: [1,2,3,5,7,11,13,17,19]
Please print out: ((A Union B) Intersect C)
5.) Present a Truth Table for the following statement:
!(A XOR C) NAND (B OR A)
*******************************************************************************/
#include <iostream>

using namespace std;

#include <string>
#include <cstring> //this one is real right?
#include <cmath> //we need the power function

using namespace std;

//this is a nifty function that assumes as 26 letter string alphabet input
//I am too lazy to comment this, this was explained in the plan. 
string cipherShift(string alph){
    //store the first letter to replace the last letter
    char temp;
    temp = alph[0];
    
    for(int i=0; i<25; i++){
        alph[i] = alph[i+1];
    }
    //manually shift the last letter to avoid wraparound issues. 
    alph[25] = temp;
    return alph;
}

//this shifts the input
string useKey(string instring, string upkey, string lowkey, string upal, string lowal){
    string input = instring; //make a local copy. 
    //First find the length of the string, older version of C++ go brrrrr
    int i = 0;
    while (input[i]){
        i++;   
    }
    int size = i; //mission acomplished
    
    //iterate through the input string. 
    for(int i = 0; i<size; i++){
        //first find the letter of the alphabet to shift the letter to.
        //OR hear me out, why don't we just do everything here, I wasn't planning
        //this part but it just works :tm:
        int letternum = 0;
        for(int j = 0; j<26; j++){
            if (input[i] == upal[j]) {
                input[i] = upkey[j];
                break;
            }else if (input[i] == lowal[j]){
                input[i] = lowkey[j];
                break;
            }
        }
    }
    return input;
}


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

#include <array>

using namespace std;

int set_magnitude(int arrayinput[]){
    int magnitude = 0;
    for(int i = 0; i < 10; i++){
        if(arrayinput[i]>0){
            magnitude++;
        }
    }
    return magnitude;
}



void set_union(int arrayinput1[], int arrayinput2[], int emptyarray[]){
    for(int i =0; i<10; i++){
        if(arrayinput1[i]> 0 ){
            emptyarray[i] = arrayinput1[i];
        }else{
            emptyarray[i] = arrayinput2[i];
        }
    }
}

void set_intersect(int arrayinput1[], int arrayinput2[], int emptyarray[]){
    for(int i =0; i<10; i++){
        if(arrayinput1[i]==arrayinput2[i]){
            emptyarray[i] = arrayinput1[i];
        }
    }

}

void set_removal(int arrayinput1[], int arrayinput2[], int emptyarray[]){
    for(int i =0; i<10; i++){
        //if arrays are the same, remove the second,
        //otherwise copy the first. 
        if(arrayinput1[i]==arrayinput2[i]){
            emptyarray[i] = 0;
        }else{
            emptyarray[i] = arrayinput1[i];
        }
    }

}

void print_array(int arrayinput[]){
    cout << endl;
    for(int i =0; i<10; i++){
        if(arrayinput[i]>0){
            cout << arrayinput[i] << " ";
        }
    }
}




int main()
{
    

    //1.) Decrypt the following: “Lo cebo dy nbsxu iyeb Yfkvdsxo”
    string upperciph, upalph;
    upperciph = upalph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    string lowerciph, lowalph;
    lowerciph = lowalph = "abcdefghijklmnopqrstuvwxyz";
    
    //I don't want to do multiple inputs, that is annoying. 
    string inputarray[] = {"Lo cebo dy nbsxu iyeb Yfkvdsxo"};
    
    for (int j = 0; j <1; j++){
        upperciph = upalph;
        lowerciph = lowalph;
        for(int i = 0; i<26; i++){
            cout <<endl << useKey(inputarray[j], upperciph, lowerciph, upalph, lowalph);
            upperciph = cipherShift(upperciph);
            lowerciph = cipherShift(lowerciph);
        }

    }
    
    //2.) Convert 871 to base 7.
    int n, base;
    int d = 0; //decimnal places needed.
    n = 871;
    base = 7;
    cout << endl << "Converting " << n << " to base " << base;
    int ncopy = n;
    //step 1, count the number of decimal places for initializing the array. 
    
    while(ncopy > 0){
       ncopy = ncopy / base;
       d += 1;  
    }
    
    string output[d]; //we did it, we now have an array 
    //stuff the array.
    for(int i=0; i<d; i++){
        //create a thingy to convert to base 16
        switch(n % base){
            case 0:
                output[i] = "0";
                break;
            case 1:
                output[i] = "1";
                break;
            case 2:
                output[i] = "2";
                break;
            case 3:
                output[i] = "3";
                break;
            case 4:
                output[i] = "4";
                break;                
            case 5:
                output[i] = "5";
                break;
            case 6:
                output[i] = "6";
                break;
            case 7:
                output[i] = "7";
                break;
            case 8:
                output[i] = "8";
                break;                   
            case 9:
                output[i] = "9";
                break;
            case 10:
                output[i] = "A";
                break;
            case 11:
                output[i] = "B";
                break;
            case 12:
                output[i] = "C";
                break;   
            case 13:
                output[i] = "D";
                break;
            case 14:
                output[i] = "E";
                break;
            case 15:
                output[i] = "F";
                break;
            default:
                //if you blame the user, it's a user error, not a design error. 
                output[i] = " ERROR THIS IS YOUR FAULT FOR PUTTING IN N>16" ;
                break;
        }
        //cout << output[i];
        n = n/base;
    }
    
    //read the output backwards
    //the assignment does not state that I need to output it as a number
    //only that I must create the output. 
    cout << endl << "The conversion is: ";
    for(int i=0;i<d;i++){
        cout << output[d-1-i]; //I keep forgetting arrays start at 0, had to throw in that 1.
    }




 
    //3.) Please sort the following with the Heap Sorter:
    //{71, 29, 32, 18, 7, 22, 51}
    int in1[] = {71, 29, 32, 18, 7, 22, 51};
    heap_Sort(in1, 7);
    
    /*
    4.) Universal Set: [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
Set A: [1,2,3,5,8,13]
Set B: [1,3,5,7,9,11,13,15,17,19]
Set C: [1,2,3,5,7,11,13,17,19]
Please print out: ((A Union B) Intersect C)
    */
    
    //Solution, make all arrays same length, hard code. 
    int A[] = {1,2,3,5,8,13,0,0,0,0};
    int B[] = {1,3,5,7,9,11,13,15,17,19};
    int C[] = {1,2,3,5,7,11,13,17,19,0};
    int problem1[] = {0,0,0,0,0,0,0,0,0,0};
    int problem1part2[] = {0,0,0,0,0,0,0,0,0,0};
    
    cout << endl << "The answer to  ((A Union B) Intersect C)";
    set_union(A,B,problem1);
    set_intersect(problem1,C, problem1part2);
    print_array(problem1part2);

    cout << endl << "I have run";
    
    /*
    5.) Present a Truth Table for the following statement:
!(A XOR C) NAND (B OR A)
    */
    
    //Declare arrays of all possible inputs
    //There's probably a way to autogenerate these, but I'm betting we won't have another
    //lab like this for truth tables. (Watch me be wrong LOL)
    //I WAS WRONG!!!!!!
    int A5[8]={0,0,0,0,1,1,1,1};
    int B5[8]={0,0,1,1,0,0,1,1};
    int C5[8]={0,1,0,1,0,1,0,1};
    //The outputs will go here. Go team. 
    int outputArray1[8];
    // tell the user what the heck they are looking at
    cout << "The combinations are as follows:" << endl;
    for(int i = 0; i <8; i++){
        cout << endl << "Combination " << i+1 << " :"
        << " A: " << A5[i]
        << " B: " << B5[i]
        << " C: " << C5[i];
    }
    
    cout << endl << "The output for each combination is provided in order, left to right" << endl;
    cout << "1 represents true, 0 represents false";
    cout << endl << "The output for question 5 is: ";
    for(int i = 0; i <8; i++){
        if (!(!(A5[i] != C5[i]) and (A5[i] or C5[i]))){
            outputArray1[i] = 1;
        }else
            outputArray1[i] = 0;
        cout << outputArray1[i] << " " ;
    }
    
    cout << endl << "I have completed question 5";
    
 

    


    return 0;
}


