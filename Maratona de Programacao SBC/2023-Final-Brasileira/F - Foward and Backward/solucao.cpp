#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int M = 1e9+7;
ll pot[1000001][41];
ll N=0;
 
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
 



void innit(){
	for(int i=2;i<=1e6;i++){
		pot[i][0]=1;
	}
	for(int i=2;i<=1e6;i++){
		for(int j=1;j<=40;j++){
			pot[i][j]=i*pot[i][j-1];
			if(pot[i][j]>N)
				break;
		}
	}
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    innit();
    vector <ll> low_base;
    deque <ll> high_base;
    ll max=sqrt(N);
    
    //base com dois dígitos
    for(ll i=1;i<=max;i++){
    	if(N%(i)==0){
    		ll maior=N/(i);
    		if(i<maior-1)
				high_base.push_front(maior-1);
		}
	}
	
	//base com três ou mais dígitos
	ll numDig=3;
	for(ll i=max;i>=2;i--){
		if(i==10)
			i=10;
		while(N/pot[i][numDig-1]>=i && numDig<=40){
			numDig++;
		}
		ll resto=N;
		ll fim=numDig-1;
		ll id=0;
		bool base=true;
		ll interior=N;
		for(id;id<=(numDig)/2 -1;id++){
			if(id!=0){
			
				if(resto%i != 0){
					base=false;
					break;
				}
				interior = resto/i;
			}
			resto = interior % (pot[i][fim-id]+1);
			if(interior / (pot[i][fim-id]+1) >=i){
				base=false;
				break;
			}
			fim--;
		}
		if(numDig%2==1){
			if(resto%i!=0 || resto/i>=i){
				base=false;
			}
		}
		else{
			if(interior%(i+1)!=0){
				base=false;
			}
		}
		if(base){
			high_base.push_front(i);
		}
	}
	
	ll q1=low_base.size();
	ll q2=high_base.size();
	if(q1+q2==0)
		cout << "*\n";
	else{
		for(int i=0;i<q1;i++){
			cout <<low_base[i] << " ";
		}
		for(int i=0;i<q2-1;i++){
			cout << high_base[i] << " ";
		}
		cout << high_base[q2-1] << "\n";
	}
    return 0;
}