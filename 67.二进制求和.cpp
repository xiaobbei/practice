#include<iostrea>
using namespace std; 

string addBinary(string a, string b) {
    int i=a.size()-1,j=b.size()-1,index=0;
    string res="";
    for(;i>=0&&j>=0;i--,j--){
        if((a[i]-'0')&&(b[j]-'0')&&index) res +="1";
        else if(!(a[i]-'0')&&!(b[j]-'0')&&!index) res +="0";
        else if((a[i]!=b[j])!=index) res +="1",index=0; 
        else res +="0",index=1;
    }
    if(index){
        for(;i>=0;i--){
            if((a[i]-'0')&&index) res +="0";
            else if((a[i]-'0')^index)  res +="1",index=0;
            else res +="0";
        }
        for(;j>=0;j--){
            if((b[j]-'0')&&index) res +="0";
            else if((b[j]-'0')^index)  res +="1",index=0;
            else res +="0";
        }
        if(index) res +="1";
    }
    else{
        for(;i>=0;i--) res +=a[i];
        for(;j>=0;j--) res +=b[j];
    }
    reverse(res.begin(),res.end());
    return res;
} 

int main()
{
	return 0;
}
