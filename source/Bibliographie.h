/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Bibliographie.h
 * Author: etudiant
 *
 * Created on 23 novembre 2022, 00:27
 */

#ifndef BIBLIOGRAPHIE_H
#define BIBLIOGRAPHIE_H

#include <string>
#include "ContratException.h"
#include "Reference.h"
#include <vector>

namespace biblio
{

  class Bibliographie
  {
  public:
    Bibliographie (const std::string& p_nomBibliographie);
    Bibliographie (const Bibliographie& p_bibliographie);
    ~Bibliographie ();

    const std::string& reqNomBibliographie () const;
    void ajouterReference (const Reference& p_nouvelleReference);
    const std::string reqBibliographieFormate () const;
    Bibliographie& operator= (const Bibliographie& p_bibliographie);

  private:

    bool referenceEstDejaPresente (const std::string& p_identifiant) const;
    void copierVecteur (const Bibliographie& p_bibliographie);
    void viderVecteur ();

    void verifieInvariant () const;

    std::string m_nomBibliographie;
    std::vector<Reference*> m_vReferences;


  };
}
#endif /* BIBLIOGRAPHIE_H */

