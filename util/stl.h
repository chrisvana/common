// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _COMMON_UTIL_STL_H__
#define _COMMON_UTIL_STL_H__

// Map/set utilities
template <typename Container, typename Key>
bool ContainsKey(const Container& c, const Key& k) {
  return c.find(k) != c.end();
}

template <typename Container, typename Key, typename Value>
bool FindWithDefault(const Container& c, const Key& k, const Value& v) {
  auto it = c.find(k);
  return (it == c.end() ? v : it.second);
}

template <typename Container, typename Key, typename Value>
bool FindPtrOrNull(const Container& c, const Key& k) {
  auto it = c.find(k);
  return (it == c.end() ? nullptr : it.second);
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

template <typename T>
class ElementDeleter {
 public:
  explicit ElementDeleter(T* t) : t_(t) {}
  ~ElementDeleter() {
    DeleteElements(t_);
  }
 private:
  T* t_;
};

template <typename T>
class ValueDeleter {
 public:
  explicit ValueDeleter(T* t) : t_(t) {}
  ~ValueDeleter() {
    DeleteValues(t_);
  }
 private:
  T* t_;
};

#endif  // _COMMON_UTIL_STL_H__
