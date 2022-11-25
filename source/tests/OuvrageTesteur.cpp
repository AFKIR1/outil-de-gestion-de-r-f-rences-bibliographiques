#include <gtest/gtest.h>
#include "Ouvrage.h"
#include "ContratException.h"
#include "validationFormat.h"



using namespace std;

using namespace biblio;


TEST (Ouvrage, anneeNull)
{

  ASSERT_THROW (Ouvrage Ouvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 0, "ISBN 978-0-387-77591-3", "Springer", "New York"); , PreconditionException ) ;
}


TEST (Ouvrage, constructeurEditeurVide)
{

  ASSERT_THROW (Ouvrage Ouvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "", "New York"); , PreconditionException ) ;
}


TEST (Ouvrage, constructeurVilleVide)
{

  ASSERT_THROW (Ouvrage Ouvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", ""); , PreconditionException ) ;
}

class OuvrageValid : public ::testing::Test
{

public:


  OuvrageValid () : t_ouvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", "New York") { };
  Ouvrage t_ouvrage;
} ;


/*
TEST_F (OuvrageValid, reqEditeur)
{

  ASSERT_EQ ("Springer", t_ouvrage.reqEditeur ());

}


TEST_F (OuvrageValid, reqVille)
{

  ASSERT_EQ ("New York", t_ouvrage.reqVille ());

}


TEST_F (OuvrageValid, reqReferenceFormate)
{

  ASSERT_EQ ("Homayoon Beigi. Fundamentals of Speaker Recognition. New York : Springer, 2011. ISBN 978-0-387-77591-3.", t_ouvrage.reqReferenceFormate ());

}*/


TEST_F (OuvrageValid, cloneValid)
{
  Reference* unClone = t_ouvrage.clone ();

  ASSERT_EQ (t_ouvrage.reqAuteurs (), unClone->reqAuteurs ());
  ASSERT_EQ (t_ouvrage.reqTitre (), unClone->reqTitre ());
  ASSERT_EQ (t_ouvrage.reqAnnee (), unClone->reqAnnee ());
  ASSERT_EQ (t_ouvrage.reqIdentifiant (), unClone->reqIdentifiant ());
  //ASSERT_EQ (t_ouvrage.reqReferenceFormate (), unClone->reqReferenceFormate ());

  delete unClone;

}