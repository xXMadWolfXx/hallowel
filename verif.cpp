#include <iostream>
#include <string>
#include <limits>

using namespace std;

int verif (int reponses, string option1, string option2)
{
    double tentative;
    bool var;

    do
    {
    if (option1 != "" && option2 != "")
    {
        cout << endl << option1 << endl << option2 << endl;
        var = true;
    }
    else if (option1 != "" && option2 == "")
    {
        cout << endl << option1 << endl;
        var = true;
    }
    else if (option1 == "" && option2 == "")
    {
        cout << endl;
        var = false;
    }

    cin >> tentative;
    if (tentative > reponses)
    {
        cout << endl << "Il n'y a pas autant de reponses." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        tentative = 0;
    }
    else if (tentative < 0)
    {
        cout << endl << "Non, les reponses negatives n'existent pas" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        tentative = 0;
    }
    else if (tentative > 0 && tentative <= reponses)
    {
        for (int i(0); i <= reponses; i++)
        {
                if (tentative == i)
                {
                    i = 1000;
                }
                else if (i == reponses)
                {
                    cout << endl <<"Veillez a ne bien taper que sur le chiffre qui correspond a la reponse." << endl;
                    tentative = 0;
                }
        }
    }
    else
    {
        cout << endl <<"Veillez a ne bien taper que sur le chiffre qui correspond a la reponse." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        tentative = 0;
    }
    }while (tentative == 0 && var == true);

    return tentative;
}
