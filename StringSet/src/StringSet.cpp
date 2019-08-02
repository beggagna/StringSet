#include "StringSet.h"

StringSet::StringSet()
{

}
void StringSet::addWord(string word)
{
    for(size_t i = 0; i < getLength(); i++)
    {
        if (vec[i] == word)
            return;
    }
    vec.push_back(word);
}
unsigned int StringSet::getLength() const
{
    return vec.size();
}
string StringSet::at(int i) const
{
    return vec[i];
}
bool StringSet::find(string word)
{
    for (size_t i = 0; i < getLength(); i++)
    {
        if (vec[i] == word)
        {
            return true;
        }
    }
    return false;
}
StringSet operator +(const StringSet& s1, const StringSet& s2)
{

    StringSet result;

    for (size_t i = 0; i < s1.getLength(); i++)
    {
        result.addWord(s1.at(i));
    }

    for(size_t i = 0; i < s2.getLength(); i++)
    {
        result.addWord(s2.at(i));
    }

    return result;
}
ostream& operator <<(ostream& out, const StringSet& s)
{
    for (size_t i = 0; i < s.getLength();  i++)
    {
        out << s.at(i) + " ";
    }
    return out;
}

StringSet operator *(const StringSet& s1,const StringSet& s2)
{
    StringSet result;

    for (size_t i = 0; i < s1.getLength(); i++)
    {
        for (size_t j = 0; j < s2.getLength(); j++)
        {
            if(s1.at(i) == s2.at(j))
            {
                result.addWord(s1.at(i));
            }
        }
    }
    return result;
}
