//
//  main.cpp
//  printStar
//
//  Created by Bhavin Soni on 11/6/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>

using namespace std;

void printStar(){
    cout<<"*";
}

int main(){
    for (int i=0; i<5; i++) {
        for (int x=0; x<=i; x++){
            printStar();
        }
        cout<<endl;
    }
}