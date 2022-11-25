/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Journal.h
 * Author: etudiant
 *
 * Created on 22 novembre 2022, 22:33
 */

#ifndef JOURNAL_H
#define JOURNAL_H

#include <string>
#include "ContratException.h"
#include "Reference.h"


namespace biblio
{

  class Journal : public biblio::Reference
  {
  public:
    Journal (const std::string& p_auteurs, const std::string& p_titre,
             const unsigned int p_annee, const std::string& p_identifiant,
             const std::string& p_nom, const unsigned int p_volume,
             const unsigned int p_numero, const unsigned int p_page);

    const std::string& reqNom () const;
    int reqVolume () const;
    int reqNumero () const;
    int reqPage () const;
    virtual const std::string reqReferenceFormate () const;
    virtual Reference* clone () const;

  private:
    void verifieInvariant () const;

    const std::string& m_nom;
    unsigned int m_volume;
    unsigned int m_numero;
    unsigned int m_page;


  };
}


#endif /* JOURNAL_H */

