/**
*
* CacheManager.hpp : This is the header file for CacheManager.
*
* 09/23/24 - Created by ChatGPT
* 09/23/24 - Modified by jhui
* 11/07/24 - Modified by jhui
* 12/17/24 - Modified, fixed error and added Smart pointer by Chirayu Jain 
*/


#ifndef _CACHE_MANAGER
#define _CACHE_MANAGER

#include "FifoNode.hpp"
#include "DoublyLinkedList.hpp"
#include "HashTable.hpp"
#include <string>
#include <memory>

class CacheManager {
private:
    size_t _maxSize;
    size_t _curSize;

    std::unique_ptr<DoublyLinkedList> _fifoCache;
    std::unique_ptr<HashTable> _hashTable;

public:
    CacheManager(size_t capacity);
    ~CacheManager() = default; // Smart pointers handle cleanup

    // Non-copyable
    CacheManager(const CacheManager&) = delete;
    CacheManager& operator=(const CacheManager&) = delete;

    // Movable
    CacheManager(CacheManager&&) = default;
    CacheManager& operator=(CacheManager&&) = default;

    // Return raw pointers for compatibility with existing code
    HashTable* getTable();
    DoublyLinkedList* getFifoList();
    Node* getItem(int key);

    size_t getSize();
    bool isEmpty();
    size_t getNumberOfItems();
    bool add(int key, Data* data);
    bool remove(int key);
    void clear();
    bool contains(int key);
};

#endif // _CACHE_MANAGER

