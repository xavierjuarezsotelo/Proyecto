#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define izquierda 75
#define derecha 77
using namespace std;
//Metodo para moverse
void gotoxy(int x, int y){
    HANDLE consola;
    consola = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X =x;
    pos.Y = y;
    SetConsoleCursorPosition(consola,pos);

}
//Metodo para ocultar el parpadeo del cursor
void cursor_ocultar(){
    HANDLE consola;
    consola = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO c;
    c.dwSize=1;
    c.bVisible = false;
    SetConsoleCursorInfo(consola,&c);
}
//Clase para crear la nave
class nave{
    int x,y;
public:
    nave(int x_, int y_): x(x_),y(y_){}
    void crear();
    void borrador();
    void mover();
};


//Crea la nave
void nave::crear(){
    gotoxy(x,y);  printf("  %c",94);
    gotoxy(x,y+1);printf(" %c%c%c",40,238,41);
    gotoxy(x,y+2);printf("  %c",176);
}
//Borra el rastro de la nave
void nave::borrador(){
    gotoxy(x,y);printf("   ");
    gotoxy(x,y+1);printf("    ");
    gotoxy(x,y+2);printf("   ");

}
void nave::mover(){
    //Detecta si se ha presionado una tecla, sirve para moverse
        if(kbhit()){
            char tecla = getch();
            borrador();
            //Compara la variable tecla para determinar hacia donde se mueve flecha izquierda = izquierda flecha derecha =Derecha
            if(tecla==izquierda && x>5){
                x-=3;
            }
            if(tecla==derecha && x<69){
                x+=3;
            }
            crear();
        }
}
//Crea los bordes y esquinas
void limites(){
    for(int i=2;i<78;i++){
        gotoxy(i,3);printf("%c",205);
        gotoxy(i,33);printf("%c",205);
    }
    for(int i=4;i<33;i++){
        gotoxy(2,i);printf("%c",186);
        gotoxy(77,i);printf("%c",186);
    }
    gotoxy(2,3);printf("%c",201);
    gotoxy(2,33);printf("%c",200);
    gotoxy(77,3);printf("%c",187);
    gotoxy(77,33);printf("%c",188);
}

int main()
{
    limites();
    cursor_ocultar();
    //Crear el objeto
    nave ob(38,27);
    //Llamar a los metodos de la clase
    ob.crear();
    //Hace que el juego se siga ejecutando
    bool fin = false;
    while(!fin){
        ob.mover();
        Sleep(30);

    }
    return 0;
}
