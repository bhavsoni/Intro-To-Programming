//
//  main.cpp
//  grade calc multiple1
//
//  Created by Bhavin Soni on 10/12/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>

//
//  main.cpp
//  week6hwextra
//
//  Created by Bhavin Soni on 10/6/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    float hwinput = 0;
    int hwcounter =-1;
    float hw =0;
    float hwavg;
    float hwper;
    
    float midinput =0;
    int midcounter =-1;
    float mid=0;
    float midavg;
    float midper;
    
    float fininput =0;
    int fincounter =-1;
    float fin=0;
    float finavg;
    float finper;
    
    float projinput =0;
    int projcounter =-1;
    float proj=0;
    float projavg;
    float projper;
    
    float cumulative;
    
    while (hwinput>=0){
        hw = hw + hwinput;
        hwcounter++; //increases the input of the hw grade by 1
        cout<<"Enter your Homework scores. Press 'Enter' after every score. Enter a negative number (i.e. -1) to stop entering Homework grades."<<endl;
        cin>>hwinput;
        
    }
    hwavg=hw/hwcounter;
    
    while (midinput>=0){
        mid=mid+midinput;
        midcounter++;
        cout<<"Enter your Midterm exam scores. Press 'Enter' after every score. Enter a negative number (i.e. -1) to stop entering Midterm grades."<<endl;
        cin>>midinput;
    }
    midavg=mid/midcounter;
    
    while (fininput>=0){
        fin=fin+fininput;
        fincounter++;
        cout<<"Enter your Final exam scores. Press 'Enter' after every score. Enter a negative number (i.e. -1) to stop entering Final grades."<<endl;
        cin>>fininput;
    }
    finavg=fin/fincounter;
    
    while (projinput>=0){
        proj=proj+projinput;
        projcounter++;
        cout<<"Enter your Project scores. Press 'Enter' after every score. Enter a negative number (i.e. -1) to stop entering Project grades."<<endl;
        cin>>projinput;
    }
    projavg=proj/projcounter;
    
    cout<< "Enter weightage of homework as a decimal.(i.e. 40% as 0.40)"<<endl;
    cin>>hwper;
    
    cout<<"Enter weightage of midterms as a decimal. (i.e. 40% as 0.40)"<<endl;
    cin>>midper;
    
    cout<<"Enter weightage of finals as a decimal. (i.e. 40% as 0.40)"<<endl;
    cin>> finper;
    
    cout<<"Enter weightage of projects as a decimal. (i.e. 40% as 0.40)"<<endl;
    cin>>projper;
    
    cumulative = (hwper*hwavg)+(midper*midavg)+(finper*finavg)+(projper*projavg);
    
    if(cumulative>90){
        cout << "Course Letter Grade: A"<<endl;
        cout<<"Grade: "<<cumulative<<"%"<< endl;
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
