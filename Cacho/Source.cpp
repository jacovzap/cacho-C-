#include <iostream>
#include <string> 
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#define NUMERO_DADOS 5

using namespace std;

void jugarContraUnJugador(bool turnoPlayerOne, int turno);
void jugarContraMaquina(bool turnoPlayerOne, int turno);



struct Tablero {
	int casilla[3][3];
	int grandes[2];
};

struct Jugador{
	string nombre;
	int puntaje = 0;
    Tablero tablero;
	int numeroDeTurno = 0;
}jugador1, jugador2;


struct Cacho{
	int dados[NUMERO_DADOS];
}cacho;


void llenarTablero()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			jugador1.tablero.casilla[i][j] = -1;
			jugador2.tablero.casilla[i][j] = -1;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		jugador1.tablero.grandes[i] = -1;
		jugador2.tablero.grandes[i] = -1;
	}
}


void dibujarTablero() {
	cout << "                                "<<jugador1.nombre<<"                                         "<<jugador2.nombre<<"                                   " << endl;
	cout << "                                                                                                              " << endl;
	cout << "                                                                                                              " << endl;
	cout << "                              |       |                                    |       |                          "<< endl;
	cout << "                         "<<jugador1.tablero.casilla[0][0]<<"    |  " << jugador1.tablero.casilla[0][1] << "   |  " << jugador1.tablero.casilla[0][2] << "                           " << jugador2.tablero.casilla[0][0] << "   |  " << jugador2.tablero.casilla[0][1] << "   |  " << jugador2.tablero.casilla[0][2] << "                     "<< endl;
	cout << "                              |       |                                    |       |                          "<< endl;
	cout << "                     _________________________                    _________________________                 "<< endl;
	cout << "                              |       |                                    |       |                          "<< endl;
	cout << "                         "<<jugador1.tablero.casilla[1][0]<<"    |  " << jugador1.tablero.casilla[1][1] << "   |  " << jugador1.tablero.casilla[1][2] << "                           " << jugador2.tablero.casilla[1][0] << "   |  " << jugador2.tablero.casilla[1][1] << "   |  " << jugador2.tablero.casilla[1][2] << "                     "<< endl;
	cout << "                              |       |                                    |       |                          "<< endl;
	cout << "                     _________________________                    _________________________                 "<< endl;
	cout << "                              |       |                                    |       |                          "<< endl;
	cout << "                         "<<jugador1.tablero.casilla[2][0]<<"    |  " << jugador1.tablero.casilla[2][1] << "   |  " << jugador1.tablero.casilla[2][2] << "                           " << jugador2.tablero.casilla[2][0] << "   |  " << jugador2.tablero.casilla[2][1] << "   |  " << jugador2.tablero.casilla[2][2] << "                    "<< endl;
	cout << "                              |       |                                    |       |                          "<< endl;
	cout << endl;
	cout << "                             " << jugador1.tablero.grandes[0] <<  "   /   " << jugador1.tablero.grandes[1] << "                                  " << jugador2.tablero.grandes[0] << "   /   " << jugador2.tablero.grandes[1] <<"                   "<< endl;
	cout << endl;
}





void guardarPartida()
{
	/*jugador1.nombre = "Juan";
	jugador1.puntaje = 3 + 9 + 18;
	jugador1.tablero.casilla[0][0] = 3;
	jugador1.tablero.casilla[2][0] = 9;
	jugador1.tablero.casilla[2][2] = 18;
	jugador1.numeroDeTurno = 3;

	jugador2.nombre = "Rosa";
	jugador2.puntaje = 6 + 12 +15;
	jugador2.tablero.casilla[1][0] = 6;
	jugador2.tablero.casilla[0][2] = 12;
	jugador2.tablero.casilla[1][2] = 15;
	jugador2.numeroDeTurno = 3*/

	ofstream myfile("example.txt");
	if (myfile.is_open())
	{

		myfile << jugador1.nombre << "\n";
		myfile << jugador2.nombre << "\n";

		myfile << jugador1.numeroDeTurno << "\n";
		myfile << jugador2.numeroDeTurno << "\n";

		myfile << jugador1.puntaje << "\n";
		myfile << jugador2.puntaje << "\n";

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				myfile << jugador1.tablero.casilla[i][j] << "\n";
				myfile << jugador2.tablero.casilla[i][j] << "\n";
			}
		}

		for (int i = 0; i < 2; i++)
		{
			myfile << jugador1.tablero.grandes[i] << "\n";
			myfile << jugador2.tablero.grandes[i] << "\n";
		}

		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			myfile << cacho.dados[i] << "\n";
		}

		myfile.close();
	}
	else cout << "Unable to open file";
}

