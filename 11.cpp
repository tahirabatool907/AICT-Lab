#include <iostream>
using namespace std;
int main()
{
string n1, n2;
float m1, i1, e1, e2;

cout << "Name1: ";
cin >> n1;
cout << "Matric Inter Ecat: ";
cin >> m1 >> i1 >> e1;

cout << n1 << "Aggregate = " << (m1/1100*30 + i1/550*30 + e1/400*40) << "%\n";

cout << "Name2: ";
cin >> n2;
cout << "Ecat: ";
cin >> e2;
if(e1 > e2)
cout << n1 << " higher\n";
else if(e2 > e1)
cout << n2 << "higher\n";
else 
cout << "Equal\n";
}	`
