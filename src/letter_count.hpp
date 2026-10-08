#ifndef LETTER_COUNT_HPP
#ifndef LETTER_COUNT_HPP
#include <iostream>
#include <string>
using namespace std;

int char_to_index(char ch)
{
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
        if (ch >= 'a' && ch <= 'z')
            ch = ch - 'a' + 'A';
        
        if (ch >= 'A' && ch <= 'Z')
            counts[char_to_index(ch)]++;
    }
}
void print_counts(int counts[]. int len)
{
    for (int 1 = 0; i < lens; i++)
    {
        count << index_to_char(i) << " " << counts[i] << endl;
    }
}

#endif