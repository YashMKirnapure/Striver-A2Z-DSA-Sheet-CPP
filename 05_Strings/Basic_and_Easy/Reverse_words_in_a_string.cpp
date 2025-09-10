#include <iostream>
using namespace std;

string reverseWords(string s)
{
    int n = s.size();
    int i = n - 1;
    string res = "";

    while (i >= 0)
    {
        while (i >= 0 && s[i] == ' ')
            i--;
        if (i < 0)
            break;
        int j = i;

        while (j >= 0 && s[j] != ' ')
            j--;

        if (!res.empty())
            res += ' ';

        res += s.substr(j + 1, i - j);
        i = j - 1;
    }
    return res;
}

/*
1. Start from the end of the string
    We set i = n - 1 (last character).
    We’re basically scanning backward.

2. Skip extra spaces
    While s[i] == ' ', move i left.
    This handles trailing spaces (and multiple spaces between words).

3. Mark the end of a word
    Once we find a non-space character, that’s part of a word.
    Let j = i.

4. Find the start of the word
    Keep moving j left until we either reach -1 or a space.
    Now the word is from s[j+1] to s[i].

5. Add the word to the result
    If the result string isn’t empty, add a space before appending the new word.
    Append s.substr(j+1, i-j) (that’s the word).

6. Move left for the next word
    Set i = j - 1 and repeat until we’ve covered the whole string.

7. Return the result → which now has all words reversed in order and no extra spaces.
*/