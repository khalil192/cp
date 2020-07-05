#include<iostream>
#include<string>
#include<set>
using namespace std;



int main(){
    int n;
    cin>>n;
    set<string> words;
    for(int i = 0;i<n;i++){

        string cmd , curr;
        cin>>cmd>>curr;
        if(cmd == "add"){
           words.insert(curr);
        }
        
        if(cmd == "find"){
            int cnt = 0 , len = curr.length();
            set<string> :: iterator it;
            for(it  = words.begin();it != words.end();it++){
                string w = *it;
                if(w.length() >= len &&  w.substr(0,len) == curr){
                    cnt++;
                }
            }
            cout<<cnt<<endl;
        }
    }
   return 0;
}
