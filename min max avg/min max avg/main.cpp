//
//  main.cpp
//  min max avg
//
//  Created by Bhavin Soni on 10/12/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>

using namespace std;

int main (){
    float num=0;
    int i;
    float numinput=0;
    float avg;
    
    int max=0;
    int min;
    
    for (i=0; i<=9; i++){
        cout<<"Enter 10 unique numbers. Press 'Enter' key to enter a new number."<<endl;
        cin>>numinput;
        num=num+numinput;
        
        if(numinput>max){
            max=numinput;
        }
        
        else if(numinput<min && numinput>=0){
            min=numinput;
        }
    }
    
    avg = num/10.0;
    cout<<"Average: "<<avg<<endl;
    cout<<"Max: "<<max<<endl;
    cout<<"Min: "<<min<<endl;
}