#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <iostream>

class Test
{
    public :

    Test();
    void initialisation();
    void compteTest(int position);
    int resultat(int position) const;

    private :

    int m_var[10];
};

#endif // TEST_H_INCLUDED
