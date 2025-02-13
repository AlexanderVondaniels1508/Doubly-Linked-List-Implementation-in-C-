#ifndef LINKEDLIST_VERSION_TWO_H
#define LINKEDLIST_VERSION_TWO_H

#include <iostream>
#include <memory>
#include <cstring>
#include "Exceptions.h"

using std::string;
using std::cout;
using std::endl;


template <class T> 
class Object final 
{
public:
    Object() = default;

    explicit Object(T data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev =nullptr;
    }
    T get_data(void) const {
        return data;
    }
    std::shared_ptr<Object<T>> get_next(void) const {
        return next;
    }
    std::shared_ptr<Object<T>> get_prev(void) const {
        return prev;
    }

public:
    T data;
    std::shared_ptr<Object<T>> next;
    std::shared_ptr<Object<T>> prev;
};


template <class T> 
class LinkedList final 
{
public:

    using shared_obj_ptr = std::shared_ptr<Object<T>>; 
    using type_name = T;

    explicit LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    ~LinkedList(){
        while(head != nullptr){
            pop_front();
        }
    }

    shared_obj_ptr push_front(T data) 
    {
        shared_obj_ptr ptr;

        try{
            ptr=std::make_shared<Object<T>>(data);
        } 
        catch(const std::bad_alloc&)
        {
            throw LinkedListMemoryError("Failed to allocate memory for new node.");
        }

        ptr->next = head;
        if (head != nullptr)
            head->prev = ptr;
        if (tail == nullptr)
            tail = ptr;
        head = ptr;

        length++;

        return ptr;
    }


    shared_obj_ptr push_back(T data) 
    {
        shared_obj_ptr ptr;

        try {
            ptr = std::make_shared<Object<T>>(data);
        } catch (const std::bad_alloc&) {
            throw LinkedListMemoryError("Failed to allocate memory for new node.");
        }

        ptr->prev = tail;
        if (tail != nullptr)
            tail->next = ptr;
        if (head == nullptr)
            head = ptr;
        tail = ptr;

        length++;

        return ptr;
    }

    void pop_front(void) 
    {
        if (head == nullptr) 
            throw LinkedListEmptyError("Attempt to pop from an empty list.");

        shared_obj_ptr ptr = head->next;
        if (ptr != NULL)
            ptr->prev = nullptr;
        else
            tail = nullptr;

        head = ptr;

        length--;
    }


    void pop_back(void) 
    {
        if(tail == nullptr)
            throw LinkedListEmptyError("Attempt to pop from an empty list.");

        shared_obj_ptr ptr = tail->prev;

        if(ptr != nullptr)
            ptr->next = nullptr;
        tail = ptr;

        length--;
    }

    shared_obj_ptr getAt(int index) 
    {
        if(index < 0 || index >= length)
            throw LinkedListIndexError("Invalid element index.");
        shared_obj_ptr ptr = head;
        int n = 0;

        while (n != index) {
            if (ptr == NULL)
                return ptr;
            ptr = ptr->next;
            n++;
        }
        
        return ptr;
    }

    shared_obj_ptr insert(int index, T data) 
    {
        if (index < 0 || index > length)
            throw LinkedListIndexError("Invalid element index.");

        if (index == 0)
            return push_front(data);

        if (index == length)
            return push_back(data);

        shared_obj_ptr right = getAt(index);
        shared_obj_ptr left = right->prev;

        shared_obj_ptr ptr;

        try {
            ptr = std::make_shared<Object<T>>(data);
        } 
        catch (const std::bad_alloc&) 
        {
            throw LinkedListMemoryError("Failed to allocate memory for new node.");
        }

        ptr->prev = left;
        ptr->next = right;
        left->next = ptr;
        right->prev = ptr;

        length++;

        return ptr;
    }

    void remove(int index)
    {
        if(index < 0 || index >= length)
            throw LinkedListIndexError("Invalid element index.");

        shared_obj_ptr ptr = getAt(index);
        if(ptr == nullptr)
            return;
        if(ptr->prev == nullptr){
            pop_front();
            return;
        }
        if(ptr->next == nullptr){
            pop_back();
            return;
        }

        shared_obj_ptr left = ptr->prev;
        shared_obj_ptr right = ptr->next;

        left->next = right;
        right->prev = left;

        if(left == nullptr && right == nullptr) {
            head = nullptr;
            tail = nullptr;
        }
        length--;
    }

    shared_obj_ptr get_head(void) const {
        return this->head;
    }

    shared_obj_ptr get_tail(void) const {
        return this->tail;
    }

    T& operator [] (int index) 
    {
        if(index < 0 || index >= length)
            throw LinkedListIndexError("Invalid element index.");
        shared_obj_ptr ptr = getAt(index);
        if(ptr == nullptr) 
            throw LinkedListIndexError("Invalid element index.");
        return ptr->data;
    }
    
    inline void print(void) const 
    {
        shared_obj_ptr ptr = head;
        for(; ptr != nullptr; ptr = ptr->next){
            cout << ptr->data << " ";
        }
    }
    
    inline bool empty(void) const {
        return length==0;
    }
    
    inline int size(void) const {
        return this->length;
    }

private:
    std::shared_ptr<Object<T>> head;
    std::shared_ptr<Object<T>> tail;

    unsigned int length{0};
};

#endif // LINKEDLIST_VERSION_TWO_HPP