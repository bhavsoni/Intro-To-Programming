//
//  main.cpp
//  neverquit
//
//  Created by Bhavin Soni on 11/9/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>

using namespace std;

void dispesnesHeroin() {
    cout<<"shoot dat shit lil nig"<<endl;
    
}

void dispensesCocaine() {
    cout<<"sniff this shit cuh"<< endl<<endl; //2 endl enters twice (double spaces)
    
}

void dispensesKush() {
    cout<<"smoke dat and stay fly" <<endl;
}


int main (){
    int choice;
    
    while(1){
        //never ending loop
        cout<<"Enter 1 for heroin"<<endl;
        cout<<"enter 2 for cocaine"<<endl;
        cout<<"enter 3 for dat good kush"<<endl;
        cout<<"enter whatever to get the fuck outta here"<<endl;
        cin >> choice;
        
        switch(choice) { //sitches
            case 1: dispesnesHeroin ();
                break; //need the break so it dispenses one at a time
                
            case 2: dispensesCocaine();
                break;
                
            case 3: dispensesKush();
                break;
                
            default: cout << "fuck outta here pussy ass bitch...beter luck next time"<< endl;
                exit(1);
        }
    }
}