void cargarPartida() {

	fstream file;
	string word, t, q, filename;

	filename = "example.txt";

	file.open(filename.c_str());
	int contador = 0, i = 0, j = 0, grandes = 0, dado = 0;
	while (file >> word)
	{
		if (j == 3)
		{
			i++;
			j = 0;
		}

		if (contador == 0)
		{
			jugador1.nombre = word;
		}
		if (contador == 1)
		{
			jugador2.nombre = word;
		}

		if (contador == 2)
		{
			jugador1.numeroDeTurno = stoi(word);
		}

		if (contador == 3)
		{
			jugador2.numeroDeTurno = stoi(word);
		}

		if (contador == 4)
		{
			jugador1.puntaje = stoi(word);
		}

		if (contador == 5) {
			jugador2.puntaje = stoi(word);
		}

		if (contador % 2 == 0 and contador > 5 and contador <= 23)
		{
			jugador1.tablero.casilla[i][j] = stoi(word);
		}

		if (contador % 2 != 0 and contador > 5 and contador <= 23)
		{
			jugador2.tablero.casilla[i][j] = stoi(word);
			j++;
		}

		if (contador % 2 == 0 and contador > 23 and contador <= 27)
		{
			jugador1.tablero.grandes[grandes] = stoi(word);
		}

		if (contador % 2 != 0 and contador > 23 and contador <= 27)
		{
			jugador2.tablero.grandes[grandes] = stoi(word);
			grandes++;
		}

		if (contador > 27)
		{
			cacho.dados[dado] = stoi(word);
			dado++;
		}

		contador++;

	}

	bool turnoPlayer1 = false;

	if (jugador1.numeroDeTurno == jugador2.numeroDeTurno)
	{
		turnoPlayer1 = true;
	}

	/*
	cout << jugador1.nombre << endl;
	cout << jugador1.puntaje << endl;
	cout << jugador1.numeroDeTurno << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << jugador1.tablero.casilla[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	cout << jugador1.tablero.grandes[0] << endl;

	cout << jugador1.tablero.grandes[1] << endl;
	cout << endl;

	for (int i = 0; i < NUMERO_DADOS; i++)
	{
		cout << cacho.dados[i] << " ";
	}
	cout << endl;



	cout << jugador2.nombre << endl;
	cout << jugador2.puntaje << endl;
	cout << jugador2.numeroDeTurno << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << jugador2.tablero.casilla[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	cout << jugador2.tablero.grandes[0] << endl;

	cout << jugador2.tablero.grandes[1] << endl;
	cout << endl;

	for (int i = 0; i < NUMERO_DADOS; i++)
	{
		cout << cacho.dados[i] << " ";
	}
	cout << endl;
	system("pause");
	*/

	if (jugador2.nombre == "MAQUINA")
	{
		jugarContraMaquina(turnoPlayer1, jugador1.numeroDeTurno + jugador2.numeroDeTurno);
	}
	else
	{
		jugarContraUnJugador(turnoPlayer1, jugador1.numeroDeTurno + jugador2.numeroDeTurno);
	}

	
	
	
}

void voletarDados()
{
	int cantidad, dadoRegresado, recorrerDadosRegresados;
	bool encontrado;
	cout << "Cuantos dados desea voltear? (MAX 2): ";
	cin >> cantidad;

	for (int i = 0; i < cantidad; i++)
	{
		cout << " Dado " << i + 1 << ": ";
		cin >> dadoRegresado;
		recorrerDadosRegresados = 0;
		encontrado = false;
		while (!encontrado)
		{
			if (cacho.dados[recorrerDadosRegresados] == dadoRegresado)
			{
				cacho.dados[recorrerDadosRegresados] = 7 - dadoRegresado;
				encontrado = true;
			}
			recorrerDadosRegresados++;
		}
	}
	cout << "                           ";
	for (int i = 0; i < NUMERO_DADOS; i++) {
		cout << " " << cacho.dados[i] << " ";
	}
	cout << endl;

}



void voltearUnDadoMaquina(int dadoRegresado)
{
	int recorrerDadosRegresados;
	bool encontrado;



		recorrerDadosRegresados = 0;
		encontrado = false;
		while (!encontrado)
		{
			if (cacho.dados[recorrerDadosRegresados] == dadoRegresado)
			{
				cacho.dados[recorrerDadosRegresados] = 7 - dadoRegresado;
				encontrado = true;
			}
			recorrerDadosRegresados++;
		}

	cout << "                           ";
	for (int i = 0; i < NUMERO_DADOS; i++) {
		cout << " " << cacho.dados[i] << " ";
	}
	cout << endl;

}


void voltearDosDadoMaquina(int dado1, int dado2)
{
	int recorrerDadosRegresados, dadoRegresado;
	bool encontrado;


	for (int i = 0; i < 2; i++)
	{
		if (i == 0)dadoRegresado = dado1;
		else dadoRegresado = dado2;

		recorrerDadosRegresados = 0;
		encontrado = false;
		while (!encontrado)
		{
			if (cacho.dados[recorrerDadosRegresados] == dadoRegresado)
			{
				cacho.dados[recorrerDadosRegresados] = 7 - dadoRegresado;
				encontrado = true;
			}
			recorrerDadosRegresados++;
		}
	}
	cout << "                           ";
	for (int i = 0; i < NUMERO_DADOS; i++) {
		cout << " " << cacho.dados[i] << " ";
	}
	cout << endl;

}



int contarPuntos(int numero)
{
	int contador = 0, invertirDos = 0;
	for (int i = 0; i < NUMERO_DADOS; i++)
	{
		if (cacho.dados[i] == numero)
		{
        	contador++;
		}
	}

	return contador * numero;
}


int contarEscalera(int lanzamiento) {
	int dadoSeRepiteMas[6];
	int contador, unosConsecutivos = 0;


	for (int j = 0; j < 6; j++)
	{
		contador = 0;
		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			if (cacho.dados[i] == j + 1)
			{
				contador++;
			}
		}
		dadoSeRepiteMas[j] = contador;
	}


	for (int i = 0; i < 6; i++)
	{
		if (dadoSeRepiteMas[i] == 1) {
			unosConsecutivos++;
		}
		else
		{
			unosConsecutivos = 0;
		}

		if (unosConsecutivos == 5)
		{
			if (lanzamiento == 1)
			{
				return 25;
			}
			else
			{
				return 20;
			}
		}
		
	}

	return 0;
}


