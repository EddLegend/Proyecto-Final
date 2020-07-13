#include <iostream>
#include <string.h>
#include <string>

const int longCad = 20;

using namespace std;

struct costoPorArticulo
{
    char nombreArticulo[longCad + 1];
    int cantidad;
    float precio;
    float costoPorArticulo;
};
//declaracion de funciones
void Leer_Inf (int n, costoPorArticulo producto[]);
void Cost_Art (int n, costoPorArticulo producto[]);
float Factura (int n, costoPorArticulo producto[]);

//funcion para pedir informacion 
void Leer_Inf(int n, costoPorArticulo producto[])
{
    string nam;
    
    cout << "\nINTRODUZCA LOS SIGUIENTES DATOS:" <<endl <<endl;
    
    for(int i = 0; i < n; i++)
    {
        cout << "**************************" <<endl;
        cout <<"NOMBRE ART: ";
        getline(cin, nam, '\n');
        strncpy(producto[i].nombreArticulo, nam.c_str(), longCad);
        producto[i].nombreArticulo[longCad] = '\0';

        cout << "CANTID ART: ";
        cin  >> producto[i].cantidad;

        cout << "PRECIO C/U: ";
        cin  >> producto[i].precio;
        cout << endl;
        cin.ignore (100, '\n');
    }
}

//funcion costo del articulo
void Cost_Art(int n, costoPorArticulo producto[])
{
    for(int i = 0; i < n; i++)
    {
        producto[i].costoPorArticulo = producto[i].cantidad * producto[i].precio;
    }
}

//funcion costo total de la compra
float Factura(int n, costoPorArticulo producto[])
{
    float total = 0;

    for(int i = 0; i < n; i++)
    {
        total = total + producto[i].costoPorArticulo;
    }

    return total;
}

//funcion a la que se mandan todas las demas funciones creadas
int main()
{
    int n;
    float total;
    
    cout <<"\n***UCA SUPERMARKET***\n" <<endl;
    cout << "NUMERO DE ART DIFERENTES: ";
    cin >> n;
    costoPorArticulo producto[n];
    cin.ignore (100, '\n');
    
    Leer_Inf (n, producto);
    Cost_Art (n, producto);

    cout << "**************************" <<endl;
    cout << "EL TOTAL DE SU COMPRA ES: ";
    cout <<endl <<endl;

    //Informacion de precio y cantidad
    for(int i = 0; i < n; i++)
    {
        cout << producto[i].nombreArticulo << " " << producto[i].cantidad << " UNI " << "X $";
        cout << producto[i].precio << " C/U = TOTAL $ " << producto[i].costoPorArticulo << "\n";
    }

    total = Factura(n, producto);
    cout << "\n" <<endl;
    cout << "TOTAL A PAGAR: $" << total <<endl;
    cout << "**************************" <<endl;

    return 0;
}