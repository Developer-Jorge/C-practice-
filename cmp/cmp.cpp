#include <iostream>
#include <string>
using namespace std;
template<typename T>
void cmpYmst(T a,T b,T c,int cmpTT(T,T),string tToString(T))
{
    T mayor, medio, menor;
    if(cmpTT(a,b)>0 && cmpTT(a,c)>0)
    {
        mayor=a;
        if(cmpTT(b,c)){
            medio=b;
            menor=c;
        }
        else{
            medio=c;
            menor=b;
        }
    }
    if(cmpTT(b,a)>0 && cmpTT(b,c)>0){
        mayor=b;
        if(cmpTT(a,c)>0){
            medio=a;
            menor=c;
        }
        else{
            medio=c;
            menor=a;
        }
    }
    if(cmpTT(c,a)>0 && cmpTT(c,b)>0){
        mayor=c;
        if(cmpTT(a,b)>0){
            medio=a;
            menor=b;
        }
        else{
            medio=b;
            menor=a;
        }
    }
cout<<"Menor:"<<tToString(menor)<<endl;
cout<<"Medio:"<<tToString(medio)<<endl;
cout<<"Mayor:"<<tToString(mayor)<<endl;
}

struct Fraction{
    int n;
    int d;
};

Fraction fraccion(int n,int d){return {n,d};}

string FractionToString(Fraction f){
    return to_string(f.n)+"/"+to_string(f.d);
}
int cmpFraccion(Fraction a,Fraction b){
    double Va = (double)a.n/a.d;
    double Vb = (double)b.n/b.d;
    int ret;
    return Va<Vb?ret=-1:Va>Vb?ret=1:ret=0;
}
int cmpString(string a, string b){
    int ret;
    return a<b?ret=-1:a>b?ret=1:ret=0;
}
string StringToString(string a){
    return a;
}
int main(){
    cmpYmst<string>("Juan","Jorge","Ana",cmpString,StringToString);
    cmpYmst<Fraction>(fraccion(2,5),fraccion(1,8),fraccion(3,7),cmpFraccion,FractionToString);
}