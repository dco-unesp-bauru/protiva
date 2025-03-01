#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	vector<int> seq;
	cin >> n;
	
	int num = 0;
	int maxNum = 0;
	int nInicial = 0;
	int nFinal = 0;
	vector<int> usedNums;
	
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		seq.push_back(a);
		nFinal = seq.size()-1;
		for(int k = 0; k < usedNums.size(); k++)
		{
			if(usedNums[k] == a)
			{
				nInicial = k+1;
			}
		}
		usedNums.push_back(a);
		num = (nFinal - nInicial);
		
		if(maxNum < num)
			maxNum = num;
	}
	cout << maxNum + 1 << endl;

    return 0;
}
