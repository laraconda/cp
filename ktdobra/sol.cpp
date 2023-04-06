/*
 * La idea aquí es hacer fuerza bruta. En cada espacio en blanco,
 * tenemos que ver si es posible poner una consonante o una vocal,
 * puede que sea posible poner ambas, entonces con una funcion recursiva
 * exploramos de cuántas maneras podemos llenar el resto de la cadena.
 * Es decir, supongamos que estamos en el caracter i, si ponemos una
 * consonante ahí, de cuantas maneras podemos llenar la cadena
 * s[i-1, 0]? cuando sabemos esto, multiplicamos por 21 (que es el número)
 * de consonantes, porque podemos poner cualquiera de esas letras en ese
 * espacio. Luego intentamos poner una vocal ahí, si se puede, entonces
 * al numero de maneras posibes de s[i-1, 0] la multiplicamos por 5.
 * El resultado de ambos casos (pueden ser 0) se suma y es lo que 
 * la función regresa.
 * Esta implementación sería de O(2**k) donde k es el numero de espacios
 * en blanco, k es a lo mas 10, 2**10 es nada entonces todo bien.
 * El unico problema con ese método es que puede que nuestra cadena final
 * no tenga L's. Se soluciona contando el numero inicial de Ls y haciendo
 * que nuestra función recursiva tenga tres ramas en vez de dos.
 * Con dos ramas teniamos las opciones de vocal o consonante, con tres
 * tenemos L, consonante que no sea L o vocal. Si no hay L's al final de
 * la cadena, no cuenta. Para saber si hay L's o no, solo hace falta llevar
 * un contador de L's. Importante mirar la funcion 'rec' para entender esto.
 * Entonces la complejidad es O(3**k) que sigue siendo nada con k=10.
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll V = 5;  // numero de vocales
const ll C = 20;   // numero de consonantes sin la L

vector<char> vs = {'A', 'E', 'I', 'O', 'U'};
int ls = 0;

bool isc(char c) {  // es consonante?
    for (char v: vs) {
        if (c == v) return false;
    }
    return (c != '_');
}

bool isv(char c) {  // es vocal?
    for (char v : vs)
        if (c == v) return true;
    return false;
}

bool posc(int i, int N, string& s) {  // se puede poner consonante en i?
    if (i + 2 < N) {
        if (isc(s[i+1]) && isc(s[i+2])) return false;
    }
    if (i - 2 >= 0) {
        if (isc(s[i-1]) && isc(s[i-2])) return false; 
    }
    if (i<N-1 && i > 0) {
        if (isc(s[i-1]) && isc(s[i+1])) return false;
    }
    return true;
}

bool posv(int i, int N, string& s) {  // se puede poner vocal en i?
    if (i + 2 < N) {
        if (isv(s[i+1]) && isv(s[i+2])) return false;
    }
    if (i - 2 >= 0) {
        if (isv(s[i-1]) && isv(s[i-2])) return false;
    }
    if (i<N-1 && i > 0) {
        if (isv(s[i-1]) && isv(s[i+1])) return false;
    }
    return true;
}

ll rec(int i, int N, string& s) {
    if (i == -1) {
        if (ls > 0) return 1;
        else return 0;
    }
    if (s[i] != '_') return rec(i-1, N, s);
    ll r = 0;
    if (posc(i,N,s)) {
        s[i] = 'S';  // ponemos una consonante cualquiera
        // para que el metodo posc siga funcionando
        r += rec(i-1, N, s) * C;
        s[i] = 'L';
        ls++;  // contador de L's
        r += rec(i-1, N, s);
        ls--;
        s[i] = '_';
    }
    if (posv(i,N,s)) {
        s[i] = 'A';  // vocal cualquiera
        r += rec(i-1, N, s) * V;
        s[i] = '_';
    }
    return r;
}

int main() {
    string s;
    cin >> s;

    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'L') ls++;
    }
    ll r = rec((int)s.size() - 1, s.size(), s);
    cout << r << endl;
}
