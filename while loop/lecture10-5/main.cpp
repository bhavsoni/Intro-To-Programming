//
//  main.cpp
//  lecture10-5
//
//  Created by Bhavin Soni on 10/5/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>

//for (int i=0, i<100; i++){
//  cout <<

using namespace std;

int main (){
    char response = 'y';
    int number;
    
    while(response=='y') //while response y keep repeating
    {
        cout << "give me number mofo"<<endl;
        cin >> number;
        
        cout << "you tellin me you gave me this?" << number<< endl;
        cout << " enter n to quit like a  bitch or y to hussle like a real nigga" << endl;
        cin >> response;
        if (response == 'y'){
            cout <<"damn g you gangbangin? good shit mah nigga" << endl;
            cout << " so let me ask you again: " << endl;
        }
        else {
            cout << "damn cuh you a bigga bitch than i thot...fuck outta here" << endl;
        }
    }
    
}