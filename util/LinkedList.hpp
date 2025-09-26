#pragma once
#include <cstddef>
#include <stdio.h>
#include <vector>
/*
template <typename T> class node{
    public:
        T* data;
        node* next;
        bool to_free;
        bool to_delete;
        node(T* data, bool to_free)
        {
            this->data = data;
            this->to_free = to_free;
            to_delete = false;
        }
        ~node()
        {
            if (to_free)
                delete data;
        }
};
template <typename T> class LinkedList
{
    std::vector<node<T>*> list;
    int deleted = 0;

    public:
        void reserve(int preallocated_size)
        {
            list.reserve(preallocated_size);
        }
        void insert_node(node<T>* new_node)
        {
            list.push_back(new_node);
        }
        int get_count()
        {
            return list.size() - this->deleted;
        }
        void tag(int index)
        {
            deleted++;
            list[index]->to_delete = true;
        }
        int get_deleted()
        {
            return deleted;
        }
        void remove_tagged()
        {
            deleted = 0;
            for (int i = 0; i < list.size(); i++)

        }
        void clear()
        {
           for (int i = 0; i < list.size(); i++)
                delete list[i];
            list.clear();
        }
        T* iterate(int ind)
        {
            return list[ind]->data;
        }
};
*/

template <typename T> class node{
    public:
        T* data;
        node* next;
        bool to_free;
        bool to_delete;
        node(T* data, bool to_free)
        {
            this->data = data;
            this->to_free = to_free;
            to_delete = false;
        }
        ~node()
        {
            if (to_free)
                delete data;
        }
};
template <typename T> class LinkedList
{
    node<T> *first;
    node<T> *last;
    node<T> *last_pre;
    node<T> *current;
    int count = 0, index = 0, deleted = 0;
    bool preallocated = false;
    int preallocated_size;
    private:
        int clear(node<T> *n)
        {
            if (n == NULL)
                return count;
            node<T> *next = n->next;
            delete n;
            int depth = clear(next)+1;

            return depth;
        }
        void remove_node(node<T>* pre, node<T>* curr)
        {
            if (pre)
                pre->next = curr->next;
            else
                first = curr->next;

            if (!curr->next)
                last = pre;

            if (preallocated)
            {

                curr->data = NULL;
                last->next = curr;
            }
            else
                delete curr;

            count--;
        }

    public:
        void reserve(int preallocated_size)
        {
            this->preallocated_size = preallocated_size;
            for (int i = 0; i < preallocated_size; i++)
                insert_node(new node<T>(NULL, false));
            count = 0;
            preallocated = true;

        }
        void insert_node(node<T>* new_node)
        {
            if (preallocated && count >= preallocated_size)
                return;
            if (count == 0)
            {
                if (preallocated)
                {
                    last_pre = first;
                    first->data = new_node->data; 
                    current= first;
                    delete new_node;
                }
                else
                {
                    last = new_node;
                    first = new_node;
                    current = new_node;
                }
            }
            else
            {
                if (preallocated)
                {
                    last_pre->next->data = new_node->data;
                    last_pre = last_pre->next;
                    delete new_node;
                }
                else
                {
                    last->next = new_node;
                    last = new_node;
                }
            }
            last->next = NULL;

            count++;

        }
        int get_count()
        {
            return this->count - this->deleted;
        }
        void tag()
        {
            deleted++;

            if (index == count)
            {
                if (preallocated)
                    last_pre->to_delete = true;
                else
                    last->to_delete = true;
                return;
            }
            this->current->to_delete = true;
        }
        int get_deleted()
        {
            return deleted;
        }
        void remove_tagged()
        {
            deleted = 0;
            node<T>* c_i = first;
            node<T>* c_1i = NULL;
            node<T>* c_2i = NULL;
            int i = 0;
            while (i < count)
            {
                if (c_i->to_delete)
                {
                    node<T> *ci_next = c_i->next;
                    remove_node(c_1i, c_i);
                    c_i = ci_next;
                }
                else    
                {
                    c_1i = c_i;
                    c_i = c_i->next;
                    i++;
                }
                
            }   

        }
        void clear()
        {
            if (count > 0)
                clear(first);
            count = 0;
            reset_iterate();
        }
        T* iterate()
        {
            if (index < count)
            {
                if (index == 0)
                    this->current = first;
                else
                    this->current = this->current->next;
                T *hold = this->current->data;
                
                index++;
                if (this->current->to_delete)
                    return iterate();
                return hold;
            }
            return NULL;
        }
        void reset_iterate()
        {
            index = 0;
            current = first;
        }
        node<T>* get_list() const
        {
            return first;
        }
}; 
