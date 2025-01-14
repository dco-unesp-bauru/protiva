#include <iostream>
#include <set>

class Carta
{
public:
    int d = 0, u = 0, v = 0;
    char n;
};

void validar(const std::set<int> &cartas)
{
    if ((cartas.find(0) != cartas.end()))
    {
        std::cout << "erro";
    }
    else
    {
        std::cout << 13 - cartas.size();
    }
}

int main()
{
    using namespace std;
    string input;
    set<int> sC, sE, sU, sP;
    set<std::set<int>> baralho;
    cin >> input;

    // Processa a entrada a cada 3 caracteres
    for (size_t i = 0; i < input.size(); i += 3)
    {
        // Pega os próximos 3 caracteres
        std::string group = input.substr(i, 3);
        Carta carta;

        // separar valores:
        carta.d = group[0] - '0';
        carta.u = group[1] - '0';
        carta.n = group[2];
        carta.v = carta.d * 10 + carta.u;

        // 3 sets
        // verificar se item existe
        // se existe então erro
        // as cartas faltantes igual 13-set.size

        switch (carta.n)
        {
        case 'C':
            // Se a carta existir
            if (sC.find(carta.v) != sC.end())
            {
                // marca set com 0;
                sC.insert(0);
            }
            else
            {
                sC.insert(carta.v);
            }
            break;
        case 'E':
            if (sE.find(carta.v) != sE.end())
            {
                // marca set com 0;
                sE.insert(0);
            }
            else
            {
                sE.insert(carta.v);
            }
            break;
        case 'U':
            if (sU.find(carta.v) != sU.end())
            {
                // marca set com 0;
                sU.insert(0);
            }
            else
            {
                sU.insert(carta.v);
            }

            break;
        case 'P':
            if (sP.find(carta.v) != sP.end())
            {
                // marca set com 0;
                sP.insert(0);
            }
            else
            {
                sP.insert(carta.v);
            }
            break;
        default:
            break;
        }
    }

    validar(sC);
    validar(sE);
    validar(sU);
    validar(sP);

    return 0;
}