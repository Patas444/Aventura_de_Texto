#include "Commons.h"
#include "Jugador.h"

class
Aventura {
public:
//Menu principal donde se selecciona a un personaje
void
Personaje() {
cout << "----------------------------------------" << endl;
cout << "Quien soy?:" << endl;
cout << "1- Issac." << endl;
cout << "2- Magdalane." << endl;
cout << "3- Azazel." << endl;
cout << "4- Salir del Juego" << endl;
cout << "----------------------------------------" << endl;
int op;
cin >> op;
switch (op) {

case 1:
Issac();
break;

case 2:
Magdalane();
break;

case 3:
Azazel();
break;

case 4:
exit(0);
break;

default:
cout << "No se quien es . . . " << endl;
break;
}
}

//Seleccion de personaje: Issac
void
Issac() {
//Aqui se especifican las estadisticas del jugador
Jugador	jugador;
jugador.vida = 3;
jugador.item = 0;
jugador.item2 = 0;
jugador.bomba = 1;
jugador.boss = 20;
cout << "----------------------------------------" << endl;
cout << "Issac:" << endl;
cout << "Vida:" << jugador.vida << endl;
cout << "Bombas:" << jugador.bomba << endl;
cout << "Objeto: Ninguno." << endl;
cout << "----------------------------------------" << endl;
cout << "Soy Issac?" << endl;
cout << "1- Aceptar" << endl;
cout << "2- Volver" << endl;
cout << "----------------------------------------" << endl;
int op;
cin >> op;
switch (op) {
case 1:
Sala_1(jugador);
break;
case 2:
Personaje();
break;
}
}

//Seleccion de personaje: Magdalane
void
Magdalane() {
//Aqui se especifican las estadisticas del jugador
Jugador	jugador;
jugador.vida = 5;
jugador.item = 1;
jugador.item2 = 0;
jugador.bomba = 0;
jugador.boss = 20;
cout << "----------------------------------------" << endl;
cout << "Magdalane:" << endl;
cout << "Vida:" << jugador.vida << endl;
cout << "Bombas:" << jugador.bomba << endl;
cout << "Objeto: Corazon: Al entrar a un cuarto obtendras +1 de vida." << endl;
cout << "----------------------------------------" << endl;
cout << "Soy Magdalane?" << endl;
cout << "1- Aceptar" << endl;
cout << "2- Volver" << endl;
cout << "----------------------------------------" << endl;
int op;
cin >> op;
switch (op) {

case 1:
Sala_1(jugador);
break;

case 2:
Personaje();
break;
}
}

//Seleccion de personaje: Azazel
void
Azazel() {
//Aqui se especifican las estadisticas del jugador
Jugador	jugador;
jugador.vida = 1;
jugador.item = 2;
jugador.item2 = 0;
jugador.bomba = 1;
jugador.boss = 20;
cout << "----------------------------------------" << endl;
cout << "Azazel:" << endl;
cout << "Vida:" << jugador.vida << endl;
cout << "Bombas:" << jugador.bomba << endl;
cout << "Objeto: Alas de Demonio: Pasa por obstaculos o enemigos con facilidad." << endl;
cout << "----------------------------------------" << endl;
cout << "Soy Azazel?" << endl;
cout << "1- Aceptar" << endl;
cout << "2- Volver" << endl;
cout << "----------------------------------------" << endl;
int op;
cin >> op;
switch (op) {

case 1:
Sala_1(jugador);
break;

case 2:
Personaje();
break;
}
}

//Habitacion 1
void
Sala_1(Jugador& jugador) {
//Stats Actuales del Jugador
cout << "----------------------------------------" << endl;
cout << "Vida:" << jugador.vida << endl;
cout << "Bombas:" << jugador.bomba << endl;
cout << "----------------------------------------" << endl;
cout << "Estas en cuarto vacio con 4 puertas a tu alrededor" << endl;
cout << "Que debo hacer?" << endl;
cout << "1- Ir por la puerta dorada de arriba." << endl;
cout << "2- Ir por la puerta de la izquierda." << endl;
cout << "3- Ir por la puerta de abajo." << endl;
cout << "4- Ir por la puerta de la derecha." << endl;
cout << "----------------------------------------" << endl;
int op;
cin >> op;
switch (op) {

case 1:
Sala_Tesoro(jugador);
break;

case 2:
Sala_4(jugador);
break;

case 3:
Sala_3(jugador);
break;

case 4:
Sala_2(jugador);
break;

//Gamer Over: Por oprimir otro boton
default:
cout << "----------------------------------------" << endl;
cout << "Explotaste sin ninguna razon . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
break;
}
}

//Habitacion Especial:Aqui hay un item con un efecto en varias salas.
void
Sala_Tesoro(Jugador jugador) {
if
(jugador.item == 1) {
jugador.vida += 1;
}
//Stats Actuales del Jugador
cout << "----------------------------------------" << endl;
cout << "Vida:" << jugador.vida << endl;
cout << "Bombas:" << jugador.bomba << endl;
cout << "----------------------------------------" << endl;
cout << "Este cuarto esta rodeado por algunas fogatas." << endl;
cout << "Y en frente de ti hay un pedestal." << endl;
cout << "Sin embargo este esta rodeado por unas rocas" << endl;

cout << "Que debo hacer?" << endl;
cout << "1- Tomar Brimstone (4 Bombas)" << endl;
cout << "2- Volver a la sala anterior" << endl;
int op;
cin >> op;
switch (op) {
case 1:
//Evento de Bomba: Si el jugador tiene las bombas necesarias podra acceder a las recompensas.
if
(jugador.bomba == 4) {
cout << "----------------------------------------" << endl;
cout << "Con las 4 bombas lograste romper las rocas." << endl;
cout << "Tomaste El Brimstone: Destruye enemigos con un potente laser." << endl;
cout << "Despues de ello has decidido volver a la sala anterior." << endl;
jugador.bomba -= 1;
jugador.item2 = 1;
Sala_1(jugador);
}
else if
(jugador.bomba < 4) {
cout << "Al no tener suficientes bombas decidiste volver por donde viniste." << endl;
cout << "----------------------------------------" << endl;
Sala_1(jugador);
}
break;

case 2:
Sala_1(jugador);
break;

//Gamer Over: Por oprimir otro boton
default:
cout << "----------------------------------------" << endl;
cout << "Explotaste sin ninguna razon . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
break;
}
}

//Habitacion 2
void
Sala_2(Jugador jugador) {
//Evento por objeto 1: Cura al jugador cada sala.
if
(jugador.item == 1) {
jugador.vida += 1;
}
//Stats Actuales del Jugador
cout << "----------------------------------------" << endl;
cout << "Vida:" << jugador.vida << endl;
cout << "Bombas:" << jugador.bomba << endl;
cout << "----------------------------------------" << endl;
cout << "En el cuarto hay unas formaciones de piedras y unas 4 moscas merodeando el cuarto." << endl;
cout << "Que debo hacer?" << endl;
cout << "1- Pelear." << endl;
cout << "2- Investigar." << endl;
cout << "3- Volver a la sala anterior." << endl;
int op;
cin >> op;
switch (op) {
case 1:
cout << "----------------------------------------" << endl;
cout << "Sin piedad acabaste con las moscas." << endl;
cout << "Ahora que debo hacer?" << endl;
cout << "1- Investigar." << endl;
cout << "2- Volver a la sala anterior." << endl;
	cin >> op;
	switch (op) {

	case 1:
	cout << "----------------------------------------" << endl;
	cout << "Investigando un poco te percatas de una grieta." << endl;
	//Evento de Bomba: Si el jugador tiene 1 bomba  podra acceder a las recompensas.
	if
	(jugador.bomba >= 1) {
	cout << "Al tener una bomba lograste romper la pared y entrar a la sala secreta." << endl;
	cout << "En la Sala encontraste 2 corazones de alma." << endl;
	cout << "Decidiste volver a la sala anterior." << endl;
	cout << "----------------------------------------" << endl;
	jugador.bomba -= 1;
	jugador.vida += 2;
	Sala_1(jugador);
	}
	else if
	(jugador.bomba == 0) {
	cout << "Al no tener una bomba decidiste volver por donde viniste." << endl;
	Sala_1(jugador);
	}
	break;

	case 2:
	Sala_1(jugador);
	break;
	}
break;

case 2:
cout << "----------------------------------------" << endl;
cout << "Gracias a las piedras pudiste cubrirte y evadir las moscas" << endl;
cout << "Investigando un poco te percatas de una grieta." << endl;
//Evento de Bomba: Si el jugador tiene 1 bomba  podra acceder a las recompensas.
if
(jugador.bomba >= 1) {
cout << "Al tener una bomba lograste romper la pared y entrar a un cuarto secreta." << endl;
cout << "En la Sala encontraste 2 corazones de alma." << endl;
cout << "Decidiste volver a la sala anterior." << endl;
cout << "----------------------------------------" << endl;
jugador.bomba -= 1;
jugador.vida += 2;
Sala_1(jugador);
}
else if
(jugador.bomba == 0) {
cout << "Al no tener una bomba decidiste volver por donde viniste." << endl;
cout << "----------------------------------------" << endl;
Sala_1(jugador);
}
break;

case 3:
Sala_1(jugador);
break;

//Gamer Over: Por oprimir otro boton
default:
cout << "----------------------------------------" << endl;
cout << "Explotaste sin ninguna razon . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
break;
}
}

//Habitacion 3
void
Sala_3(Jugador jugador) {
//Evento por objeto 1: Cura al jugador cada sala.
if
(jugador.item == 1) {
jugador.vida += 1;
}
//Stats Actuales del Jugador
cout << "----------------------------------------" << endl;
cout << "Vida:" << jugador.vida << endl;
cout << "Bombas:" << jugador.bomba << endl;
cout << "----------------------------------------" << endl;
cout << "En el cuarto solo hay algunas cacas tiradas por el suelo . . ." << endl;
cout << "Que debo hacer?" << endl;
cout << "1- Investigar." << endl;
cout << "2- Volver a la sala anterior." << endl;
cout << "----------------------------------------" << endl;
int op;
cin >> op;
switch (op) {
case 1:
cout << "----------------------------------------" << endl;
cout << "Investigando un poco pisaste algunas de las cacas . . ." << endl;
cout << "Que asco . . . " << endl;
cout << "Con suerte y por extraño que paresca." << endl;
cout << "Encontraste una bomba." << endl;
cout << "Al final decidiste volver por donde viniste." << endl;
cout << "----------------------------------------" << endl;
jugador.bomba += 1;
Sala_1(jugador);
break;

case 2:
Sala_1(jugador);
break;

//Gamer Over: Por oprimir otro boton
default:
cout << "----------------------------------------" << endl;
cout << "Explotaste sin ninguna razon . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
break;
}
}

//Habitacion 4
void
Sala_4(Jugador jugador) {
//Evento por objeto 1: Cura al jugador cada sala.
if
(jugador.item == 1) {
jugador.vida += 1;
}
//Stats Actuales del Jugador
cout << "----------------------------------------" << endl;
cout << "Vida:" << jugador.vida << endl;
cout << "Bombas:" << jugador.bomba << endl;
cout << "----------------------------------------" << endl;
cout << "En el cuarto hay algunos Gapers merodado." << endl;
cout << "Y al fondo se alcanza a ver otra puerta." << endl;
cout << "Que debo hacer?" << endl;
cout << "1- Pelear." << endl;
cout << "2- Investigar." << endl;
cout << "3- Huir." << endl;
cout << "4- Volver a la sala anterior." << endl;
cout << "----------------------------------------" << endl;
int op;
cin >> op;
switch (op) {
case 1:
cout << "----------------------------------------" << endl;
cout << "Con un poco de suerte acabaste con todos los Gapers" << endl;
cout << "Ahora que debo hacer?" << endl;
cout << "1- Ir por la puerta de la izquierda." << endl;
cout << "2- Volver a la sala anterior." << endl;
	cin >> op;
	switch (op) {

	case 1:
	Sala_5(jugador);
	break;

	case 2:
	cout << "----------------------------------------" << endl;
	cout << "Decidiste volver por donde viniste." << endl;
	cout << "----------------------------------------" << endl;
	Sala_1(jugador);
	break;

	//Gamer Over: Por oprimir otro boton
	default:
	cout << "----------------------------------------" << endl;
	cout << "Explotaste sin ninguna razon . . ." << endl;
	cout << "GAME OVER" << endl;
	cout << "----------------------------------------" << endl;
	break;
	}
break;

case 2:
if (jugador.item == 2) {
cout << "----------------------------------------" << endl;
cout << "Investigaste la zona volando pero no habia nada." << endl;
cout << "Decidiste ir al siguiente cuarto." << endl;
}
else{
cout << "----------------------------------------" << endl;
cout << "Intentaste investigar pero los Gapers te alcanzaron a morder." << endl;

jugador.vida -= 1;
if (jugador.vida <= 0) {
cout << "----------------------------------------" << endl;
cout << "Ya no tienes vida . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
}
else if (jugador.vida > 0) {
cout << "Tuviste que retroceder al cuarto anterior." << endl;
cout << "----------------------------------------" << endl;
Sala_1(jugador);
}
}
break;

case 3:
if(jugador.item == 2){
cout << "----------------------------------------" << endl;
cout << "Pasaste por arriba de los enemigos sin problema." << endl;
Sala_5(jugador);
}
else {
cout << "----------------------------------------" << endl;
cout << "Corriste hacia la puerta pero los Gapers te acorralaron." << endl;
//Verificador de Vida: Cuando esta llega a 0 Sera Game Over
//Si aun tiene vida este podra continuar
jugador.vida -= 2;
if (jugador.vida <= 0) {
cout << "----------------------------------------" << endl;
cout << "Ya no tienes vida . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
}
else if (jugador.vida > 0) {
cout << "Con dificultad llegaste a la puerta." << endl;
Sala_5(jugador);
}
}
break;

case 4:
Sala_1(jugador);
break;

//Gamer Over: Por oprimir otro boton
default:
cout << "----------------------------------------" << endl;
cout << "Explotaste sin ninguna razon . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
break;
}
}

//Habitacion 5
void
Sala_5(Jugador jugador) {
//Evento por objeto 1: Cura al jugador cada sala.
if
(jugador.item == 1) {
jugador.vida += 1;
}
//Stats Actuales del Jugador
cout << "----------------------------------------" << endl;
cout << "Vida:" << jugador.vida << endl;
cout << "Bombas:" << jugador.bomba << endl;
cout << "----------------------------------------" << endl;
cout << "En el cuarto hay un cofre en el centro pero esta rodeado por algunas piedras." << endl;
cout << "Ademas se puede ver 3 puertas mas en la habitacion." << endl;
cout << "Que debo hacer?" << endl;
cout << "1- Investigar" << endl;
cout << "2- Ir por la puerta de la izquierda" << endl;
cout << "3- Ir por la puerta de arriba." << endl;
cout << "4- Ir por la puerta de abajo." << endl;
cout << "5- Volver a la sala anterior" << endl;
cout << "----------------------------------------" << endl;
int op;
cin >> op;
switch (op) {

case 1:
//Evento de Bomba: Si el jugador tiene 1 bomba  podra acceder a las recompensas.
if
(jugador.bomba >= 1) {
cout << "Al tener una bomba lograste romper las rocas." << endl;
cout << "Dentro del cofre habia 3 corazones de alma" << endl;
cout << "----------------------------------------" << endl;
jugador.vida += 3;
jugador.bomba -= 1;
cout << "Ahora que debo hacer?" << endl;
cout << "1- Ir por la puerta de la izquierda." << endl;
cout << "2- Ir por la puerta de arriba." << endl;
cout << "3- Ir por la puerta de abajo." << endl;
cout << "4- Volver a la sala anterior" << endl;
	cin >> op;
	switch (op) {

	case 1:
	Sala_7(jugador);
	break;

	case 2:
	Sala_8(jugador);
	break;

	case 3:
	Sala_6(jugador);
	break;

	case 4:
	Sala_4(jugador);
	break;
	}
	}
else if
	(jugador.bomba == 0) {
	cout << "Pateaste la roca . . ." << endl;
	cout << "Eso dolio." << endl;
	jugador.vida -= 1;
	//Verificador de Vida: Cuando esta llega a 0 Sera Game Over
	//Si aun tiene vida este podra continuar
	if (jugador.vida <= 0) {
	cout << "----------------------------------------" << endl;
	cout << "Ya no tienes vida . . ." << endl;
	cout << "GAME OVER" << endl;
	cout << "----------------------------------------" << endl;
	}
	else if (jugador.vida > 0) {

	cout << "Ahora que debo hacer?" << endl;
	cout << "1- Ir por la puerta de la izquierda." << endl;
	cout << "2- Ir por la puerta de arriba." << endl;
	cout << "3- Ir por la puerta de abajo." << endl;
	cout << "4- Volver a la sala anterior." << endl;
	cin >> op;
	switch (op) {

	case 1:
	Sala_7(jugador);
	break;

	case 2:
	Sala_8(jugador);
	break;

	case 3:
	Sala_6(jugador);
	break;

	case 4:
	Sala_4(jugador);
	break;
	}
	}
	}
break;
		
case 2:
Sala_7(jugador);
break;

case 3:
Sala_8(jugador);
break;

case 4:
Sala_6(jugador);
break;

case 5:
Sala_4(jugador);
break;

//Gamer Over: Por oprimir otro boton
default:
cout << "----------------------------------------" << endl;
cout << "Explotaste sin ninguna razon . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
break;
}
}

//Habitacion 6
void
Sala_6(Jugador jugador) {
//Evento por objeto 1: Cura al jugador cada sala.
if
(jugador.item == 1) {
jugador.vida += 1;
}
//Stats Actuales del Jugador
cout << "----------------------------------------" << endl;
cout << "Vida:" << jugador.vida << endl;
cout << "Bombas:" << jugador.bomba << endl;
cout << "----------------------------------------" << endl;
cout << "En el cuarto hay varias arañas y en el suelo hay varios picos." << endl;
cout << "Que debo hacer?" << endl;
cout << "1- Pelear." << endl;
cout << "2- Investigar." << endl;
cout << "3- Volver a la sala anterior." << endl;
int op;
cin >> op;
switch (op) {

case 1:
if (jugador.item2 == 1) {
cout << "----------------------------------------" << endl;
cout << "El laser destruyo todo a su paso." << endl;
cout << "Al vencer encontraste una bomba" << endl;
cout << "Al final decides volver a la sala anterior." << endl;
jugador.bomba += 1;
Sala_5(jugador);
}
else if (jugador.item == 2) {
cout << "----------------------------------------" << endl;
cout << "Eliminaste sin problema a todos los enemigos." << endl;
cout << "Al vencer encontraste una bomba" << endl;
cout << "Al final decides volver a la sala anterior." << endl;
jugador.bomba += 1;
Sala_5(jugador);
}
else {
cout << "----------------------------------------" << endl;
cout << "La pelea fue complicada pero las arañas fueron eliminadas." << endl;
cout << "En el combate te picaste con los picos." << endl;
jugador.vida -= 1;
if 
//Verificador de Vida: Cuando esta llega a 0 Sera Game Over
//Si aun tiene vida este podra continuar
(jugador.vida <= 0) {
cout << "----------------------------------------" << endl;
cout << "Ya no tienes vida . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
}
else if (jugador.vida > 0) {
cout << "Pero al vencer encontraste una bomba" << endl;
cout << "Al final decides volver a la sala anterior." << endl;
jugador.bomba += 1;
Sala_5(jugador);
}
}

break;
			
case 2:
if (jugador.item == 2) {
cout << "----------------------------------------" << endl;
cout << "Investigaste la zona volando pero no habia nada." << endl;
cout << "Al final decides volver a la sala anterior." << endl;
Sala_5(jugador);
}
else{
cout << "----------------------------------------" << endl;
cout << "Intentaste investigar pero las arañas te atacaron sin piedad." << endl;
cout << "Ademas te te picaste con los picos al intentar huir." << endl;
cout << "Esto te hizo regresar a la sala anterior." << endl;
jugador.vida -= 2;
if 
//Verificador de Vida: Cuando esta llega a 0 Sera Game Over
//Si aun tiene vida este podra continuar
(jugador.vida <= 0) {
cout << "----------------------------------------" << endl;
cout << "Ya no tienes vida . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
}
else if (jugador.vida > 0) {
Sala_5(jugador);
}
}
break;

case 3:
Sala_5(jugador);
break;

//Gamer Over: Por oprimir otro boton
default:
cout << "----------------------------------------" << endl;
cout << "Explotaste sin ninguna razon . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
break;
}
}

//Habitacion 7
void
Sala_7(Jugador jugador) {
//Evento por objeto 1: Cura al jugador cada sala.
if
(jugador.item == 1) {
jugador.vida += 1;
}
//Stats Actuales del Jugador
cout << "----------------------------------------" << endl;
cout << "Vida:" << jugador.vida << endl;
cout << "Bombas:" << jugador.bomba << endl;
cout << "----------------------------------------" << endl;
cout << "Al entrar la puerta del cuarto se cierra." << endl;
cout << "Enfrete tienes 2 botones." << endl;
cout << "Que debo hacer?" << endl;
cout << "1- Presionar el boton 1." << endl;
cout << "2- Presionar el boton 2." << endl;
int op;
cin >> op;
switch (op) {
case 1:
cout << "----------------------------------------" << endl;
cout << "Pisaste el boton 1 . . ." << endl;
cout << "Para tu suete la puerta se abrio." << endl;
cout << "Rapidamente saliste del cuarto." << endl;
Sala_5(jugador);
break;

case 2:
cout << "----------------------------------------" << endl;
cout << "Pisaste el boton 2 . . ." << endl;
cout << "De la nada aparecieron 2 moscas explosivas." << endl;
cout << "Te estallaron en la cara . . ." << endl;
jugador.vida -= 2;
if
//Verificador de Vida: Cuando esta llega a 0 Sera Game Over
//Si aun tiene vida este podra continuar
(jugador.vida <= 0) {
cout << "----------------------------------------" << endl;
cout << "Ya no tienes vida . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
}
else if 
(jugador.vida > 0) {
cout << "Con suerte estallaron la puerta." << endl;
cout << "Volviste a la sala anterior" << endl;
Sala_5(jugador);
}
break;

//Gamer Over: Por oprimir otro boton
default:
cout << "----------------------------------------" << endl;
cout << "Explotaste sin ninguna razon . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
break;
}
}

//Habitacion 8
void
Sala_8(Jugador jugador) {
//Evento por objeto 1: Cura al jugador cada sala.
if
(jugador.item == 1) {
jugador.vida += 1;
}
//Stats Actuales del Jugador
cout << "----------------------------------------" << endl;
cout << "Vida:" << jugador.vida << endl;
cout << "Bombas:" << jugador.bomba << endl;
cout << "----------------------------------------" << endl;
cout << "Al horizonte unas moscas explosivas se hacercan rapidamente." << endl;
cout << "Sin embargo a la distancia igualmete vez una puerta." << endl;
cout << "Pero esta bloqueado por unos picos." << endl;
cout << "Que debo hacer?" << endl;
cout << "1- Pelear." << endl;
cout << "2- Huir." << endl;
cout << "3- Volver a la sala anterior." << endl;
int op;
cin >> op;
switch (op) {
case 1:
cout << "----------------------------------------" << endl;
cout << "Logras derribarlos antes que lleguen." << endl;
cout << "Gracias a ellos los picos se han retraido." << endl;
Sala_9(jugador);
break;

case 2:
if (jugador.item == 2) {
cout << "----------------------------------------" << endl;
cout << "Evadiste a las moscas facilmente y pasa por los ahires los picos." << endl;
cout << "Y asi pasaste de a gratis al siguiente cuarto." << endl;
}
else
{
cout << "----------------------------------------" << endl;
cout << "Corriste como loco y te explotaron en la cara." << endl;
cout << "Te valio comino los picos y pasaste sobre ellos." << endl;
jugador.vida -= 3;
if 
//Verificador de Vida: Cuando esta llega a 0 Sera Game Over
//Si aun tiene vida este podra continuar
(jugador.vida <= 0) {
cout << "----------------------------------------" << endl;
cout << "Ya no tienes vida . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
}
else if 
(jugador.vida > 0) {
cout << "Obviamente dolio pero valio la pena." << endl;
Sala_9(jugador);
}
}

break;

case 3:
Sala_5(jugador);
break;

//Gamer Over: Por oprimir otro boton
default:
cout << "----------------------------------------" << endl;
cout << "Explotaste sin ninguna razon . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
break;
}
}

//Habitacion 9
void
Sala_9(Jugador jugador) {
//Evento por objeto 1: Cura al jugador cada sala.
if
(jugador.item == 1) {
jugador.vida += 1;
}
//Stats Actuales del Jugador
cout << "----------------------------------------" << endl;
cout << "Vida:" << jugador.vida << endl;
cout << "Bombas:" << jugador.bomba << endl;
cout << "----------------------------------------" << endl;
cout << "En el cuarto parece haber algunas rocas en las esquinas." << endl;
cout << "A la vez una puerta con apariencia siniestra se encuentra a la derecha del cuarto." << endl;
cout << "Que debo hacer?" << endl;
cout << "1- Ir por la Puerta Siniestra." << endl;
cout << "2- Investigar." << endl;
cout << "3- Volver a la sala anterior." << endl;
int op;
cin >> op;
switch (op) {

case 1:
Sala_10(jugador);
break;

case 2:
cout << "----------------------------------------" << endl;
cout << "Investigando un poco te percatas de una grieta." << endl;
//Evento de Bomba: Si el jugador tiene 1 bomba  podra acceder a las recompensas.
if
(jugador.bomba >= 1) {
cout << "Al tener una bomba lograste romper la pared y entrar a la sala secreta." << endl;
cout << "En la Sala encontraste 4 corazones de alma." << endl;
cout << "Decidiste volver a la sala anterior." << endl;
cout << "----------------------------------------" << endl;
jugador.bomba -= 1;
jugador.vida += 4;
Sala_9(jugador);
}
else if
(jugador.bomba == 0) {
cout << "Al no tener una bomba decidiste volver por donde viniste." << endl;
cout << "----------------------------------------" << endl;
Sala_9(jugador);
break;
}

case 3:
Sala_8(jugador);
break;

//Gamer Over: Por oprimir otro boton
default:
cout << "----------------------------------------" << endl;
cout << "Explotaste sin ninguna razon . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
break;
}
}

//Habitacion 10: Intro del Jefe
void
Sala_10(Jugador jugador) {
//Evento por objeto 1: Cura al jugador cada sala.
if
(jugador.item == 1) {
jugador.vida += 1;
}
//Stats Actuales del Jugador
cout << "----------------------------------------" << endl;
cout << "Vida:" << jugador.vida << endl;
cout << "Bombas:" << jugador.bomba << endl;
cout << "----------------------------------------" << endl;
cout << "Al entrar solo puedes ver una inmesa oscuridad . . ." << endl;
cout << "Sin embargo escuchas una voz familiar." << endl;
cout << "-Isssaaaac" << endl;
cout << "Mama ha aparecido" << endl;
cout << "Que debo hacer?" << endl;
cout << "1- Pelear Contra Mama" << endl;
int op;
cin >> op;
switch (op) {
case 1:
Final(jugador);
break;

//Gamer Over: Por oprimir otro boton
default:
cout << "----------------------------------------" << endl;
cout << "Explotaste sin ninguna razon . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
break;
}
}

//Jefe Final: Si la salud del Jefe llega a 0 el Juego Termina.
void
Final(Jugador jugador) {
if
(jugador.boss >= 1) {
//Stats Actuales del Jugador y del Jefe Final
cout << "----------------------------------------" << endl;
cout << "Vida:" << jugador.vida << endl;
cout << "Bombas:" << jugador.bomba << endl;
cout << "----------------------------------------" << endl;
cout << "Vida de Mama:" << jugador.boss << endl;
cout << "----------------------------------------" << endl;
cout << "Que debo hacer?" << endl;
cout << "1- Ir por el Pie" << endl;
cout << "2- Usar Bomba" << endl;
cout << "3- Esquivar" << endl;
int op;
cin >> op;
switch (op) {

case 1:
cout << "----------------------------------------" << endl;
cout << "Atacas con todo Mama perdio 2 de vida pero igualmete contraataca." << endl;
jugador.boss -= 2;
jugador.vida -= 1;
if 
//Verificador de Vida: Cuando esta llega a 0 Sera Game Over
//Si aun tiene vida este podra continuar
(jugador.vida <= 0) {
cout << "----------------------------------------" << endl;
cout << "Ya no tienes vida . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
}
else if (jugador.vida > 0) {
Final(jugador);
}
break;

case 2:
if
(jugador.bomba >= 1) {
cout << "Pones 1 bomba y haces que Mama reciba mucho daño" << endl;
cout << "----------------------------------------" << endl;
jugador.bomba -= 1;
jugador.boss -= 4;
Final(jugador);
}
else if
(jugador.bomba == 0) {
cout << "Te quedaste como idiota y Mama te aplasto" << endl;
cout << "----------------------------------------" << endl;
jugador.vida -= 2;
}
if
//Verificador de Vida: Cuando esta llega a 0 Sera Game Over
//Si aun tiene vida este podra continuar
(jugador.vida <= 0) {
cout << "----------------------------------------" << endl;
cout << "Ya no tienes vida . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
}
else if (jugador.vida > 0) {
Final(jugador);
}
break;

case 3:
cout << "Mama ataca pero lograste evadirlo ademas recogiste un corazon de alma" << endl;
jugador.vida += 1;
Final(jugador);
break;

//Gamer Over: Por oprimir otro boton
default:
cout << "----------------------------------------" << endl;
cout << "Explotaste sin ninguna razon . . ." << endl;
cout << "GAME OVER" << endl;
cout << "----------------------------------------" << endl;
break;
}
}
//La condicion de victoria.
else if (jugador.boss == 0) {
cout << "----------------------------------------" << endl;
cout << "Mama a sido derrotada . . ." << endl;
cout << "GANASTE!!!!" << endl;
cout << "----------------------------------------" << endl;
}
}
};