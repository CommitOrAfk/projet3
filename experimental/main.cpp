/** main.cpp juste pour tester
test date uniquement pour l'instant
**/
#include "date.h"
#include "client.h"
#include "compte.h"
#include "test.h"
#include "livret.h"
#include "posseder.h"

int main()
{
/*Date D1;
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
C1.Saisir(cin);
C1.Afficher(cout);*/

/*Compte Co1(111, 1234.56);
Co1.Afficher();
Co1.ChangerCoordonnes();
Co1.Cloturer();
Co1.Afficher(); //ne marche pas car le compte est cloturé!*/

//Test T1(2.4);
/*Compte *ptr_C01 = new Test(2.4);
ptr_C01->Afficher();
delete ptr_C01;*/


//Test T1(2.40);
//T1.Afficher();
posseder p;
p.SaisirClient();

return 0;
}
