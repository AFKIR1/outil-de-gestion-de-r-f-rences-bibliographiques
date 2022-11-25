/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Bibliographie.h"
#include <sstream>
#include <iostream>
#include <vector>


using namespace std;

namespace biblio
{


  Bibliographie::Bibliographie (const std::string& p_nomBibliographie) :
  m_nomBibliographie (p_nomBibliographie)
  {
    PRECONDITION (!p_nomBibliographie.empty ());


    POSTCONDITION (m_nomBibliographie == p_nomBibliographie);
    POSTCONDITION (!m_nomBibliographie.empty ());


    INVARIANTS ();

  }


  Bibliographie::Bibliographie (const Bibliographie& p_bibliographie)
  {

    m_nomBibliographie = p_bibliographie.m_nomBibliographie;
    copierVecteur (p_bibliographie);

    POSTCONDITION (m_nomBibliographie == p_bibliographie.m_nomBibliographie);

    INVARIANTS ();


  }


  Bibliographie::~Bibliographie ()
  {
    viderVecteur ();

  }


  const std::string&
  Bibliographie::reqNomBibliographie () const
  {

    return m_nomBibliographie;
  }


  void
  Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
  {


    if (!referenceEstDejaPresente (p_nouvelleReference.reqIdentifiant ()))
      {

        m_vReferences.push_back (p_nouvelleReference.clone ());
      }
    //POSTCONDITION (referenceEstDejaPresente (p_nouvelleReference.reqIdentifiant ()));
    INVARIANTS ();

  }


  const std::string
  Bibliographie::reqBibliographieFormate () const
  {

    ostringstream os;
    os << "Bibliographie" << endl << "===============================" << endl;
    ;
    for (int i = 0; i < m_vReferences.size (); i++)
      {
        os << "[" << i + 1 << "]" << m_vReferences[i]->reqReferenceFormate () << endl;
      }

    return os.str ();

  }


  void
  Bibliographie::copierVecteur (const Bibliographie& p_bibliographie)
  {

    PRECONDITION (m_vReferences.empty ());

    for (int i = 0; i < p_bibliographie.m_vReferences.size (); i++)
      {
        ajouterReference (*p_bibliographie.m_vReferences[i]);
      }

    INVARIANTS ();


  }


  Bibliographie& Bibliographie::operator= (const Bibliographie& p_bibliographie)
  {

    m_nomBibliographie = p_bibliographie.m_nomBibliographie;
    viderVecteur ();
    copierVecteur (p_bibliographie);

    POSTCONDITION (m_nomBibliographie == p_bibliographie.m_nomBibliographie);

    INVARIANTS ();

    return *this;
  }


  bool
  Bibliographie::referenceEstDejaPresente (const std::string& p_identifiant) const
  {
    bool present = false;
    for (int i = 0; i < m_vReferences.size (); i++)
      {
        if (m_vReferences[i]->reqIdentifiant () == p_identifiant)
          {
            present == true;
          }
      }
    return present;

  }


  void
  Bibliographie::viderVecteur ()
  {
    for (int i = 0; i < m_vReferences.size (); i++)
      {
        delete m_vReferences[i];
      }
    m_vReferences.clear ();

    INVARIANTS ();

  }


  void
  Bibliographie::verifieInvariant () const
  {
    INVARIANT (m_vReferences.size () >= 0);
  }



}