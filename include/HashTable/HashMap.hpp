#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

#include <vector>

template <typename K, typename V> struct HashPair {
  K key;
  V val;
  HashPair(K key, V val) : key(key), val(val) {}
};

template <typename K, typename V> class HashMap {
public:
  HashMap() : size(0), capacity(4), mLoadFactor(2.0 / 3.0), extendRatio(2) {
    mBuckets.resize(capacity);
  }
  ~HashMap() {}

  size_t hasFunc(K key) { return key % capacity; }
  double loadFactor() { return (double)size / (double)capacity; }

  void put(K key, V val) {
    if (loadFactor() > mLoadFactor) {
      extend();
    }
    size_t index = hasFunc(key);
    for (HashPair<K, V> *pair : mBuckets[index]) {
      if (pair->key == key) {
        pair->val = val;
        return;
      }
    }
    mBuckets[index].push_back(new HashPair<K, V>(key, val));
    size++;
  }
  V get(K key) {
    size_t index = hasFunc(key);
    for (HashPair<K, V> *pair : mBuckets[index]) {
      if (pair->key == key) {
        return pair->val;
      }
    }
    return V();
  }

  void extend() {
    std::vector<std::vector<HashPair<K, V> *>> buckets = mBuckets;
    capacity *= extendRatio;
    mBuckets.clear();
    mBuckets.resize(capacity);
    size = 0;
    for (auto &bucket : mBuckets) {
      for (HashPair<K, V> *pair : bucket) {
        put(pair->key, pair->val);
        delete pair;
      }
    }
  }

  void print() {
    for (auto &bucket : mBuckets) {
      std::cout << "[";
      for (HashPair<K, V> *pair : bucket) {
        std::cout << pair->key << "->" << pair->val << ", ";
      }
      std::cout << "]" << std::endl;
    }
  }

  size_t Capacity() const { return capacity; }

private:
  size_t size;
  size_t capacity;
  double mLoadFactor;
  size_t extendRatio = 1;
  std::vector<std::vector<HashPair<K, V> *>> mBuckets;
};

#endif // HASH_MAP_HPP
