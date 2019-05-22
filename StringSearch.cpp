#include "stringSearch.h"


bool StringSearch::matches_at(int i)
{
if(i+P.size()>T.size())
{
    return false;
}
for(int j=0;j<P.size();j++)
{
    if(T[i+j]!=P[j])
    {
        return false;
    }
}
return true;
}
/*vector& StringSearch::got_ocuracies()
{
    return occurances;
}*/

void StringSearch::search()
{
for(int i=0;i<=T.size()-P.size();i++)
{
    if(matches_at(i))
    {
        ocuracies.push_back(i);
    }
}
}

/*vector& StringSearch::got_ocuracies()
{

}
*/

void SundaySearch::search()
{
    counter=0;
    int i=0;
    while(i<=n-m)
    {
        if(matches_at(i))
        {
            counter++;
            ocuracies.push_back(i);
        }
        if(i+m<n)
        {
            i+=m-helper[T[i+m]];
        }
        else
        {
            break;
        }
    }
}
bool SundaySearch::matches_at(int i)
{
   if(i+m > n)
    {
        return false;
    }
    for(int j=0; j<m; j++)
    {
        if(T[i+j]!=P[j])
        {
            return false;
        }
    }
    return true;
}

void PrefixSearch::fill_P()
{

PI[0]=-1;
int i=0;
int j=0;
while(i<P.size())
{
    while(j<-1&&P[i]==P[j])
    {
        j=PI[j];
    }
    i++;
    j++;
    PI[i]=j;
}

}
void BadCharacter::init1()
{
    int i=m;
int j=m+1;
while(i>0)
{


while(j<=m && P[i-1]!=P[j-1])
{
    if(S[j]==0)
    {
        S[j]=j-i;
    }
    j=F[j];
}
j=m+1;
i--;j--;
F[i]=j;
}
}
void BadCharacter::init2()
{
int j=F[0];
for(int i=0;i<=m;i++)
{
    if(S[i]==0)
    {
        S[i]=j;
    }
    if(i==j)
    {
        j=F[j];
    }
}

}
void Boyer_Moore::search()
{
    init1();
    init2();
    int i=0;
    while(i<=n-m)
    {
        int j=m-1;
        while(j>=0 && T[i+j] == P[j])
        {
            j--;
        }
        if(j<0)
        {

            ocuracies.push_back(i);
            i+=S[0];
        }
        else
        {
            i+=max(S[j+1], j-helper[T[i+j]]);
        }
    }
}
void Morris_Pratt::search()
{
    counter=0;
int i = 0, j = 0;
    weakgoodP(Pi);
    while(i<n)
    {
        while(j>=0 && T[i]!=P[j])
        {
            j=Pi[j];
        }
        i++;
        j++;
        if(j==m)
        {
            int k=i-j;
            ocuracies.push_back(i-j);
            counter++;
            j=Pi[m];
        }
    }
}

void Morris_Pratt::weakgoodP(int* _Pi)
{
    this->Pi=_Pi;
    int i=0;
    int j=-1;
    Pi = new int[m+1];
    Pi[0]=-1;
    while(i<m)
    {
        while(j>-1 && P[i]!=P[j])
        {
            j=Pi[j];
        }
        i++;
        j++;
        Pi[i]=j;
    }
}


