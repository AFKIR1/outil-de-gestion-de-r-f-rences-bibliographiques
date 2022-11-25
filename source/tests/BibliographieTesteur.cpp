#include <gtest/gtest.h>
#include "Bibliographie.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "ContratException.h"
#include <sstream>



using namespace std;

using namespace biblio;


TEST (Bibliographie, Constructeurvalide)
{
  Bibliographie uneBibliographie ("liste Reference");
  ASSERT_EQ ("liste Reference", uneBibliographie.reqNomBibliographie ());

}

class BibliographieValide : public ::testing::Test
{

public:


  BibliographieValide () :
  f_bibliographie ("liste Reference"),
  f_ouvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", "New York")
  {
    f_bibliographie.ajouterReference (f_ouvrage);
  };
  Bibliographie f_bibliographie;
  Ouvrage f_ouvrage;

} ;


TEST_F (BibliographieValide, ConstructeurCopieValide)
{

  Bibliographie uneCopie (f_bibliographie);
  ASSERT_EQ ("liste Reference", uneCopie.reqNomBibliographie ());
  //ASSERT_EQ (f_bibliographie.reqBibliographieFormate (), uneCopie.reqBibliographieFormate ());

}


TEST_F (BibliographieValide, reqNomBibliographie)
{
  ASSERT_EQ ("liste Reference", f_bibliographie.reqNomBibliographie ());
}

/*
TEST_F (BibliographieValide, ajouterUnReference)
{
  Journal Journal ("Hart", "A survey of source code management tools for programming courses",
                   2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges",
                   24, 6, 113);
  f_bibliographie.ajouterReference (Journal);
  ostringstream os;
  os << "Bibliographie" << endl << " ===============================" << endl;
  os << "[1] Homayoon Beigi. Fundamentals of Speaker Recognition. New York : Springer, 2011. ISBN 978-0-387-77591-3." << endl;
  os << "Hart. A survey of source code management tools for programming courses. Journal of Computing Sciences in Colleges, vol. 24, no. 6, pp. 113, 2009. ISSN 1937-4771.";
  ASSERT_EQ (os.str (), f_bibliographie.reqBibliographieFormate ());


}


TEST_F (BibliographieValide, ajouterUnReferenceDejaPresente)
{
  Ouvrage Ouvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", "New York");
  f_bibliographie.ajouterReference (Ouvrage);
  ostringstream os;
  os << "Bibliographie" << endl << " ===============================" << endl;
  os << "[1] Homayoon Beigi. Fundamentals of Speaker Recognition. New York : Springer, 2011. ISBN 978-0-387-77591-3." << endl;
  ASSERT_EQ (os.str (), f_bibliographie.reqBibliographieFormate ());


}


TEST_F (BibliographieValide, reqBibliographieFormate)
{
  Journal Journal ("Hart", "A survey of source code management tools for programming courses",
                   2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges",
                   24, 6, 113);
  f_bibliographie.ajouterReference (Journal);
  ostringstream os;
  os << "Bibliographie" << endl << " ===============================" << endl;
  os << "[1] Homayoon Beigi. Fundamentals of Speaker Recognition. New York : Springer, 2011. ISBN 978-0-387-77591-3." << endl;
  os << "[2] Hart. A survey of source code management tools for programming courses. Journal of Computing Sciences in Colleges, vol. 24, no. 6, pp. 113, 2009. ISSN 1937-4771.";
  ASSERT_EQ (os.str (), f_bibliographie.reqBibliographieFormate ());


}*/
/*

TEST_F (BibliographieValide, Assigniation)
{

  Bibliographie TestBibliographie ("Bibliographie de test");
  Journal Journal ("Hart", "A survey of source code management tools for programming courses",
                   2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges",
                   24, 6, 113);
  TestBibliographie.ajouterReference (Journal);
  TestBibliographie = f_bibliographie;
  ASSERT_EQ (f_bibliographie.reqNomBibliographie (), TestBibliographie.reqNomBibliographie ());
  ASSERT_EQ (f_bibliographie.reqBibliographieFormate (), TestBibliographie.reqBibliographieFormate ());

}*/