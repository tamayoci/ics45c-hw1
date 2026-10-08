#ifndef LETTER_COUNT_HPP
#define LETTER_COUNT_HPP

#include <iostream>
#include <string>
using namespace std;

int char_to_index(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        ch = ch - 'a' + 'A';

    return ch - 'A';
}

char index_to_char(int i)
{
    return 'A' + i;
}

void count(string s, int counts[])
{
    for (char ch : s)
    {
        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z'))
        {
            counts[char_to_index(ch)]++;
        }
    }
}

void print_counts(int counts[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << index_to_char(i) << " " << counts[i] << endl;
    }
}

#endif