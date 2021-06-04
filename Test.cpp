#include <iostream>
#include "Test.h"

using namespace std;

Test::Test()
{

}

void Test::initialisation()
{
    for (int i(0); i < 10; i++)
    {
        m_var[i] = 0;
    }
}

void Test::compteTest(int position)
{
    m_var[position] ++;
}

int Test::resultat(int position) const
{
    return m_var[position];
}
