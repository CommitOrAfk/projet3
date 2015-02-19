/** main.cpp juste pour tester
test date uniquement pour l'instant
**/
#include "date.h"
#include "client.h"

int main()
{
Date D1;
Date D2(18, 2, 2015);

D1.Afficher(cout);
D2.Afficher(cout);

if(D1<D2)
{
    cout<<"toto \n";
}
else
{
    cout<<"pa toto \n";
}

D2 = D2+5;
D2.Afficher(cout);

Client C1(1111, 0000, "Aznar", "Pierre", "24, rue de machin Millau");
C1.Afficher(cout);

return 0;
}
