
#include <bits/stdc++.h>

using namespace std;
string FindAndReplace(string find, string Replace,string s);
// mohamed mostafa
// 20220309
// problem 02
// s23
int main (){
    string s ,s1 ;
    getline(cin, s);

    s1 = FindAndReplace("him" , "him or her", s);
   cout << FindAndReplace ("he" , "he or she", s1);
    //cout << FindAndReplace ("he" , "he or she",2 , s);

}
string FindAndReplace(string find, string replace ,string s){
    string  s1,s2;
    int startIndex = 0;
    int length = find.length();
    int index;

    do{
        s1= s;
        transform(s1.begin(),s1.end(), s1.begin(), ::tolower);
        s2 = s1.substr(startIndex, s1.length() - startIndex);
        index = s2.find(find);
        if(!(s1[index + startIndex -1]>= 97 && s1[index-1]<= 122)){
            if(index+length < s.length()){
                if(!(s1[index+ startIndex +length]>= 97 && s1[index+ startIndex+length]<= 122) && !(s1[index+ startIndex+length] >= 48 && s1[index+ startIndex+length] <= 57)){
                    s.replace(index+ startIndex, length, replace);
                }
            } else{
                s.replace(index+ startIndex, length, replace);
            }


        }
        startIndex = index+ startIndex + length;
    }while (index!=string::npos);
    return s;
}