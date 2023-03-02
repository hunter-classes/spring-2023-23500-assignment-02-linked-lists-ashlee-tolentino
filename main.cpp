#include <iostream>
#include "List.h"

int main()
{
  List *l = new List();
  std::cout << l->toString() << " " << l->length() << "\n";
  l->insert(0,"a");
  std::cout << l->toString() << " " << l->length() << "\n";
  l->insert(0,"b");
  l->insert(0,"c");
  l->insert(0,"d");
  try {
    l->insert(10,"x");
  } catch (std::exception e){
    std::cout << "Insert x didn't work\n";
  }
  std::cout << l->toString() << "\n";
  l->insert(2,"inserted at 2");
  std::cout << l->toString() << "\n";
  l->insert(5,"inserted at end");
  std::cout << l->toString() << " " << l->length() << "\n";

  // New functions for project 2 part 1
  std::cout << "----------------------------------------\n";
  std::cout << l->contains("a") << std::endl; // 1
  std::cout << l->contains("d") << std::endl; // 1
  std::cout << l->contains("inserted at 2") << std::endl; // 1
  std::cout << l->contains("g") << std::endl; // 0
  std::cout << l->contains("z") << std::endl; // 0
  return 0;
}
