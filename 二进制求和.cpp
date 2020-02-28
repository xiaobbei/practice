#include<iostream>
#include<string>

using namespace std;
string addBinary(string a, string b) {
    int la = a.size();
    int lb = b.size();
    if(la < lb){
        swap(a, b);
        swap(la, lb);
    }
    if(la - lb > 0)
        b.insert(0, la - lb, '0');
    int pre = 0, cur = 0;
    string res;
    for(int i = la - 1; i >= 0; i--){
        int ia = a[i] - '0';
        int ib = b[i] - '0';
        cur = ia ^ ib ^ pre;  // ����������ӽ�����������ͬ
        if(ia + ib + pre >= 2) pre = 1;
        else pre = 0;
        res.insert(0, 1, cur + '0');
    }
    if(pre)  // ���λ�Ľ�λ��������
        res.insert(0, 1, pre + '0');
    return res;
}


int main()
{
	return 0;
 } 
