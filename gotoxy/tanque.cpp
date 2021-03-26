#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <ctime>
#include <cstdlib>


//Flechas direccionales
/*
#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77
*/


//Caracteres i, j, k, l

#define ARRIBA 'i'       // 105
#define ABAJO 'k'        // 106
#define IZQUIERDA 'j'    // 107
#define DERECHA 'l'      // 108



#define DISPARA_ENEMIGO 'm'      // 109   Dispara enemigo
#define DISPARA ' '    // 32  Disparo yo :D

/*
// Bordes exactos
#define LIMITE_SUPERIOR 1
#define LIMITE_INFERIOR 25
#define LIMITE_DERECHO 80
#define LIMITE_IZQUIERDO 1
*/

/*
#define LIMITE_SUPERIOR 1
#define LIMITE_INFERIOR 24
#define LIMITE_DERECHO 70
#define LIMITE_IZQUIERDO 20
*/
#define LIMITE_SUPERIOR 2
#define LIMITE_INFERIOR 23
#define LIMITE_DERECHO 70
#define LIMITE_IZQUIERDO 20

#define VIDAS 5
#define MAX_BALAS 100
#define CARACTER_BALA 158

//#define CARACTER_TANQUE 219
#define CARACTER_TANQUE 219
#define CARACTER_ENEMIGO 178

#define CANTIDAD_TIEMPO 2000

void pintar_bordes();

using namespace std;

class TANQUE;

class TIEMPO {
private:
   int tiempo;
public:
   TIEMPO(int);
   void muestra_tiempo();
   int getTiempo();
};

TIEMPO::TIEMPO(int tiempo) { this->tiempo = tiempo; }

int TIEMPO::getTiempo() { return tiempo; }

void TIEMPO::muestra_tiempo() {
   gotoxy(60, 1); printf("%5d", tiempo);
   tiempo--;
}

class BALA {
private:
	int x, y;	// Coordenadas
	int direccion;
	TANQUE *t;
	bool estado;      // vivo o muerto
public:
   BALA(int, int, int);
	int getX();
	int getY();
	// void setDireccion(int direccion);
	bool getEstado();
	void setEstado(bool);
   void morir();
	void pintar();
	void mover();
	void borrar();
};

// Al momento de su creación, la bala tiene una dirección predeterminada
BALA::BALA(int x, int y, int direccion) {
    this->x = x;
    this->y = y;
    this->direccion = direccion;
    this->estado = true;
}

/*
void BALA::setDireccion(int direccion) {
    this->direccion = direccion;
}
*/

int BALA::getX() { return x; }
int BALA::getY() { return y; }

void BALA::pintar() {
   if (!getEstado()) return;
   // gotoxy(x, y); printf("%c", 94);
   // gotoxy(x, y); printf("*");
   gotoxy(x, y); textcolor(LIGHTRED); printf("%c", CARACTER_BALA); textcolor(LIGHTGRAY);
}

void BALA::borrar() {
   gotoxy(x, y); printf(" ");
}

void BALA::mover() {
   borrar();

   if (direccion == ARRIBA && y >= LIMITE_SUPERIOR + 1) {
      if (y == LIMITE_SUPERIOR + 1) {
         /*
         y = t->getY() + 1;
         x = t->getX() + 1;
         */
         estado = false;
      } else {
         y--;
      }
   }

   if (direccion == ABAJO && y <= LIMITE_INFERIOR - 1) {
      if (y == LIMITE_INFERIOR - 1) {
         /*
         y = t->getY() + 1;
         x = t->getX() + 1;
         */
         estado = false;
      } else {
         y++;
      }
   }

   if (direccion == IZQUIERDA && x >= LIMITE_IZQUIERDO + 1) {
      if (x == LIMITE_IZQUIERDO + 1) {
         /*
         x =  t->getX() + 1;
         y = t->getY() + 1;
         */
         estado = false;
      } else {
         x--;
      }
   }

   if (direccion == DERECHA && x <= LIMITE_DERECHO - 1) {
      if (x == LIMITE_DERECHO - 1) {
         /*
         x =  t->getX() + 1;
         y = t->getY() + 1;
         */
         estado = false;
      } else {
         x++;
      }
   }

   if (estado) pintar(); // Pinto en su nueva posición
}

bool BALA::getEstado() {
   return estado;
}

void BALA::setEstado(bool estado) {
   this->estado = estado;
}

