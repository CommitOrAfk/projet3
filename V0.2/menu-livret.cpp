void MenuLivret(Livret &unLivret)
{
    int choix;
    cout<<"1. Ajouter de l'argent à votre compte épargne"<<endl<<"2. Calcul de vos intérêts sur l'année"<<endl;
    cout<<"Entrer l'opération à effectuer : ";
    cin>>choix;

      while(choix<1 || choix>2)
    {
        cout<<"Erreur ! Entrer un chiffre entre 1 et 2 : ";
        cin>>choix;
    }
    if(choix==1)
    {
        unLivret.Ajouter();
    }
    else
    {
        unLivret.CalculInteret();
    }
}
