

#include <iostream>
#include <string>
#include <new>

using namespace std;

#include "Map.h"

template<class K, class V>
Map<K, V>::Map()
{
    this->pHead = nullptr;
}

template<class K, class V>
Map<K, V>::~Map()
{
    delete []this->pHead->pNext;
}

template<class K, class V>
Node<K, V> Map<K, V>::getHead(K key) const
{
    Node<K, V> * p = this->pHead;
    if (p->key == key)
        return p;
    else 
        return nullptr;
}

template<class K, class V>
int Map<K, V>::size() const
{
    Node<K, V> * p = this->pHead;
    int count = 0;
    
    while (p != nullptr)
    {
        count++;
        p = p->pNext;
    }    
    return count;
}

template<class K, class V>
bool Map<K, V>::put(K key, V value)
{
    Node<K, V> * p = nullptr;
    try
    {
        p = new Node<K, V>();        
    }
    catch (bad_alloc e)
    {
        cout << e.what();
        exit(-1);
    }
    
    p->key = key;
    p->value = value;
    
    if (size() == 0)
        this->pHead = p;
    else
    {
        Node<K, V> * temp = this->pHead;
        while (temp->pNext != nullptr)
        {
            temp = temp->pNext;
        }
        temp->pNext = p; 
    }    
    return true;
}

template<class K, class V>
V Map<K, V>::get(K key) const
{    
    Node<K, V> * p = this->pHead;
    V v;
    while(p != nullptr)
    {        
        if (p->key == key)
        {
            v = p->value;
            break;
        }                  
        else
            p = p->pNext;
    }
    return v;
}

template<class K, class V>
void Map<K, V>::clear()
{
    while (this->pHead->pNext != nullptr)
    {
        Node<K, V> * temp = this->pHead;
        temp = this->pHead->pNext;
        this->pHead->pNext = temp->pNext;
        delete temp;  
        delete this ->pHead;
    }    
    delete this->pHead;
}

template<class K, class V>
ostream& operator<< (ostream & stream, Map<K, V> & map)
{
    for(int i =0; i < map.size(); i++)
    {
        stream << map.get(i) << " ";
    }

    return stream;
}