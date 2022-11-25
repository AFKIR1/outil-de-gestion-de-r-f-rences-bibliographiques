#include <gtest/gtest.h>
#include "Journal.h"
#include "ContratException.h"
#include "validationFormat.h"



using namespace std;

using namespace biblio;


TEST (Journal, numeroInvalide)
{

  ASSERT_THROW (Journal Journal ("Hart", "A survey of source code management tools for programming courses",
                                 2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges",
                                 24, 0, 113), PreconditionException ) ;
}


TEST (Journal, volumeInvalide)
{

  ASSERT_THROW (Journal Journal ("Hart", "A survey of source code management tools for programming courses",
                                 2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges",
                                 0, 6, 113), PreconditionException ) ;
}

class JournalValid : public ::testing::Test
{

public:


  JournalValid () : t_journal ("Hart",
                               "A survey of source code management tools for programming courses",
                               2009, "ISSN 1937-4771",
                               "Journal of Computing Sciences in Colleges",
                               24, 6, 113) { };
  Journal t_journal;
} ;


/*
TEST_F (JournalValid, reqNom)
{

  ASSERT_EQ ("Journal of Computing Sciences in Colleges", t_journal.reqNom ());

}*/


TEST_F (JournalValid, reqNumero)
{

  ASSERT_EQ (6, t_journal.reqNumero ());

}


TEST_F (JournalValid, reqVolume)
{

  ASSERT_EQ (24, t_journal.reqVolume ());

}


TEST_F (JournalValid, reqPage)
{

  ASSERT_EQ (113, t_journal.reqPage ());

}


/*
TEST_F (JournalValid, reqReferenceFormate)
{

  ASSERT_EQ ("Hart. A survey of source code management tools for programming courses. Journal of Computing Sciences in Colleges, vol. 24, no. 6, pp. 113, 2009. ISSN 1937-4771.", t_journal.reqReferenceFormate ());

}*/


TEST_F (JournalValid, cloneValid)
{
  Reference* unClone = t_journal.clone ();

  ASSERT_EQ (t_journal.reqAuteurs (), unClone->reqAuteurs ());
  ASSERT_EQ (t_journal.reqTitre (), unClone->reqTitre ());
  ASSERT_EQ (t_journal.reqAnnee (), unClone->reqAnnee ());
  ASSERT_EQ (t_journal.reqIdentifiant (), unClone->reqIdentifiant ());
  ASSERT_EQ (t_journal.reqReferenceFormate (), unClone->reqReferenceFormate ());

  delete unClone;

}
