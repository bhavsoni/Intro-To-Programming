//
//  main.cpp
//  basic calc 1
//
//  Created by Bhavin Soni on 10/12/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>

//
//  main.cpp
//  assignment2-calculator
//
//  Created by Bhavin Soni on 9/29/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>

using namespace std;

float a=1.00;
float b=1.00;
float result;
char operation;

//defines the variables as floats

float add(float x, float y){
    return x+y;
}

//defines the different operations and how the numbers for the calculation is put in and what is returned

float sub(float x, float y){
    return x-y;
}

float mul(float x, float y){
    return x*y;
}

float div(float x, float y){
    return x/y;
}

int main ()
{
    cout << "~Bhavin's Basic Calculator~" << endl;
    
    cout << "Type the operation (for example: x+y; x-y; x*y; or x/y): "<< endl; //tells user to input an equation
    cin >> a >> operation >> b;
    
    try{      //instead of the complier saying that the code cannot be complied it will sense that there is an error in the input and will sensse it is an error before it runs
        
        if (operation == '+'){
            result= add (a,b);
        }
        
        //this tells the complier which operation to use and values to input for x and y using if then statements
        
        else if (operation == '-'){
            result = sub(a,b);
        }
        
        else if (operation=='*'){
            result = mul(a,b);
        }
        else if (operation =='/'){
            result = div(a,b);
        }
        
        else {
            cout<<"error"<<endl;
            return 0;
        }
    }
    catch(exception e){     //exception e means it will 'catch' any excepion to the code/complier input and then it will dsiplay an error for any wrong input
        cout<<"error"<<endl;
    }
    
    cout << "The answer is: " << result << endl;
    return 0;
}

