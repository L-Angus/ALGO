#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <vector>

template <typename K, typename V> struct HashPair {
  K key;
  V val;
  HashPair(K k, V v) : key(k), val(v) {}
};

template <typename K, typename V> class HashTable {
public:
  HashTable() { mBuckets = std::vector<HashPair<K, V> *>(100); }
  ~HashTable() {
    for (const auto &bucket : mBuckets) {
      delete bucket;
    }
    mBuckets.clear();
  }

  size_t HashFunc(K key) {
    size_t hashIndex = key % mBuckets.capacity();
    return hashIndex;
  }

  V get(K key) {
    auto hashIndex = HashFunc(key);
    HashPair<K, V> *pair = mBuckets.at(hashIndex);
    return pair ? V() : pair->val;
  }

  void put(K key, V val) {
    HashPair<K, V> *pair = new HashPair(key, val);
    size_t hashIndex = HashFunc(key);
    mBuckets[hashIndex] = pair;
  }

  std::vector<HashPair<K, V> *> PairSet() {
    std::vector<HashPair<K, V> *> pairSet;
    for (HashPair<K, V> *pair : mBuckets) {
      if (pair) {
        pairSet.push_back(pair);
      }
    }
    return pairSet;
  }

  void print() {
    for (HashPair<K, V> *bucket : mBuckets) {
      if (!bucket)
        continue;
      std::cout << "key: " << bucket->key << "** value: " << bucket->val << std::endl;
    }
  }

  size_t size() const { return mBuckets.size(); }

private:
  std::vector<HashPair<K, V> *> mBuckets;
};

#endif // HASH_TABLE_HPP