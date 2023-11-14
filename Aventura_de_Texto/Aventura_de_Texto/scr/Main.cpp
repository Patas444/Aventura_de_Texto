#include "Commons.h"
#include "Aventura.h"

//Titulo del Juego y menu de inicio.
int
main() {
cout << "----------------------------------------" << endl;
cout << "The Binding of Issac" << endl;
cout << "Version Aventura de Texto" << endl;
cout << "----------------------------------------" << endl;
//Recibe la informacion de Aventura.h para iniciar con el juego.
Aventura aventura;
aventura.Personaje();
return 0;
}