#include <iostream>
#include <vector>


vector<int> merge(vector<int>& izq, vector<int>& der){
    vector<int> mergeados;
    int i = 0;
    int j = 0;

    while (i < izq.size() && j < der.size()) {
        if (izq[i] < der[j]){
            mergeados.push_back(izq[i]);
            i += 1;
        }
        else{
            mergeados.push_back(der[j]);
            j += 1;
        }
    }
    if (i >= izq.size(
    mergeados.push_back(
}

vector<int> mergesort(const vector<int>& arr){
    if (arr.size() <= 1)
        return arr;
    int medio = arr.size() / 2; // divisor y dividendo enteros => division entera
    
    vector<int> izq(arr.begin(), arr.begin() + medio);
    vector<int> der(arr.begin() + medio, arr.end());

    mitad_izq = mergesort(izq);
    mitad_der = mergesort(der);

    return merge(mitad_izq, mitad_der);
}

// driver
int main(){
    return 0;
}
