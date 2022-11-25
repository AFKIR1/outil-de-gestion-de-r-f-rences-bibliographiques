/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include "Journal.h"
#include <sstream>
#include <iostream>
using namespace std;
using namespace util;

namespace biblio
{


  Journal::Journal (const std::string& p_auteurs, const std::string& p_titre, const unsigned int p_annee, const std::string& p_identifiant, const std::string& p_nom, const unsigned int p_volume, const unsigned int p_numero, const unsigned int p_page)
  : Reference (p_auteurs, p_titre, p_annee, p_identifiant), m_nom (p_nom)  , m_volume (p_volume), m_numero (p_numero), m_page (p_page)
  {
    PRECONDITION (p_nom.length () > 0);
    PRECONDITION (p_volume > 0);
    PRECONDITION (p_numero > 0);
    PRECONDITION (p_page > 0);
    PRECONDITION (validerCodeIssn (p_identifiant));

    POSTCONDITION (m_nom == p_nom);
    POSTCONDITION (m_volume == p_volume);
    POSTCONDITION (m_numero == p_numero);
    POSTCONDITION (m_page == p_page);

    INVARIANTS ();

  }


  const std::string&
  Journal::reqNom () const
  {
    return m_nom;

  }


  int
  Journal::reqVolume () const
  {
    return m_volume;
  }


  int
  Journal::reqNumero () const
  {
    return m_numero;
  }


  int
  Journal::reqPage () const
  {
    return m_page;
  }


  const std::string
  Journal::reqReferenceFormate () const
  {

    ostringstream os;
    os << Reference::reqReferenceFormate () <<  reqNom () << ", vol. " << reqVolume () << ", no. " << reqNumero ()
            << ", pp. " << reqPage () << ", " << reqAnnee () << ". " << reqIdentifiant () << ".";
    return os.str ();
  }


  Reference*
  Journal::clone () const
  {

    return new Journal (*this);
  }


  void
  Journal::verifieInvariant () const {
    //INVARIANT ();
  }

}