class TANQUE {
private:
	int x, y;	// Coordenadas
   int direccion;
   int puntaje;
   int vida;
   int max_balas;
public:
   vector <BALA *> balas;
	TANQUE(int, int);
	int getX();
	int getY();
	int getMax_balas();
	int getVida();
	void setVida(int);
	int getPuntaje();
	void setPuntaje(int);
	void setX(int);
   void setY(int);
	void setDireccion(int);
	int getDireccion();
	void pintar();
	void pintarArriba();
	void pintarAbajo();
	void pintarIzquierda();
	void pintarDerecha();
	void pintarVidaPuntaje();
	void borrar();
	void mover();
	void mover_balas();
	void morir(BALA *bala);
	int getNumeroBalas();
};

TANQUE::TANQUE(int x, int y) {
   this->x = x;
   this->y = y;
   direccion = ARRIBA;
   vida = VIDAS;
   puntaje = 0;
   max_balas = MAX_BALAS;
}

int TANQUE::getX() {
	return x;
}

int TANQUE::getY() {
	return y;
}

int TANQUE::getMax_balas() {
   return max_balas;
}

void TANQUE::setX(int x) {
   this->x = x;
}

void TANQUE::setY(int y) {
   this->y = y;
}

int TANQUE::getPuntaje() {
   return puntaje;
}

void TANQUE::setPuntaje(int puntaje) {
   this->puntaje = (puntaje >= 0) ? puntaje : 0;
}

int TANQUE::getVida() {
   return vida;
}

void TANQUE::setVida(int vida) {
   this->vida = (vida >= 0) ? vida : 3;
}

void TANQUE::setDireccion(int direccion) {
   if (direccion == ARRIBA || direccion == ABAJO || direccion == IZQUIERDA || direccion == DERECHA) {
      this->direccion = direccion;
   }
}

int TANQUE::getDireccion() {
    return direccion;
}

void TANQUE::pintarArriba() {
	gotoxy(x, y); printf(" %c", CARACTER_TANQUE);
	gotoxy(x, y + 1);	printf("%c%c%c", CARACTER_TANQUE, CARACTER_TANQUE, CARACTER_TANQUE);
	gotoxy(x, y + 2);	printf("%c %c", CARACTER_TANQUE, CARACTER_TANQUE);
}

void TANQUE::pintarAbajo() {
	gotoxy(x, y);	printf("%c %c", CARACTER_TANQUE, CARACTER_TANQUE);
	gotoxy(x, y + 1); printf("%c%c%c", CARACTER_TANQUE, CARACTER_TANQUE, CARACTER_TANQUE);
	gotoxy(x, y + 2); printf(" %c ", CARACTER_TANQUE);
}

void TANQUE::pintarDerecha() {
   gotoxy(x, y); printf("%c%c", CARACTER_TANQUE, CARACTER_TANQUE);
	gotoxy(x, y + 1); printf(" %c%c", CARACTER_TANQUE, CARACTER_TANQUE);
	gotoxy(x, y + 2);	printf("%c%c", CARACTER_TANQUE, CARACTER_TANQUE);
}

void TANQUE::pintarIzquierda() {
	gotoxy(x, y); printf(" %c%c", CARACTER_TANQUE, CARACTER_TANQUE);
	gotoxy(x, y + 1); printf("%c%c", CARACTER_TANQUE, CARACTER_TANQUE);
	gotoxy(x, y + 2);	printf(" %c%c", CARACTER_TANQUE, CARACTER_TANQUE);
}

void TANQUE::pintarVidaPuntaje() {
   gotoxy(1, 2); cout << "Vida: " << getVida();
   gotoxy(1, 3); cout << "Puntaje: " << getPuntaje();
}

void TANQUE::pintar() {
   switch(direccion) {
      case ARRIBA:
         pintarArriba();
         break;
      case ABAJO:
         pintarAbajo();
         break;
      case IZQUIERDA:
         pintarIzquierda();
         break;
      case DERECHA:
         pintarDerecha();
         break;
   }
   /* Pinta el corazon del tanque de algún color*/
   gotoxy(x + 1, y + 1);
   textcolor(LIGHTRED); textbackground(YELLOW); cprintf("%c", 76); textcolor(LIGHTGRAY); textbackground(BLACK);
   this->pintarVidaPuntaje();
}

void TANQUE::borrar() {
   gotoxy(x, y); printf("   ");
   gotoxy(x, y + 1); printf("   ");
   gotoxy(x, y + 2); printf("   ");
}

