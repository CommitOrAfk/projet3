/** main.cpp juste pour tester
test date uniquement pour l'instant
**/
#include "date.h"

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


return 0;
}
