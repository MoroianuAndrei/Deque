#pragma once
#include <iostream>
#include <vector>

template <typename T>
class Deque
{
private:
    const int BLOCK_SIZE = 8;
    std::vector<T*> map;
    int map_size;
    int front_index, back_index;
    int front_block, back_block;
    int m_size;
    int deleted_front, deleted_back;

    void expand_front();

    void expand_back();

public:
    Deque();

    ~Deque();

    void push_front(const T& value);

    void push_back(const T& value);

    void pop_front();

    void pop_back();

    T& front();

    T& back();

    bool empty();

    void clear();

    int size();

    T& operator[](int poz);

    void insert(T element, int poz);

    void del(int poz);

    void print();
};

template<typename T>
void Deque<T>::expand_front()
{
    if (front_index == 0)
    {
        if (front_block == 0)
        {
            if (deleted_front == 0)
            {
                map.insert(map.begin(), new T[BLOCK_SIZE]);
                front_block++;
                back_block++;
                map_size++;
            }
            else
            {
                deleted_front--;
            }
        }
        front_index = BLOCK_SIZE;
        front_block--;
    }
}

template<typename T>
void Deque<T>::expand_back()
{
    if (back_index == BLOCK_SIZE - 1)
    {
        if (back_block == map_size - 1)
        {
            if (deleted_back == 0)
            {
                map.push_back(new T[BLOCK_SIZE]);
                map_size++;
            }
            else
            {
                deleted_back--;
            }
        }
        back_index = -1;
        back_block++;
    }
}

template<typename T>
Deque<T>::Deque() : map_size(2), front_index(BLOCK_SIZE), back_index(-1), 
front_block(0), back_block(1), m_size(0), deleted_front(0), deleted_back(0)
{
    map.push_back(new T[BLOCK_SIZE]);
    map.push_back(new T[BLOCK_SIZE]);
}

template<typename T>
Deque<T>::~Deque()
{
    for (auto block : map)
    {
        delete[] block;
    }
}

template<typename T>
void Deque<T>::push_front(const T& value)
{
    expand_front();
    map[front_block][--front_index] = value;
    m_size++;
}

template<typename T>
void Deque<T>::push_back(const T& value)
{
    expand_back();
    map[back_block][++back_index] = value;
    m_size++;
}

template<typename T>
void Deque<T>::pop_front()
{
    if (front_index == BLOCK_SIZE)
    {
        if (front_block == back_block)
        {
            std::cout << "Deque is empty" << std::endl;
            return;
        }
        deleted_front++;
        if (deleted_front == 2)
        {
            delete[] map[front_block - 2];
            map.erase(map.begin() + front_block - 2);
            deleted_front--;
            map_size--;
        }
        front_block++;
        front_index = 0;
    }
    else
    {
        front_index++;
    }
    m_size--;
}

template<typename T>
void Deque<T>::pop_back()
{
    if (back_index == -1)
    {
        if (back_block == front_block)
        {
            std::cout << "Deque is empty" << std::endl;
            return;
        }
        deleted_back++;
        if (deleted_back == 2)
        {
            delete[] map[back_block + 2];
            map.erase(map.begin() + back_block + 2);
            deleted_back--;
            map_size--;
        }
        back_block--;
        back_index = BLOCK_SIZE - 1;
    }
    else
    {
        back_index--;
    }
    m_size--;
}

template<typename T>
T& Deque<T>::front()
{
    int copyFrontBlock = front_block, copyFrontIndex = front_index;
    if (front_index == BLOCK_SIZE)
    {
        if (front_block == back_block)
        {
            std::cout << "Deque is empty" << std::endl;
        }
        copyFrontBlock++;
        copyFrontIndex = 0;
    }
    return map[copyFrontBlock][copyFrontIndex];
}

template<typename T>
T& Deque<T>::back()
{
    int copyBackBlock = back_block, copyBackIndex = back_index;
    if (back_index == -1)
    {
        if (back_block == front_block)
        {
            std::cout << "Deque is empty" << std::endl;
        }
        copyBackBlock--;
        copyBackIndex = BLOCK_SIZE - 1;
    }
    return map[copyBackBlock][copyBackIndex];
}

template<typename T>
bool Deque<T>::empty()
{
    if (m_size == 0)
        return true;
    else
        return false;
}

template<typename T>
void Deque<T>::clear()
{
    while (!empty())
        pop_back();
}

template<typename T>
int Deque<T>::size()
{
    return m_size;
}

template<typename T>
T& Deque<T>::operator[](int poz)
{
    if (poz < 0 || poz >= m_size)
    {
        std::cout << "Index out of bounds" << std::endl;
    }

    int block_index = (poz + front_index) / BLOCK_SIZE;
    int element_index = (poz + front_index) % BLOCK_SIZE;

    return map[block_index][element_index];
}

template<typename T>
void Deque<T>::insert(T element, int poz)
{
    if (poz < 0 || poz > m_size)
    {
        std::cout << "Invalid position for insertion" << std::endl;
        return;
    }

    expand_back();
    push_back(0);

    int block_index = (poz + front_index) / BLOCK_SIZE;
    int element_index = (poz + front_index) % BLOCK_SIZE;

    for (int i = m_size - 1; i > poz; i--)
    {
        (*this)[i] = (*this)[i - 1];
    }

    (*this)[poz] = element;
}

template<typename T>
void Deque<T>::del(int poz)
{
    for (int i = poz; i < m_size - 1; i++)
    {
        (*this)[i] = (*this)[i + 1];
    }

    pop_back();
}

template<typename T>
void Deque<T>::print()
{
    for (int i = 0; i < m_size; i++)
        std::cout << (*this)[i] << " ";
    std::cout << std::endl;
}