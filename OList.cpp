#include <iostream>
#include <string>
#include "Node.h"
#include "OList.h"

// Constructor
OList::OList(){
  head = nullptr;
}

// Destructor
OList::~OList(){
  std::cerr << "Calling the destructor\n";
  Node *walker = head;
  Node *trailer = nullptr;
  while (walker != nullptr) {
    trailer = walker;
    walker = walker->getNext();
    std::cerr << "Deleting " << trailer->getData() << ", ";
    delete trailer;
  }
  std::cerr << "\n";
}

// Inserts a new node with value into the list in its proper location
void OList::insert(std::string value){
  Node *walker;
  walker = this->head; // start of the list

  if(length() == 0){
    insert(0, value);
  }
  else{
    int loc = 0;
    while(walker != nullptr){
      if((walker->getData().compare(value)) > 0){
	insert(loc, value);
	return;
      }
      else{
	loc++;
	walker = walker->getNext();
      }
    }
    if(walker == nullptr){
      insert(length(), value);
    }
  }
}

/*
  insert at loc
  We need a pointer to the node BEFORE
  the location where we want to insert 

  Piggybacking 
*/
void OList::insert(int loc, std::string data){
  Node *walker, *trailer;
  walker = this->head; // start of the list
  trailer = nullptr; // one behind
  
  while(loc > 0 && walker != nullptr){
    loc = loc-1;

    /* trailer will always be one node
       behind walker */
    trailer = walker;
    walker = walker->getNext();
    
  }

  // At this point, trailer points to the Node
  // BEFORE where we want to insert


  // test to see if we're trying to
  // insert past the end 
  if (loc > 0){
    // do something to indicate this is invalid
    throw std::out_of_range("Our insert is out of range");
  }

  Node *newNode = new Node(data);
  // Inserting at true location 0
  // will have trailer == nullptr
  // - we have to treat that as a special case
  if (trailer == nullptr){
    newNode->setNext(head);
    head = newNode;
  } else {
    // do the regular case 
    newNode->setNext(walker);
    trailer->setNext(newNode);
  }
}

int OList::length(){
  int count = 0;
  Node *walker = head;
  while (walker != nullptr){
    count++;
    walker = walker->getNext();
  }
  return count;
}

// Returns a string representation of the full list
std::string OList::toString(){
  Node *tmp = this->head;
  std::string result = "";
  while (tmp != nullptr){
    result = result + tmp->getData();
    result = result + " --> ";
    tmp = tmp->getNext();
  }
  result = "head --> " + result + "nullptr";
  return result;
}

// Returns true if value is in the list, and false otherwise
bool OList::contains(std::string value){
  Node *tmp = this->head;
  while(tmp != nullptr){
    if(tmp->getData() == value){
      return true;
    }
    tmp = tmp->getNext();
  }
  return false;
}

// Returns the value at loc
std::string OList::get(int loc){
  Node *tmp = this->head;
  if(loc >= length()){
    return "Location does not exist";
  }
  else{
    for(int i = 0; i < loc; i++){
      tmp = tmp->getNext();
    }
  }
  return tmp->getData();
}

// Removes the value at the specified location
void OList::remove(int loc){
  Node *walker, *trailer;
  walker = head; // first item of the list
  trailer = nullptr; // one behind
  
  while(loc > 0 && walker != nullptr){
    loc = loc-1;

    /* trailer will always be one node
       behind walker */
    trailer = walker;
    walker = walker->getNext();
  }

  // At this point, trailer points to the Node
  // BEFORE where we want to remove


  // test to see if we're trying to
  // remove past the end 
  if (walker == nullptr){
    // do something to indicate this is invalid
    throw std::out_of_range("Our remove is out of range");
  }

  // Removing at location 0
  // will have trailer == nullptr
  // - we have to treat that as a special case
  if (trailer == nullptr){
    // we're removing the first item in the list
    head = walker->getNext();
    delete walker;
  } else {
    // do the regular case
    // general case of having a node before the
    // node to delete
    trailer->setNext(walker->getNext());
    delete walker;
  }
}

// Reverses the list - it reverses the pointers
void OList::reverse(){
  Node *current = head;
  Node *previous = nullptr;
  Node *next = nullptr;

  while(current != nullptr){
    next = current->getNext();
    current->setNext(previous);
    previous = current;
    current = next;
  }
  head = previous;
}
