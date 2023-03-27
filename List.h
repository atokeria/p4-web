#ifndef LIST_H
#define LIST_H
/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Project UID c1f28c309e55405daf00c565d57ff9ad
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:

  List()
    :first(nullptr),last(nullptr){
  }

  ~List(){
    clear();
  }

  List(const List<T> &other)
    :first(nullptr),last(nullptr){
    copy_all(other);
  }

  List & operator=(const List<T> &rhs){
    if(this == &rhs){return *this;}else{
      clear();
      copy_all(rhs);
      return *this;
    }
  }

  //EFFECTS:  returns true if the list is empty
  bool empty() const {
    return sizey == 0;
  }

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
  int size() const{
    return sizey;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front(){
    return first->datum;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back(){
    return last->datum;
  }

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum){
    ++sizey;
    Node *p = new Node;
    if(empty()){
      first = p;
      last = p;
      p->prev = nullptr;
      p->next = nullptr;
    }else{
      p->next = first->next;
      p->prev = nullptr;
      first = p;
    }
  }

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum){
    Node *p = new Node;
    p->datum = datum;
    p->next = nullptr;
    if(empty()){
      first = last = p;
      p->prev = nullptr;
      ++sizey;
    }else{
      p->prev = last;
      last->next = p;
      last = p;
      ++sizey;
    }
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front(){
    --sizey;
   if(first == last){
    delete first;
    first = last = nullptr;
   }else{
     first = first->next;
     delete first->prev;
     first->prev = nullptr;
   }
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back(){
    --sizey;
    if(first == last){
      delete first;
      first = last = nullptr;
    }else{
      last = last->prev;
      delete last->next;
      last->next = nullptr;
    }
  }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear(){
    while(!empty()){
      pop_back();
    }
    sizey = 0;
  }

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

private:

  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  int sizey = 0;


  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other){
    for(Node *p = other.first; p != nullptr; p = p->next){
      push_back(p->datum);
    }
  }

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty

public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.

  public:
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.


    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }

    Iterator& operator++(){
      assert(node_ptr);
      node_ptr = node_ptr->next;
      return *this;
    }

    bool operator==(Iterator rhs) const{
      return node_ptr == rhs.node_ptr;
    }

    bool operator!=(Iterator rhs) const{
      return node_ptr != rhs.node_ptr;
    }

    T & operator*(){
      assert(node_ptr);
      return node_ptr->datum;
    }

  private:
  friend class List;
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
    // construct an Iterator at a specific position
    Iterator(Node *p)
      :node_ptr(p){
    }

    Iterator()
      :node_ptr(nullptr){
    }
  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
  Iterator end() const{
    return Iterator();
  }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
  void erase(Iterator i){
    if(i.node_ptr == first && i.node_ptr == last){
      delete i.node_ptr;
      first = nullptr;
      last = nullptr;
    }
    else if(i.node_ptr == first){
      first = first->next;
      delete first->prev;
      first->prev = nullptr;
    }
    else if(i.node_ptr == last){
      last = last->prev;
      delete last->next;
      last->next = nullptr;
    }
    else{
      Node *previous = i.node_ptr->prev;;
      Node *nexty = i.node_ptr->next;
      previous->next = nexty;
      nexty->prev = previous;
      delete i.node_ptr;
    }
  }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
  void insert(Iterator i, const T &datum){
    if(i.node_ptr == nullptr){
      push_back(datum);
    }
    else if(i.node_ptr == first && i.node_ptr == last){
      push_front(datum);
    }
    else if(i.node_ptr == first){
      push_front(datum);
    }else{
      Node *current = i.node_ptr;
      Node *p = new Node;
      p->datum = datum;
      p->next = current;
      p->prev = current->prev;
      current->prev->next = p;
    }
  }

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.


#endif // Do not remove this. Write all your code above this line.
