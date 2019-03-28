#include "linearglob.h"

template <typename T>
void LinearGlob<T>::add(std::string key, T value) {
  this->internalMap[key] = value;
}

template <typename T>
T LinearGlob<T>::getSingle(std::string key) {
  auto it = this->internalMap.find(key);
  if (it == this->internalMap.end()) {
    throw std::invalid_argument("no key matches: " + key);
  }
  return it->second;
}

template <typename T>
std::vector<T> LinearGlob<T>::getPattern(const char* pattern) {
  std::vector<T> v;

  for (const auto &pair : this->internalMap) {
    if (fnmatch(pattern, pair.first.c_str(), 0) == 0) {
      v.push_back(pair.second);
    }
  }
  // downsize. likely this won't be added to.
  v.shrink_to_fit();
  return v;
}
