// URL Finder
// Written by Elliot Etches
// 2022/02/04
// UofL Comp Sci. - 3750

#include <stdio.h>
#include <string>
#include <queue>
#include "curl/curl.h"
#include "url.h"
#include "tree.h"

int main(int argc, char *argv[]) {
  std::queue<std::string> test;
  
  // Prints program usage if wrong number of arguments
  if(argc < 3) {
    printf("Usage: ./main <start> <end> \n");
    return 1;
  }

  // Begins search
  tree t1(argv[1], argv[2], NULL);
  t1.searchTree();

  curl_global_cleanup();

  return 0;
}
