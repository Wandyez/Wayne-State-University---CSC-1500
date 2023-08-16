/******************************************************************************

Assignment: Create a program which is capable of 
assembling and displaying various sets I will provide you with.
The program must correctly display the result of operators on sets 
(such as Union and Intersection), 
and in addition it must do the following two things: 
First, it must NOT repeat any values that might appear more than once. 
So if you Union two sets together that each have the number ‘5’ somewhere
in them, then ‘5’ should only appear ONCE in the resulting set. 
Second, if the resulting thread is empty, your program must indicate the empty
thread in some recognizable manner, such as displaying “Empty Thread” or “E” or
something similar. Below are the threads you will use. A will serve as our
Universal Set. (100pts total: 60 for program, 5 per problem)

A = {1,2,3,4,5,6,7,8,9,10}

B = {2,4,6,8,10}

C = {1,3,5,7,9}

D = {1,2,3,5,7}

Problem 1.)  B union D

Problem 2.) C intersect D

Problem 3.) A - D

Problem 4.) N(C union D)

Problem 5.) N((C - D) union B)

A reminder, N() indicates the SIZE of the resulting set.
So if you have a set such as A = {1,3,7,10} then N(A) = 4. For problems asking for N(),
your result should be a single number indicating the resulting set’s size.
*******************************************************************************/
#include <iostream>
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
    //Solution, make all arrays same length, hard code. 
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    int B[] = {0,2,0,4,0,6,0,8,0,10};
    int C[] = {1,0,3,0,5,0,7,0,9,0};
    int D[] = {1,2,3,0,5,0,7,0,0,0};
    int problem1[] = {0,0,0,0,0,0,0,0,0,0};
    int problem2[] = {0,0,0,0,0,0,0,0,0,0};
    int problem3[] = {0,0,0,0,0,0,0,0,0,0};
    int problem4[] = {0,0,0,0,0,0,0,0,0,0};
    int problem5[] = {0,0,0,0,0,0,0,0,0,0};
    int problem5part2[] = {0,0,0,0,0,0,0,0,0,0};
    cout << endl << "The answer to  B union D";
    set_union(B,D,problem1);
    print_array(problem1);
    
    cout << endl << "The answer to  C intersect D";
    set_intersect(C,D,problem2);
    print_array(problem2);
    
    cout << endl << "The answer to  A - D";
    set_removal(A,D,problem3);
    print_array(problem3);
    
    cout << endl << "The answer to  N(C union D)";
    set_union(C,D,problem4);
    cout << endl << set_magnitude(problem4);
    
    cout << endl << "The answer to  N((C - D) union B)";
    set_removal(C,D,problem5);
    set_union(problem5,B, problem5part2);
    cout << endl << set_magnitude(problem5part2);
    

    return 0;
}