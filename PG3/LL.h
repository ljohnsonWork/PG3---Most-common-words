//
//  LL.h
//  PG3 V3
//
//  Created by Lawrence Johnson on 10/05/14 3:14PM.
//  Copyright (c) 2014 Lawrence Johnson. All rights reserved.
//

#ifndef __PG3__LL__
#define __PG3__LL__

#include <iostream>
#include <string>
#include <cstdlib>
#include "LLN.h"
using namespace std;

class LLN;
class LL {
    
private:
    LLN *head;
    
public:
    LL ();
    ~LL();
    void addfront (string I);
    void addback (string I);
    void getnodeat (int p);
    void match ();
    void sort();
    void print ();
};
#endif /* defined(__PG3__LL__) */
