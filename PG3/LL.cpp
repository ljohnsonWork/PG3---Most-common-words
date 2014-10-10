//
//  LL.cpp
//  PG3 V3
//  V2 - Match refinements
//  All results should be printed in the correct order and
//  will now print all values if no matches are found.
//
//  Created by Lawrence Johnson on 10/05/14 3:14PM.
//  Copyright (c) 2014 Lawrence Johnson. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "LL.h"
#include "LLN.h"
using namespace std;

/*
 Setup new linked list with NULL head pointer
 */
LL::LL () {
    head = NULL;
}

/*
 Delete the current head pointer.
 */
LL::~LL () {
    delete head;
}

/*
 Add value to the front of the Linked List.
 */
void LL::addfront (string I) {
    head = new LLN (I,head);
}

/*
 Add value to the end of the Linked List.
 */
void LL::addback (string I) {
    if(head == NULL) head = new LLN(I,head);
    else head->addback(I);
}

/*
 Get node at position p and print it to screen.
 */
void LL::getnodeat (int p) {
    LLN *t = head;
    // Check if head exists
    if (t != NULL){
        // loop to position requestes. Print when at position
        // and break if position is outside of range.
        for (int c = 0; c <= p ; ++c) {
            if (c < p && t->getnext() != NULL) t = t->getnext();
            else if (c == p) t->print();
            else {
                cout << "Out of bounds!\n the last entry was ";
                t->print();
                cout << " at position " << c << ".\n";
                break;
            }
        }
    }
    // If head does not exist, break.
    else cout << "Out of bounds!\nYour linked list is empty!\n";
}

/*
 Check though list and print out the matches.
 V2 - check inner notes for changes.
 */
void LL::match () {
    
    // V2 If the total lenght is one string, print it
    // and skip the rest of the checks.
    if (head->getnext() == NULL) head->print();
    
    // V2 encased the match function under an else statement
    // this will only run if the length of the list is greater
    // than 1 entry.
    else {
        int ml = 0; // Length of longest match
        LL *matches = new LL();
    
        // Start at head and count how many matches there are.
        for (LLN *lead = head; lead != NULL; lead = lead->getnext()) {
            int wl = 0; // length of current match
            for (LLN *compair = lead->getnext(); compair != NULL; compair = compair->getnext()) {
            
                // Check for a match. if one exists, move lead to
                // compair and increment the working length.
                if (lead->geti() == compair->geti()) {
                    lead = compair;
                    wl++;
                
                    /* If the working length is larger, check if
                     matches head is NULL. If it is, add the
                     the match to matches. Otherwise delete the
                     old list and recreate the list with the new
                     top match. */
                    if (wl > ml) {
                        if (matches->head == NULL) {
                            matches->addback(lead->geti());
                            ml++;
                        }
                        else {
                            delete matches;
                            matches = new LL();
                            matches->addback(lead->geti());
                            ml = wl;
                        }
                    }
                
                    // If the lenght of matches are the same, add
                    // the matching value to the match list.
                    else if (wl == ml) matches->addback(lead->geti());
                }
            }
        }
        // V2 If there are no matches, add all values to the list.
        if (ml == 0) {
            for (LLN *h = head; h != NULL; h = h->getnext()) {
                matches->addback(h->geti());
            }
        }
        
        // Print the results and clean-up.
        matches->print();
        delete matches;
    }
}

/*
 Sort let list to be able to get matches easier.
 */
void LL::sort(){
    for (LLN *s = head; s != NULL; s = s->getnext()) {
        for (LLN *n = s->getnext(); n != NULL; n = n->getnext()) {
            if (s->geti() > n->geti()) {
                string temp = s->geti();
                s->seti(n->geti());
                n->seti(temp);
            }
        }
    }
    cout << endl;
}
/*
 Print out list to screen.
 */
void LL::print () {
    
    for (LLN *h = head; h != NULL; h = h->getnext())
        h->print ();
    cout << endl;
}
