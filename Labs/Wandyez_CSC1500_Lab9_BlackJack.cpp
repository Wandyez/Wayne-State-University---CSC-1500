/******************************************************************************

Assignment:  Create a Blackjack (21) game. 
Your version of the game will imagine only a SINGLE suit of cards,
so 13 unique cards, {2,3,4,5,6,7,8,9,10,J,Q,K,A}. 
Upon starting, you will be given two cards from the set,
non-repeating. Your program MUST then tell you the odds
of receiving a beneficial card (that would put your value at 21 or less),
and the odds of receiving a detrimental card
(that would put your value over 21). 
ecall that the J, Q, and K cards are worth ‘10’ points,
the A card can be worth either ‘1’ or ‘11’ points,
and the other cards are worth their numerical values.

FOR YOUR ASSIGNMENT: Provide two screenshots, one in which the game suggests 
it’s a good idea to get an extra card and the result, and one in which the game suggests
it’s a bad idea to get an extra card, and the result of taking that extra card.
*******************************************************************************/
#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <ctime>

using namespace std;

class Deck{
    public:
        //one deck for the user to get 'values'
        //one deck for Aces value 1
        //one deck for Aces value 11
        string UserDeck[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
        string UserHand[13] = {"0","0","0","0","0","0","0","0","0","0","0","0","0"};
        int MDeck1[13] = {2,3,4,5,6,7,8,9,10,10,10,10,1};
        int MHand1[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
        int MDeck11[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};
        int MHand11[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
        int rand1;
        int rand2;
        
        void showHand(){
            cout << endl << "Curent Hand: ";
            for(int i =0; i<13;i++){
                if(UserHand[i] != "0"){
                    cout << UserHand[i] << " ";
                }
            }
        }
        
        void draw(){
            cout << endl << "You have drawn an additional card:";
            //generate random numbers
            int rand1;
            default_random_engine generator(time(nullptr));
            uniform_int_distribution<int> distribution(0,12);
            rand1 = distribution(generator);
            
            //make sure the random number isn't already in use. Check user hand{
            bool uniquedraw = false;
            while(uniquedraw == false){
                if(UserHand[rand1] == "0"){
                    uniquedraw = true;
                }else{
                    //draw again HERE
                    rand1 = distribution(generator);
                }
            }
            
            //fill hand arrays with drawn cards
            //replace drawn cards with blanks
            for(int i = 0; i<13;i++){
                if(i==rand1){
                    MHand1[i] = MDeck1[i];
                    MDeck1[i] = 0;
                    MHand11[i] = MDeck11[i];
                    MDeck11[i] = 0;
                    UserHand[i] = UserDeck[i];
                    UserDeck[i] = "0";
                    
                }
            }
            showHand();
            odds();
        }

        
        void odds(){
            //numbers in the list that are less than 21 if added to the total
            int sum1 = 0;
            int sum11 = 0 ;
            int cardsremaining = 0;
            int odds = 0;
            
            
            for (int i =0; i<13; i++){
                sum1 += MHand1[i];
                sum11 += MHand11[i];
                if (UserDeck[i] != "0"){
                    cardsremaining += 1;
                }
            }
            
            cout << endl << "The total of your hand is: " << sum1 << " or " << sum11;
            
            int l211 = 0; //less than 21 ace = 1
            int l2111 = 0; //less than 21 ace = 11
            cout << endl << "Remaining beneficial cards in deck: ";

            for(int i =0; i<13; i++){
                //check if the remaining cards in the deck (those with value NOT ZERO)
                //are less than or equal to 21 - the sum total of either hand
                string temp = "";
                if((MDeck1[i] <= ( 21-sum1)) and (MDeck1[i] != 0) ){
                    l211 += 1;
                    cout << UserDeck[i] << " ";
                }
                //in hindsight this section of code is redundant, as l211 is always going to be greater
                //based upon this logic check here (I will leave this in, I am lazy)
                if((MDeck11[i] <= ( 21-sum11)) and (MDeck11[i] != 0) ){
                    l2111 += 1;
                    
                }
            }
            
            if(l211 > l2111){
                odds = l211;
            }else{
                odds = l2111;
            }
            cout << endl << "There is a " << odds << "/" << cardsremaining << " chance to draw a beneficial card";
            
            if((sum1 == 21) or (sum11 ==21)){
                cout << endl << "You have reached 21, you have won. It is not beneficial to draw an additional card. ";
            }else if(odds > 6){
                cout << endl << "It is beneficial to draw a card";
            }else{
                cout << endl << "It is not beneficial to draw a card.";
            }

            if ((sum1 > 21) and (sum11 > 21)){
                cout << endl << "You have exceeded 21, you have lost. Please call the Gambling Addiction Hotline at 0808 8020 133";
            }
        }
        
        
};

//convert the card value into a number.
//wait this is stupid. Why not just create another 'shadow deck'



int main()
{
    cout<<"It is never a good idea to draw a card. The safest bet is to not gamble at all";
    Deck Deck1;
    Deck1.draw();
    Deck1.draw();
    Deck1.draw();
    Deck1.draw();

    
    return 0;
}
