#include <iostream>
using namespace std;
#include "letter_count.hpp"

constexpr int N_CHARS = ('Z' - 'A' + 1);

int main()
{
    string s;
    int counts[N_CHARS] = {0};

    getline(cin, s);
    count(s, counts);
    print_counts(counts, N_CHARS);

    return 0;
}