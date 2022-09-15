#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE/**
void ULListStr::push_back(const std::string& val) {
  if (size_ > 0) {
    if (tail_->last < ARRSIZE) {
      tail_->val[tail_->last] = val;
      tail_->last ++;
    } else {
      Item* newTail = new Item();
      newTail->val[0] = val;
      newTail->first = 0;
      newTail->last = 1;
      tail_->next = newTail;
      newTail->prev = tail_;
      tail_ = newTail;
    }
  } else {
    Item* firstItem = new Item();
    firstItem->val[0] = val;
    firstItem->last ++;
    head_ = firstItem;
    tail_ = firstItem;
  }
  size_ ++;
}

/**
  * Removes a value from the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_back() {
  if (tail_->last > 0) {
    tail_->last --;
  } else {
    Item* oldTail = tail_;
    tail_ = tail_->prev;
    tail_->next = NULL;
    delete oldTail;
  }
  size_ --;
}

/**
  * Adds a new value to the front of the list.
  * If there is room before the 'first' value in
  * the head node add it there, otherwise, 
  * allocate a new head node.
  *   - MUST RUN in O(1)
  */
void ULListStr::push_front(const std::string& val) {

}

/**
  * Removes a value from the front of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_front() {

}

/**
  * Returns a const reference to the back element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::back() const {
  if (tail_ == NULL) {
    return NULL;
  } else {
    return tail_->val[tail_->last - 1];
  }
}

/**
  * Returns a const reference to the front element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::front() const {
  if (head_ == NULL) {
    return NULL;
  } else {
    return head_->val[head_->first];
  }
}

void ULListStr::print () const {
  Item* current = head_;
  std::cout << "ULL Size " << size_ << ": ";
  while (current != NULL) {
    for (size_t i = 0; i < ARRSIZE; i ++) {
      std::cout << (i >= current->first && i < current->last ? (
        current->val[i]
      ) : (
        "_"
      ));
    }
    std::cout << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  Item* current = head_;
  size_t i = 0;
  while (current != NULL) {
    const size_t itemSize = (current->last - current->first);
    if (i + itemSize > loc) {
      return &(current->val[current->first + (loc - i)]);
    } else {
      i += itemSize;
      current = current->next;
    }
  }
  return NULL;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
