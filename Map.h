/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <string>
#include <new>

template<class K, class V>
struct Node
{
    K key;
    V value;
    Node<K, V> * pNext;
};

template<class K, class V>
class Map
{
    private:
        Node<K, V> * pHead;
    public:
        Map();
        ~Map();
        int size() const;
        bool put(K key, V value);
        V get(K key) const;
        Node<K, V> getHead(K key) const;
        void clear();
        friend ostream& operator<< (ostream & stream, const Map<K, V> & map);
};

#endif /* MAP_H */
