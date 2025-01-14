#include <iostream>
#include <set>
#include <map>

class Registro
{
public:
    int tr = 0, te = -1;
};

int main()
{
    using namespace std;
    set<int> keys;
    map<int, Registro> regs;

    int tt = 0, tin = 0; // tempo total, total de inputs
    char f;              // função
    int v;// valor
    cin >> tin;

    while (tin--)
    {
        cin >> f >> v;
        switch (f)
        {
        case 'T':
        {
            tt += v;
            break;
        }

        case 'R':
        {
            Registro obj;
            obj.tr = tt;
            keys.insert(v);
            regs[v] = obj;
            tt++;
            break;
        }

        case 'E':
        {
            regs[v].te = tt - regs[v].tr;
        }
        default:
        {
        }
        break;
        }
    }
    for (int k : keys)
    {
        cout << k << " " << regs[k].te << endl;
    }

    return 0;
}
