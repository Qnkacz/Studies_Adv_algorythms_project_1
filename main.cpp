#include "stringSearch.h"

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}
void GenerujPlik()
{
    ofstream o("text.txt");
for(int i=0;i<2048;i++)
{
    int seed=rand()%5+1;
    switch(seed)
    {
    case 1:
        o<<"abcd";
        break;
    case 2:
        o<<"aaaa";
        break;
    case 3:
        o<<"accd";
        break;
    case 4:
        o<<"abbc";
        break;
    case 5:
        o<<"aacd";
        break;
    }
}
o.close();
}
int main()
{
string _P;
string t;
string _T;
srand (time(NULL));
GenerujPlik();

ifstream in;
in.open("text.txt");
while(!in.eof()) {
	getline(in, t);
	_T += t;

}

cout<<"Podaj szukana fraze: ";
cin>>_P;
int iterator=0;
string str1;
int sundaySearchCounter=0;
int morris_PrattCounter=0;
int boyer_MooreCounter=0;
StartCounter();
int suwak=(iterator+2048)-_P.size();
while(iterator<_T.size())//mechanika ciecia na kawalki
{
    if(iterator<_T.size()-2048) //duze ciecia
    {

        str1=_T.substr(iterator,iterator+2048); //robienie substringa
        iterator+=(2048-(_P.size()+1)); //przesuniecie substringa
        Boyer_Moore BM(str1,_P); //siup siup szukanko sie robi
        BM.search(); //tutaj tym bardziej
        boyer_MooreCounter+=BM.ocuracies.size(); //wpisanie liczby wyników do countera
    }
    else //male, ostatnie ciecie
    {
        str1=_T.substr(iterator,_T.size()-1);
        iterator+=(2048-_P.size());
        Boyer_Moore BM(str1,_P);
        BM.search();
        boyer_MooreCounter+=BM.ocuracies.size();
    }

}
cout<<"algorytm znalazl: "<< boyer_MooreCounter <<" wyników w przeciagu "<<GetCounter()<<endl;




return 0;
}
