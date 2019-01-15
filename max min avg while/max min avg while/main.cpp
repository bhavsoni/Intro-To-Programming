//
//  main.cpp
//  max min avg while
//
//  Created by Bhavin Soni on 10/12/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>
using namespace std;

int main (){
    float num=0;
    float numcounter = -1;
    float numinput = 0;
    float avg;
    int max =0;
    int i;
    int min;
    for (i=0; i<3; i++){
        num = 0;
        numcounter=-1;
        numinput=0;
        avg=0;
        max=0;
        
        while(numinput!=-999){
            num = num+numinput;
            numcounter++;
            cout<<" Enter a number. Press enter key to add another number. Enter -999 number to stop."<<endl;
            cin>>numinput;
            if(num==0&&num!=-999){
                min =numinput;
            }
            if (numinput>max){
                max=numinput;
                }
        
            else if (numinput<min && numinput>-999){
                min=numinput;
                }
        }
        avg = num/numcounter;
        cout<<"Average: "<< avg << endl;
        cout<< "Max: "<< max<<endl;
        cout<<"Min: "<<min<<endl;
        }
    
    return 0;
}
