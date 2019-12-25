#ifndef DELIST_H
#define DELIST_H
#include "delist.h";

  // Constructs an empty Double-Ended List
  DEList();
  // Destructor to clean-up memory of current list
  ~DEList();
  // returns a Boolean 'true' if the list is empty
  bool DEList::empty();
  // returns number of items in the list
  int DEList::size();
  // returns front item or -1 if empty list
  int DEList::front();
  // returns back item or -1 if empty list
  int DEList::back();
  // Adds a new integer to the front of the list
  void DEList::push_front(int new_val);
  // Adds a new integer to the back of the list
  void DEList::push_back(int new_val);
  // Removes the front item of the list (if it exists)
  void DEList::pop_front();
  // Removes the back item of the list (if it exists)
  void DEList::pop_back();
