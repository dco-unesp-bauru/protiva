#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n1, n2;
    vector<int> seq;
    vector<int> subseq;
    cin >> n1 >> n2;
    for(int i = 0; i < n1; i++)
    {
        int aux = 0;
        cin >> aux;
        seq.push_back(aux);
    }
    for(int i = 0; i < n2; i++)
    {
        int aux = 0;
        cin >> aux;
        subseq.push_back(aux);
    }
    
    bool isDifferent = true;
    int j = 0;
    for(int i = 0; i < n2; i++)
    {
        for(j; j < n1; j++)
        {
            if(subseq[i] == seq[j])
            {
                isDifferent = false;
                break;
            }
        }
        if(isDifferent)
        {
            cout << "N" << endl;
            return 0;
        }
        isDifferent = true;
    }
    cout << "S" << endl;
    return 0;
}
