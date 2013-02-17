#pragma once
#include "string"
#include "sstream"

using namespace std;
template <typename T>
class Tree
{
public:
    class Iterator
    {
    public:
        Iterator(Tree<T> *tmp) : it(tmp) {}
        void operator++()
        {
            it = it->next(it);
        }
        void operator--()
        {
            it = it->prev(it);
        }
        T operator*()
        {
            return it->val(it);
        }
        bool operator==(Iterator &tmp)
        {
            return it == tmp.pointer();
        }
        bool operator!=(Iterator &tmp)
        {
            return it != tmp.pointer();
        }

    private:
        Tree<T> *it;
        Tree<T> *pointer()
        {
            return it;
        }
    };

    Tree() : count(0), head(NULL), value(0) {}
    ~Tree();
    bool isEmpty() const;
    void add(const T &x);
    int length() const;
    bool search(const T &x);
    void RemoveNode(const T &x);
    int height() const;
    string printToWidth() const;
    string print() const;
    Tree<T> *first();
    Tree<T> *last();
    Tree<T> *next(Tree<T> *x);
    Tree<T> *prev(Tree<T> *x);
    T val(Tree<T> *x);

private:
    string print(Tree *tmp) const;
    int heightOfBranches(Tree *t) const;
    void clear(Tree *t);
    int count;
    Tree<T> *left;
    Tree<T> *right;
    Tree<T> *head;
    Tree<T> *begin;
    Tree<T> *parent;
    Tree<T> *end;
    T value;
};

template <typename T>
Tree<T>::~Tree()
{
    clear(head);
}

template <typename T>
bool Tree<T>::isEmpty() const
{
    return head == NULL;
}

template <typename T>
void Tree<T>::add(const T &x)
{
    if (head == NULL)
    {
        head = new Tree();
        head->left = NULL;
        head->right = NULL;
        head->value = x;
        head->parent = NULL;
        head->begin = head;
        head->end = head;
        count = 1;
        return;
    }
    Tree<T> *tmp = head;
    Tree<T> *tmp2 = head;
    while (tmp != NULL)
    {
        tmp2 = tmp;
        if (tmp->value >= x)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    tmp = new Tree();
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->value = x;
    tmp->parent = tmp2;
    if (head->begin->value >= tmp->value)
        head->begin = tmp;
    if (head->end->value < tmp->value)
        head->end = tmp;
    count++;
    if (tmp2->value >= x)
        tmp2->left = tmp;
    else
        tmp2->right = tmp;
}

template <typename T>
int Tree<T>::length() const
{
    return count;
}

template <typename T>
bool Tree<T>::search(const T &x)
{
    Tree<T> *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == x)
            return true;
        if (tmp->value > x)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return false;
}

template <typename T>
void Tree<T>::RemoveNode(const T &x)
{
    if (!search(x))
        return;
    Tree<T> **parent = &head;
    Tree<T> *tmp = head;
    while (tmp->value != x)
    {
        if (tmp->value >= x)
        {
            parent = &tmp->left;
            tmp = tmp->left;
        }
        else
        {
            parent = &tmp->right;
            tmp = tmp->right;
        }
    }
    if (tmp->left == NULL && tmp->right == NULL)
    {
        *parent = NULL;
        delete tmp;
    }
    else if (tmp->left == NULL && tmp->right != NULL)
    {
        *parent = tmp->right;
        tmp->right->parent = *parent;
        delete tmp;
    }
    else if (tmp->left != NULL && tmp->right == NULL)
    {
        *parent = tmp->left;
        tmp->left->parent = *parent;
        delete tmp;
    }
    else if (tmp->left != NULL && tmp->right != NULL)
    {
        Tree<T> **parent2 = &tmp->right;
        Tree<T> *tmp2 = tmp->right;
        while (tmp2->left != NULL)
        {
            parent2 = &tmp2->left;
            tmp2 = tmp2->left;
        }
        tmp->value = tmp2->value;
        *parent2 = NULL;
        delete tmp2;
    }
    count--;
}

template <typename T>
int Tree<T>::height() const
{
    return heightOfBranches(head);
}

template <typename T>
string Tree<T>::print() const
{
    if (head == NULL)
        return "";
    return print(head);
}

template <typename T>
Tree<T> *Tree<T>::first()
{
    return head->begin;
}

template <typename T>
Tree<T> *Tree<T>::last()
{
    return head->end;
}

template <typename T>
Tree<T> *Tree<T>::next(Tree<T> *x)
{
    Tree<T> *tmp = x;
    if (tmp->right != NULL)
    {
        tmp = tmp->right;
        while(tmp->left != NULL)
            tmp = tmp->left;
        return tmp;
    }
    if (tmp->parent == NULL)
        return x;
    tmp = tmp->parent;
    while (x->value > tmp->value)
    {
        if (tmp->parent == NULL)
            return x;
        tmp = tmp->parent;
    }
    return tmp;
}

template <typename T>
Tree<T> *Tree<T>::prev(Tree<T> *x)
{
    Tree<T> *tmp = x;
    if (tmp->left != NULL)
    {
        tmp = tmp->left;
        while(tmp->right != NULL)
            tmp = tmp->right;
        return tmp;
    }
    if (tmp->parent == NULL)
        return x;
    tmp = tmp->parent;
    while (x->value <= tmp->value)
    {
        if (tmp->parent == NULL)
            return x;
        tmp = tmp->parent;
    }
    return tmp;
}

template <typename T>
T Tree<T>::val(Tree<T> *x)
{
    return x->value;
}

template <typename T>
string Tree<T>::print(Tree *tmp) const
{
    if (tmp == NULL)
        return "";
    stringstream out;
    out << print(tmp->left);
    out << tmp->value << " ";
    out << print(tmp->right);
    return out.str();
}

template <typename T>
int Tree<T>::heightOfBranches(Tree *t) const
{
    if (t == NULL)
        return -1;
    int l = heightOfBranches(t->left);
    int r = heightOfBranches(t->right);
    if (l > r)
        return l+1;
    else
        return r+1 ;
}

template <typename T>
void Tree<T>::clear(Tree *t)
{
    if (t != NULL)
    {
        clear(t->left);
        clear(t->right);
        delete(t);
    }
}
