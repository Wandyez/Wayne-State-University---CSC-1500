/******************************************************************************
Assignment:  For this assignment you’ll be designing a program which can take
the input of a decimal number and a numerical base, and convert the decimal number 
to that base. For example, if given the decimal number seven and the base two, 
your program should output it as 111, which is how seven is represented in binary.
Another example, 8,943 in base 10, is 13,236 in base 9.

You’ll need to perform these operations on the following combinations:

A: 15, base 2.

B: 38, base 16.

C: 54, base 6.

D: 19, base 8.

E: 27, base 3.

 (100 pts total: 50 points for code, 10 points for each output)
*******************************************************************************/

/* the plan: 
create array? (issue: arrays have to be predefined in their length)
*

%inputnumber
/inputnumber - %inputnumber
*/

#include <iostream>
#include <cmath> //we need the power function

using namespace std;

int main()
{
    //shove everything in a while loop so I don't have to do it again
    //nah I'm too lazy. I'll just take 5 pictures.
    //ugg but then I would need to upload 5 pictures
    //easier to program it. 
    string run = "t";

while (run == "t"){
    int n, base;
    int d = 0; //decimnal places needed.
    cout << "Input the number you wish to convert: " ;
    cin >> n;
    cout << endl << "Input the base to convert the number to: ";
    cin >> base;
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
    for(int i=0;i<d;i++){
        cout << output[d-1-i]; //I keep forgetting arrays start at 0, had to throw in that 1.
    }
    
cout << endl << "Run again? press t" <<endl;
cin >> run;
}
    return 0;
}