int contarFull(int lanzamiento) {
	int dadoSeRepiteMas[6];
	int contador, mayor = 0, segundoMayor = 0, posicion;

	for (int j = 0; j < 6; j++)
	{
		contador = 0;
		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			if (cacho.dados[i] == j+1)
			{
				contador++;
			}
		}
		dadoSeRepiteMas[j] = contador;
	}

	for (int i = 0; i < 6; i++)
	{
		if (dadoSeRepiteMas[i] > mayor)
		{
			mayor = dadoSeRepiteMas[i];
			posicion = i;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		if (i != posicion)
		{
			if (dadoSeRepiteMas[i] > segundoMayor)
			{
				segundoMayor = dadoSeRepiteMas[i];
			}
		}
	}


	if (mayor == 3 and segundoMayor == 2)
	{
		if (lanzamiento == 1)
		{
			return 35;
		}
		else
		{
			return 30;
		}
	}

	return 0;
}


int contarPoker(int lanzamiento) {
	int dadoSeRepiteMas[6];
	int contador, mayor = 0, segundoMayor = 0, posicion;

	for (int j = 0; j < 6; j++)
	{
		contador = 0;
		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			if (cacho.dados[i] == j + 1)
			{
				contador++;
			}
		}
		dadoSeRepiteMas[j] = contador;
	}


	for (int i = 0; i < 6; i++)
	{
		if (dadoSeRepiteMas[i] > mayor)
		{
			mayor = dadoSeRepiteMas[i];
			posicion = i;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		if (i != posicion)
		{
			if (dadoSeRepiteMas[i] > segundoMayor)
			{
				segundoMayor = dadoSeRepiteMas[i];
			}
		}
	}
	

	if (mayor == 4 and segundoMayor == 1)
	{
		if (lanzamiento == 1)
		{
			return 45;
		}
		else
		{
			return 40;
		}
	}

	return 0;

}


int verificarGrande(int lanzamiento) {
	int dadoSeRepiteMas[6];
	int contador, mayor = 0;


	for (int j = 0; j < 6; j++)
	{
		contador = 0;
		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			if (cacho.dados[i] == j+1)
			{
				contador++;
			}
		}
		dadoSeRepiteMas[j] = contador;
	}


	for (int i = 0; i < 6; i++)
	{
		if (dadoSeRepiteMas[i] > mayor)
		{
			mayor = dadoSeRepiteMas[i];
		}
	}

	if (mayor == 5)
	{
		if (lanzamiento == 1)
		{
			return 500;
		}
		if (lanzamiento == 2)
		{
			return 50;
			
		}
		
	}
	return 0;
}


void tirarDeNuevo() {
	int dadosRegresados, dadoRegresado, recorrerDadosRegresados;
	bool encontrado;
	cout << "Elija cuantos dados desea introducir nuevamente al cacho: ";
	cin >> dadosRegresados;

	for (int i = 0; i < dadosRegresados; i++)
	{
		cout << " Dado " << i + 1 << ": ";
		cin >> dadoRegresado;
		recorrerDadosRegresados = 0;
		encontrado = false;
		while (!encontrado)
		{
			if (cacho.dados[recorrerDadosRegresados] == dadoRegresado)
			{
				int aux;
				if (recorrerDadosRegresados != NUMERO_DADOS - 1)
				{
					for (int h = recorrerDadosRegresados; h < NUMERO_DADOS; h++)
					{
						aux = cacho.dados[h + 1];
						cacho.dados[h + 1] = cacho.dados[h];
						cacho.dados[h] = aux;
					}
				}
				cacho.dados[NUMERO_DADOS - 1] = 1 + rand() % (6);
				encontrado = true;
			}
			recorrerDadosRegresados++;
		}
	}

	cout << "                           ";
	for (int i = 0; i < NUMERO_DADOS; i++) {
		cout << " " << cacho.dados[i] << " ";
	}
	cout << endl;
}


void tirarDeNuevoMaquina(int dadosRegresados, int dados[5]) {
	int dadoRegresado, recorrerDadosRegresados;
	bool encontrado;

	for (int i = 0; i < dadosRegresados; i++)
	{
		dadoRegresado = dados[i];
		recorrerDadosRegresados = 0;
		encontrado = false;
		while (!encontrado)
		{
			if (cacho.dados[recorrerDadosRegresados] == dadoRegresado)
			{
				int aux;
				if (recorrerDadosRegresados != NUMERO_DADOS - 1)
				{
					for (int h = recorrerDadosRegresados; h < NUMERO_DADOS; h++)
					{
						aux = cacho.dados[h + 1];
						cacho.dados[h + 1] = cacho.dados[h];
						cacho.dados[h] = aux;
					}
				}
				cacho.dados[NUMERO_DADOS - 1] = 1 + rand() % (6);
				encontrado = true;
			}
			recorrerDadosRegresados++;
		}
	}

	cout << "                           ";
	for (int i = 0; i < NUMERO_DADOS; i++) {
		cout << " " << cacho.dados[i] << " ";
	}
	cout << endl;
}




