#ifndef NODE
#define NODE

#include <vector>

#include "Data Structures/Helpers/Change.h"

class Node {
    public:
    Change value;
    Node* next;
    Node* previous;
};

#endif
