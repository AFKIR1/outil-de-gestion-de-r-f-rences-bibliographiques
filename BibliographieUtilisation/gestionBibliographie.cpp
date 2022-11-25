#include <cstdlib>
#include <iostream>
#include <string>
#include "Reference.h"
#include "validationFormat.h"
#include "Bibliographie.h"
#include "Ouvrage.h"
#include "Journal.h"


using namespace std;
using namespace biblio;
using namespace util;


int
main ()
{


  Bibliographie bibliographie ("bibliographie des ouvrages et journals");
  cout << "Bienvenue dans l'outil de gestion de references bibliographiques" << endl;
  cout << "================================================================" << endl;
  cout << "-------------------------------------------------------" << endl;
  cout << "Ajoutez un ouvrage" << endl;
  cout << "-------------------------------------------------------" << endl;

  // traitement de l'auteur
  string auteur;
  cout << "Entrez le nom du ou des auteurs :" << endl;
  getline (cin, auteur);
  while (auteur == "")
    {
      cout << "Le nom des auteurs ne doit pas être vide, recommencez" << endl;
      getline (cin, auteur);
    }

  while (!validerFormatNom (auteur))
    {
      cout << "nom d'auteur non valide,saisissez un autre:" << endl;
      getline (cin, auteur);
    }

  // traitement de titre
  string titre ;
  cout << "Entrez le titre :" << endl;
  getline (cin, titre);
  while (titre == "")
    {
      cout << "le titre ne doit pas être vide, recommencez" << endl;
      getline (cin, titre);
    }





  // traitement de l'identifiant
  string ville ;
  cout << "Entrez la ville d’édition:" << endl;
  getline (cin, ville);
  while (!validerFormatNom (ville))
    {
      cout << "nom de ville non valide,saisissez un autre:" << endl;
      getline (cin, ville);
    }


  //traitement nom editeur
  string editeur;
  cout << "Entrez l'éditeur :" << endl;
  getline (cin, editeur);
  while (!validerFormatNom (editeur))
    {
      cout << "nom de l'editeur non valide,saisissez un autre:" << endl;
      getline (cin, ville);
    }



  //traitement annee edition
  int anneeEdition;
  cout << "Entrez l'année d'édition :" << endl;
  cin >> anneeEdition;
  while (anneeEdition <= 0)
    {
      cout << "l'annee d'edition ne doit pas être vide, recommencez" << endl;
      cin >> anneeEdition;
    }







  string identifiant2;
  cout << "Entrez le code ISBN :" << endl;
  getline (cin, identifiant2);
  while (!validerCodeIsbn (identifiant2))
    {
      cout << "Le code ISBN n’est pas valide, recommencez" << endl;
      getline (cin, identifiant2);
    }


  Ouvrage unOuvrage (auteur, titre, anneeEdition, identifiant2, editeur, ville);

  bibliographie.ajouterReference (unOuvrage);


  cout << "-------------------------------------------------------" << endl;
  cout << "Ajoutez une référence de type article de journal" << endl;
  cout << "-------------------------------------------------------" << endl;

  cout << "Entrez le nom du ou des auteurs :" << endl;
  getline (cin, auteur);
  while (auteur == "")
    {
      cout << "Le nom des auteurs ne doit pas être vide, recommencez" << endl;
      getline (cin, auteur);
    }

  while (!validerFormatNom (auteur))
    {
      cout << "nom d'auteur non valide,saisissez un autre:" << endl;
      getline (cin, auteur);
    }

  // traitement de titre
  cout << "Entrez le titre :" << endl;
  getline (cin, titre);
  while (titre == "")
    {
      cout << "le titre ne doit pas être vide, recommencez" << endl;
      getline (cin, titre);
    }
  //traitement de la revue dans laquelle a été publiée la référence

  string nom;
  cout << "Entrez le nom de la revue dans laquelle a été publiée la référence :" << endl;
  getline (cin, nom);
  while (nom == "")
    {
      cout << "Le nom des auteurs ne doit pas être vide, recommencez" << endl;
      getline (cin, nom);
    }

  //volume/numero/page


  int numero;
  int volume;
  int page;

  cout << "Entrez le volume :" << endl;
  cin >> volume;
  while (volume <= 0)
    {
      cout << "le volume ne doit pas être vide, recommencez" << endl;
      cin >> volume;
    }

  cout << "Entrez le numero" << endl;
  cin >> numero;
  while (numero <= 0)
    {
      cout << "le numero d'edition ne doit pas être vide, recommencez" << endl;
      cin >> numero;
    }
  cout << "Entrez la page" << endl;
  cin >> page;
  while (page <= 0)
    {
      cout << "le numero d'edition ne doit pas être vide, recommencez" << endl;
      cin >> page;
    }

  //traiteemnt annee edition
  cout << "Entrez l'année :" << endl;
  cin >> anneeEdition;
  while (anneeEdition <= 0)
    {
      cout << "lannee ne doit pas être vide, recommencez" << endl;
      cin >> anneeEdition;
    }

  //traiteemnt identifiant
  string identifiant;
  cout << "Entrez le code ISSN :" << endl;
  getline (cin, identifiant);
  while (!validerCodeIssn (identifiant))
    {
      cout << "Le code ISSN n’est pas valide, recommencez" << endl;
      getline (cin, identifiant);
    }


  Journal unJournal (auteur, titre, anneeEdition, identifiant, nom, volume, numero, page);

  bibliographie.ajouterReference (unJournal);

  cout << "Références bibliographiques enregistrées :" << endl;
  cout << bibliographie.reqBibliographieFormate () << endl;


  //Homayoon Beigi. Fundamentals of Speaker Recognition. New York : Springer, 2011. ISBN 978-0-387-77591-3.
  //Hart. A survey of source code management tools for programming courses. Journal of Computing Sciences in Colleges, vol. 24, no. 6, pp. 113, 2009. ISSN 1937-4771 .



}