void anotar(Jugador* jugador, int lanzamiento) {
	int option, resultado;
	cout << "Que desea anotar? " << endl;
	if (jugador->tablero.casilla[0][0] == -1) cout << " 1. Balas" << endl;
	if (jugador->tablero.casilla[1][0] == -1) cout << " 2. Tontos" << endl;
	if (jugador->tablero.casilla[2][0] == -1) cout << " 3. Trenes" << endl;
	if (jugador->tablero.casilla[0][2] == -1) cout << " 4. Cuadras" << endl;
	if (jugador->tablero.casilla[1][2] == -1) cout << " 5. Quinas" << endl;
	if (jugador->tablero.casilla[2][2] == -1) cout << " 6. Senas" << endl;
	if (jugador->tablero.casilla[0][1] == -1) cout << " 7. Escalera" << endl;
	if (jugador->tablero.casilla[1][1] == -1) cout << " 8. Full" << endl;
	if (jugador->tablero.casilla[2][1] == -1) cout << " 9. Poker" << endl;
	if (jugador->tablero.grandes[0] == -1 or jugador->tablero.grandes[1] == -1) cout << " 0. GRANDE" << endl;
	cin >> option;


	switch (option) {
	case 1:
		resultado = contarPuntos(1);
		jugador->tablero.casilla[0][0] = resultado;
		break;
	case 2:
		resultado = contarPuntos(2);
		jugador->tablero.casilla[1][0] = resultado;
		break;
	case 3:
		resultado = contarPuntos(3);
		jugador->tablero.casilla[2][0] = resultado;
		break;
	case 4:
		resultado = contarPuntos(4);
		jugador->tablero.casilla[0][2] = resultado;
		break;
	case 5:
		resultado = contarPuntos(5);
		jugador->tablero.casilla[1][2] = resultado;
		break;
	case 6:
		resultado = contarPuntos(6);
		jugador->tablero.casilla[2][2] = resultado;
		break;
	case 7:
		resultado = contarEscalera(lanzamiento);
		jugador->tablero.casilla[0][1] = resultado;
		break;
	case 8:
		resultado = contarFull(lanzamiento);
		jugador->tablero.casilla[1][1] = resultado;
		break;
	case 9:
		resultado = contarPoker(lanzamiento);
		jugador->tablero.casilla[2][1] = resultado;
		break;
	case 0:
		resultado = verificarGrande(lanzamiento);
		if (jugador->tablero.grandes[0] == -1)
		{
			jugador->tablero.grandes[0] = resultado;
		}
		else
		{
			jugador->tablero.grandes[1] = resultado;
		}
		break;
	default:
		break;
	}
}

void anunciarGanador()
{
	int puntajeJugador1 = 0, puntajeJugador2 = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			puntajeJugador1 = jugador1.tablero.casilla[i][j] + puntajeJugador1;
			puntajeJugador2 = jugador2.tablero.casilla[i][j] + puntajeJugador2;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		puntajeJugador1 = jugador1.tablero.grandes[i] + puntajeJugador1;
		puntajeJugador2 = jugador2.tablero.grandes[i] + puntajeJugador2;
	}

	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout <<"                                ---------------------------------------- GANADOR:-------------------------------------"<< endl;
	if (puntajeJugador1 > puntajeJugador2)
	{

		cout << "                                                                         JUGADOR 1                                      " << endl;
	}
	else
	{
		if (puntajeJugador2 > puntajeJugador1)
		{

			cout << "                                                                         JUGADOR 2                                      " << endl;
		}
		else
		{

			cout << "                                                                         EMPATE                                      " << endl;
		}
	}

	cout << "Puntaje Jugador 1: "<<puntajeJugador1 << endl;
	cout << "Puntaje Jugador 2: " <<puntajeJugador2<< endl;
	system("pause");
}



void anunciarGanadorDormida(Jugador *jugador)
{
	system("clear");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl; 
	cout << endl;
	cout << "################################## EL JUGADOR " << jugador->nombre << " HA GANADO POR DORMIDA #######################################" << endl;
}