void TANQUE::mover() {
   if (kbhit()) {
      char tecla = getch();

      borrar();
      /*
      if (tecla == IZQUIERDA) x--;
      if (tecla == DERECHA) x++;
      if (tecla == ABAJO) y++;
      if (tecla == ARRIBA) y--;
      */
      if (tecla == IZQUIERDA) {
         if (direccion == IZQUIERDA) // Para que solo avance si estaba en esa direccion, sino solo voltee sobre su sitio
            if (x > LIMITE_IZQUIERDO + 1) x--;
      }

      if (tecla == DERECHA) {
         if (direccion == DERECHA)
            if ((x + 2) < LIMITE_DERECHO - 1) x++;
      }

      if (tecla == ABAJO) {
         if (direccion == ABAJO)
            if ((y + 2) < LIMITE_INFERIOR - 1)y++;
      }

      if (tecla == ARRIBA) {
         if (direccion == ARRIBA)
            if (y > LIMITE_SUPERIOR + 1) y--;
      }

      if (tecla == DISPARA) {

         // Darle un límite de 10 balas a nuestro tanque
         if (/*multibala == false && */balas.size() >= max_balas) return;


         /*
         */
         BALA *b;
         do {
            b = new BALA(this->x + 1, this->y + 1, this->direccion);
            //
            if (b == NULL) {

               gotoxy(x, y); cout << "NO SE PUDO OBTENER MEMORIA";
               system("pause>nul");
               system("pause>nul");
               system("pause>nul");
               system("pause>nul");
            }
            //
         } while (b ==NULL);
         balas.push_back(b); // Creamos dinámicamente la bala

         //balas.push_back(new BALA(this->x + 1, this->y + 1, this->direccion)); // Creamos dinámicamente la bala

         // NUMERO DE BALA DISPARADA
         int i = balas.size();
         gotoxy(1, 15); printf("Bala #: %2d", i - 1);
         // NUMERO DE BALA DISPARADA
      } else {
         setDireccion(tecla);
      }
      // pintar();
   }
}

// Mueve todas las balas y también las elimina de la memoria
void TANQUE::mover_balas() {
   // Hay que volver a pintar el tanque
   this->pintar();

   // Mover a todas las balas
   /* Esta forma de eliminar los punteros a balas del vector de balas es incorrecta
   for (int i = 0; i < balas.size(); ++i) {
      balas[i]->mover();
      this->pintar(); // Para que el tanque no desaparezca tanto tiempo mientras disparo bala como loco xD
      if (balas[i]->getEstado() == false) {  // Si la bala está muerta
         balas[i]->borrar(); // Borramos la bala para que desaparezca de la ventana
         delete (balas[i]);                // Borramos la bala creada dinámicamente de la memoria
         balas.erase(balas.begin() + i);     // Borramos la bala i del vector de balas
      }
   }
   */
   for (int i = 0; i < balas.size(); ++i) {
      balas[i]->mover();
      this->pintar(); // Para que el tanque no desaparezca tanto tiempo mientras disparo bala como loco xD
      if (balas[i]->getEstado() == false) {  // Si la bala está muerta
         balas[i]->borrar(); // Borramos la bala para que desaparezca de la ventana
         delete (balas[i]);                // Borramos la bala creada dinámicamente de la memoria
         balas[i] = NULL; // Marcamos las balas a borrar
      }
   }

   int i = 0;
   while (i < balas.size()) {
      if (balas[i] == NULL) {
         balas.erase(balas.begin() + i);
      } else {
         ++i;
      }
   }
}

void TANQUE::morir(BALA *bala) {
   borrar();
   cout << "\a";

   borrar();
   textcolor(WHITE);
   gotoxy(x, y);     cprintf("* *");
   gotoxy(x, y + 1); cprintf(" *");
   gotoxy(x, y + 2); cprintf("* *");
   Sleep(100);


   borrar();   // Borra el tanque
   textcolor(LIGHTGRAY);
   gotoxy(x, y);     cprintf(" * ");
   gotoxy(x, y + 1); cprintf("***");
   gotoxy(x, y + 2); cprintf(" * ");
   Sleep(100);

   borrar();
   textcolor(WHITE);
   gotoxy(x, y);     cprintf("* *");
   gotoxy(x, y + 1); cprintf(" *");
   gotoxy(x, y + 2); cprintf("* *");
   Sleep(100);

   borrar();   // Borra el tanque
   textcolor(LIGHTGRAY);
   gotoxy(x, y);     cprintf(" * ");
   gotoxy(x, y + 1); cprintf("***");
   gotoxy(x, y + 2); cprintf(" * ");
   Sleep(100);

   borrar();   // Borra el tanque
   textcolor(WHITE);
   gotoxy(x, y);     cprintf(" * ");
   gotoxy(x, y + 1); cprintf("***");
   gotoxy(x, y + 2); cprintf(" * ");
   Sleep(100);

   borrar();
   textcolor(LIGHTGRAY);
   bala->setEstado(false);
   /*
   setX(LIMITE_DERECHO + LIMITE_IZQUIERDO / 2);
   setY(LIMITE_INFERIOR + LIMITE_SUPERIOR / 2);
   */

   // Puntaje disminuye
   this->setVida(this->getVida() - 1);
}

