//
//  main.cpp
//  2ndmidpractice
//
//  Created by Bhavin Soni on 12/2/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include<iostream>
using namespace std;
void processThis(int x);

int main()
{
    int x=4;
    processThis(x);
}

void processThis(int x) {
    x = (x + 2)*2;
    cout << "Result: " << x << endl;
}