#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int M = 1e9+7;
 
int add(int x,int y){
    return (x+y)%M;
}
 
int mul(int x,int y){
    return (1ll*x*y)%M;
}
int sub(int x,int y){
    return (x-y+M)%M;
}
int exp(int x,int k){
    if(k==0) return 1;
    int x_k2=exp(x,k/2);
    if(k%2==1) return mul(mul(x_k2,x_k2),x);
    return mul(x_k2,x_k2);
}
int inv(int x){
    return exp(x,M-2);
}
 


 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N=0;
    int n=0;
    string S="";
    cin>> S;
	n=S.size();
//	cout << N << " teste\n";
    ll INV[26][n+1];
//    fflush(stdin);
    memset(INV,0,sizeof(INV));
    ll pre=0;
    ll suf=0;
    cin >> N;
    
    N%=M;
    for(int i=0;i<26;i++){
    	for(int j=0;j<n;j++){
    		if(j!=0){
    			int aux= (i+97>S[j])?1:0;
    			INV[i][j]=INV[i][j-1] + aux;
//    			cout << INV[i][j-1] << " " << aux  << " "; 	
			}
			else
				INV[i][j]=(i+97>S[j])?1:0;
//			cout << INV[i][j] << " <-- " << i << " " << j <<" \n";
		}
	}
	for(int i=0;i<n;i++){
		int letra=S[i]-97;
//		cout << INV[letra][n-1] << " <--" << letra << " \n";		
		suf=add(suf,INV[letra][n-1]);
		pre=add(pre,sub(INV[letra][n-1],INV[letra][i]));
	}
//	cout << "PRE " << pre << " suf " << suf << "\n"; 
//	cout << "N*(N-1) " << mul(N,N-1) << " inv(2) " << inv(2) << "\n";
//	cout << "N*pre " << mul(N,pre) << " soma pg " << mul(mul(N,N-1),inv(2)) << "\n"; 
//	cout << "SUFIXO*PG " << mul(suf,mul(mul(N,N-1),inv(2))) << " N = " << N << "\n";
	cout << add(mul(N,pre),mul(suf,mul(mul(N,sub(N,1)),inv(2)))) << "\n";
    return 0;
}