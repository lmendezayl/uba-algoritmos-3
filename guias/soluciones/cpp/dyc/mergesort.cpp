#include <iostream>
#include <vector>

using namespace std;

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
    // mergeados.extend(...)
    mergeados.insert(mergeados.end(), izq.begin() + i, izq.end());
    mergeados.insert(mergeados.end(), der.begin() + j, der.end());

    return mergeados;
}

vector<int> mergesort(const vector<int>& arr){
    if (arr.size() <= 1)
        return arr;
    int medio = arr.size() / 2; // divisor y dividendo enteros => division entera
    
    vector<int> izq(arr.begin(), arr.begin() + medio);
    vector<int> der(arr.begin() + medio, arr.end());

    vector<int> mitad_izq = mergesort(izq);
    vector<int> mitad_der = mergesort(der);

    return merge(mitad_izq, mitad_der);
}

// driver
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> ordenado = mergesort(arr);

    for (int x : ordenado) cout << x << " ";
    cout << "\n";
    return 0;
}
