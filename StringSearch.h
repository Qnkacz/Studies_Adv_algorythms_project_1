#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

class StringSearch
{
    public:
    StringSearch(const string &T, const string &P):T(T),P(P){};
    virtual void search() =0;
    vector<int>&got_ocuracies();
    vector<int>ocuracies;
    bool matches_at(int i);
    const string &T;
    const string &P;
    int m=P.size();
    int n=T.size();
};

class NaiveSearch : StringSearch
{

};
class KMPSearch : StringSearch
{

};
class BadCharacter : public StringSearch
{
    public:
    int m=P.size();
    vector<int>helper;
    vector<int>S;
    vector<int>F;
    void init1();
    void init2();
    BadCharacter(const string &T, const string &P) : StringSearch(T,P), helper(256,-1), S(m+1,0), F(m+1,0)
    {
        F[m]=m+1;
        for(int j=0;j<m;j++)
        {
            helper[P[j]]=j;
        }
    }

};
class SundaySearch : public BadCharacter
{
public:
int counter=0;
SundaySearch(const string &T, const string &P) : BadCharacter(T,P){};
virtual void search();
virtual bool matches_at(int i);
};
class Tester
{
public:


};
class PrefixSearch: public StringSearch
{
    virtual void fill_P()=0;
    virtual void search();
    StringSearch::T;
    StringSearch::P;
    vector<int>PI;
};
class Morris_Pratt: public  StringSearch
{
int *Pi;

public:
    Morris_Pratt(const string &T, const string &P): StringSearch(T,P){};
    virtual void search();
    void weakgoodP(int *_PI);
    int counter=0;
};
class KMP: public PrefixSearch
{

};
class Boyer_Moore :public  BadCharacter
{
    private:

public:
    Boyer_Moore(const string &T, const string &P):BadCharacter(T,P){};

int counter=0;
virtual void search();
};
