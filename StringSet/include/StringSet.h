#ifndef STRINGSET_H
#define STRINGSET_H
#include <vector>
#include <string>

using namespace std;

class StringSet
{
    private:
        vector <string> vec;
    public:
        StringSet();
        void addWord(string words);
        unsigned int getLength() const;
        string at(int i) const;
        friend StringSet operator +(const StringSet& s1, const StringSet& s2);
        friend ostream& operator <<(ostream& out, const StringSet& s);
        friend StringSet operator *(const StringSet& s1, const StringSet& s2);
        bool find(string word);

};

#endif // STRINGSET_H
