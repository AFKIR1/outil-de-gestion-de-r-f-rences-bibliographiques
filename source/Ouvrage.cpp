/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Ouvrage.h"
#include <sstream>
#include <iostream>
using namespace std;
using namespace util;

namespace biblio
{


  Ouvrage::Ouvrage (const std::string& p_auteurs, const std::string& p_titre,
                    const unsigned int p_annee, const std::string& p_identifiant,
                    const std::string& p_editeur, const std::string& p_ville)
  : Reference (p_auteurs, p_titre, p_annee, p_identifiant), m_editeur (p_editeur), m_ville (p_ville)
  {
    PRECONDITION (p_editeur.length () > 0);
    PRECONDITION (validerFormatNom (p_editeur));
    PRECONDITION (p_ville.length () > 0);
    PRECONDITION (validerFormatNom (p_ville));
    PRECONDITION (validerCodeIsbn (p_identifiant));

    POSTCONDITION (m_editeur == p_editeur);
    POSTCONDITION (m_ville == p_ville);

    INVARIANTS ();

  }


  const std::string&
  Ouvrage::reqEditeur () const
  {
    return m_editeur;

  }


  const std::string&
  Ouvrage::reqVille () const
  {
    return m_ville;
  }


  const std::string
  Ouvrage::reqReferenceFormate () const
  {

    ostringstream os;
    os << Reference::reqReferenceFormate ()  << reqVille () << " : " << reqEditeur () << ", " << reqAnnee () << ". " << reqIdentifiant () << ".";
    return os.str ();
  }


  Reference*
  Ouvrage::clone () const
  {

    return new Ouvrage (*this);
  }


  void
  Ouvrage::verifieInvariant () const {
    //INVARIANT (validerCodeIsbn (m_identifiant));
  }

}