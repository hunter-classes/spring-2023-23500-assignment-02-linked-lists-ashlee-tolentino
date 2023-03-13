#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "OList.h"
#include "Node.h"
#include <iostream>
#include <string>

OList *test1 = new OList();

TEST_CASE("Constructor"){
  CHECK((test1->toString()) == "head --> nullptr");
}

TEST_CASE("Insert"){
  test1->insert("b");
  CHECK((test1->toString()) == "head --> b --> nullptr");
  test1->insert("d");
  test1->insert("e");
  test1->insert("a");
  test1->insert("c");
  test1->insert("c");
  CHECK((test1->toString()) == "head --> a --> b --> c --> c --> d --> e --> nullptr");
}

TEST_CASE("String Representation"){
  test1->insert("f");
  CHECK((test1->toString()) == "head --> a --> b --> c --> c --> d --> e --> f --> nullptr");
  test1->remove(0);
  CHECK((test1->toString()) == "head --> b --> c --> c --> d --> e --> f --> nullptr");
}

TEST_CASE("Contains"){
  CHECK((test1->contains("e")) == 1);
  CHECK((test1->contains("z")) == 0);
  CHECK((test1->contains("f")) == 1);
  CHECK((test1->contains("x")) == 0);
}

TEST_CASE("Get"){
  CHECK((test1->get(0)) == "b");
  CHECK((test1->get(2)) == "c");
  CHECK((test1->get(5)) == "f");
  CHECK((test1->get(6)) == "Location does not exist");
  CHECK((test1->get(7)) == "Location does not exist");
}

TEST_CASE("Remove"){
  test1->remove(5);
  CHECK((test1->toString()) == "head --> b --> c --> c --> d --> e --> nullptr");
  test1->remove(0);
  CHECK((test1->toString()) == "head --> c --> c --> d --> e --> nullptr");
  test1->remove(1);
  CHECK((test1->toString()) == "head --> c --> d --> e --> nullptr");
}


TEST_CASE("Destructor"){
  delete test1;
  OList *test1;
  CHECK((test1->toString()) == "head --> nullptr");
}


TEST_CASE("Reverse"){
  OList *test2 = new OList();

  test2->insert("b");
  test2->insert("d");
  test2->insert("a");
  test2->insert("e");
  test2->insert("c");
  CHECK((test2->toString()) == "head --> a --> b --> c --> d --> e --> nullptr");

  test2->reverse();
  CHECK((test2->toString()) == "head --> e --> d --> c --> b --> a --> nullptr");
}
