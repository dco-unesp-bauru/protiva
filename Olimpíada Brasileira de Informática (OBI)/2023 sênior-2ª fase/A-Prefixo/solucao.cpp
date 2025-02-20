#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int a, b;
    string str1, str2;
    
    cin >> a >> str1 >> b >> str2;
    int sChars;
    
    for(int i = 0; i < str1.length(); i++)
    {
    	if(str1[i] == str2[i])
    		sChars++;
		else
			break;
	}
	cout << sChars << endl;
    return 0;
}