void decidirDadosIntroducir()
{
	int dadoSeRepiteMas[6], dadosHipoteticos[5], dadosEnviarACambiar[5];
	int contador, mayor = 0, posicionMayor, posicionSegundoMayor, posicionTercerMayor, segundoMayor = 0, maxVoltearDados = 2, tercerMayor = 0, aux;

	/*CUENTA EL NUMERO DE DADOS QUE SE REPITE EN UN VECTOR EJ:
	CACHO.DADOS = [1, 4, 3 ,1 ,3], ENTONCES EL VECTOR DEVOLVERIA [2, 0, 2, 1, 0, 0], DOS VECES SE REPITE EL DADO 1, CERO VECES EL DADO 2, DOS VECES EL DADO 3...
	*/
	for (int j = 0; j < 6; j++)
	{
		contador = 0;
		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			if (cacho.dados[i] == j + 1)
			{
				contador++;
			}
		}
		dadoSeRepiteMas[j] = contador;
	}

	//IDENTIFICA CUAL ES EL DADO QUE SE REPITE MAS
	for (int i = 0; i < 6; i++)
	{
		if (dadoSeRepiteMas[i] >= mayor)
		{
			mayor = dadoSeRepiteMas[i];
			posicionMayor = i;
		}
	}

	//IDENTIDICA AL SEGUNDO DADO QUE SE REPITE MAS
	for (int i = 0; i < 6; i++)
	{
		if (i != posicionMayor)
		{
			if (dadoSeRepiteMas[i] >= segundoMayor)
			{
				segundoMayor = dadoSeRepiteMas[i];
				posicionSegundoMayor = i;
			}
		}
	}

	//VOLTEA DADOS IMAGINARIAMENTE PARA DECIDIR SI IR POR GRANDE, POKER, FULL 

	//LLENAR CACHO IMAGINARIO
	for (int i = 0; i < NUMERO_DADOS; i++)
	{
		dadosHipoteticos[i] = cacho.dados[i];
	}

	//VOLTEAR
	//HAY DOS MODOS DE VOLTEAR, UNO BENEFICIA MAS A LA BUSQUEDA DE GRANDE Y EL OTRO A LA BUSQUEDA DE POKER O FULL
	if (jugador2.tablero.grandes[0] == -1 or jugador2.tablero.grandes[1] == -1 or (jugador2.tablero.casilla[0][1] != -1 and jugador2.tablero.casilla[1][1] != -1 and jugador2.tablero.casilla[2][1] != -1))
	{
		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			if (maxVoltearDados != 0)
			{
				if (dadosHipoteticos[i] == (7 - posicionMayor - 1))
				{
					dadosHipoteticos[i] = posicionMayor + 1;
					maxVoltearDados--;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			if (maxVoltearDados != 0)
			{
				if (dadosHipoteticos[i] == 7 - posicionMayor - 1)
				{
					dadosHipoteticos[i] = posicionMayor + 1;
					maxVoltearDados--;
				}
				if (dadosHipoteticos[i] == 7 - posicionSegundoMayor - 1)
				{
					dadosHipoteticos[i] = posicionSegundoMayor + 1;
					maxVoltearDados--;
				}
			}
		}
	}


	for (int j = 0; j < 6; j++)
	{
		contador = 0;
		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			if (dadosHipoteticos[i] == j + 1)
			{
				contador++;
			}
		}
		dadoSeRepiteMas[j] = contador;
	}

	//IDENTIFICA CUAL ES EL DADO QUE SE REPITE MAS
	for (int i = 0; i < 6; i++)
	{
		if (dadoSeRepiteMas[i] >= mayor)
		{
			mayor = dadoSeRepiteMas[i];
			posicionMayor = i;
		}
	}

	//IDENTIDICA AL SEGUNDO DADO QUE SE REPITE MAS
	for (int i = 0; i < 6; i++)
	{
		if (i != posicionMayor)
		{
			if (dadoSeRepiteMas[i] >= segundoMayor)
			{
				segundoMayor = dadoSeRepiteMas[i];
				posicionSegundoMayor = i;
			}
		}
	}

	//IDENTIDICA AL TERCER DADO QUE SE REPITE MAS
	for (int i = 0; i < 6; i++)
	{
		if (i != posicionMayor and i!= posicionSegundoMayor)
		{
			if (dadoSeRepiteMas[i] >= tercerMayor)
			{
				tercerMayor = dadoSeRepiteMas[i];
				posicionTercerMayor = i;
			}
		}
	}






	//INTRODUCIR DADOS SEGUN DECISION
	

	//GRANDE
	if ((jugador2.tablero.grandes[0] == -1 or jugador2.tablero.grandes[1] == -1) and (mayor == 5 and segundoMayor == 0))
	{
		dadosEnviarACambiar[0] = posicionMayor + 1;
		
		tirarDeNuevoMaquina(1, dadosEnviarACambiar);
		
		return;
	}

	if ((jugador2.tablero.grandes[0] == -1 or jugador2.tablero.grandes[1] == -1) and (mayor == 4 and segundoMayor == 1))
	{
		dadosEnviarACambiar[0] = posicionSegundoMayor + 1;
		
		tirarDeNuevoMaquina(1, dadosEnviarACambiar);
		
		return;
	}

	//POKER
	if (jugador2.tablero.casilla[2][1] == -1 and (mayor == 3 and segundoMayor == 2))
	{
		dadosEnviarACambiar[0] = posicionSegundoMayor + 1;
		
		tirarDeNuevoMaquina(1, dadosEnviarACambiar);
		
		return;
	}

	if (jugador2.tablero.casilla[2][1] == -1 and (mayor == 3 and segundoMayor == 1))
	{
		dadosEnviarACambiar[0] = posicionTercerMayor + 1;
		
		tirarDeNuevoMaquina(1, dadosEnviarACambiar);
		
		return;
	}

	if (jugador2.tablero.casilla[2][1] == -1 and (mayor == 4 and segundoMayor == 1))
	{
		dadosEnviarACambiar[0] = posicionSegundoMayor + 1;
		
		tirarDeNuevoMaquina(1, dadosEnviarACambiar);
		
		return;
	}

	//FULL
	if (jugador2.tablero.casilla[1][1] == -1 and (mayor == 3 and segundoMayor == 2))
	{
		dadosEnviarACambiar[0] = posicionSegundoMayor + 1;
		
		tirarDeNuevoMaquina(1, dadosEnviarACambiar);
		
		return;
	}
	if (jugador2.tablero.casilla[1][1] == -1 and (mayor == 2 and segundoMayor == 2))
	{
		dadosEnviarACambiar[0] = posicionTercerMayor + 1;
	
		tirarDeNuevoMaquina(1, dadosEnviarACambiar);
		
		return;
	}


	//NUMERICO 
	//6
	if (jugador2.tablero.casilla[2][2] == -1 and ((posicionMayor + 1) == 6))
	{
		aux = 0;
		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			if (posicionMayor + 1 == cacho.dados[i])
			{
				dadosEnviarACambiar[aux] = cacho.dados[i];
				aux++;
			}
		}

		
		tirarDeNuevoMaquina(aux, dadosEnviarACambiar);
		
		return;
	}


	//5
	if (jugador2.tablero.casilla[1][2] == -1 and ((posicionMayor + 1) == 5))
	{
		aux = 0;
		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			if (posicionMayor + 1 == cacho.dados[i])
			{
				dadosEnviarACambiar[aux] = cacho.dados[i];
				aux++;
			}
		}

	

		tirarDeNuevoMaquina(aux, dadosEnviarACambiar);
		
		return;
	}


	//4
	if (jugador2.tablero.casilla[0][2] == -1 and ((posicionMayor + 1) == 4))
	{
		aux = 0;
		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			if (posicionMayor + 1 == cacho.dados[i])
			{
				dadosEnviarACambiar[aux] = cacho.dados[i];
				aux++;
			}
		}

		
		tirarDeNuevoMaquina(aux, dadosEnviarACambiar);
	
		return;
	}



	//3
	if (jugador2.tablero.casilla[2][0] == -1 and ((posicionMayor + 1) == 3))
	{
		aux = 0;
		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			if (posicionMayor + 1 == cacho.dados[i])
			{
				dadosEnviarACambiar[aux] = cacho.dados[i];
				aux++;
			}
		}


	

		tirarDeNuevoMaquina(aux, dadosEnviarACambiar);
	
		return;
	}


	//2
	if (jugador2.tablero.casilla[1][0] == -1 and ((posicionMayor + 1) == 2))
	{
		aux = 0;
		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			if (posicionMayor + 1 == cacho.dados[i])
			{
				dadosEnviarACambiar[aux] = cacho.dados[i];
				aux++;
			}
		}


		tirarDeNuevoMaquina(aux, dadosEnviarACambiar);
		
		return;
	}


	//1
	if (jugador2.tablero.casilla[0][0] == -1 and ((posicionMayor + 1) == 1))
	{
		aux = 0;
		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			if (posicionMayor + 1 == cacho.dados[i])
			{
				dadosEnviarACambiar[aux] = cacho.dados[i];
				aux++;
			}
		}


		tirarDeNuevoMaquina(aux, dadosEnviarACambiar);
		
		return;
	}

	//DEFAULT CASE
	if (1 == 1)
	{
		aux = 0;
		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			dadosEnviarACambiar[aux] = cacho.dados[i];
			aux++;
		}
		tirarDeNuevoMaquina(aux, dadosEnviarACambiar);
	}
}


