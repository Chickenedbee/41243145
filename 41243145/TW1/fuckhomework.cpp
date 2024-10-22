#include <iostream>
#include<math.h>
#include <stack> 
using namespace std;
int A(int m,int n){
    if(m==0){
        return n+1;
    }
    else if(n==0){
        return A(m-1,1);
    }
        
    else {
        return A(m-1,A(m,n-1));
    }
        
}
int Ack_non_recursion(int m, int n) {
    struct Ack {    // Ackermann结构体
        int m_, n_;
        Ack(int m, int n) : m_(m), n_(n) {} // 构造函数
    } Node(m, n);

    stack<Ack> s;   // STL栈
    s.push(Node);   // 初始值入栈

    int ret = -1;   // Ackermann函数的返回值

    while(!s.empty()) {
        Node = s.top(); // 取栈顶的值
        s.pop();        // 并且出栈
        if(Node.m_ == 0) {  // 第一种情况，m 等于 0
            ret = Node.n_ + 1;  // 返回值为 n + 1
            if(s.empty())   // 如果栈空了，说明不需要继续向上返回，已经得到了最终结果
                break;      // 跳出循环
            Node = s.top(); // 否则，更新栈顶结点（第三种情况中 用 -1 标记的待计算的 n 的值）
            s.pop();        // 先出栈
            Node.n_ = ret;  // n 修改为返回值
            s.push(Node);   // 再重新入栈
        }
        else if(Node.n_ == 0) { // 第二种情况，n 等于 0
            s.push(Ack(Node.m_ - 1, 1));    // Ack(m - 1, 1) 入栈
        }
        else {  // 第三种情况，m, n 都大于 0
            s.push(Ack(Node.m_ - 1, -1));   // 用 -1 标记 n ，表示还没有计算出值，Ack(m - 1, -1) 入栈
            s.push(Ack(Node.m_, Node.n_ - 1));  // 要计算 n 的值，Ack(m, n - 1) 入栈
        }
    }
    return ret;
}
int main(){
    int m,n,out,count;
    cin>>m>>n;
    out=A(m,n);
    cout<<out<<endl;
    #include <stack>



//版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。
                        
//原文链接：https://blog.csdn.net/qq_26119041/article/details/111941618
}