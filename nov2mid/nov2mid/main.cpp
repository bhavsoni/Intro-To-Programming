//
//  main.cpp
//  nov2mid
//
//  Created by Bhavin Soni on 11/2/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>

using namespace std;

void simpleGreeting () {
    cout<<"good morning nigga"<<endl;
}

//takes somehting but returns nothing
void add(int x, int y){
    int result;
    result = x+y;
    cout<<"result: "<<result<<endl;
}

// take soemthing, returns soemthing

int mult (int x, int y){
    int result;
    result = x*y;
    return result;
}

int main (){
    //int num1, num2;
    //cout<<"add num1"<<endl;
    //cin>>num1;
    cout<<"main fx"<<endl;
    simpleGreeting (); //calling a fx, result of the fx
    add (2,3);
    //add (num1, num2):
    int multResult;
    multResult = mult (25, 16);
    cout<<"calling multiply, it returned: "<< mult (25, 16)<< endl;
    return 1;
}