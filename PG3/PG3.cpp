//
//  PG3.cpp
//  PG3 V3 - LL and LLN modifications
//
//  Created by Lawrence Johnson on 10/05/14 3:14PM.
//  Copyright (c) 2014 Lawrence Johnson. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "PG3.h"
#include "LL.h"
#include "LLN.h"

using namespace std;

int main(int argc, const char * argv[]) {
    LL *words = new LL();
    string input = "temp";
    int sz = 0;
    
    // Only take inputs that aren't NULL
    while (input.length() > 0){
        cout << "Please enter a string: ";
        getline(cin, input);
        
        if (input.length() > 0) {
            words->addfront(input);
            sz++;
        }
        else cout << endl;
    }

    cout << "The words that appear the most are: " << endl;
    
    // Sort the list and find matches
    // V3 Added condition to only run if there is something entered.
    if (sz > 0) {
        words->sort();
        words->match();
    }
    
    // Clean-up
    delete words;
}
