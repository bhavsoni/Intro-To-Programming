//
//  main.cpp
//  week6hw
//
//  Created by Bhavin Soni on 10/5/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    float hw1;
    float hw2;
    float hw3;
    float hw4;
    float hw5;
    float hwavg;
    float mid1;
    float mid2;
    float midavg;
    float final;
    float project;
    float cumulative;
    
    cout << "What are your homework scores? Enter first score:"<< endl;
    cin >> hw1;
    cout << " Second score:"<< endl;
    cin >> hw2;
    cout << " Third score:"<< endl;
    cin >> hw3;
    cout << "Fourth score:"<< endl;
    cin >> hw4;
    cout << "Fifth score:"<< endl;
    cin >> hw5;
    
    hwavg = (hw1 + hw2 + hw3 + hw4 + hw5)/5;
    
    
    cout<<"What are your midterm scores? Enter your first score:" << endl;
    cin>>mid1;
    cout<<"Second score:"<<endl;
    cin>>mid2;
    
    midavg = (mid1 + mid2)/2;
    
    cout<<"What is your final exam score? Enter your score:" << endl;
    cin>>final;
    
    cout<<"What is your project score? Enter your score:" << endl;
    cin>>project;
    
    cumulative = 0.40*hwavg + 0.30*midavg + 0.10*final + 0.20*project;
    
    if(cumulative>90 or hwavg==100 && midavg==100){
        cout << "Course Letter Grade: A"<<endl;
        cout<<"Grade: "<<cumulative<<"%"<< endl;
        if (hwavg==100 && midavg==100){
            cout<< "You got an 'A' due to your consistent perfect scores on the homework and midterms!"<<endl;
        }
    }
    
    else if (cumulative>=81 && cumulative<=90){
        cout <<"Course Grade: B"<<endl;
        cout<<"Grade: "<<cumulative<<"%"<< endl;
    }
    
    else if (cumulative>=71 && cumulative<=80){
        cout <<"Course Grade: C"<<endl;
        cout<<"Grade: "<<cumulative<<"%"<< endl;
    }
    
    else if (cumulative>=61 && cumulative<=70){
        cout <<"Course Grade: D"<<endl;
        cout<<"Grade: "<<cumulative<<"%"<< endl;
    }
    
    else{
        cout <<"Course Grade: F"<<endl;
        cout<<"Grade: "<<cumulative<<"%"<< endl;
    }
    
    return 0;
}