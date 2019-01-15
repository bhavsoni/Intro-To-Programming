//
//  main.cpp
//  dispenser
//
//  Created by Bhavin Soni on 11/17/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

int Coke = 20;
int cokeremain;
int Sprite = 20;
int Water = 20;
float cokeamount;
float cokechange;
float spriteamount;
float spritechange;
float wateramount;
float waterchange;


void dispenseCoke() {
    cout <<"Please input $1.25: "<< endl;
    cin>>cokeamount;
    if (cokeamount == 1.25){
        Coke--;
        if (Coke>0){
            cout<<"Here's your refreshing Coca-Cola"<<endl;
        }
        else if (Coke==0){
            cout<<"Sorry, we are out of stock! Here's your change back: "<<cokeamount<<endl;
        }

    }
    
    else if (cokeamount > 1.25){
        cokechange = cokeamount - 1.25;
        Coke--;
        if (Coke>0){
            cout<<"Change: "<<cokechange<<endl;
            cout<<"Here's your refreshing Coca-Cola"<<endl;
        }
        
        else if (Coke==0){
            cout<<"Sorry, we are out of stock! Here's your change back: "<<cokeamount<<endl;
        }
    }
    
    else {
        cout<<" Insufficient funds. Please try again."<<endl;
    }
}

void dispenseSprite() {
    cout <<"Please input $1.25: "<< endl;
    cin>>spriteamount;
    if (spriteamount == 1.25){
        Sprite--;
        if (Sprite>0){
            cout<<"Here's your refreshing Sprite"<<endl;
        }
        else if (Sprite==0){
            cout<<"Sorry, we are out of stock! Here's your change back: "<<spriteamount<<endl;
        }
    }
    else if (spriteamount > 1.25){
        spritechange = spriteamount - 1.25;
        Sprite--;
        if (Sprite>0){
            cout<<"Change: "<<spritechange<<endl;
            cout<<"Here's your refreshing Sprite"<<endl;
        }
        
        else if (Sprite==0){
            cout<<"Sorry, we are out of stock! Here's your change back: "<<spriteamount<<endl;
        }

    }
    else {
        cout<<" Insufficient funds. Please try again."<<endl;
    }
}

void dispenseWater() {
    cout <<"Please input $1.25: "<< endl;
    cin>>wateramount;
    if (wateramount == 1.25){
        Water--;
        if (Water>0){
            cout<<"Here's your refreshing Water"<<endl;
        }
        else if (Water==0){
            cout<<"Sorry, we are out of stock! Here's your change back: "<<wateramount<<endl;
        }
    }
    else if (wateramount > 1.25){
        waterchange = wateramount - 1.25;
        Sprite--;
        if (Water>0){
            cout<<"Change: "<<waterchange<<endl;
            cout<<"Here's your refreshing Water"<<endl;
        }
        
        else if (Water==0){
            cout<<"Sorry, we are out of stock! Here's your change back: "<<wateramount<<endl;
        }

    }
    else {
        cout<<" Insufficient funds. Please try again."<<endl;
    }
}

int main (){
    int choice;
    
    while(1){
        cout<<"Enter 1 for Coke"<<endl;
        cout<<"Enter 2 for Sprite"<<endl;
        cout<<"Enter 3 for Water"<<endl;
        cout<<"Enter anything else to stop dispensing."<<endl;
        cin >> choice;
        
        switch(choice) {
            case 1: dispenseCoke();
                break;
                
            case 2: dispenseSprite();
                break;
                
            case 3: dispenseWater();
                break;
                
            default: cout << "Sorry better luck next time..."<< endl;
                exit(1);
        }
    }
}