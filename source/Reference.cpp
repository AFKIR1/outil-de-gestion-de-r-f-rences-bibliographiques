/**
 * \file Reference.cpp
 * \brief
 * \author Mohammed afkir
 * \version
 * \date 2021-10-20
 */


#include <sstream>
#include <iostream>
#include "Reference.h"

using namespace std;
using namespace util;

namespace biblio
{


  /**
   * \brief constructeur de la class Reference
   * \param[in] p_auteurs le nom l'auteur (ou du premier auteur s’ils sont plusieurs)
   * \param[in] p_titre le titre de reference
   * \param[in] p_annee l'année d'édition de la référence
   * \param[in] p_identifiant l’identifiant de la référence
   */
  Reference::Reference (const std::string& p_auteurs, const std::string& p_titre, unsigned int p_annee, const std::string& p_identifiant) :
  m_auteurs (p_auteurs) , m_titre (p_titre) , m_annee (p_annee) , m_identifiant (p_identifiant)
  {
    PRECONDITION (validerFormatNom (p_auteurs));
    PRECONDITION (p_auteurs.length () > 0);
    PRECONDITION (p_titre.length () > 0);
    PRECONDITION (p_annee > 0);
    PRECONDITION (p_identifiant.length () > 0);

    POSTCONDITION (m_auteurs == p_auteurs);
    POSTCONDITION (m_titre == p_titre);
    POSTCONDITION (m_annee == p_annee);
    POSTCONDITION (m_identifiant == p_identifiant);

    INVARIANTS ();

  }


  /**
   * \brief retourner le nom de l'auteur
   * \return nom de l'auteur
   */

  const std::string&
  Reference::reqAuteurs () const
  {
    return m_auteurs;
  }


  /**
   * \brief retourner le titre de reference
   * \return nom de titre de reference
   */
  const std::string&
  Reference::reqTitre () const
  {
    return m_titre;
  }


  /**
   * \brief retourner l'annee d'edition
   * \return annee d'edition
   */
  int
  Reference::reqAnnee () const
  {
    return m_annee;
  }


  /**
   * \brief retourner l'identifiant
   * \return identifiant
   */
  const std::string&
  Reference::reqIdentifiant () const
  {
    return m_identifiant;
  }


  /**
   * \brief  Assigne une annee à l'objet courant
   * \param[in] p_annee est un entier qui représente la nouvel annee
   */
  void
  Reference::asgAnnee (unsigned int p_annee)

  {
    PRECONDITION (p_annee > 0);

    m_annee = p_annee;

    POSTCONDITION (m_annee == p_annee);
  }


  /**
   * \brief  visualiser les informations correspondantà une référence formatées
   * \return chaine de caractere sous le format suivant "auteur, titre, annee d'edition, identifiant"
   */
  const string
  Reference::reqReferenceFormate () const
  {
    ostringstream os;
    os << reqAuteurs () << ". " << reqTitre () << ". ";
    return os.str ();
  }


  /**
   * \brief  tester l'egalite de deux reference
   * \param[in] p_reference un objet reference
   * \return 1 s'ils sont egaux, 0 sinon
   */
  bool Reference::operator== (const Reference& p_reference) const
  {
    return reqAuteurs () ==  p_reference.reqAuteurs ()
            && reqTitre () == p_reference.reqTitre ()
            && reqAnnee () == p_reference.reqAnnee ()
            && reqIdentifiant () == p_reference.reqIdentifiant ();
  }


  void
  Reference::verifieInvariant () const
  {
    INVARIANT (validerCodeIssn (m_identifiant) || validerCodeIsbn (m_identifiant));
  }
}
