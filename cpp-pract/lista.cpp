#include <iostream>
#include <list>

list<int> ceros (2, 0);
list<int> fibo;
fibo.assign(3,1);

list<int>::iterator it = fibo.begin();

auto end_it = fibo.end();

it++; // avanza al siguiente paso
next(it, n); // avanza n pasos

// Iterador básico 
for (auto it = fibo.begin(); it != fibo.end(); it++)
{
    cout << "Valor: " << *it << endl; // *it puntero, endl es \n
}




