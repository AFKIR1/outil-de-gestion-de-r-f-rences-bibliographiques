#include <gtest/gtest.h>
#include "Reference.h"
#include"ContratException.h"
#include"validationFormat.h"
#include<string>


using namespace std;
using namespace biblio;
using namespace util;

class ReferenceTest : public Reference
{

public:


  ReferenceTest (const std::string& p_auteurs, const std::string& p_titre, unsigned int p_annee, const std::string& p_identifiant) :
  Reference (p_auteurs,  p_titre,  p_annee,  p_identifiant) { };


  virtual const std::string
  reqReferenceFormate ()const
  {
    return Reference::reqReferenceFormate ();

  };


  virtual Reference*
  clone ()const
  {
    return nullptr;
  };
} ;


TEST (Reference, ConstructeurValid)
{
  ReferenceTest referenceTest ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3");

  ASSERT_EQ ("Homayoon Beigi", referenceTest.reqAuteurs ());
  ASSERT_EQ ("Fundamentals of Speaker Recognition", referenceTest.reqTitre ());
  ASSERT_EQ (2011, referenceTest.reqAnnee ());
  ASSERT_EQ ("ISBN 978-0-387-77591-3", referenceTest.reqIdentifiant ());

  ASSERT_TRUE (validerFormatNom (referenceTest.reqAuteurs ()));
  ASSERT_TRUE (referenceTest.reqAnnee () > 0);
}


TEST (Reference, ConstructeurTitreVide)
{

  ASSERT_THROW (ReferenceTest referenceTest ("Homayoon Beigi", "", 2011, "ISBN 978-0-387-77591-3"), PreconditionException);

}


TEST (Reference, ConstructeurAnneeInvalide)
{

  ASSERT_THROW (ReferenceTest referenceTest ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 0, "ISBN 978-0-387-77591-3"), PreconditionException);

}


TEST (Reference, ConstructeurIdentifiantInvalide)
{

  ASSERT_THROW (ReferenceTest referenceTest ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 0, "ISSN 1937-4771"), PreconditionException);

}

class ReferenceValid : public ::testing::Test
{

public:


  ReferenceValid () : t_reference ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3") { };
  ReferenceTest t_reference;
} ;


TEST_F (ReferenceValid, asgAnneeValide)
{

  t_reference.asgAnnee (2100);
  ASSERT_EQ (2100, t_reference.reqAnnee ());
  ASSERT_TRUE (t_reference.reqAnnee () > 0);

}


TEST_F (ReferenceValid, asgAnneeInValide)
{

  ASSERT_THROW (t_reference.asgAnnee (0), PreconditionException);


}


TEST_F (ReferenceValid, reqReferenceFormate)
{

  ASSERT_EQ ("Homayoon Beigi. Fundamentals of Speaker Recognition. ", t_reference.reqReferenceFormate ());


}


TEST_F (ReferenceValid, egalite)
{


  ReferenceTest Exemple ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3");

  ASSERT_TRUE (Exemple == t_reference);


}


TEST_F (ReferenceValid, differenceAnnee)
{


  ReferenceTest Exemple ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2012, "ISBN 978-0-387-77591-3");

  ASSERT_FALSE (Exemple == t_reference);


}


TEST_F (ReferenceValid, NomNonegale)
{


  ReferenceTest Exemple ("Hart", "Fundamentals of Speaker Recognition", 2012, "ISBN 978-0-387-77591-3");

  ASSERT_FALSE (Exemple == t_reference);


}