int TANQUE::getNumeroBalas() {
   return balas.size();
}

/* TANQUE ENEMIGO */
class TANQUE_ENEMIGO {
private:
	int x, y;	// Coordenadas
   int direccion;
   bool estado;
   bool multibala;

public:
   vector <BALA *> balas;
	TANQUE_ENEMIGO(int, int, bool MULTIVALA);
	int getX();
	int getY();
	void setDireccion(int);
	int getDireccion();
	void pintar();
	void pintarArriba();
	void pintarAbajo();
	void pintarIzquierda();
	void pintarDerecha();
	void borrar();
	void mover();
	void choque();
	void mover_balas();
	void genera_movimiento();
	void morir(BALA *);
};

TANQUE_ENEMIGO::TANQUE_ENEMIGO(int x, int y, bool multibala) {
   this->x = x;
   this->y = y;
   direccion = ARRIBA;
   estado = true;
   this->multibala = multibala;
}

int TANQUE_ENEMIGO::getX() {
	return x;
}

int TANQUE_ENEMIGO::getY() {
	return y;
}

void TANQUE_ENEMIGO::setDireccion(int direccion) {
   if (direccion == ARRIBA || direccion == ABAJO || direccion == IZQUIERDA || direccion == DERECHA) {
      this->direccion = direccion;
   }
}

int TANQUE_ENEMIGO::getDireccion() {
    return direccion;
}

void TANQUE_ENEMIGO::pintarArriba() {
	gotoxy(x, y); printf(" %c", CARACTER_ENEMIGO);
	gotoxy(x, y + 1);	printf("%c%c%c", CARACTER_ENEMIGO, CARACTER_ENEMIGO, CARACTER_ENEMIGO);
	gotoxy(x, y + 2);	printf("%c %c", CARACTER_ENEMIGO, CARACTER_ENEMIGO);
}

void TANQUE_ENEMIGO::pintarAbajo() {
	gotoxy(x, y);	printf("%c %c", CARACTER_ENEMIGO, CARACTER_ENEMIGO);
	gotoxy(x, y + 1); printf("%c%c%c", CARACTER_ENEMIGO, CARACTER_ENEMIGO, CARACTER_ENEMIGO);
	gotoxy(x, y + 2); printf(" %c ", CARACTER_ENEMIGO);
}

void TANQUE_ENEMIGO::pintarDerecha() {
   gotoxy(x, y); printf("%c%c", CARACTER_ENEMIGO, CARACTER_ENEMIGO);
	gotoxy(x, y + 1); printf(" %c%c", CARACTER_ENEMIGO, CARACTER_ENEMIGO);
	gotoxy(x, y + 2);	printf("%c%c", CARACTER_ENEMIGO, CARACTER_ENEMIGO);
}

void TANQUE_ENEMIGO::pintarIzquierda() {
	gotoxy(x, y); printf(" %c%c", CARACTER_ENEMIGO, CARACTER_ENEMIGO);
	gotoxy(x, y + 1); printf("%c%c", CARACTER_ENEMIGO, CARACTER_ENEMIGO);
	gotoxy(x, y + 2);	printf(" %c%c", CARACTER_ENEMIGO, CARACTER_ENEMIGO);
}

void TANQUE_ENEMIGO::pintar() {
   switch(direccion) {
      case ARRIBA:
         pintarArriba();
         break;
      case ABAJO:
         pintarAbajo();
         break;
      case IZQUIERDA:
         pintarIzquierda();
         break;
      case DERECHA:
         pintarDerecha();
         break;
   }
   /* Pinta el corazon del tanque de algún color*/
   gotoxy(x + 1, y + 1);
   textcolor(LIGHTRED); textbackground(LIGHTBLUE); cprintf("%c", 69); textcolor(LIGHTGRAY); textbackground(BLACK);
}

void TANQUE_ENEMIGO::borrar() {
   gotoxy(x, y); printf("   ");
   gotoxy(x, y + 1); printf("   ");
   gotoxy(x, y + 2); printf("   ");
}

