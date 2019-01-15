//
//  main.cpp
//  lecture2 9/21
//making a calculator
//  Created by Bhavin Soni on 9/21/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>     //comments
                        // system ("pause");

using namespace std;

int main ()
{
    int number1;
    int number2;
    int result;
    
    cout<<number1<<endl;
    
    cout << "Enter a number: " << endl;
    cin >> number1;
    
    cout << "Enter another number :" << endl;
    cin >> number2;
    
    result = number1 + number2;
    cout << result << endl;
    
    return 1;  //retunr code to 1 or 0, tells the operating systm where to go back if code is broken or not working
    
}
