// Tree
// Written by Elliot Etches
// 2022/02/04

// Tree executes a breadth first search from a source URL to a target URL.
// It constructs a search tree as it expands.
// When it finds the target URL it returns the list of links leading from the source to
// the target.

#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "url.h"

class tree {
  private:
    // URL of the current node
    std::string urlC;
    
    // Target URL
    std::string search;
    
    // Parent URL
    tree *root;
    
    // List of visited URLs to prevent looping
    std::vector<std::string> visited;
  public:
    // Constructor
    tree(std::string, std::string, tree *);
    
    // Getter for URL
    std::string getUrl();
    
    // Retrives a list of links from current URL
    std::queue<std::string> expandTree();
    
    // Checks if the current URL is the target url
    bool checkTree();
    
    // Begins breadth first search
    bool searchTree();
  
    // Recursively prints all URLs leading back to the root from the current URL
    bool printToRoot();

    // Compares the visited URLs to a given URL
    bool searchVec(std::string);
};

#endif
