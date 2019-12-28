#include <iostream>
//#include <string>
#include "linked_list.h"
using namespace std;

int main()
{
    float s;
    float n;
    Database d;
    d.add_to_beginning("Matouš", "Reaktor", 54);
    d.add_to_beginning("Marek", "Veverka", 56);
    d.add_to_beginning("Lukáš", "Chladilvostošest", 36);
    d.add_to_beginning("Jan", "Jádro", 5);
    d.add_to_end("Jób", "Jetel", 22);
    d.add_to_beginning("Sára", "Vohřálvodová", 20);

    d.print();
    cout <<"------------------"<<endl;
    cout <<"Počet lidí je ";
    cout <<d.num_of_ages()<<endl;
    d.sum_of_ages();
    if (!d.is_empty())
        cout<<"Průměrný věk je "<< d.average_age()<<endl;
    else
        cout <<"Seznam je prádný!";
    return 0;
}