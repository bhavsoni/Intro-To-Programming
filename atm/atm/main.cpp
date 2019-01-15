//
//  main.cpp
//  atm
//
//  Created by Bhavin Soni on 11/19/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//


#include <iostream>
#include <stdlib.h>
using namespace std;


class AtmMachine{
public:
    //ONE: what does it look like?
    int cashBalance;
    
    //TWO: what it does?
    void checkBalance(){
        cout<<"Balance: "<<cashBalance<<endl;
        
    }
    void deposit(int amount){
        cout<< "Depositing: "<<amount<<endl;
        cashBalance+=amount;            //cashBalance = cashBalance + amount
        
    }
    void withdraw(int amount){
        if (amount<=cashBalance){
            cout<<"Withdrawing: "<<amount<<endl;
            cashBalance-=amount;        //cashBalance = cashBalance - amount
            
        }
        else{
            cout<<"insufficent funds"<<endl;
        }
        
    }
    //THREE: what does it look like by default?
    
    
    //shares the exact same name as you class...aka the constructor
    AtmMachine(){
        cashBalance=100;
        
    }
};

int main(int argc, const char * argv[]) {
    int choice;
    int dollarAmount;
    AtmMachine myMachine;
    
    while (1){
        cout<<"Press 1 to check balance"<<endl;
        cout<<"Press 2 to depost"<<endl;
        cout<<"Press 3 to withdraw"<<endl;
        cout<<"Anything else to quit"<<endl;
        
        cin >>choice;
        
        switch(choice){
            case 1: myMachine.checkBalance();
                break;
            case 2: cout<<"how much cash you giving "<<endl;
                cin>>dollarAmount;
                myMachine.deposit(dollarAmount);
                
                break;
            case 3: cout<<"how much you withdrawing"<<endl;
                cin>>dollarAmount;
                myMachine.withdraw(dollarAmount);
            
            default: exit(1);
                
        }
        
        
    }
    
    
    
    
    
    
}
