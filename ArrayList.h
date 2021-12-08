//
// File: ArrayList.h
// Author: Kali Hale
// Date: 2021-12-02
//

#include <string>
#include <iostream>
#include <regex>

#ifndef ARRAYLIST_LIBRARY_H
#define ARRAYLIST_LIBRARY_H

template<typename T>
class ArrayList
{
private:
    size_t m_size = 0;
    size_t m_capacity = 0;
protected:
    T* m_data = nullptr;
public:
    ArrayList()
    {
        realloc(2);
    }
    explicit ArrayList(int size)
    {
        realloc(size);
    };
    ArrayList(ArrayList const &copy)
    {
        realloc(copy.capacity());
        for(size_t i = 0; i < copy.size(); i++)
        {
            m_data[i] = copy.get(i);
        }
        m_size = copy.size();
    }
    ~ArrayList()
    {
        delete[] m_data;
    }
    std::string toString()
    {
        std::string s = "[";
        for (int i = 0; i < m_size - 1; i++)
        {
            s += m_data[i] + ", ";
        }
        s += m_data[m_size - 1] + "]";
        return s;
    }
    bool equals(ArrayList<T> array) const
    {
        if(array.size() != m_size)
        {
            return false;
        }
        else
        {
            for(int i = 0; i < m_size; i++)
            {
                if(m_data[i] != array.m_data[i])
                {
                    return false;
                }
            }
            return true;
        }
    }
    int size() const
    {
        return m_size;
    }
    int capacity() const
    {
        return m_capacity;
    }
    bool isEmpty() const
    {
        return m_size == 0;
    }
    bool contains(T object) const
    {
        for(size_t i = 0; i < m_size; i++)
        {
            if(m_data[i] == object)
            {
                return true;
            }
        }
        return false;
    }
    T get(int index) const
    {
        if (index < 0 || index >= m_size) throw "Index Out Of Bounds";
        return m_data[index];
    }
    T set(int index, T element)
    {
        if(index < 0 || index >= m_size) throw "Index Out Of Bounds";
        m_data[index] = element;
        return element;
    }
    void add(T element)
    {
        if(m_size >= m_capacity)
        {
            realloc(m_capacity * 1.5);
        }
        m_data[m_size] = element;
        m_size++;
    }
    void add(size_t index, T element)
    {
        if(index < 0 || index > m_size) throw "Index Out Of Bounds";
        T* temp = copyArray();
        if(m_size == m_capacity)
        {
            realloc(m_capacity * 1.5);
        }

        m_size += 1;
        m_data[index] = element;
        for(size_t i = index + 1; i < m_size; i++)
        {
            m_data[i] = temp[i - 1];
        }
        delete[] temp;
    }
    T remove(int index)
    {
        if(index < 0 || index >= m_size) throw "Index Out Of Bounds";
        T temp = m_data[index];
        for(int i = index; i < m_size - 1; i++)
        {
            m_data[i] = m_data[i + 1];
        }
        m_size -= 1;
        return temp;
    }
    // ／(•ㅅ•)＼ Removes first instance of o
    bool remove(T o)
    {
        int index = indexOf(o);
        if(index == -1) return false;
        else
        {
            for(size_t i = index; i < m_size - 1; i++)
            {
                m_data[i] = m_data[i + 1];
            }
            m_size -= 1;
            return true;
        }
    }
    int indexOf(T o)
    {
        for(size_t i = 0; i < m_size; i++)
        {
            if(m_data[i] == o)
            {
                return i;
            }
        }
        return -1;
    }
    int lastIndexOf(T o)
    {
        for(size_t i = m_size - 1; i >= 0; i--)
        {
            if(m_data[i] == o)
            {
                return i;
            }
        }
        return -1;
    }
private:
    void realloc(size_t newCapacity)
    {
        T* newBlock = new T[newCapacity];

        if(newCapacity < m_size)
        {
            m_size = newCapacity;
        }

        for(size_t i = 0; i < m_size; i++)
        {
            newBlock[i] = m_data[i];
        }

        delete[] m_data;
        m_data = newBlock;
        m_capacity = newCapacity;
    }
    T* copyArray()
    {
        T* newBlock = new T[m_capacity];

        for(size_t i = 0; i < m_size; i++)
        {
            newBlock[i] = m_data[i];
        }
        return newBlock;
    }
};

#endif //ARRAYLIST_LIBRARY_H