void TANQUE_ENEMIGO::mover() {
   int I, U;
   /*
   I = ARRIBA;
   U = DISPARA;
   */

   /*
   Los números aleatorios que se generan varían en el rango de [I , U]
   I = ARRIBA - 5
   U = ABAJO + 5
   Cuando ARRIBA, ABAJO, IZQUIERDA y DERECHA son:
                                                      ARRIBA 72
                                                      ABAJO 80
                                                      IZQUIERDA 75
                                                      DERECHA 77
                                                      DISPARA_ENEMIGO
         ========> I = 72 - 5
         ========> U = 80 + 5
    Cuando ARRIBA, ABAJO, IZQUIERDA y DERECHA son:
                                                      ARRIBA 'i'               105
                                                      ABAJO  'k'               107
                                                      IZQUIERDA 'j'            106
                                                      DERECHA   'l'            108
                                                      DISPARA_ENEMIGO   'm'    109
         ========> I = 105 - 5 = 100
         ========> U = 107 + 5 = 112
   */

   I = ARRIBA - 5;
   U = ABAJO + 5;

   int tecla = rand() % (U - I + 1) + I;
   //if (tecla == ABAJO || tecla == ARRIBA || tecla == IZQUIERDA
   //    || tecla == DERECHA || tecla == DISPARA) {

      borrar();
      /*
      if (tecla == IZQUIERDA) x--;
      if (tecla == DERECHA) x++;
      if (tecla == ABAJO) y++;
      if (tecla == ARRIBA) y--;
      */
      if (tecla == IZQUIERDA) {
         if (direccion == IZQUIERDA) // Para que solo avance si estaba en esa direccion, sino solo voltee sobre su sitio
            if (x > LIMITE_IZQUIERDO + 1) x--;
      }

      if (tecla == DERECHA) {
         if (direccion == DERECHA)
            if ((x + 2) < LIMITE_DERECHO - 1) x++;
      }

      if (tecla == ABAJO) {
         if (direccion == ABAJO)
            if ((y + 2) < LIMITE_INFERIOR - 1)y++;
      }

      if (tecla == ARRIBA) {
         if (direccion == ARRIBA)
            if (y > LIMITE_SUPERIOR + 1) y--;
      }

      if (tecla == DISPARA_ENEMIGO) { // Se crean las balas

         // El enemigo solo podrá lanzar muchas balas cuando multibala esté activado (true)
         // Si está desactivado, solo podrá lanzar una bala
         if (multibala == false && balas.size() > 0)
            return;// Solo dispara una bala

         balas.push_back(new BALA(this->x + 1, this->y + 1, this->direccion)); // Creamos dinámicamente la bala
      }

      setDireccion(tecla);
      pintar();
   //}
}

void TANQUE_ENEMIGO::mover_balas() {
   // Hay que volver a pintar el tanque
   this->pintar();

   // Mover a todas las balas
   for (int i = 0; i < balas.size(); ++i) {
      balas[i]->mover(); // Establece a false y pinta los true
      this->pintar(); // Para que el tanque no desaparezca tanto tiempo mientras disparo bala como loco xD
      if (!balas[i]->getEstado()) {  // Si la bala está muerta
         balas[i]->borrar(); // Borramos la bala para que desaparezca de la ventana (los que mataron a un tanque enemigo)
         delete (balas[i]);                // Borramos la bala de la memoria
         balas[i] = NULL; // Marcamos los punteros BALA * a borrar del vector
      }
   }

   int i = 0;
   while (i < balas.size()) {
      if (balas[i] == NULL) {
         balas.erase(balas.begin() + i);
      } else {
         ++i;
      }
   }
}

void TANQUE_ENEMIGO::morir(BALA *bala) {
   estado = false;

   cout << "\a";

   // Borra las balas de la pantalla
   for (int i = 0; i < balas.size(); ++i) {
      balas[i]->borrar();
   }
   // Borra todas sus balas de la memoria

   /* Esta forma de eliminar todas las balas de un tanque enemigo es incorrecta porque
      se debería hacer con el método clear
      for (int i = 0; i < balas.size(); ++i) {
         delete(balas[i]);
         balas.erase(balas.begin() + i);
      }
   */
   for (int i = 0; i < balas.size(); ++i) {
      delete(balas[i]);
   }
   this->balas.clear();

   borrar();
   gotoxy(x, y);     printf("* *");
   gotoxy(x, y + 1); printf(" *");
   gotoxy(x, y + 2); printf("* *");
   Sleep(50);


   borrar();   // Borra el tanque
   gotoxy(x, y);     printf(" * ");
   gotoxy(x, y + 1); printf("***");
   gotoxy(x, y + 2); printf(" * ");
   Sleep(50);

   borrar();   // Borra el tanque
   gotoxy(x, y);     printf(" * ");
   gotoxy(x, y + 1); printf("***");
   gotoxy(x, y + 2); printf(" * ");
   Sleep(50);

   borrar();
   // Establece a muerto a la bala que lo mató
   bala->setEstado(false);
}

