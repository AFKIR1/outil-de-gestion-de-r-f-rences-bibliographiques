/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Ouvrage.h
 * Author: etudiant
 *
 * Created on 22 novembre 2022, 21:12
 */

#ifndef OUVRAGE_H
#define OUVRAGE_H

#include <string>
#include "ContratException.h"
#include "Reference.h"


namespace biblio
{

  class Ouvrage : public biblio::Reference
  {
  public:
    Ouvrage (const std::string& p_auteurs, const std::string& p_titre,
             const unsigned int p_annee, const std::string& p_identifiant,
             const std::string& p_editeur, const std::string& p_ville);

    const std::string& reqEditeur () const;
    const std::string& reqVille () const;
    virtual const std::string reqReferenceFormate () const;
    virtual Reference* clone () const;

  private:
    void verifieInvariant () const;

    const std::string& m_editeur;
    const std::string& m_ville;

  };
}

#endif /* OUVRAGE_H */

