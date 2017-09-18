#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

static int CAP = -800;

int roullete(int hands) {
    int liam_cash = 0, pete_cash = 0;
    int liam_bet = 10, pete_bet = 10;
    
    double randnum;
    srand((unsigned)time(0));
    
    for(int i = 0; i < hands; i++){
        randnum = rand() % 10000;
        
        if(randnum < 4637) { // Liam wins
            liam_cash += liam_bet;
            pete_cash -= pete_bet;
            
            if(pete_cash + liam_cash > CAP){
                pete_bet += 10;
//                if(pete_bet > 80)
//                    pete_bet += 10;
//                else
//                    pete_bet *= 2;
            } else {
                return pete_cash + liam_cash;
            }
            
        } else if(randnum < 9274) { // Pete wins
            pete_cash += pete_bet;
            liam_cash -= liam_bet;
            
            if(pete_cash + liam_cash > CAP){
                liam_bet += 10;
//                if(liam_bet > 80)
//                    liam_bet += 10;
//                else
//                    liam_bet *= 2;
            } else {
                return pete_cash + liam_cash;
            }
        } else { // Both lose
            liam_cash -= liam_bet/2;
            pete_cash -= pete_bet/2;
        }
    }
    return pete_cash + liam_cash;
}

int main() {
    
    int cash = roullete(10);
    
//    cout << "Liam money made: " << liam_cash << endl;
//    cout << "Pete money made: " << pete_cash << endl;
    cout << "Total money made: " << cash << endl;
}

