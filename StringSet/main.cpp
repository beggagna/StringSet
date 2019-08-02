#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "StringSet.h"

using namespace std;

void readFileKeywords(StringSet& setDocument, const char filename[]);
double similarity(const StringSet& s1, const StringSet& s2);


int main()
{
    StringSet doc1;
    StringSet doc2;
    StringSet theUnion;
    StringSet query;


    readFileKeywords(doc1, "doc1.txt");
    readFileKeywords(doc2, "doc2.txt");


    cout << "Doc1: " << doc1 << endl;
    cout << "Doc2: " << doc2 << endl;
    theUnion = doc1 + doc2;
    cout << "Union: " << theUnion << endl;

    readFileKeywords(query, "query.txt");
    cout << "Query: " << query << endl;

    int count = 0;
    for (unsigned int i = 0; i < query.getLength(); i++)
    {
        if (theUnion.find(query.at(i)))
        {
            count++;
        }
    }

    cout << "Query size: " << query.getLength() << endl;
    cout << "Found in union: " << count << endl;


    // Calculate similarity to each document
    double sim1 = similarity(doc1, query);
    cout << "Similarity to doc1: " << sim1 << endl;


    double sim2 = similarity(doc2, query);
    cout << "Similarity to doc2: " << sim2 << endl;

    return 0;
}
void readFileKeywords(StringSet& setDocument, const char filename[])
{
    ifstream inFile;
    inFile.open(filename);

    if (inFile.fail())
    {
        cout << "Failed to open file!";
        exit(1);
    }

    while(!inFile.eof())
    {
        string word;
        while(inFile >> word)
        setDocument.addWord(word);
    }
    inFile.close();

}
double similarity(const StringSet& s1, const StringSet& s2)
{
    StringSet sim = (s1 * s2);

    return sim.getLength() / (sqrt(s1.getLength())* sqrt(s2.getLength()));
}

