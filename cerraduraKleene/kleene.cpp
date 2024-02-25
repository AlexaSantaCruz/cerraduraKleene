#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<string> cerraduraKleene(const vector<string>& lenguaje, int cardinalidad);

int main() {
    int cardinalidad;
    int numPalabras;
    vector<string> palabras;

    cout << "¿Cuántas palabras tiene el lenguaje?";
    cin >> numPalabras;

    cout << "Ingresa las " << numPalabras << " palabras de lenguaje:" << endl;
    for (int i = 0; i < numPalabras; ++i) {
        string palabra;
        cin >> palabra;
        palabras.push_back(palabra);
    }

    cout << "¿Qué nivel de cerradura de Kleene deseas conocer?";
    cin >> cardinalidad;

    vector<string> cerradura = cerraduraKleene(palabras, cardinalidad);

    cout << "El conjunto de palabras que corresponde al nivel " << cardinalidad << " de cerradura son:" << endl;
    for (const auto& palabra : cerradura) {
        cout << palabra << " ";
    }

    cout << "\nCantidad de palabras: " << cerradura.size() << endl;

}

vector<string> cerraduraKleene(const vector<string>& lenguaje, int cardinalidad) {
    vector<string> resultado;

    if (cardinalidad == 0) {
        /*Nivel 0, solo incluir la palabra vacía*/
        resultado.push_back("");
    }
    else {
        /*Niveles mayores a 0*/
        resultado = lenguaje;                               /*copiamos las palabras*/
        for (int i = 1; i < cardinalidad; ++i) {            /*iteramos sobre la cardinalidad*/
            vector<string> temp;                            /*crear vector temporal para poder guardar las nuevas palabras*/
            for (const auto& word : resultado) {            /*esto es para iterar sobre el nivel actual de kleene*/
                for (const auto& originalWord : lenguaje) { /*se itera para tomar la anterior con la original*/
                    temp.push_back(word + originalWord);    /*lo unimo*/
                }
            }
            resultado = temp;
        }
    }

    return resultado;
}
