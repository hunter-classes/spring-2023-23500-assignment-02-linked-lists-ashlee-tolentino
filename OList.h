#pragma once
#include <iostream>
#include "Node.h"

class OList{
 private:
  Node *head;
  
 public:
  OList(); // constructor
  ~OList(); // destructor
  
  void insert(std::string value);
  void insert(int loc, std::string data); // 0 indexed
  int length();

  std::string toString(); // for testing purposes
  bool contains(std::string value);
  std::string get(int loc);
  void remove(int loc);
  void reverse();
};
