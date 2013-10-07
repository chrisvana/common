// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_UTIL_STL_H__
#define _COMMON_UTIL_STL_H__

#include "common/base/callback.h"

// Map/set utilities
template <typename Container, typename Key>
bool ContainsKey(const Container& c, const Key& k) {
  return c.find(k) != c.end();
}

// Vector/list/etc.
template <typename Value>
struct STLElementEquals {
  bool operator()(const Value& a, const Value& b) const {
    return a == b;
  }
};
template <typename Container, typename Value,
          typename Equals=STLElementEquals<Value> >
bool ContainsValue(const Container& c, const Value& v) {
  for (const Value& val : c) {
    if (Equals()(v, val)) {
      return true;
    }
  }
  return false;
}

template <typename Container, typename Key,
          typename Value=typename Container::mapped_type>
Value FindWithDefault(const Container& c, const Key& k, const Value& v) {
  auto it = c.find(k);
  return (it == c.end() ? v : it->second);
}

template <typename Container, typename Key,
          typename Value=typename Container::mapped_type>
Value FindPtrOrNull(const Container& c, const Key& k) {
  auto it = c.find(k);
  return (it == c.end() ? nullptr : it->second);
}

// Memory management --------------------------------------------
template <typename T>
void DeleteElements(T* t) {
  for (auto& it : *t) {
    delete it;
  }
}

template <typename T>
void DeleteValues(T* t) {
  for (auto& it : *t) {
    delete it.second;
  }
}

class ElementDeleter {
 public:
  template <typename T>
  explicit ElementDeleter(T* t) : runner_(NewCallback(&DeleteElements<T>, t)) {}
  ~ElementDeleter() {}
 private:
  AutoClosureRunner runner_;
};

class ValueDeleter {
 public:
  template <typename T>
  explicit ValueDeleter(T* t) :runner_(NewCallback(&DeleteValues<T>, t)) {}
  ~ValueDeleter() {}
 private:
  AutoClosureRunner runner_;
};

#endif  // _COMMON_UTIL_STL_H__