// Pinta los bordes del escenario
void pintar_bordes()
{
   // Pinta borde superior e inferior
   for (int i = LIMITE_IZQUIERDO; i <= LIMITE_DERECHO; ++i) {
      gotoxy(i, LIMITE_SUPERIOR); printf("%c", 205);
      gotoxy(LIMITE_DERECHO - i + LIMITE_IZQUIERDO, LIMITE_INFERIOR); printf("%c", 205);
      Sleep(10);
   }

   for (int i = LIMITE_SUPERIOR; i <= LIMITE_INFERIOR; ++i) {
      gotoxy(LIMITE_IZQUIERDO, i); printf("%c", 186);
      gotoxy(LIMITE_DERECHO, LIMITE_INFERIOR - i + LIMITE_SUPERIOR); printf("%c", 186);
      Sleep(10);
   }

   // Esquinas
   gotoxy(LIMITE_IZQUIERDO, LIMITE_SUPERIOR); printf("%c", 201);
   gotoxy(LIMITE_DERECHO, LIMITE_SUPERIOR); printf("%c", 187);
   gotoxy(LIMITE_IZQUIERDO, LIMITE_INFERIOR); printf("%c", 200);
   gotoxy(LIMITE_DERECHO, LIMITE_INFERIOR); printf("%c", 188);
}

TANQUE tanque1((LIMITE_DERECHO + LIMITE_IZQUIERDO) / 2, (LIMITE_INFERIOR + LIMITE_SUPERIOR) / 2);






