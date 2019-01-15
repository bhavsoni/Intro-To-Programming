//
//  main.cpp
//  strings
//
//  Created by Bhavin Soni on 11/4/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>

using namespace std;

int main () {
    string x, y;
    cout<<" Enter first string: "<<endl;
    cin>>x;
    
    cout<<" Enter second string: "<<endl;
    cin>> y;
    cout<<""<<endl;
    
    cout<<" The length of the first string is: "<<endl;
    cout<<x.length();
    cout<<""<<endl;
    cout<<" The length of the second string is:"<<endl;
    cout<<y.length()<<endl;
    cout<<""<<endl;
    
    cout<<"The strings are: ";
    if (x.compare(y)==0){
        cout<<" Equal"<< endl;
        
    }
    
    else {
        cout<<"Not equal"<<endl;
    }
    
    if(x.length()>y.length() && x.find(y)!= -1){
        cout<<y+" is a subset of "+x<<endl;
    }
    
    else if(x.length()<y.length()&&y.find(x)!=-1){
        cout<<x+ " is a subset of "+y<<endl;
    }
    
    else {
        cout<<"No subsets"<<endl;
    }

    string sub="";
    for(int s=0;s<x.length();s++){
        for(int l=0;l<=x.length()-s;l++){
            if(y.find(x.substr(s,l))!=-1 && x.substr(s,l).length()>sub.length()){ //whenever there is a longer substring it replaces that as the new one
                sub = x.substr(s,l);
            }
        }
    }
    if (sub.length()==0){
        cout<<"There are no common substrings"<<endl;
    }
    else{
    cout<<"Longest common substring is: "<< sub<<endl;
    }
}