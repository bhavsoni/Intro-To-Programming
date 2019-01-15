//
//  main.cpp
//  w4ass1extra
//
//  Created by Bhavin Soni on 9/20/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main(){
    time_t rawtime;     // time function
    struct tm * timeinfo;
    
    time (&rawtime);
    timeinfo = localtime (&rawtime);    // time in 24hrs
    string x = asctime(timeinfo);   //outputs the time
    string y = x.substr(11,2);  //substring - hh mm ss --> the 11th to 13th character are the hours (13-11=2char in length)
    int z = atoi(y.c_str());    //takes the string and makes it into a integer
    
    if(z<12)    //if the hour is less than 12pm then print message below
    {
        cout<<"Good Morning, Professor Mukund!"<<endl;
    }
    else if (z>12&&z<18)    //if hour is between 12 and 18(6pm) then print message below
    {
        cout<<"Good Afternoon Professor Mukund!"<<endl;
    }
    else    //if its anything after 18hrs, then print message below
    {
        cout<<"Good Evening, Professor Mukund!"<<endl;
    }
    
    return 0;

}
