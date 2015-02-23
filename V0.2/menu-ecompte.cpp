/**
* @author Sofian HAMADACHE
**/

int MenuECompte(ECompte &CompteLambda)
{
    int choix;

    do
    {
        cout << "╔══════════════════════════════════════════════════════╗" << endl;;
        cout << "║              Gestion E-Compte                        ║" <<endl;;
        cout << "╠══════════════════════════════════════════════════════╣" << endl;
        cout << "║ "; Afficher_Today(today) ; cout <<"                  ║ " << endl;
        cout << "╟──────────────────────────────────────────────────────╢" << endl;
        cout << "║ Que voulez vous faire?                               ║ " << endl;
        cout << "║ 1. Afficher le compte                                ║ " << endl;
        cout << "║ 2. Ajouter de l'argent.                              ║ " << endl;
        cout << "║ 3. Retirer de l'argent.                              ║ " << endl;
        cout << "║ 4. Modifier les coordonnees.                         ║ " << endl;
        cout << "╟──────────────────────────────────────────────────────╢" << endl;
        cout << "║ 0. Retour au menu principal.                         ║ " << endl;
        cout << "╚══════════════════════════════════════════════════════╝" << endl;

        cout<<"\nVotre choix:";
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

            case 0: return;
                    break;

            default : cout<<"Ce choix n'est pas valide !\n";
                      break;
        }
    }
    while(!=0);
}
