/******************************************************************************

Assignment: Create a program which can test the validity of propositional logic. Remember, a propositional logical statement is invalid should you find any combination of input where the PROPOSITIONAL statements are ALL true, while the CONCLUSION statement is false.

Propositional Statements:

If someone has a rocket, that implies they’re an astronaut.
r <= a

If someone is an astronaut, that implies they’re highly trained.
a <= h
If someone is highly trained, that implies they’re educated.
h <=e


Conclusion Statement:

A person is educated, that implies they have a rocket.
e <= r

Your output should declare the statement to either be valid or invalid. If it’s invalid, it needs to state which combination of inputs yielded the statement invalid. MAKE SURE IT POINTS OUT EVERY TIME THE STATEMENT IS INVALID IF IT IS INDEED INVALID.

(50pts code, 50pts for output)

*******************************************************************************/


//Why not? Include everything.
#include <iostream>
#include <array>
#include <cmath>


using namespace std;

int main()
{
    bool invalid = false;
    
    //NOTES: IGNORE THESE. THEY ARE UNIMPORTANT APPARENTLY.
    //Solution plan: Solution doesn't require input, we can handle that later
        //1.) Create truth tables 
        //three things to compare means arrays of length 8 for each statement to test. 
        //still need to create an autogenerator for those one of these days. but that's not required in the assignment. 
        //2.) Compare logical outputs to make sure it points out when invalid
        //for this section, educated should always lead to rocket, therefore any time a person is educated and DOES NOT have a ocket is false
        //this is what we are checking for. 
        //statement to validate 
    //how many combinations do we need to test? 2^inputs
    //int inputs = 4;
    //int combinations = pow(2,inputs)
    
    //determine length of each array
    //hardcode all possible combinations of inputs.
    /*int r[combinations]; //rocket
    int a[combinations]; //astronaut
    int h[combinations]; //highly trained
    int e[combinations]; //educated
    */
    //fill out variables and all possible combinations.
    //hardcode proposition tests.
    //maybe there is a lazier way to do this. 
    //what if I just brute force a bazillion random combinations. Seems easier. 
    
    //statement to check for all combinations:
    // ((r<=a) and (a<=h) (h<=e)) != (e<=r)
    for (int r =0; r<2; r++){
        for (int a =0; a<2; a++){
            for (int h =0; h<2; h++){
                for (int e =0; e<2; e++){
                    //The world where all the given statements are true
                    if(((r<=a) and (a<=h) and (h<=e))){
                        //the world where the statements are not equal to the conclusion statement
                        if(((r<=a) and (a<=h) and (h<=e)) != (e<=r)){
                            invalid = true;
                            cout << endl << "INVALID COMBINATION " <<
                            "R:" << r << " "
                            "A:" << a << " "
                            "H: "<< h << " "
                            "E: " << e << " ";
                        }
                    }   
                }
            }
        }
    }
    
    if(invalid = false){
        cout << endl << "The statement is true!";
    }
    return 0;
}