void decidirDadosVoltear()
{

	int dadoSeRepiteMas[6];
	int contador, mayor = 0, posicionMayor, posicionSegundoMayor, posicionTercerMayor, segundoMayor = 0, maxVoltearDados = 2, tercerMayor = 0, aux;

	for (int j = 0; j < 6; j++)
	{
		contador = 0;
		for (int i = 0; i < NUMERO_DADOS; i++)
		{
			if (cacho.dados[i] == j + 1)
			{
				contador++;
			}
		}
		dadoSeRepiteMas[j] = contador;
	}

	//IDENTIFICA CUAL ES EL DADO QUE SE REPITE MAS
	for (int i = 0; i < 6; i++)
	{
		if (dadoSeRepiteMas[i] >= mayor)
		{
			mayor = dadoSeRepiteMas[i];
			posicionMayor = i;
		}
	}

	//IDENTIDICA AL SEGUNDO DADO QUE SE REPITE MAS
	for (int i = 0; i < 6; i++)
	{
		if (i != posicionMayor)
		{
			if (dadoSeRepiteMas[i] >= segundoMayor)
			{
				segundoMayor = dadoSeRepiteMas[i];
				posicionSegundoMayor = i;
			}
		}
	}

	//IDENTIDICA AL TERCER DADO QUE SE REPITE MAS
	for (int i = 0; i < 6; i++)
	{
		if (i != posicionMayor and i != posicionSegundoMayor)
		{
			if (dadoSeRepiteMas[i] >= tercerMayor)
			{
				tercerMayor = dadoSeRepiteMas[i];
				posicionTercerMayor = i;
			}
		}
	}


	//VOLTEAR
	
	for (int i = 0; i < NUMERO_DADOS; i++)
	{
		if (maxVoltearDados != 0)
		{
			if (cacho.dados[i] == 7 - posicionMayor - 1)
			{
				cacho.dados[i] = posicionMayor + 1;
				maxVoltearDados--;
			}
		}
	}

	for (int i = 0; i < NUMERO_DADOS; i++)
	{
		if (maxVoltearDados != 0)
		{
			if (cacho.dados[i] == 7 - posicionSegundoMayor - 1)
			{
				cacho.dados[i] = posicionSegundoMayor + 1;
				maxVoltearDados--;
			}
		}
	}


	cout << "                           ";
	for (int i = 0; i < NUMERO_DADOS; i++) {
		cout << " " << cacho.dados[i] << " ";
	}
	cout << endl;



	//ANOTAR

	//GRANDE
	if ((jugador2.tablero.grandes[0] == -1 or jugador2.tablero.grandes[1] == -1) and verificarGrande(2) != 0)
	{
		aux = verificarGrande(2);
		if (jugador2.tablero.grandes[0] == -1)
		{
			jugador2.tablero.grandes[0] = aux;
		}
		else
		{
			jugador2.tablero.grandes[1] = aux;
		}
		return; 
	}

	//POKER
	if (jugador2.tablero.casilla[2][1] == -1 and contarPoker(2) != 0)
	{
		aux = contarPoker(2);
		jugador2.tablero.casilla[2][1] = aux;
		return;
	}


	//FULL
	if (jugador2.tablero.casilla[1][1] == -1 and contarFull(2) != 0 )
	{
		aux = contarFull(2);
		jugador2.tablero.casilla[1][1] = aux;
		return;
	}


	//ESCALERA 

	if (jugador2.tablero.casilla[0][1] == -1 and contarEscalera(2) != 0)
	{
		aux = contarEscalera(2);
		jugador2.tablero.casilla[0][1] = aux;
		return;
	}


	//NUMERICO MEJOR OPCION 
	//6
	if (jugador2.tablero.casilla[2][2] == -1 and ((posicionMayor + 1) == 6))
	{
		aux = contarPuntos(6);
		jugador2.tablero.casilla[2][2] = aux;
		return;
	}
	//5
	if (jugador2.tablero.casilla[1][2] == -1 and ((posicionMayor + 1) == 5))
	{
		aux = contarPuntos(5);
		jugador2.tablero.casilla[1][2] = aux;
		return;
	}
	//4
	if (jugador2.tablero.casilla[0][2] == -1 and ((posicionMayor + 1) == 4))
	{
		aux = contarPuntos(4);
		jugador2.tablero.casilla[0][2] = aux;
		return;
	}
	//3
	if (jugador2.tablero.casilla[2][0] == -1 and ((posicionMayor + 1) == 3))
	{
		aux = contarPuntos(3);
		jugador2.tablero.casilla[2][0] = aux;
		return;
	}
	//2
	if (jugador2.tablero.casilla[1][0] == -1 and ((posicionMayor + 1) == 2))
	{
		aux = contarPuntos(2);
		jugador2.tablero.casilla[1][0] = aux;
		return;
	}
	//1
	if (jugador2.tablero.casilla[0][0] == -1 and ((posicionMayor + 1) == 1))
	{
		aux = contarPuntos(1);
		jugador2.tablero.casilla[0][0] = aux;
		return;
	}


	//NUMERICO SEGUNDA MEJOR OPCION	
	//6
	if (jugador2.tablero.casilla[2][2] == -1 and ((posicionSegundoMayor + 1) == 6))
	{
		aux = contarPuntos(6);
		jugador2.tablero.casilla[2][2] = aux;
		return;
	}
	//5
	if (jugador2.tablero.casilla[1][2] == -1 and ((posicionSegundoMayor + 1) == 5))
	{
		aux = contarPuntos(5);
		jugador2.tablero.casilla[1][2] = aux;
		return;
	}
	//4
	if (jugador2.tablero.casilla[0][2] == -1 and ((posicionSegundoMayor + 1) == 4))
	{
		aux = contarPuntos(4);
		jugador2.tablero.casilla[0][2] = aux;
		return;
	}
	//3
	if (jugador2.tablero.casilla[2][0] == -1 and ((posicionSegundoMayor + 1) == 3))
	{
		aux = contarPuntos(3);
		jugador2.tablero.casilla[2][0] = aux;
		return;
	}
	//2
	if (jugador2.tablero.casilla[1][0] == -1 and ((posicionSegundoMayor + 1) == 2))
	{
		aux = contarPuntos(2);
		jugador2.tablero.casilla[1][0] = aux;
		return;
	}
	//1
	if (jugador2.tablero.casilla[0][0] == -1 and ((posicionSegundoMayor + 1) == 1))
	{
		aux = contarPuntos(1);
		jugador2.tablero.casilla[0][0] = aux;
		return;
	}



	//NUMERICO TERCERA MEJOR OPCION	
//6
	if (jugador2.tablero.casilla[2][2] == -1 and ((posicionTercerMayor + 1) == 6))
	{
		aux = contarPuntos(6);
		jugador2.tablero.casilla[2][2] = aux;
		return;
	}
	//5
	if (jugador2.tablero.casilla[1][2] == -1 and ((posicionTercerMayor + 1) == 5))
	{
		aux = contarPuntos(5);
		jugador2.tablero.casilla[1][2] = aux;
		return;
	}
	//4
	if (jugador2.tablero.casilla[0][2] == -1 and ((posicionTercerMayor + 1) == 4))
	{
		aux = contarPuntos(4);
		jugador2.tablero.casilla[0][2] = aux;
		return;
	}
	//3
	if (jugador2.tablero.casilla[2][0] == -1 and ((posicionTercerMayor + 1) == 3))
	{
		aux = contarPuntos(3);
		jugador2.tablero.casilla[2][0] = aux;
		return;
	}
	//2
	if (jugador2.tablero.casilla[1][0] == -1 and ((posicionTercerMayor + 1) == 2))
	{
		aux = contarPuntos(2);
		jugador2.tablero.casilla[1][0] = aux;
		return;
	}
	//1
	if (jugador2.tablero.casilla[0][0] == -1 and ((posicionTercerMayor + 1) == 1))
	{
		aux = contarPuntos(1);
		jugador2.tablero.casilla[0][0] = aux;
		return;
	}


	//EMPEZAR A BORRAR

	//1
	if (jugador2.tablero.casilla[0][0] == -1)
	{
		aux = contarPuntos(1);
		jugador2.tablero.casilla[0][0] = aux;
		return;
	}

	//2
	if (jugador2.tablero.casilla[1][0] == -1)
	{
		aux = contarPuntos(2);
		jugador2.tablero.casilla[1][0] = aux;
		return;
	}

	//3
	if (jugador2.tablero.casilla[2][0] == -1)
	{
		aux = contarPuntos(3);
		jugador2.tablero.casilla[2][0] = aux;
		return;
	}

	//4
	if (jugador2.tablero.casilla[0][2] == -1)
	{
		aux = contarPuntos(4);
		jugador2.tablero.casilla[0][2] = aux;
		return;
	}

	//5
	if (jugador2.tablero.casilla[1][2] == -1)
	{
		aux = contarPuntos(5);
		jugador2.tablero.casilla[1][2] = aux;
		return;
	}

    //6
	if (jugador2.tablero.casilla[2][2] == -1)
	{
		aux = contarPuntos(6);
		jugador2.tablero.casilla[2][2] = aux;
		return;
	}

	//ESCALERA 

	if (jugador2.tablero.casilla[0][1] == -1)
	{
		aux = contarEscalera(2);
		jugador2.tablero.casilla[0][1] = aux;
		return;
	}

	//FULL
	if (jugador2.tablero.casilla[1][1] == -1)
	{
		aux = contarFull(2);
		jugador2.tablero.casilla[1][1] = aux;
		return;
	}

	//POKER
	if (jugador2.tablero.casilla[2][1] == -1)
	{
		aux = contarPoker(2);
		jugador2.tablero.casilla[2][1] = aux;
		return;
	}


	//GRANDE
	if (jugador2.tablero.grandes[0] == -1 or jugador2.tablero.grandes[1] == -1)
	{
		aux = verificarGrande(2);
		if (jugador2.tablero.grandes[0] == -1)
		{
			jugador2.tablero.grandes[0] = aux;
		}
		else
		{
			jugador2.tablero.grandes[1] = aux;
		}
		return;
	}
}



