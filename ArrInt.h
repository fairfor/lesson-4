#ifndef ARRAYINT_H
#define ARRAYINT_H

#include <cassert> // ��� assert()
#include <iostream>
class ArrayInt
{
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() : m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length) :
        m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        // ����� ��� ����� ������� m_data �������� nullptr, ����� �� ������ �� ���� �������� ���������
        m_data = nullptr;
        m_length = 0;
    }
    int getLength() { return m_length; }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // ������� resize �������� ������ �������. ��� ������������ �������� �����������. ������� ���������
    void resize(int newLength)
    {
        // ���� ������ ��� ������ ����� � return
        if (newLength == m_length)
            return;

        // ���� ����� ������� ������ ������ � ������ ��� � ����� return
        if (newLength <= 0)
        {
            erase();
            return;
        }

        // ������ �����, ��� newLength >0
        // �������� ����� ������
        int* data = new int[newLength];

        // ����� ����� ����������� � ����������� ���������� ��������� � ����� ������
        // ����� ����������� ������� ���������, ������� �� ���� � ������� �� ��������
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            // ���������� �������� ��������
            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        // ������� ������ ������, ��� ��� �� ��� ��� �� �����
        delete[] m_data;

        // � ���������� ������ ������� ������� �����! �������� ��������, m_data ���������
        // �� ��� �� �����, �� ������� ��������� ��� ����� ����������� ���������� ������. ���������
        // ������ ���� ����������� ���������� � ��� �� ����� ����������, ����� ������ �� ������� ���������
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        // �������� ������������ ������������� �������
        assert(index >= 0 && index <= m_length);

        // ������� ����� ������ �� ���� ������� ������ ������� �������
        int* data = new int[m_length + 1];

        // �������� ��� �������� �� index-�
        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        // ��������� ����� ������� � ����� ������
        data[index] = value;

        // �������� ��� �������� ����� ������������ ��������
        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        // ������� ������ ������ � ���������� ������ ���� ����� 
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value) { insertBefore(value, m_length); }

    // ======================================================================

    void delBefore(int index) {
        assert(index >= 0 && index <= m_length);

        int* data = new int[m_length - 1];

        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void pop_back() {
        delBefore(m_length);
    }

    void swap(int* xp, int* yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

    void sort(int arr[], int n)
    {
        int i, j;
        for (i = 0; i < n - 1; i++)
            for (j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(&arr[j], &arr[j + 1]);
    }

    void printArr() {
        for (int i = 0; i < m_length; i++) {
            std::cout << m_data[i] << " " << std::endl;
        }
    }
};
#endif