#include <iostream>
#include <string>
#include "OList.h"
#include "Node.h"

int main()
{
  OList *l = new OList();

  std::cout << l->toString() << " " << l->length() << "\n"; // empty
    
  l->insert("b");
  std::cout << l->toString() << " " << l->length() << "\n"; // b
  l->insert("d");
  std::cout << l->toString() << " " << l->length() << "\n"; // b d
  l->insert("e");
  std::cout << l->toString() << " " << l->length() << "\n"; // b d e
  l->insert("a");
  std::cout << l->toString() << " " << l->length() << "\n"; // a b d e
  l->insert("c");
  std::cout << l->toString() << " " << l->length() << "\n"; // a b c d e
  l->insert("c");
  std::cout << l->toString() << " " << l->length() << "\n"; // a b c c d e
  
  std::cout << "----------------------------------------\n";
  std::cout << l->contains("a") << std::endl; // 1
  std::cout << l->contains("d") << std::endl; // 1
  std::cout << l->contains("c") << std::endl; // 1
  std::cout << l->contains("g") << std::endl; // 0
  std::cout << l->contains("z") << std::endl; // 0

  std::cout << "----------------------------------------\n";
  std::cout << l->get(6) << std::endl; // Location does not exist
  std::cout << l->get(7) << std::endl; // Location does not exist
  std::cout << l->get(0) << std::endl; // a
  std::cout << l->get(5) << std::endl; // e

  std::cout << "----------------------------------------\n";
  std::cout << l->toString() << std::endl;
  try{
    l->remove(6);
    std::cout << l->toString() << std::endl;
  } catch (std::exception e){
    std::cout << "Tried to remove past the end\n";
  }
  l->remove(5);
  std::cout << l->toString() << std::endl;
  l->remove(4);
  std::cout << l->toString() << std::endl;
  l->remove(3);
  std::cout << l->toString() << std::endl;
  l->remove(2);
  std::cout << l->toString() << std::endl;
  l->remove(1);
  std::cout << l->toString() << std::endl;
  //l->remove(0);
  //std::cout << l->toString() << std::endl;

  std::cout << "----------------------------------------\n";
  delete l; // Deleting a,

  std::cout << "----------------------------------------\n";
  OList *l2 = new OList();

  l2->insert("b");
  l2->insert("d");
  l2->insert("a");
  l2->insert("e");
  l2->insert("c");
  std::cout << l2->toString() << " " << l2->length() << "\n"; // a b c d e

  l2->reverse();
  std::cout << l2->toString() << " " << l2->length() << "\n"; // e d c b a
  
  return 0;
}
