#include <iostream>
#include<math.h>
#include <stack> 
#include<vector>
using namespace std;


int main(){
    vector<int> arr;
    int num,n;
    cin>>num;
    for(int i=2;i<=num;i++){
        if(num%i==0){
            while (num%i!=0){
                num/=i;
                arr.push_back(i);
            } 
        }
    }
    
}