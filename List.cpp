#include <iostream>
#include "Node.h"
#include "List.h"

List::List(){
  head = nullptr;
}

// insert at the "front" (head)
void List::insert(std::string data){
  Node *tmp = new Node(data);
  tmp->setNext(head);
  head = tmp;
}

/*
  insert at loc
  We need a pointer to the node BEFORE
  the location where we want to insert 

  Piggybacking 
*/
void List::insert(int loc, std::string data){
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

/*
  Alternate solution:
  make a private variable to store the length
  and just return it here.

  Change all the insert/delete/remove type
  routines to update that variable 
*/
int List::length(){
  int count = 0;
  Node *walker = head;
  while (walker != nullptr){
    count++;
    walker = walker->getNext();
  }
  return count;
}

std::string List::toString(){
  Node *tmp = this->head;
  std::string result = "";
  while (tmp != nullptr){
    result = result + tmp->getData();
    result = result + "-->";
    tmp = tmp->getNext();
  }
  result = result + "nullptr";
  return result;
}

// Returns true if item is in the list and false otherwise
bool List::contains(std::string item){
  Node *tmp = this->head;
  while(tmp != nullptr){
    if(tmp->getData() == item){
      return true;
    }
    tmp = tmp->getNext();
  }
  return false;
}

// Removes an item at the specified location
void List::remove(int loc){
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

// destructor
List::~List(){
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
