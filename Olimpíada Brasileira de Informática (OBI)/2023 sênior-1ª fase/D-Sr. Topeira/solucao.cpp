#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int> > tunnels;
    int n1, n2, n3;
    int tours = 0;
    
    cin >> n1 >> n2;
    for(int i = 0; i < n2; i++)
    {
        int a, b;
        cin >> a >> b;
        //para c++ 11 ou superior 
        /*tunnels.push_back({a, b}); 
    	tunnels.push_back({b, a}); */
        
        //inferior:
        vector<int> auxVec1, auxVec2;
        auxVec1.push_back(a); auxVec1.push_back(b);
        auxVec2.push_back(b); auxVec2.push_back(a);
        tunnels.push_back(auxVec1); tunnels.push_back(auxVec2);
        
    }
    cin >> n3;
    tours = n3;
    
    for(int i = 0; i < n3; i++)
    {
        bool canTour = false;
        vector<int> nums;
        int num;
        
        cin >> num;
        for(int k = 0; k < num; k++)
        {
            int y;
            cin >> y;
            nums.push_back(y);
        }
        
        for(int k = 0; k < num; k++)
        {   
            for(int j = 0; j < n2*2; j++)
            {
                if(tunnels[j][0] == nums[k])
                {
                    if(tunnels[j][1] == nums[k+1] || k+1 >= num)
                    {
                        canTour = true;
                        break;
                    }
                }
                
            }
            if(canTour == false)
            {
                tours--;
                break;
            }
            canTour = false;
        }
    }
    
    cout << tours << endl;
    return 0;
}
