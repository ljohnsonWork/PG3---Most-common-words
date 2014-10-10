//
//  LLN.h
//  PG3 V3
//
//  Created by Lawrence Johnson on 10/05/14 3:14PM.
//  Copyright (c) 2014 Lawrence Johnson. All rights reserved.
//

#ifndef __PG3__LLN__
#define __PG3__LLN__

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class LLN {
private:
    string i;
    LLN * next;
    
public:
    LLN (string I, LLN * n);
    ~LLN ();
    string geti ();
    void seti (string I);
    LLN *getnext ();
    void addback (string I);
    void print ();
};


#endif /* defined(__PG3__LLN__) */