void jugarContraUnJugador(bool turnoJugador1, int turno)
{
	int option;
	char tecla;

	while (turno < 22)
	{
			if (turnoJugador1 == true)
			{
				system("cls");
				dibujarTablero();
				cout << "                           ";
				for (int i = 0; i < NUMERO_DADOS; i++) {
					cacho.dados[i] = 1 + rand() % (6);
					cout << " " << cacho.dados[i] << " ";
				}

				cout << "\nQue desea hacer?: " << endl;
				cout << " 1. Introducir dados. " << endl;
				cout << " 2. Anotar : ";
				cin >> option;

				switch (option) {
				case 1:
					tirarDeNuevo();
					voletarDados();
					anotar(&jugador1, 2);
					break;
				case 2:
					anotar(&jugador1, 1);
					break;
				}
				turnoJugador1 = false;
				jugador1.numeroDeTurno = jugador1.numeroDeTurno + 1;
			}
			else
			{
				system("cls");
				dibujarTablero();
				cout << "                                                                         ";
				for (int i = 0; i < NUMERO_DADOS; i++) {
					cacho.dados[i] = 1 + rand() % (6);
					cout << " " << cacho.dados[i] << " ";
				}

				cout << "\nQue desea hacer?: " << endl;
				cout << " 1. Introducir dados. " << endl;
				cout << " 2. Anotar : ";
				cin >> option;

				switch (option) {
				case 1:
					tirarDeNuevo();
					voletarDados();
					anotar(&jugador2, 2);
					break;
				case 2:
					anotar(&jugador2, 1);
					break;
				}
				jugador2.numeroDeTurno = jugador2.numeroDeTurno + 1;
				turnoJugador1 = true;
		
			}
			turno++;
	}
	anunciarGanador();
}