int main()
{
   pintar_bordes();

   TIEMPO tiempo(CANTIDAD_TIEMPO);

	// TANQUE tanque1(LIMITE_DERECHO - 3, LIMITE_INFERIOR - 3);
	tanque1.pintar();

	TANQUE_ENEMIGO tanque_enemigo1(LIMITE_IZQUIERDO + 1, LIMITE_SUPERIOR + 1, true);
	TANQUE_ENEMIGO tanque_enemigo2(LIMITE_DERECHO - 3, LIMITE_SUPERIOR + 1, true);
	TANQUE_ENEMIGO tanque_enemigo3(LIMITE_IZQUIERDO + 1, LIMITE_INFERIOR - 3, true);
	TANQUE_ENEMIGO tanque_enemigo4(LIMITE_DERECHO - 3, LIMITE_INFERIOR - 3, true);

	TANQUE_ENEMIGO tanque_enemigo5(LIMITE_IZQUIERDO + 7, LIMITE_SUPERIOR + 6, true);
	TANQUE_ENEMIGO tanque_enemigo6(LIMITE_DERECHO - 9, LIMITE_SUPERIOR + 5, true);
	TANQUE_ENEMIGO tanque_enemigo7(LIMITE_IZQUIERDO + 7, LIMITE_INFERIOR - 8, true);
	TANQUE_ENEMIGO tanque_enemigo8(LIMITE_DERECHO - 9, LIMITE_INFERIOR - 7, true);

	TANQUE_ENEMIGO tanque_enemigo9(LIMITE_IZQUIERDO + 13, LIMITE_SUPERIOR + 9, true);
	TANQUE_ENEMIGO tanque_enemigo10(LIMITE_DERECHO - 15, LIMITE_SUPERIOR + 9, true);
	TANQUE_ENEMIGO tanque_enemigo11(LIMITE_IZQUIERDO + 13, LIMITE_INFERIOR - 10, true);
	TANQUE_ENEMIGO tanque_enemigo12(LIMITE_DERECHO - 15, LIMITE_INFERIOR - 10, true);

	TANQUE_ENEMIGO tanque_enemigo13(LIMITE_IZQUIERDO + 19, LIMITE_SUPERIOR + 3, true);
	TANQUE_ENEMIGO tanque_enemigo14(LIMITE_DERECHO - 21, LIMITE_SUPERIOR + 15, true);
	TANQUE_ENEMIGO tanque_enemigo15(LIMITE_IZQUIERDO + 19, LIMITE_INFERIOR - 5, true);
	TANQUE_ENEMIGO tanque_enemigo16(LIMITE_DERECHO - 21, LIMITE_INFERIOR - 3, true);

   vector <TANQUE_ENEMIGO *> te;
   te.push_back(&tanque_enemigo1);
   te.push_back(&tanque_enemigo2);
   te.push_back(&tanque_enemigo3);
   te.push_back(&tanque_enemigo4);
   te.push_back(&tanque_enemigo5);
   te.push_back(&tanque_enemigo6);
   te.push_back(&tanque_enemigo7);
   te.push_back(&tanque_enemigo8);
   te.push_back(&tanque_enemigo9);
   te.push_back(&tanque_enemigo10);
   te.push_back(&tanque_enemigo11);
   te.push_back(&tanque_enemigo12);
   te.push_back(&tanque_enemigo13);
   te.push_back(&tanque_enemigo14);
   te.push_back(&tanque_enemigo15);
   te.push_back(&tanque_enemigo16);

   tiempo.muestra_tiempo();
	// while (1 &&) {
	while (tiempo.getTiempo() > 0) {


      /*********************BORRRRAR********/
      /*
      gotoxy(1, 10); clreol();
      gotoxy(1, 11); clreol();
      gotoxy(1, 12); clreol();
      gotoxy(1, 13); clreol();
      */
      /*******************************/



      tanque1.mover();
      tanque1.mover_balas();

      /*
      tanque_enemigo1.mover();
      tanque_enemigo1.mover_balas();
      tanque_enemigo2.mover();
      tanque_enemigo1.mover_balas();
      tanque_enemigo3.mover();
      tanque_enemigo3.mover_balas();
      tanque_enemigo4.mover();
      tanque_enemigo4.mover_balas();
      tanque_enemigo5.mover();
      tanque_enemigo5.mover_balas();
      */
      //  Moverlos a todos los tanques enemigos
      for (int i = 0; i < te.size(); ++i) {
         te[i]->mover();
         te[i]->mover_balas();
      }

      // Para ver si choca alguna bala con el tanque
      for (int i = 0; i < te.size(); ++i) {
         for (int j = 0; j < te[i]->balas.size(); ++j) {

            int x = te[i]->balas[j]->getX();
            int y = te[i]->balas[j]->getY();

            switch(tanque1.getDireccion()) {
               case DERECHA:
                  if (y == tanque1.getY() && (x == tanque1.getX() || x == tanque1.getX() + 1)
                      || y == tanque1.getY() + 1 && (x == tanque1.getX() + 1 || x == tanque1.getX() + 2)
                      || y == tanque1.getY() + 2 && (x == tanque1.getX() || x == tanque1.getX() + 1)) {
                     // Colisión
                     tanque1.morir(te[i]->balas[j]);
                  }
                  break;

               case IZQUIERDA:
                  if (y == tanque1.getY() && (x == tanque1.getX() + 1 || x == tanque1.getX() + 2)
                      || y == tanque1.getY() + 1 && (x == tanque1.getX() || x == tanque1.getX() + 1)
                      || y == tanque1.getY() + 2 && (x == tanque1.getX() + 1 || x == tanque1.getX() + 2)) {
                     // Colisión
                     tanque1.morir(te[i]->balas[j]);
                  }
                  break;

               case ARRIBA:
                  if (y == tanque1.getY() && x == tanque1.getX() + 1
                      || y == tanque1.getY() + 1 && (x >= tanque1.getX() && x <= tanque1.getX() + 2)
                      || y == tanque1.getY() + 2 && (x == tanque1.getX() || x == tanque1.getX() + 2)) {
                     // Colisión
                     tanque1.morir(te[i]->balas[j]);
                  }
                  break;

               case ABAJO:
                  if (y == tanque1.getY() && (x == tanque1.getX() || x == tanque1.getX() + 2)
                      || y == tanque1.getY() + 1 && (x >= tanque1.getX() && x <= tanque1.getX() + 2)
                      || y == tanque1.getY() + 2 && x == tanque1.getX() + 1) {
                     // Colisión
                     tanque1.morir(te[i]->balas[j]);
                  }
                  break;
            } // fin de switch
         } // fin for
      } // fin de for




// Versión 1
/************************************************************************************************************/
      // Para ver si choca mi conjunto de balas con algún tanque enemigo
      // Para ver si choca alguna bala con el tanque
      /* REVISAR EL PROBLEMA, PASA ALGO CON LAS BALAS*/
      /* LE PUSE LÍMITE DE BALAS Y AUN ASÍ, SIGUEN LOS PROBLEMAS, HAY QUE REVISAR*/
// /*
      // Recorrido por tanques enemigos
      for (int j = 0; j < te.size(); ++j) {
         int direccion_tanque_enemigo = te[j]->getDireccion();

         for (int i = 0; i < tanque1.balas.size(); ++i) { // Por balas
            int x = tanque1.balas[i]->getX(); // Coordenada x de mi bala actual
            int y = tanque1.balas[i]->getY(); // Coordenada y de mi bala actual

            switch (direccion_tanque_enemigo) {
               case DERECHA:
                  if (y == te[j]->getY() && (x == te[j]->getX() || x == te[j]->getX() + 1)
                      || y == te[j]->getY() + 1 && (x == te[j]->getX() + 1 || x == te[j]->getX() + 2)
                      || y == te[j]->getY() + 2 && (x == te[j]->getX() || x == te[j]->getX() + 1)) {
                     // Colisión

                     // BORRAR, SOLO PARA DEPURACION
                     // gotoxy(1, 10); cout << "Mato bala numero " << i; /////////
                     // BORRAR, SOLO PARA DEPURACION


                     te[j]->morir(tanque1.balas[i]);
                     // BORRAR, SOLO PARA DEPURACION
                     // gotoxy(1, 11); cout << "Murio tanque enemigo\nBala marcada para desaparecer"; /////////
                     // BORRAR, SOLO PARA DEPURACION


                     // El tanque que mate es eliminado del vector
                     te.erase(te.begin() + j);

                     // BORRAR, SOLO PARA DEPURACION
                     // gotoxy(1, 13); cout << "El tanque fue eliminado del vector"; /////////
                     // BORRAR, SOLO PARA DEPURACION


                     // Disminuye puntaje del tanque
                     tanque1.setPuntaje(tanque1.getPuntaje() + 1);

                     continue;
                  }
                  break;


               case IZQUIERDA:
                  if (y == te[j]->getY() && (x == te[j]->getX() + 1 || x == te[j]->getX() + 2)
                      || y == te[j]->getY() + 1 && (x == te[j]->getX() || x == te[j]->getX() + 1)
                      || y == te[j]->getY() + 2 && (x == te[j]->getX() + 1 || x == te[j]->getX() + 2)) {
                     // Colisión

                     // BORRAR, SOLO PARA DEPURACION
                     // gotoxy(1, 10); cout << "Mato bala numero " << i; /////////
                     // BORRAR, SOLO PARA DEPURACION

                     te[j]->morir(tanque1.balas[i]); // Llama al método morir del tanque enemigo y se marca la bala que lo mató
                     // BORRAR, SOLO PARA DEPURACION
                     // gotoxy(1, 11); cout << "Murio tanque enemigo\nBala marcada para desaparecer"; /////////
                     // BORRAR, SOLO PARA DEPURACION

                     // Es eliminado del vector
                     te.erase(te.begin() + j);

                     // BORRAR, SOLO PARA DEPURACION
                     // gotoxy(1, 13); cout << "El tanque enemigo fue eliminado del vector"; /////////
                     // BORRAR, SOLO PARA DEPURACION

                     tanque1.setPuntaje(tanque1.getPuntaje() + 1);

                     continue;
                  }
                  break;

               case ARRIBA:
                  if (y == te[j]->getY() && x == te[j]->getX() + 1
                      || y == te[j]->getY() + 1 && (x >= te[j]->getX() && x <= te[j]->getX() + 2)
                      || y == te[j]->getY() + 2 && (x == te[j]->getX() || x == te[j]->getX() + 2)) {
                     // Colisión

                     // BORRAR, SOLO PARA DEPURACION
                     // gotoxy(1, 10); cout << "Mato bala numero " << i; /////////
                     // BORRAR, SOLO PARA DEPURACION


                     te[j]->morir(tanque1.balas[i]);
                     // BORRAR, SOLO PARA DEPURACION
                     // gotoxy(1, 11); cout << "Murio tanque enemigo\nBala marcada para desaparecer"; /////////
                     // BORRAR, SOLO PARA DEPURACION


                     // Es eliminado del vector
                     te.erase(te.begin() + j);

                     // BORRAR, SOLO PARA DEPURACION
                     // gotoxy(1, 13); cout << "El tanque fue eliminado del vector"; /////////
                     // BORRAR, SOLO PARA DEPURACION

                     tanque1.setPuntaje(tanque1.getPuntaje() + 1);

                     continue;
                  }
                  break;

               case ABAJO:
                  if (y == te[j]->getY() && (x == te[j]->getX() || x == te[j]->getX() + 2)
                      || y == te[j]->getY() + 1 && (x >= te[j]->getX() && x <= te[j]->getX() + 2)
                      || y == te[j]->getY() + 2 && x == te[j]->getX() + 1) {
                     // Colisión

                     // BORRAR, SOLO PARA DEPURACION
                     // gotoxy(1, 10); cout << "Mato bala numero " << i; /////////
                     // BORRAR, SOLO PARA DEPURACION


                     te[j]->morir(tanque1.balas[i]);
                     // BORRAR, SOLO PARA DEPURACION
                     // gotoxy(1, 11); cout << "Murio tanque enemigo\nBala marcada para desaparecer"; /////////
                     // BORRAR, SOLO PARA DEPURACION


                     // Es eliminado del vector
                     te.erase(te.begin() + j);

                     // BORRAR, SOLO PARA DEPURACION
                     // gotoxy(1, 13); cout << "El tanque fue eliminado del vector"; /////////
                     // BORRAR, SOLO PARA DEPURACION

                     tanque1.setPuntaje(tanque1.getPuntaje() + 1);

                       continue;
                  }
                  break;

            } // fin de switch

         } // fin de for
      } // fin de while
// */