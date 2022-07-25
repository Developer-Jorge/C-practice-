#include <iostream>
#include <string>
using namespace std;

string intToString(int a){
    return to_string(a);
}
string tToString(string t){
    return t;
}
template<typename T>
struct Coll{
    string s;
    char sep;
};
template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T)){
    addToken(c.s,c.sep,tToString(t));
    return collSize<T>(c)-1;
}
int main(){
    Coll<int> c1 = coll<int>();
    collAdd<int>(c1,3,intToString);
    collAdd<int>(c1,5,intToString);
    collAdd<int>(c1,7,intToString);
    collAdd<int>(c1,9,intToString);

}
