//
//  main.cpp
//  w4ass1
//
//  Created by Bhavin Soni on 9/20/16.
//  Copyright © 2016 Bhavin Soni. All rights reserved.
//

#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

//must run in terminal in order to see the pretty colors 

using namespace std;

int main()
{
    cout << "I never sleep cause sleep is the cousin of death" << endl;
    
    cout << RED << "Scared to death, scared to look, they shook / ‘Cause ain't no such things as halfway crooks" << endl;
    
    cout << GREEN <<"Birthdays was the worst days / Now we sip champagne when we thirsty" << endl;
    
    cout << YELLOW << "I see no changes, all I see is racist faces/ Misplaced hate makes disgrace for races" << endl;
    
    cout << MAGENTA << "Life is parallel to Hell but I must maintain and be prosperous, though we live dangerous." << endl;
    
    cout << RED << "h" << BLUE << "e" << GREEN << "l" << YELLOW<< "l" << MAGENTA<< "o, " << CYAN << "w" << RED << "o" << YELLOW << "r" << GREEN << "l" << BLUE << "d" << RESET << endl;
    
    return 0;
    
}