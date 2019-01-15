//
//  main.cpp
//  28
//
//  Created by Bhavin Soni on 9/28/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int midtermScore;
    int homeworkScore;
    int finalScore;
    float cumulativeScore;
    
    //find out more about user
    //1.ask for hw
    
    cout << "da fuq you get on your hw?" << endl;
    cin>> homeworkScore;
    
    //midterms
    
    cout << "how bout em midterms?" << endl;
    cin>>midtermScore;
    
    //finals
    cout << "finals?" << endl;
    cin >> finalScore;
    
    //lets get cumulative score
    
    cumulativeScore = 0.33*homeworkScore + 0.33*midtermScore + 0.33*finalScore;
    
    //cumulativeScore = (homework + midterm + final)*0.33
    
    //if you get >90 then get A
    
    if(cumulativeScore>90)
        {
            cout << "good shit mofo you get an A" <<endl;
        }
    
    else if(cumulativeScore>=80&& cumulativeScore <=90)
        {
            cout <<" not bad but your shits off, B" << endl;
        }
    else {
        cout <<"dumb bitch" << endl;
    }
    
    return 0;
}