// Tree
// Written by Elliot Etches
// 2022/02/04
// UofL Comp Sci. - 3750

#include "tree.h"

// Constructor
tree::tree(std::string urlIn, std::string searchIn, tree *parent) {
 urlC = urlIn;
 search = searchIn;
 root = parent;
}

// Search Tree
bool tree::searchTree() {
 std::queue<tree *> que;
 
 que.push(this);
 
while(!que.empty()) {
  std::queue<std::string> tmpQ;
  
  // Temporary copy of root tree for referencing in constructor
  tree *tmpT = que.front();
  
  if(que.front()->checkTree())
    return 1;
  
  // Expand current URL
  tmpQ = que.front()->expandTree();
  
  //std::cout << que.front()->getUrl() << std::endl;
  
  // After expansion, remove from queue
  que.pop();
  
  // Insert child nodes into queue
  while(!tmpQ.empty()) {
     // Check if any nodes are already visited
     if(!searchVec(tmpQ.front())) {
      visited.push_back(tmpQ.front());
      que.push(new tree(tmpQ.front(), search, tmpT));
     }
    tmpQ.pop();
  }
 }

 return 0; 
}

// Get URl
std::string tree::getUrl() {
  return urlC;
}

// Check Tree
bool tree::checkTree() {
  if(urlC == search) {
    std::cout << "~~Path~~" << std::endl;
    this->printToRoot();
    return 1;
  }
  return 0;
}

// Expand Tree
std::queue<std::string> tree::expandTree() {
  char * writable = new char[urlC.size() + 1];
 
  std::copy(urlC.begin(), urlC.end(), writable);
  
  writable[urlC.size()] = '\0';
  
  url t1(writable);
  
  return t1.findLinks();
}

// Print to Root  
bool tree::printToRoot() {
  if(root != NULL) {
    std::cout << urlC << std::endl;
    root->printToRoot();
    return 0;
  }
  std::cout << urlC << std::endl;
  return 1;
}

// Search Vector
bool tree::searchVec(std::string s) {
  for(unsigned int i = 0; i < visited.size(); i++)
    if (s.compare(visited[i]) == 0)
      return 1;
  return 0;
}
