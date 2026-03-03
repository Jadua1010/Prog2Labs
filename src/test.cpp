//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 3.2
//=====================...........................=================================

// Important to ensure the include directory is listed in the compiler
#include "Tree.h"
#include <vector>

int main() {
    Tree<int> t;

    std::vector<int> fillers = {10, 45, 1, 6, 7, 90, 43, 77, 84, 35, 44, 67};

    // Now go through all filler values and insert them into a tree
    std::cout << "TEST: Inserting 12 fun integers (instead of 10)" << std::endl;
    for (int val : fillers) {
        t.insertNode(val);
    }

    std::cout << "This is what you 'grew'" << std::endl;
    t.outputTree();

    // Setup search value
    int searchVal = 0;
    std::cout << "Enter a value you'd like to find:" << std::endl;
    std::cout << "TEST: What happens if we enter something random that is not an int (equivalent to nothing)" << std::endl;

    // Warn the user if the searchval did not get updated
    if (searchVal == 0)
    std::cout << "WARNING! You either entered 0 or did not enter an integer!" << std::endl;

    // Print retults
    std::cout << std::endl << "Looking for " << searchVal << std::endl;
    auto ptrLoc = t.searchTree(searchVal);
    if (ptrLoc != nullptr) {
        std::cout << "Your value lies at pointer " << ptrLoc << std::endl;
    }
    else {
        std::cout << "Your value isn't in the tree :(" << std::endl;
    }

    return 0;

}
