void MenuLivret(Livret &unLivret)
{
    int choix;
	double interet;
    cout << "╔══════════════════════════════════════════════════════╗" << endl;;
    cout << "║              Gestion Livret Epargne                   ║" <<endl;;
    cout << "╠══════════════════════════════════════════════════════╣" << endl;
    cout << "╟──────────────────────────────────────────────────────╢" << endl;
    cout << "║ Que voulez vous faire?                               ║ " << endl;
    cout << "║ 1. Ajouter de l'argent à votre compte épargne        ║ " << endl;
    cout << "║ 2. Calcul de vos intérêts sur l'année                ║ " << endl;
    cout << "║ 3. Cloturer le Livret Epargne                        ║ " << endl;
    cout << "╟──────────────────────────────────────────────────────╢" << endl;
    cout << "║ 0. Retour au menu principal.                         ║ " << endl;
    cout << "╚══════════════════════════════════════════════════════╝" << endl;
    cout<<"Entrer l'opération à effectuer : ";
    cin>>choix;

      while(choix<0 || choix>3)
    {
        cout<<"Erreur ! Entrer un chiffre entre 0 et 3 : ";
        cin>>choix;
    }
    switch(choix)
	{
		case 0 :	return;
					break;
					
		case 1 :	Livret.Ajouter();
					break;
					
		case 2 :	interet=Livret.CalculInteret();
					cout<<"Vos intérêts durant l'année est de "<<interet<<"€"<<endl;
					break;
		case 3 :	Livret.Cloturer();
					cout<<"Votre compte épargne a bien été clôturé"<<endl;
					break;
	}
	
	
	
	
	
	
}
