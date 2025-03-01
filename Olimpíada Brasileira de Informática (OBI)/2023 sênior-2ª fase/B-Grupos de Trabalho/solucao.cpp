#include<iostream>
#include<vector>
#include <bits/stdc++.h>	
using namespace std;

int main()
{
	int e, m, d;
	cin >> e >> m >> d;
	vector<vector<int> > pLike;
	vector<vector<int> > pDLike;
	
	for (int i = 0; i < m; i++) 
	{
	    int a, b;
	    vector<int> auxV;
	    cin >> a >> b;
	    
	    auxV.push_back(a); auxV.push_back(b);
	    pLike.push_back(auxV);
	}
	
	for(int i = 0; i < d; i++)
	{
		int a, b;
		vector<int> auxV;
	    cin >> a >> b;
	    
	    auxV.push_back(a); auxV.push_back(b);
		pDLike.push_back(auxV);
	}
	
	int rest = 0;
	bool canContinue = false;
	
	for(int i = 0; i < e/3; i++)
	{
		int a, b, c;
		vector<int> auxV;
		cin >> a >> b >> c;
		
		for(int i = 0; i < pLike.size(); i++)
		{
			if(pLike[i][0] == a || pLike[i][0] == b || pLike[i][0] == c)
			{
				if(pLike[i][1] == a || pLike[i][1] == b || pLike[i][1] == c)
				{
					canContinue = true;
					break;
				}	
			}
		}
		
		for(int i = 0; i < pDLike.size(); i++)
		{
			if(pDLike[i][0] == a || pDLike[i][0] == b || pDLike[i][0] == c)
			{
				if(pDLike[i][1] == a || pDLike[i][1] == b || pDLike[i][1] == c)
				{
					rest++;
				}	
			}
		}
	}
	if(!canContinue && m != 0)
	{
		rest++;
		canContinue = true;
	}
		
	cout << rest << endl;
    return 0;
}
