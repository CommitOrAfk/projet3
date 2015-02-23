/**
* @author Sofian HAMADACHE
**/

int MenuECompte(ECompte &CompteLambda)
{
    int choix;
    cout<<"\nBienvenue dans l'E-Compte\n");

    do
    {
        cout<<"\nQue voulez-vous faire ?\n";
        cout<<"1-Afficher les donnees du compte\n2-Deposer de l'argent sur le compte\n";
        cout<<"3-Retirer de l'argent sur le compte\n4-Modifier les coordonees du compte";
        cout<<"0-Retour au menu precedent\n";
        cin>>choix;

        switch(choix)
        {
            case 1: CompteLambda.Afficher();
                    break;

            case 2: CompteLambda.Ajouter();
                    break;

            case 3: CompteLambda.Retrait();
                    break;

            case 4: CompteLambda.ChangerCoordonnes();
                    break;

            case 0: return 1;
                    break;

            default : cout<<"Ce choix n'est pas valide !\n";
                      break;
        }
    }
    while(1);
}
