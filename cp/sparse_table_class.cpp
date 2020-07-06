#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;


class sparseTable{
    public :
        vector<int>log_table;
        vector<vector<int> >sTable;
        sparseTable(vector<int> arr){
            buildSTable(arr);
        }
      
        void buildSTable(vector<int>& arr){
            log_table.resize(arr.size()+1, 0);
            for (int i = 2; i < log_table.size(); i++) 
                log_table[i] = log_table[i/2] + 1;
            sTable.resize(log_table.back()+1 , vector<int>(arr.size()));
            sTable[0] = arr;
            for(int row = 1; row < sTable.size(); row++) {
                for (int i = 0; i + (1 << row) <= arr.size(); i++) {
                    sTable[row][i] = func(sTable[row-1][i], sTable[row-1][i+(1<<(row-1))]);
                }
        }
        }
        int func(int x, int y){ return x < y ? x : y; } 
        int rangeMin(int l,int r){
            r++;
            int log = log_table[r - l];
            int minimum = min(sTable[log][l], sTable[log][r - (1 << log)]);
            return minimum;
        }
};


int main(){
    vector<int> v;
    v.push_back(7);
    v.push_back(12);
    v.push_back(-1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(-2);
    v.push_back(1);

    sparseTable st = sparseTable(v);
    int c = 3;
    while(c--){
        int l,r;
        cin>>l>>r;
        cout<< st.rangeMin(l,r)<<endl;
    }

    return 0;
}