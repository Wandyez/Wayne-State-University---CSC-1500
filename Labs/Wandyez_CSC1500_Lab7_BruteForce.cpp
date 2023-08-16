/******************************************************************************

For this assignment you’ll be making a Brute Force Code Cracker. It will take a cipher for input, and run through all possible shift-cipher keys for it. Keep in mind there are only 26 possible keys for a shift cipher. After taking in a cipher input, you’ll need to, one-by-one, convert the characters that make up the string into numbers, shift them based on the key you’re currently testing, then shift them back to characters. Characters, when converting to numbers, always take their ASCII values. Lower-case ‘a’ is 97, while lower-case ‘z’ is 122. Upper-case ‘A’ is 65, while upper-case ‘Z’ is 90. All the letters between them, have the numbers ranging between them.

Also keep in mind that you’ll need to use modulo to take into account letters that might shift past the end of the group, such as trying to shift ‘y’ five letters to the right. The following cipher decodes as ‘Testing the System’ and may be used to verify your code.

Whvwlqj wkh Vbvwhp

You’ll need to deliver a screenshot for EACH of the five ciphers below. Do note that there is an English phrase decryption of each of them.

1: Wkh qljkw lv orqj dqg zh doo suhwhqg wr vohhs

2: F xrfqq hnyd mfx gjjs inxhtajwji zsijw ymj gtbqnsl fqqjd

3: Yx Drebcnki dro vslbkbi gsvv lo exuxygklvo

4: Epht bsf opu bmmpxfe jo uif eph qbsl

5: Jrypbzr gb Avtug Inyr

*******************************************************************************/

/*The PLAN:
Hear me out, ASCI values are dumb. I refuse to accept their existence. 
If I instead create an alphabet cipher as a string of characters, then replace the end 
letter with the beginning letter, and then shift each character up one, and repeat 26 times
I can then simply COUT a combination. 

*/
#include <iostream>
#include <string>
#include <cstring> //this one is real right?

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

int main()
{
    string upperciph, upalph;
    upperciph = upalph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    string lowerciph, lowalph;
    lowerciph = lowalph = "abcdefghijklmnopqrstuvwxyz";
    
    //I don't want to do multiple inputs, that is annoying. 
    string inputarray[] = {"Wkh qljkw lv orqj dqg zh doo suhwhqg wr vohhs",
    "F xrfqq hnyd mfx gjjs inxhtajwji zsijw ymj gtbqnsl fqqjd",
    "Yx Drebcnki dro vslbkbi gsvv lo exuxygklvo",
    "Epht bsf opu bmmpxfe jo uif eph qbsl",
    "Jrypbzr gb Avtug Inyr"};
    
    



    for (int j = 0; j <5; j++){
        upperciph = upalph;
        lowerciph = lowalph;
        for(int i = 0; i<26; i++){
            cout <<endl << useKey(inputarray[j], upperciph, lowerciph, upalph, lowalph);
            upperciph = cipherShift(upperciph);
            lowerciph = cipherShift(lowerciph);
        }

    }

    return 0;
}