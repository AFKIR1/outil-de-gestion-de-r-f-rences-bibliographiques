/*
 * File:   Reference.h
 * Author: etudiant
 *
 * Created on 19 octobre 2022, 01:08
 */

#ifndef REFERENCE_H
#define REFERENCE_H

#include <string>
#include "ContratException.h"
#include "validationFormat.h"

namespace biblio
{

  class Reference
  {
  public:

    Reference (const std::string& p_auteurs, const std::string& p_titre, unsigned int p_annee, const std::string& p_identifiant);

    virtual
    ~Reference () { };


    const std::string& reqAuteurs () const;
    const std::string& reqTitre () const;
    const std::string& reqIdentifiant () const;
    int reqAnnee () const;

    void asgAnnee (unsigned int p_annee);

    virtual const std::string reqReferenceFormate () const = 0;

    bool operator== (const Reference& p_reference) const;

    virtual Reference* clone () const = 0;


  private:

    void verifieInvariant () const;

    std::string m_auteurs; //Auteur(s) de la reference
    std::string m_titre; //titre de la reference
    unsigned int m_annee; //Annee d'edition de la reference
    std::string m_identifiant; // identifiant de la reference  ISSN ou ISBN


  };
} // namespace biblio

#endif /* REFERENCE_H */