void jugarContraMaquina(bool turnoJugador1, int turno)
{
	
	int option, resultado;
	char tecla;
	while (turno < 22)
	{
	
			if (turnoJugador1 == true)
			{
				system("cls");
				dibujarTablero();
				cout << "                           ";
				for (int i = 0; i < NUMERO_DADOS; i++) {
					cacho.dados[i] = 1 + rand() % (6);
					cout << " " << cacho.dados[i] << " ";
				}

				cout << "\nQue desea hacer?: " << endl;
				cout << " 1. Introducir dados. " << endl;
				cout << " 2. Anotar : ";
				cin >> option;

				switch (option) {
				case 1:
					tirarDeNuevo();
					voletarDados();
					anotar(&jugador1, 2);
					break;
				case 2:
					anotar(&jugador1, 1);
					break;
				}
				turnoJugador1 = false;
				jugador1.numeroDeTurno = jugador1.numeroDeTurno + 1;
			}
			else
			{
				system("cls");
				dibujarTablero();
				cout << "                                                                         ";
				for (int i = 0; i < NUMERO_DADOS; i++) {
					cacho.dados[i] = 1 + rand() % (6);
					cout << " " << cacho.dados[i] << " ";
				}

				// VERIFICAR DORMIDA
				if (verificarGrande(1) != 0)
				{
					anunciarGanadorDormida(&jugador2);

				}

				//VERFICAR ESCALERA DE MANO
				resultado = contarEscalera(1);
				if (jugador2.tablero.casilla[0][1] == -1)
				{
					if (resultado != 0)
					{
						jugador2.tablero.casilla[0][1] = resultado;
						continue;
					}
				}

				//VERIFICAR FULL DE MANO
				resultado = contarFull(1);
				if (jugador2.tablero.casilla[1][1] == -1)
				{
					if (resultado != 0)
					{
						jugador2.tablero.casilla[1][1] = resultado;
						continue;
					}
				}

				//VERIFICAR POKER DE MANO
				resultado = contarPoker(1);
				if (jugador2.tablero.casilla[2][1] == -1)
				{
					if (resultado != 0)
					{
						jugador2.tablero.casilla[2][1] = resultado;
						continue;
					}
				}


				cout << endl;
				cout << " ELIGIENDO Y VOLVIENDO A TIRAR LOS DADOS:... " << endl;

				decidirDadosIntroducir();
				system("pause");
				cout << " ELIGIENDO Y VOLTEANDO LOS DADOS:... " << endl;

				decidirDadosVoltear();
				system("pause");
				cout << endl;
				cout << endl;



				/*switch (option) {
				case 1:
					tirarDeNuevo();
					voletarDados();
					anotar(&jugador2, 2);
					break;
				case 2:
					anotar(&jugador2, 1);
					break;
				}*/
				turnoJugador1 = true;
				jugador2.numeroDeTurno = jugador2.numeroDeTurno + 1;
			}
			turno++;
	}
	anunciarGanador();
}



void menu() {
	int option;

	do {
		system("cls");
		cout << "                                          BIENVENIDOS A CACHO ALALAY !!!                                      " << endl;
		cout << " 1. Jugar contra un jugador" << endl;
		cout << " 2. Jugar contra la maquina" << endl;
		cout << " 3. Cargar juego" << endl;
		cout << " 0. Salir" << endl;
		cin >> option;


		switch (option) {
		case 1:
			system("cls");
			cout << "Ingrese el nombre del JUGADOR 1: ";
			cin >> jugador1.nombre;
			cout << "Ingrese el nombre del JUGADOR 2: ";
			cin >> jugador2.nombre;
			jugarContraUnJugador(true,0);
			break;
		case 2:
			system("cls");
			cout << "Ingrese el nombre del JUGADOR: ";
			cin >> jugador1.nombre;
			jugador2.nombre = "MAQUINA";
			jugarContraMaquina(true,0);
			//jugarContraMaquinaPrueba();
			break;
		case 3:
			cargarPartida();
			break;
		default:
			break;
		}
	} while (option != 0);


}


int main() {
	//dibujarTablero();
	srand(time(NULL));
	llenarTablero();
	menu();
}

