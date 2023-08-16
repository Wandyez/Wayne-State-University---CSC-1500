/******************************************************************************

Assignment: For this assignment, you will construct a program which is capable
of taking a user-given number, and adding up all of the numbers between 1 and th
e given number. So if someone inputs 12, it should add 1 + 2 + 3 + 4 + … 9 + 10 + 11 + 12, and return the answer.

STUDENT COMMENT: I am assuming this means only integers. 

However, you’ll be using two different methods to do this. 
The first method should utilize either a for loop or a while loop, to simply add the numbers together. 
The second method will meanwhile use the following formula.

Given some number, and told to calculate the sum from 1 to the given number,
you can calculate the answer by simply calculating (X*(X + 1)) / 2

FOR YOUR ASSIGNMENT, you will use both of these methods to return the answer to the user,
specifying which answer came from which method. In addition to simply returning the numbers however,
your program MUST also mention the number of operations that occurred in calculating that answer. 
For this particular assignment we will only count arithmetic operations, adding, subtracting, multiplying, and dividing.
So that if you perform the following: 1 + 2 + 3 + 4 + 5, the result requires FOUR addition operations.

For the two different methods you use, you’ll need your program to return the number of operations
it had to perform to reach its answer. WHAT YOU NEED TO TURN IN, are two very specific scenarios,
as you’ll be supplying the input yourself. First, you need to show a result
in which using the mathematical formula uses fewer operations than using the looping addition.
Second, you need to show a result in which using the looping addition uses fewer operations than the formula.

*******************************************************************************/
#include <iostream>

using namespace std;

//define the functions here so I don't have to think too hard
//remember to include a counter and COUT it
//based on the text of the problem statement, I am assuming the for loop does not count as an artimetic calculation. 

void method1(int num){
    int temp = 0;
    int calculations = 0; //total artimetic operations 
    for (int i = 1; i < (num+1); i++){
        temp += i;
        calculations += 1;
    }
    
    cout << endl << "Method 1's sum is: " << temp;
    cout << endl << "Method 1 took " << calculations << " calculations";
    
}

void method2 (int num){
    int temp = (num*(num+1))/2; //this took 3 arithmetic alculations, I counted by hand. Mission acomplished. 
    cout << endl << "Method 2's sum is: " << temp;
    cout << endl << "Method 2 took " << 3 << " calculations";
}



int main()
{
    int userInput;
    cout<<"Input a number to calculate the sum of all integers from 1 to that number: ";
    cin >> userInput;
    method1(userInput);
    method2(userInput);
    
    return 0;
}