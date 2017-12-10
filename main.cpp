//A driver program that tests if two strings are anagrams.
#include <iostream>
#include <cctype>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void input(string& s1, string& s2);
//Reads a line of input into s1 and s2.

void stripSpacesAndPunct(string& s);
//Removes all whitespace and punctuation characters from s1 and s2.

void toLowerCase(string& s);
//Converts all uppercase characters to lowercase characters in s1 and s2.

void sort(string& s, int startPos, int endPos);
//Precondition: startPos and endPos are non-negative integers.
//Postcondition: Sorts letters in s in alphabetical order using in-place
//mergesort.

bool isAnagram(string& s1, string& s2);
//Precondition: Both s1 and s2 have been alphabetized, stripped 
//of all whitespace and punctuation characters, and are both in lowercase form. 
//Postcondition: Returns true if s1 and s2 are anagrams; otherwise, returns false.

void output(string& s1, string& s2);
//Precondition: s1 and s2 have been alphabetized, stripped of all whitespace
//and punctuation characters, and are both in lowercase form.
//Postcondition: Prints out the result of determing if both s1 and s2 are
//anagrams.

int main()
{
    string s1, s2;
    input(s1, s2); 
    output(s1, s2);

    return 0;
}


bool isAnagram(string& s1, string& s2)
{
    stripSpacesAndPunct(s1);
    stripSpacesAndPunct(s2);

    toLowerCase(s1);
    toLowerCase(s2);

    sort(s1, 0, s1.length() - 1);
    sort(s2, 0, s2.length() - 1);

    return s1 == s2;
}

void sort(string& s, int startPos, int endPos)
{
    if ((endPos - startPos) <= 1)
        return;

    sort(s, startPos, ((startPos + endPos) / 2));
    sort(s, ((startPos + endPos) / 2) + 1, endPos);

    for (int i = 1; i <= endPos; i++)
    {
        for (int j = i; j > 0 && s[j] < s[j - 1]; j--)
        {
            char temp = s[j - 1];
            s[j - 1] = s[j];
            s[j] = temp;
        }
    }
}

void toLowerCase(string& s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (isupper(s[i]))
            s[i] = tolower(s[i]);
    }
}

void stripSpacesAndPunct(string& s)
{
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (!isalnum(s[i]))
            s.erase(i, 1);
    }
}

void input(string& s1, string& s2)
{
    cout<<"Enter two sentences on different lines: \n\n";
    getline(cin, s1);
    getline(cin, s2);
    cout<<endl;
}

void output(string& s1, string& s2)
{
    if (isAnagram(s1, s2))
        cout<<"Both strings are anagrams.\n";
    else
        cout<<"These strings are not anagrams.\n";
}
