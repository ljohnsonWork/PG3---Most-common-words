//
//  LLN.cpp
//  PG3 V3 - Added addback
//
//  Created by Lawrence Johnson on 10/05/14 3:14PM.
//  Copyright (c) 2014 Lawrence Johnson. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "LLN.h"
using namespace std;

LLN::LLN (string I, LLN * n) {
    i = I; next = n;
}

LLN::~LLN () {
    delete next;
}

string LLN::geti () {return i;}

void LLN::seti (string I) {i = I;}

LLN * LLN::getnext () {return next;}

/*
 V2 Added
 */
void LLN::addback (string I) {
    if (next == NULL) next = new LLN(I, NULL);
    else next->addback(I);
}

void LLN::print() {
    cout << i << endl;
}
