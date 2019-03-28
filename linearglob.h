/*
  Linear glob is a very simple data structure. It acts as a wrapper
  for a map that maps strings to values. It allows values to be indexed
  by globs.
*/
#ifndef LINEARGLOB_H
#define LINEARGLOB_H
#include <map>
#include <string>
#include <fnmatch.h>
#include <vector>

template <typename T>
class LinearGlob {
private:
  std::map<std::string, T> internalMap;
public:
  LinearGlob() {};
  void add(std::string key, T value);
  T getSingle(std::string key);
  std::vector<T> getPattern(const char* pattern);
};

#include "linearglob.tpp"

#endif
