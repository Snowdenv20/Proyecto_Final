#include <librerias.h>
#include <time.h>
#include <fstream>
#include <ctype.h>
#include<iomanip>
char CT = 203, LTI = 204, H = 205, CRUZ = 206, CB = 202, TOPE = 201, EIA = 201, EIB = 200, LTD = 185, V = 186, EDA = 187, EDB = 188, P = 177;

#define HOR cout << H << H << H << H << H << H << H << H << H;
#define PUN cout << P << P << P << P << P << P << P << P << P << P;
#define VER cout << V;
#define separador2 cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;
#define ARAR cout << EIA << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDA << endl;
#define AREN cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;
#define ARENBJ cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;
#define ABJ cout << EIB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDB << endl;
#define arriba cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;
#define separador cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;
#define abajo cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;

struct Marcas
{
     int idMarca;
     char NombreMarca[50];
};
typedef Marcas Marca;

struct fecha
{
     int d, m, a, hh, mm, ss;
};
typedef fecha Fechas;

struct Productos
{
     int CodigoProducto, idMarca;
     char DescripcionProducto[100];
     double PrecioCosto, PrecioVenta;
     struct fecha FechaDeIngreso;
};
typedef Productos Producto;

struct Clientes
{
     char NIT[12];
     char NombreCliente[50], DireccionCliente[50];
};
typedef Clientes Cliente;

struct Facturas
{
     int NoFactura;
     char NITFactura[12];
     struct fecha FechaFactura;
};
typedef Facturas Factura;

struct FacturasDetalle
{
     int *idProductos, NoFactura, IdFacturaDetalle;
     double *PrecioVenta;
};
typedef FacturasDetalle FacturaDetalle;

//Variables Globales para la fecha y hora
time_t tSac = time(NULL);
struct tm *tmP = localtime(&tSac);
char opc;          //opciones de funciones del do while
bool real = false; //Verificacion de nit
int IA = 0;        //Incremento Automatico XD
//Prototipos de Funciones Del Programa
void MenuPrincipal();
bool VerificadorDeNumeros(string);
void Minusculas(string &);
void MenuMarcas();
void IngresoDeMarcas();
void MostrarMarcas();
void ModificarMarca();
void EliminarMarca();
void MenuInventario();
void IngresoProductos();
void MostrarProductos();
void BuscarProductos();
void SearchProductsForName();
void SearchProductsForCode();
void ModificarProductos();
void EliminarProducto();
void Codigo_barra();
void MenuFacturas();
void Facture();
bool ValidacionNIT(string);
int Contador(int);
void ProductosAComprar();
void MenuBusquedaCliente();
void SearchWhitName();
void SearchClientWhitNIT();
void MenuBusquedaFactura();
void SearchWhitCorrelative();
void SearchFactureWhitNIT();
void MenuAyuda();
void mostrar();
void Actualizacion(int, int);
main()
{
     /*SetConsoleTitle("Supermercado UMG");
    system("color 09");
     gotoxy(40,10);cout << "Bienvenidos al Programa Supermercado"<<endl;
     gotoxy(45,11);cout << "Hecho por: Rodrigo Vasquez"<<endl;
     gotoxy(50,12);cout << "RV.Enterprices"<<endl;
     cout<<endl;
     char a = 177, b = 219;
     cout << "\t\t\t\t";
     for (int i = 0; i <= 50; i++)
          cout << a;
     cout << "\r";
     cout << "\t\t\t\t";
     for (int i = 0; i <= 50; i++)
     {
          cout << b;
          Sleep(200);
     }
     system("CLS");
*/
     MenuPrincipal();
}
bool VerificadorDeNumeros(string str)
{
     for (int i = 0; i < str.length(); i++)
          if (isdigit(str[i]) == false)
               return false;
     return true;
}
void MenuPrincipal()
{
     char opc;
     SetConsoleTitle("MENU PRINCIPAL");
     system("CLS");
     for (int a = 10; a <= 101; a++)
     {
          gotoxy(a, 1);
          HOR;
     }
     for (int a = 2; a <= 4; a++)
     {
          gotoxy(9, a);
          VER
     }
     for (int a = 11; a <= 99; a++)
     {
          gotoxy(a, 2);
          PUN;
     }
     for (int a = 11; a <= 99; a++)
     {
          gotoxy(a, 3);
          PUN;
     }
     for (int a = 11; a <= 99; a++)
     {
          gotoxy(a, 4);
          PUN;
     }
     for (int a = 10; a <= 101; a++)
     {
          gotoxy(a, 5);
          HOR;
     }
     gotoxy(46, 3);
     cout << " M E N U   P R I N C I P A L ";
     for (int a = 2; a <= 4; a++)
     {
          gotoxy(110, a);
          VER
     }
     gotoxy(9, 1);
     cout << TOPE;
     gotoxy(110, 1);
     cout << EDA;
     gotoxy(9, 5);
     cout << EIB;
     gotoxy(110, 5);
     cout << EDB;

     for (int a = 10; a <= 101; a++)
     {
          gotoxy(a, 7);
          HOR;
     }
     for (int a = 8; a <= 27; a++)
     {
          gotoxy(9, a);
          VER
     }
     for (int a = 10; a <= 101; a++)
     {
          gotoxy(a, 28);
          HOR;
     }
     for (int a = 8; a <= 27; a++)
     {
          gotoxy(110, a);
          VER
     }
     gotoxy(9, 7);
     cout << TOPE;
     gotoxy(110, 7);
     cout << EDA;
     gotoxy(9, 28);
     cout << EIB;
     gotoxy(110, 28);
     cout << EDB;
     for (int a = 8; a <= 26; a++)
     {
          gotoxy(35, a);
          VER
     }
     for (int a = 8; a <= 26; a++)
     {
          gotoxy(84, a);
          VER
     }
     gotoxy(35, 10);
     cout << V << "              -->   [1] MARCAS                  " << V;
     gotoxy(35, 12);
     cout << V << "              -->   [2] INVENTARIO              " << V;
     gotoxy(35, 14);
     cout << V << "              -->   [3] FACTURAS                " << V;
     gotoxy(35, 16);
     cout << V << "              -->   [4] MODO DE BANDA           " << V;
     gotoxy(35, 18);
     cout << V << "              -->   [5] AYUDA                   " << V;
     gotoxy(35, 22);
     ARENBJ;
     gotoxy(35, 26);
     ABJ;
     gotoxy(35, 24);
     cout << V << "                  ESC. SALIR                    " << V;
     gotoxy(35, 27);
     opc = getch();
     switch (opc)
     {
     case '1':
     {
          MenuMarcas();
          getch();
          MenuPrincipal();
          break;
     }
     case '2':
     {
          MenuInventario();
          getch();
          MenuPrincipal();
          break;
     }
     case '3':
     {
          MenuFacturas();
          getch();
          MenuPrincipal();
          break;
     }
     case '4':
     {
          MenuPrincipal();
          break;
     }
     case '5':
     {
          MenuAyuda();
          getch();
          MenuPrincipal();
          break;
     }
     case 27:
     {
          exit(0);
          break;
     }
     default:
     {
          cout << " \aOPCION INCORRECTA, ELIJA NUEVAMENTE " << endl;
          getch();
          MenuPrincipal();
          break;
     }
     }
}
void MenuMarcas()
{
     char opc;
     SetConsoleTitle("MENU DE MARCAS");
     system("CLS");
     for (int a = 10; a <= 101; a++)
     {
          gotoxy(a, 5);
          HOR;
     }
     for (int a = 5; a <= 6; a++)
     {
          gotoxy(9, a);
          VER
     }
     for (int a = 11; a <= 99; a++)
     {
          gotoxy(a, 6);
          PUN;
     }
     for (int a = 10; a <= 101; a++)
     {
          gotoxy(a, 7);
          HOR;
     }
     gotoxy(50, 6);
     cout << " M  A  R  C  A  S ";
     for (int a = 5; a <= 6; a++)
     {
          gotoxy(110, a);
          VER
     }
     gotoxy(9, 5);
     cout << TOPE;
     gotoxy(110, 5);
     cout << EDA;
     gotoxy(9, 7);
     cout << EIB;
     gotoxy(110, 7);
     cout << EDB;

     for (int a = 10; a <= 101; a++)
     {
          gotoxy(a, 9);
          HOR;
     }
     for (int a = 9; a <= 24; a++)
     {
          gotoxy(9, a);
          VER
     }
     for (int a = 10; a <= 101; a++)
     {
          gotoxy(a, 24);
          HOR;
     }
     for (int a = 9; a <= 24; a++)
     {
          gotoxy(110, a);
          VER
     }
     gotoxy(9, 9);
     cout << TOPE;
     gotoxy(110, 9);
     cout << EDA;
     gotoxy(9, 24);
     cout << EIB;
     gotoxy(110, 24);
     cout << EDB;
     for (int a = 10; a <= 22; a++)
     {
          gotoxy(35, a);
          VER
     }
     for (int a = 10; a <= 22; a++)
     {
          gotoxy(84, a);
          VER
     }
     gotoxy(35, 11);
     cout << V << " -->   [1] INGRESO DE MARCAS                    " << V;
     gotoxy(35, 13);
     cout << V << " -->   [2] VISUALIZACION DEL LISTADO DE MARCAS  " << V;
     gotoxy(35, 15);
     cout << V << " -->   [3] MODIFICACION DE MARCAS               " << V;
     gotoxy(35, 17);
     cout << V << " -->   [4] ELIMINACION DE MARCAS                " << V;
     gotoxy(35, 19);
     ARENBJ;
     gotoxy(35, 23);
     ABJ;
     gotoxy(35, 21);
     cout << V << "         <-- REGRESAR / ESC. SALIR              " << V;
     gotoxy(35, 25);
     opc = getch();
     if (opc == 8)
     {
          MenuPrincipal();
     }
     else
     {
          switch (opc)
          {
          case '1':
          {
               IngresoDeMarcas();
               getch();
               MenuMarcas();
               break;
          }
          case '2':
          {
               MostrarMarcas();
               getch();
               MenuMarcas();
               break;
          }
          case '3':
          {
               ModificarMarca();
               getch();
               MenuMarcas();
               break;
          }
          case '4':
          {
               EliminarMarca();
               getch();
               MenuMarcas();
               break;
          }
          case 27:
          {
               exit(0);
               break;
          }
          default:
          {
               cout << "\aOPCION INCORRECTA, ELIJA NUEVAMENTE" << endl;
               getch();
               MenuMarcas();
               break;
          }
          }
     }
}
void IngresoDeMarcas()
{
     fflush(stdin);
     SetConsoleTitle("INGRESO DE MARCAS");
     Marcas Marca;
     char opc;
     FILE *ArchivoMarcas = fopen("Marcas.dat", "a+b");
loop:
     rewind(ArchivoMarcas);
     string AUX;
     int AuxIdMarca;
     system("CLS");
     fflush(stdin);
     for (int a = 11; a <= 99; a++)
     {
          gotoxy(a, 3);
          PUN;
     }
     gotoxy(44, 3);
     cout << " I N G R E S O   D E   M A R C A S ";

     cout << "\n\n\n\t\t ID DE LA MARCA -> ";
     getline(cin, AUX);
     if (VerificadorDeNumeros(AUX))
     {
          AuxIdMarca = atoi(AUX.c_str());
     }
     else
     {
          for (int a = 11; a <= 99; a++)
          {
               gotoxy(a, 9);
               PUN;
          }
          cout << "\n\n\t\t\t   * EL INGRESO DE LETRAS ES INCORRECTO, VALIDO UNICAMENTE NUMEROS *" << endl;
          getch();
          system("CLS");
          goto loop;
     }
     fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
     while (!feof(ArchivoMarcas))
     {
          if (AuxIdMarca == Marca.idMarca)
          {
               cout << "\n\n\t\t\t\t\t   * EL ID QUE INGRESO YA EXISTE *" << endl;
               getch();
               goto loop;
          }
          fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
     }
     fflush(stdin);
     Marca.idMarca = AuxIdMarca;
     cout << "\n\n\n\t\t NOMBRE DE LA MARCA -> ";
     cin.getline(Marca.NombreMarca, 50, '\n');
     fflush(stdin);
     fwrite(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
     for (int a = 11; a <= 99; a++)
     {
          gotoxy(a, 13);
          PUN;
     }
     cout << "\n\n\t\t\t\t\tDESEA INGRESAR OTRO REGISTRO? (S | N) -> ";
     cin >> opc;
     if (opc == 'S' || opc == 's')
     {
          goto loop;
     }
     for (int a = 11; a <= 99; a++)
     {
          gotoxy(a, 17);
          PUN;
     }
     cout << "\n\n\t\t\t\t\t\t* GUARDADO EXITOSAMENTE *" << endl;
     fclose(ArchivoMarcas);
}
void MostrarMarcas()
{
     system("CLS");
     int Filas = 7, FilasTotales = 7;
     SetConsoleTitle("LISTADO DE MARCAS");
     Marcas Marca;
     FILE *ArchivoMarcas = fopen("Marcas.dat", "rb");
     if (ArchivoMarcas == NULL)
     {
          cout << " ERROR 001 " << endl;
          getch();
          MenuMarcas();
     }
     else
     {
          system("CLS");
          fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
          for (int a = 11; a <= 100; a++)
          {
               gotoxy(a, 2);
               PUN;
          }
          gotoxy(43, 2);
          cout << " L I S T A D O  D E  M A R C A S ";
          gotoxy(25, 4);
          cout << EIA << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDA << endl;
          gotoxy(25, 5);
          cout << V;
          gotoxy(27, 5);
          cout << "I D  M A R C A";
          gotoxy(42, 5);
          cout << V;
          gotoxy(63, 5);
          cout << "N O M B R E";
          gotoxy(94, 5);
          cout << V << endl;
          gotoxy(25, 6);
          separador;

          while (!feof(ArchivoMarcas))
          {
               gotoxy(25, Filas);
               cout << V;
               gotoxy(32, Filas);
               cout << Marca.idMarca;
               gotoxy(42, Filas);
               cout << V;
               gotoxy(66, Filas);
               cout << Marca.NombreMarca;
               gotoxy(94, Filas);
               cout << V << endl;
               ++Filas;
               ++FilasTotales;
               fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
          }
          gotoxy(25, FilasTotales);
          cout << EIB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDB << endl;
          fclose(ArchivoMarcas);
     }
}
void ModificarMarca()
{
     SetConsoleTitle("MODIFICACION DE MARCAS");
inicio:
     fflush(stdin);
     Marcas Marca;
     FILE *ArchivoMarcas = fopen("Marcas.dat", "r+b");
     int AuxIdMarca, existe = 0, aux2;
     string AUX;
     system("CLS");
     fflush(stdin);
     MostrarMarcas();
     cout << "\n\n\n\t\t ID DE LA MARCA QUE DESEA MODIFICAR -> ";
     cin >> AUX;
     fflush(stdin);
     if (VerificadorDeNumeros(AUX))
     {
          fflush(stdin);
          AuxIdMarca = atoi(AUX.c_str());
     }
     else
     {
          cout << "\n\n\t\t\t   * EL INGRESO DE LETRAS ES INCORRECTO, VALIDO UNICAMENTE NUMEROS *" << endl;
          getch();
          system("CLS");
          goto inicio;
     }
     fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
     while (!feof(ArchivoMarcas))
     {
          if (AuxIdMarca == Marca.idMarca)
          {
               cout << "\n\t\t ID MARCA: " << Marca.idMarca << endl;
               cout << "\t\t NOMBRE DE LA MARCA: " << Marca.NombreMarca << endl
                    << endl;
               getch();
               int pos = ftell(ArchivoMarcas) - sizeof(Marcas);

               fflush(stdin);
          loop:
               system("CLS");

               for (int a = 11; a <= 99; a++)
               {
                    gotoxy(a, 3);
                    PUN;
               }
               gotoxy(38, 3);
               cout << " M O D I F I C A C I O N   D E   M A R C A S ";
               cout << "\n\n\n\t\t ID NUEVO -> ";
               cin >> aux2;
               fflush(stdin);
               rewind(ArchivoMarcas);
               fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
               while (!feof(ArchivoMarcas))
               {
                    if (aux2 == Marca.idMarca)
                    {
                         for (int a = 11; a <= 99; a++)
                         {
                              gotoxy(a, 8);
                              PUN;
                         }
                         cout << "\n\n\t\t\t\t\t   * EL ID INGRESADO YA EXISTE *" << endl;
                         getch();
                         goto loop;
                    }
                    fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
               }
               fflush(stdin);

               Marca.idMarca = aux2;
               fflush(stdin);
               fseek(ArchivoMarcas, pos, SEEK_SET);
               cout << "\n\n\n\t\t NOMBRE NUEVO -> ";
               cin.getline(Marca.NombreMarca, 50, '\n');
               fflush(stdin);
               fwrite(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
               for (int a = 11; a <= 99; a++)
               {
                    gotoxy(a, 12);
                    PUN;
               }
               cout << "\n\n\t\t\t\t\t\t* MODIFICADO EXITOSAMENTE *" << endl;
               existe = 1;
               break;
          }

          fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
     }
     if (existe == 0)
     {
          for (int a = 11; a <= 99; a++)
          {
               gotoxy(a, 16);
               PUN;
          }
          cout << "\n\n\t\t\t\t\t* NO EXISTE UNA MARCA CON ESE ID *" << endl;
     }

     fclose(ArchivoMarcas);
     Actualizacion(aux2, AuxIdMarca);
}
void Actualizacion(int idnew, int idold)
{
     Productos Producto;
     FILE *Inventario = fopen("Productos.dat", "r+b");
     FILE *Temporal = fopen("temporal.dat", "a+b");
     fread(&Producto, sizeof(Productos), 1, Inventario);
     while (!feof(Inventario))
     {
          if (idold == Producto.idMarca)
          {
               Producto.CodigoProducto = Producto.CodigoProducto;
               strcpy(Producto.DescripcionProducto, Producto.DescripcionProducto);
               Producto.FechaDeIngreso.d = Producto.FechaDeIngreso.d;
               Producto.FechaDeIngreso.m = Producto.FechaDeIngreso.m;
               Producto.FechaDeIngreso.a = Producto.FechaDeIngreso.a;
               Producto.idMarca = idnew;
               Producto.PrecioCosto = Producto.PrecioCosto;
               Producto.PrecioVenta = Producto.PrecioVenta;
               fwrite(&Producto, sizeof(Productos), 1, Temporal);
          }
          else
          {
               fwrite(&Producto, sizeof(Productos), 1, Temporal);
          }
          fread(&Producto, sizeof(Productos), 1, Inventario);
     }

     fclose(Inventario);
     fclose(Temporal);
     remove("Productos.dat");
     rename("temporal.dat", "Productos.dat");
}
void EliminarMarca()
{
     SetConsoleTitle("ELIMINACION DE MARCAS");
     fflush(stdin);
     Marcas Marca;
     FILE *ArchivoMarcas = fopen("Marcas.dat", "rb");
     FILE *Temporal = fopen("Temporal.dat", "wb");
     int AuxIdMarca, existe = 0;
     system("CLS");
     fflush(stdin);
     MostrarMarcas();
     cout << "\n\n\n\t\t ID DE LA MARCA QUE DESEA ELIMINAR -> ";
     cin >> AuxIdMarca;
     fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
     while (!feof(ArchivoMarcas))
     {
          if (AuxIdMarca == Marca.idMarca)
          {
               cout << "\n\t\t ID MARCA: " << Marca.idMarca;
               cout << "\n\t\t NOMBRE DE LA MARCA: " << Marca.NombreMarca << endl
                    << endl;
               existe = 1;
               cout << endl;
               for (int a = 11; a <= 99; a++)
               {
                    gotoxy(a, 18);
                    PUN;
               }
               cout << "\n\n\t\t\t\t\t* SE HA ELIMINADO CORRECTAMENTE*" << endl;
          }
          else
          {
               fwrite(&Marca, sizeof(Marcas), 1, Temporal);
               fflush(stdin);
          }
          fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
     }
     if (existe == 0)
     {
          cout << "\n\n\t\t\t\t\t* NO EXISTE UNA MARCA CON ESE ID *" << endl;
     }

     fclose(Temporal);
     fclose(ArchivoMarcas);
     remove("Marcas.dat");
     rename("Temporal.dat", "Marcas.dat");
}
void MenuInventario()
{
     char opc;
     SetConsoleTitle("MENU DE INVENTARIO");
     system("CLS");
     for (int a = 10; a <= 101; a++)
     {
          gotoxy(a, 5);
          HOR;
     }
     for (int a = 5; a <= 6; a++)
     {
          gotoxy(9, a);
          VER
     }
     for (int a = 11; a <= 99; a++)
     {
          gotoxy(a, 6);
          PUN;
     }
     for (int a = 10; a <= 101; a++)
     {
          gotoxy(a, 7);
          HOR;
     }
     gotoxy(50, 6);
     cout << " I N V E N T A R I O ";
     for (int a = 5; a <= 6; a++)
     {
          gotoxy(110, a);
          VER
     }
     gotoxy(9, 5);
     cout << TOPE;
     gotoxy(110, 5);
     cout << EDA;
     gotoxy(9, 7);
     cout << EIB;
     gotoxy(110, 7);
     cout << EDB;

     for (int a = 10; a <= 101; a++)
     {
          gotoxy(a, 9);
          HOR;
     }
     for (int a = 9; a <= 26; a++)
     {
          gotoxy(9, a);
          VER
     }
     for (int a = 10; a <= 101; a++)
     {
          gotoxy(a, 26);
          HOR;
     }
     for (int a = 9; a <= 26; a++)
     {
          gotoxy(110, a);
          VER
     }
     gotoxy(9, 9);
     cout << TOPE;
     gotoxy(110, 9);
     cout << EDA;
     gotoxy(9, 26);
     cout << EIB;
     gotoxy(110, 26);
     cout << EDB;
     for (int a = 10; a <= 24; a++)
     {
          gotoxy(35, a);
          VER
     }
     for (int a = 10; a <= 24; a++)
     {
          gotoxy(84, a);
          VER
     }
     gotoxy(35, 11);
     cout << V << " -->   [1] INGRESO DE PRODUCTOS                 " << V;
     gotoxy(35, 13);
     cout << V << " -->   [2] LISTADO DE PRODUCTOS                 " << V;
     gotoxy(35, 15);
     cout << V << " -->   [3] BUSQUEDA DE PRODUCTOS                " << V;
     gotoxy(35, 17);
     cout << V << " -->   [4] MODIFICACION DE PRODUCTOS            " << V;
     gotoxy(35, 19);
     cout << V << " -->   [5] ELIMINACION DE PRODUCTOS             " << V;
     gotoxy(35, 21);
     cout << V << " -->   [6] CODIGO DE BARRA                      " << V;
     gotoxy(35, 22);
     ARENBJ;
     gotoxy(35, 25);
     ABJ;
     gotoxy(35, 24);
     cout << V << "         <-- REGRESAR / ESC. SALIR              " << V;
     gotoxy(35, 27);
     opc = getch();
     if (opc == 8)
     {
          MenuPrincipal();
     }
     else
     {
          switch (opc)
          {
          case '1':
          {
               IngresoProductos();
               getch();
               MenuInventario();
               break;
          }
          case '2':
          {
               MostrarProductos();
               getch();
               MenuInventario();
               break;
          }
          case '3':
          {
               BuscarProductos();
               getch();
               MenuInventario();
               break;
          }
          case '4':
          {
               ModificarProductos();
               getch();
               MenuInventario();
               break;
          }
          case '5':
          {
               EliminarProducto();
               getch();
               MenuInventario();
               break;
          }
          case '6':
          {
               Codigo_barra();
               MenuInventario();
               break;
          }
          case 27:
          {
               exit(0);
               break;
          }
          default:
          {
               cout << "Opcion Incorreta elija de nuevo" << endl;
               getch();
               MenuInventario();
               break;
          }
          }
     }
}
void IngresoProductos()
{
     fflush(stdin);
     SetConsoleTitle("INGRESO DE PRODUCTOS");
     Productos Producto;
     Marcas Marca;
     FILE *ArchivoMarcas = fopen("Marcas.dat", "rb");
     FILE *ArchivoProductos = fopen("Productos.dat", "a+b");
InicioIngresoProductos:
codigoProducto:
     MostrarMarcas();
     int auxCodigoProducto, encontradoCodigoProducto = 0, auxIdMarca;
     cout << "\n\n\t\tCODIGO DEL PRODUCTO -> ";
     cin >> auxCodigoProducto;
     fflush(stdin);
     rewind(ArchivoProductos);
     fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
     do
     {
          if (auxCodigoProducto == Producto.CodigoProducto)
          {
               encontradoCodigoProducto = 1;
          }
          fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
     } while (!feof(ArchivoProductos));
     if (encontradoCodigoProducto == 1)
     {
          cout << "\n\n\t\t\t\t\t * EL CODIGO QUE INGRESO YA EXISTE *" << endl;
          getch();
          goto codigoProducto;
     }
     fflush(stdin);
     Producto.CodigoProducto = auxCodigoProducto;
     fflush(stdin);
     cout << "\n\n\t\tNOMBRE DEL PRODUCTO -> ";
     cin.getline(Producto.DescripcionProducto, 100, '\n');
     fflush(stdin);
IdMarca:
     rewind(ArchivoMarcas);
     fflush(stdin);
     int encontradoIdMarca = 0;
     cout << "\n\n\t\tID DE LA MARCA DEL PRODUCTO -> ";
     cin >> auxIdMarca;
     fflush(stdin);
     fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
     do
     {
          if (auxIdMarca == Marca.idMarca)
          {
               encontradoIdMarca = 1;
          }
          fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
     } while (!feof(ArchivoMarcas));
     if (encontradoIdMarca == 0)
     {
          cout << "\n\n\t\t\t\t * NO EXISTE UNA MARCA CON EL ID QUE INGRESO *" << endl;
          getch();
          goto IdMarca;
     }
     fflush(stdin);
     Producto.idMarca = auxIdMarca;
     fflush(stdin);
     cout << "\n\n\t\tPRECIO DE VENTA DEL PRODUCTO " << Producto.DescripcionProducto << " -> ";
     cin >> Producto.PrecioVenta;
     fflush(stdin);
     cout << "\n\n\t\tPRECIO COSTO DEL PRODUCTO " << Producto.DescripcionProducto << " -> ";
     cin >> Producto.PrecioCosto;
     fflush(stdin);
     int formatofecha = 0;
     do
     {
          cout << "\n\n\t\tDIA QUE EL PRODUCTO INGRESO -> ";
          cin >> Producto.FechaDeIngreso.d;
          fflush(stdin);
          cout << "\n\n\t\tMES QUE EL PRODUCTO INGRESO -> ";
          cin >> Producto.FechaDeIngreso.m;
          fflush(stdin);
          cout << "\n\n\t\tANIO QUE EL PRODUCTO INGRESO -> ";
          cin >> Producto.FechaDeIngreso.a;
          fflush(stdin);
          if ((Producto.FechaDeIngreso.d > 0 && Producto.FechaDeIngreso.d < 32) && (Producto.FechaDeIngreso.m > 0 && Producto.FechaDeIngreso.m < 13) && (Producto.FechaDeIngreso.a > 1999 && Producto.FechaDeIngreso.a < 2101))
          {
               formatofecha = 1;
          }
          else
          {
               cout << "\n\n\t\t* FORMATO INCORRECTO (DD/MM/AAAA)" << endl;
          }
     } while (formatofecha == 0);
     fwrite(&Producto, sizeof(Productos), 1, ArchivoProductos);
     cout << "\n\n\t\t\t\t\tDESEA INGRESAR OTRO PRODUCTO? (S | N) -> ";
     cin >> opc;
     if (opc == 's' || opc == 'S')
     {
          goto InicioIngresoProductos;
     }
     fclose(ArchivoMarcas);
     fclose(ArchivoProductos);
}
void MostrarProductos()
{
     system("CLS");
     int Filas = 6, FilasTotales = 6, encontradomarca = 0;
     SetConsoleTitle("LISTADO DE PRODUCTOS");
     Productos Producto;
     Marcas Marca;
     FILE *ArchivoMarcas = fopen("Marcas.dat", "rb");
     FILE *ArchivoProductos = fopen("Productos.dat", "rb");
     if (ArchivoProductos == NULL)
     {
          cout << " ERROR 001 " << endl;
          getch();
          MenuInventario();
     }
     else
     {
          system("CLS");
          fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
          for (int a = 10; a <= 100; a++)
          {
               gotoxy(a, 1);
               PUN;
          }
          gotoxy(43, 1);
          cout << " L I S T A D O  D E  P R O D U C T O S ";
          gotoxy(4, 3);
          cout << EIA << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDA << endl;
          gotoxy(4, 4);
          cout << V;
          gotoxy(111, 4);
          cout << V;
          gotoxy(6, 4);
          cout << "COD. PRODUCTO";
          gotoxy(20, 4);
          cout << V;
          gotoxy(24, 4);
          cout << "PRODUCTO";
          gotoxy(36, 4);
          cout << V;
          gotoxy(37, 4);
          cout << " ID MARCA";
          gotoxy(47, 4);
          cout << V;
          gotoxy(54, 4);
          cout << "MARCA";
          gotoxy(65, 4);
          cout << V;
          gotoxy(67, 4);
          cout << "PRECIO COSTO";
          gotoxy(81, 4);
          cout << V;
          gotoxy(84, 4);
          cout << "PRECIO VENTA";
          gotoxy(98, 4);
          cout << V;
          gotoxy(100, 4);
          cout << "FECHA. INGRESO";
          gotoxy(115, 4);
          cout << V;
          gotoxy(4, 5);
          separador2;
          while (!feof(ArchivoProductos))
          {
               gotoxy(4, Filas);
               cout << V;
               gotoxy(11, Filas);
               cout << Producto.CodigoProducto;
               gotoxy(20, Filas);
               cout << V;
               gotoxy(22, Filas);
               cout << Producto.DescripcionProducto;
               gotoxy(36, Filas);
               cout << V;
               rewind(ArchivoMarcas);
               fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
               while (!feof(ArchivoMarcas))
               {
                    if (Producto.idMarca == Marca.idMarca)
                    {
                         gotoxy(40, Filas);
                         cout << Marca.idMarca;
                         gotoxy(47, Filas);
                         cout << V;
                         gotoxy(50, Filas);
                         cout << Marca.NombreMarca;
                         encontradomarca = 1;
                    }
                    fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
               }
               if (encontradomarca == 0)
               {
                    gotoxy(47, Filas);
                    cout << V;
                    gotoxy(50, Filas);
                    cout << "Modificada!";
               }

               gotoxy(65, Filas);
               cout << V;
               gotoxy(68, Filas);
               cout << "Q." << Producto.PrecioCosto;
               gotoxy(81, Filas);
               cout << V;
               gotoxy(85, Filas);
               cout << "Q." << Producto.PrecioVenta;
               gotoxy(98, Filas);
               cout << V;
               gotoxy(102, Filas);
               cout << Producto.FechaDeIngreso.d << "/" << Producto.FechaDeIngreso.m << "/" << Producto.FechaDeIngreso.a;
               gotoxy(115, Filas);
               cout << V << endl;
               ++Filas;
               ++FilasTotales;
               fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
          }
          fclose(ArchivoProductos);
          fclose(ArchivoMarcas);
     }
}
void BuscarProductos()
{
     char opc;
     SetConsoleTitle("Menu Consultas");
     system("CLS");
     gotoxy(35, 7);
     ARAR;
     gotoxy(35, 8);
     cout << V << "             Menu De Consultas                    " << V << endl;
     gotoxy(35, 9);
     AREN;
     gotoxy(35, 10);
     cout << V << "              1. Busqueda de producto por nombre  " << V << endl;
     gotoxy(35, 11);
     cout << V << "              2. Busqueda De Producto Por Codigo  " << V << endl;
     gotoxy(35, 12);
     ARENBJ;
     gotoxy(35, 13);
     cout << V << "           <-- Regresar / ESC.)Salir              " << V << endl;
     gotoxy(35, 14);
     ABJ;
     gotoxy(35, 15);
     opc = getch();
     if (opc == 8)
     {
          MenuPrincipal();
     }
     else
     {
          switch (opc)
          {
          case '1':
          {
               SearchProductsForName();
               getch();
               BuscarProductos();
               break;
          }
          case '2':
          {
               SearchProductsForCode();
               getch();
               BuscarProductos();
               break;
          }

          case 27:
          {
               exit(0);
               break;
          }
          default:
          {
               cout << "Opcion Incorreta elija de nuevo" << endl;
               getch();
               BuscarProductos();
               break;
          }
          }
     }
}
void SearchProductsForName()
{

     system("CLS");
     int Filas = 6, FilasTotales = 6, encontradomarca = 0;
     SetConsoleTitle("Listado De Productos");
     Productos Producto;
     Marcas Marca;
     FILE *ArchivoMarcas = fopen("Marcas.dat", "rb");
     FILE *ArchivoProductos = fopen("Productos.dat", "rb");
     if (ArchivoProductos == NULL)
     {
          cout << "Error 001" << endl;
          getch();
          MenuInventario();
     }
     else
     {
          fflush(stdin);
          string aux;
          string nombre;
          bool encontrado = false;
          system("CLS");
          fflush(stdin);
          cout << "Ingrese el nombre del producto que busca" << endl;
          getline(cin, aux);
          fflush(stdin);
          Minusculas(aux);
          SetConsoleTitle("Registros");
          cout << "+--------------------------------------------------------------------------+" << endl;
          gotoxy(7, 4);
          cout << V;
          gotoxy(7, 4);
          cout << "Cod.Producto";
          gotoxy(30, 4);
          cout << "Producto";
          gotoxy(46, 4);
          cout << "ID Marca";
          gotoxy(57, 4);
          cout << "Precio Costo";
          gotoxy(77, 4);
          cout << "Precio Venta";
          gotoxy(96, 4);
          cout << "Fecha.Ingreso";
          gotoxy(1, 5);
          cout << endl;
          fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
          do
          {
               nombre = Producto.DescripcionProducto;
               Minusculas(nombre);
               fflush(stdin);
               if (nombre.find(aux) != string::npos)
               {
                    encontrado = true;
                    gotoxy(7, Filas);
                    cout << V;
                    gotoxy(7, Filas);
                    cout << Producto.CodigoProducto;
                    gotoxy(30, Filas);
                    cout << Producto.DescripcionProducto;
                    rewind(ArchivoMarcas);
                    fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
                    while (!feof(ArchivoMarcas))
                    {
                         if (Producto.idMarca == Marca.idMarca)
                         {
                              gotoxy(46, Filas);
                              cout << Marca.NombreMarca;
                              encontradomarca = 1;
                         }
                         fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
                    }

                    gotoxy(57, Filas);
                    cout << "Q." << Producto.PrecioCosto;
                    gotoxy(77, Filas);
                    cout << "Q." << Producto.PrecioVenta;
                    gotoxy(96, Filas);
                    cout << Producto.FechaDeIngreso.d << "/" << Producto.FechaDeIngreso.m << "/" << Producto.FechaDeIngreso.a << endl;
                    ++Filas;
                    ++FilasTotales;
               }
               fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
          } while (feof(ArchivoProductos) == 0);
          if (encontrado == false)
          {
               cout << "No se encontro" << endl;
          }
          fclose(ArchivoProductos);
     }
}
void SearchProductsForCode()
{
     system("CLS");
     int Filas = 6, FilasTotales = 6, encontradomarca = 0;
     SetConsoleTitle("Listado De Productos");
     Productos Producto;
     Marcas Marca;
     FILE *ArchivoMarcas = fopen("Marcas.dat", "rb");
     FILE *ArchivoProductos = fopen("Productos.dat", "rb");
     if (ArchivoProductos == NULL)
     {
          cout << "Error 001" << endl;
          getch();
          MenuInventario();
     }
     else
     {
          fflush(stdin);
          int aux = 0;
          bool encontrado = false;
          system("CLS");
          fflush(stdin);
          cout << "Ingrese el codigo del producto que busca" << endl;
          cin >> aux;
          fflush(stdin);
          SetConsoleTitle("Registros");
          cout << "+--------------------------------------------------------------------------+" << endl;
          gotoxy(7, 4);
          cout << V;
          gotoxy(7, 4);
          cout << "Cod.Producto";
          gotoxy(30, 4);
          cout << "Producto";
          gotoxy(46, 4);
          cout << "ID Marca";
          gotoxy(57, 4);
          cout << "Precio Costo";
          gotoxy(77, 4);
          cout << "Precio Venta";
          gotoxy(96, 4);
          cout << "Fecha.Ingreso";
          gotoxy(1, 5);
          cout << endl;
          fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
          do
          {
               if (aux == Producto.CodigoProducto)
               {
                    encontrado = true;
                    gotoxy(7, Filas);
                    cout << V;
                    gotoxy(7, Filas);
                    cout << Producto.CodigoProducto;
                    gotoxy(30, Filas);
                    cout << Producto.DescripcionProducto;
                    rewind(ArchivoMarcas);
                    fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
                    while (!feof(ArchivoMarcas))
                    {
                         if (Producto.idMarca == Marca.idMarca)
                         {
                              gotoxy(46, Filas);
                              cout << Marca.NombreMarca;
                              encontradomarca = 1;
                         }
                         fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
                    }

                    gotoxy(57, Filas);
                    cout << "Q." << Producto.PrecioCosto;
                    gotoxy(77, Filas);
                    cout << "Q." << Producto.PrecioVenta;
                    gotoxy(96, Filas);
                    cout << Producto.FechaDeIngreso.d << "/" << Producto.FechaDeIngreso.m << "/" << Producto.FechaDeIngreso.a << endl;
                    ++Filas;
                    ++FilasTotales;
               }
               fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
          } while (feof(ArchivoProductos) == 0);
          if (encontrado == false)
          {
               cout << "No se encontro" << endl;
          }
          fclose(ArchivoProductos);
     }
}
void ModificarProductos()
{
     char Eleccion;
     fflush(stdin);
     SetConsoleTitle("MODIFICACION DE PRODUCTOS");
     Productos Producto;
     Marcas Marca;
     FILE *ArchivoMarcas = fopen("Marcas.dat", "rb");
     FILE *ArchivoProductos = fopen("Productos.dat", "r+b");
BusquedaParaModificar:
     system("CLS");
     MostrarProductos();
     rewind(ArchivoProductos);
     rewind(ArchivoMarcas);
     int AuxBusquedaCodigoProducto = 0, EncontradoCodigoaModificar = 0;
     cout << "\n\n\n\t\t CODIGO DEL PRODUCTO QUE DESEA MODIFICAR -> ";
     cin >> AuxBusquedaCodigoProducto;
     fflush(stdin);
     fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
     while (!feof(ArchivoProductos))
     {
          if (AuxBusquedaCodigoProducto == Producto.CodigoProducto)
          {
               EncontradoCodigoaModificar = 1;
               cout << "\n\t\t - DESCRIPCION DEL PRODUCTO";
               cout << "\n\t\t\t CODIGO: " << Producto.CodigoProducto;
               cout << "\n\t\t\t PRODUCTO: " << Producto.DescripcionProducto;
               fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
               while (!feof(ArchivoMarcas))
               {
                    if (Producto.idMarca == Marca.idMarca)
                    {
                         cout << "\n\t\t\t ID MARCA: " << Marca.idMarca;
                         cout << "\n\t\t\t MARCA: " << Marca.NombreMarca;
                    }
                    fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
               }
               cout << "\n\t\t\t PRECIO COSTO: " << Producto.PrecioCosto;
               cout << "\n\t\t\t PRECIO VENTA: " << Producto.PrecioVenta;
               cout << "\n\t\t\t FECHA DE INGRESO: " << Producto.FechaDeIngreso.d << "/" << Producto.FechaDeIngreso.m << "/" << Producto.FechaDeIngreso.a << endl;
               cout << endl;
               cout << "\n\t\t\t\tESTE ES EL PRODUCTO QUE DESEA MODIFICAR S | N  = ";
               cin >> Eleccion;
               fflush(stdin);
               if (Eleccion == 'N' || Eleccion == 'n')
               {
                    goto BusquedaParaModificar;
               }
               int pos = ftell(ArchivoProductos) - sizeof(Productos);
               fflush(stdin);
          codigoProducto:
               MostrarMarcas();
               int auxCodigoProducto, encontradoCodigoProducto = 0, auxIdMarca;
               cout << "\n\t\t CODIGO NUEVO DEL PRODUCTO -> ";
               cin >> auxCodigoProducto;
               fflush(stdin);
               rewind(ArchivoProductos);
               fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
               do
               {
                    if (auxCodigoProducto == Producto.CodigoProducto)
                    {
                         encontradoCodigoProducto = 1;
                    }
                    fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
               } while (!feof(ArchivoProductos));
               if (encontradoCodigoProducto == 1)
               {
                    cout << "\n\n\t\t\t\t\t* CODIGO YA EXISTENTE *" << endl;
                    getch();
                    goto codigoProducto;
               }
               fflush(stdin);
               Producto.CodigoProducto = auxCodigoProducto;
               fflush(stdin);
               fseek(ArchivoProductos, pos, SEEK_SET);
               fflush(stdin);
               cout << "\n\t\t NOMBRE NUEVO DEL PRODUCTO -> ";
               cin.getline(Producto.DescripcionProducto, 100, '\n');
               fflush(stdin);
          IdMarca:
               rewind(ArchivoMarcas);
               fflush(stdin);
               int encontradoIdMarca = 0;
               cout << "\n\t\t ID DE LA MARCAR DEL PRODUCTO -> ";
               cin >> auxIdMarca;
               fflush(stdin);
               fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
               do
               {
                    if (auxIdMarca == Marca.idMarca)
                    {
                         encontradoIdMarca = 1;
                    }
                    fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
               } while (!feof(ArchivoMarcas));
               if (encontradoIdMarca == 0)
               {
                    cout << "\n\n\t\t\t\t\t* NO EXISTE UNA MARCA CON ESE ID *" << endl;
                    getch();
                    goto IdMarca;
               }
               fflush(stdin);
               Producto.idMarca = auxIdMarca;
               fflush(stdin);
               cout << "\n\t\t PRECIO VENTA DE " << Producto.DescripcionProducto << " -> ";
               cin >> Producto.PrecioVenta;
               fflush(stdin);
               cout << "\n\t\t PRECIO COSTO DE " << Producto.DescripcionProducto << " -> ";
               cin >> Producto.PrecioCosto;
               fflush(stdin);
               int formatofecha = 0;
               do
               {
                    cout << "\n\t\t DIA QUE EL PRODUCTO INGRESO -> ";
                    cin >> Producto.FechaDeIngreso.d;
                    fflush(stdin);
                    cout << "\n\t\t MES QUE EL PRODUCTO INGRESO -> ";
                    cin >> Producto.FechaDeIngreso.m;
                    fflush(stdin);
                    cout << "\n\t\t ANIO QUE EL PRODUCTO INGRESO -> ";
                    cin >> Producto.FechaDeIngreso.a;
                    fflush(stdin);
                    if ((Producto.FechaDeIngreso.d > 0 && Producto.FechaDeIngreso.d < 32) && (Producto.FechaDeIngreso.m > 0 && Producto.FechaDeIngreso.m < 13) && (Producto.FechaDeIngreso.a > 1999 && Producto.FechaDeIngreso.a < 2101))
                    {
                         formatofecha = 1;
                    }
                    else
                    {
                         cout << "\n\n\t\t* FORMATO INCORRECTO (DD/MM/AAAA)" << endl;
                    }
               } while (formatofecha == 0);
               fwrite(&Producto, sizeof(Productos), 1, ArchivoProductos);
               fflush(stdin);
               cout << "\n\n\t\t\t\t\t\t* MODIFICADO EXITOSAMENTE *" << endl;
               break;
          }
          fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
     }
     if (EncontradoCodigoaModificar == 0)
     {
          cout << "\n\n\t\t\t\t\t  * EL CODIGO QUE INGRESO NO EXISTE *" << endl;
          getch();
          goto BusquedaParaModificar;
     }

     fclose(ArchivoProductos);
     fclose(ArchivoMarcas);
}
void EliminarProducto()
{
     Productos Producto;
     SetConsoleTitle("ELIMINACION DE PRODUCTOS");
     FILE *ArchivoProductos = fopen("Productos.dat", "rb");
     FILE *Temporal = fopen("Temporal.dat", "w+b");
BusquedaDeCodigoParaEliminar:
     system("CLS");
     MostrarProductos();
     rewind(ArchivoProductos);
     int EncontradoCodigo = 0, AuxCodigoProducto = 0;
     cout << "\n\n\n\t\t CODIGO DEL PRODUCTO QUE DESEA ELIMINAR -> ";
     cin >> AuxCodigoProducto;
     fflush(stdin);
     fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
     while (!feof(ArchivoProductos))
     {
          if (AuxCodigoProducto == Producto.CodigoProducto)
          {
               cout << "\n\n\t\t\t\t\t* SE HA ELIMINADO CORRECTAMENTE*" << endl;
               EncontradoCodigo = 1;
          }
          else
          {
               fwrite(&Producto, sizeof(Productos), 1, Temporal);
               fflush(stdin);
          }
          fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
     }
     if (EncontradoCodigo == 0)
     {
          cout << "\n\n\t\t\t\t\t* NO EXISTE UN PRODUCTO CON ESE CODIGO *" << endl;
          getch();
          goto BusquedaDeCodigoParaEliminar;
     }
     fclose(ArchivoProductos);
     fclose(Temporal);
     remove("Productos.dat");
     rename("Temporal.dat", "Productos.dat");
}
//-------------------CODIGO DE BARRA-------------------
void Codigo_barra()
{
     system("CLS");
     SetConsoleTitle("CODIGO DE BARRA");
     MostrarProductos();
     int cp;
     cout << "\n\n\t\tINGRESE EL CODIGO -> ";
     cin >> cp;

     FILE *ArchivoProductos = fopen("Productos.dat", "rb");

     int indice = 0, pos = 0, cod = 0;
     Productos Producto;
     fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
     do
     {
          if (Producto.CodigoProducto == cp)
          {
               ofstream ArchivoProductos;
               ArchivoProductos.open("IMPRIMIR/Codigo_barra/Codigo_barra/bin/Debug/imprimir.txt", ios::out);
               if (ArchivoProductos.fail())
               {
                    cout << "no es posible abrir el archivo";
                    getch();
                    exit(1);
               }
               else
               {
                    fflush(stdin);
                    ArchivoProductos << Producto.CodigoProducto << endl
                                     << Producto.DescripcionProducto << " marca ";
                    FILE *ArchivoMarcas = fopen("Marcas.dat", "a+b");
                    Marcas Marca;
                    fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
                    do
                    {
                         if (Producto.idMarca == Marca.idMarca)
                         {
                              ArchivoProductos << Marca.NombreMarca << endl;
                         }
                         fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
                    } while (feof(ArchivoMarcas) == 0);
                    fclose(ArchivoMarcas);
                         ArchivoProductos << fixed << setprecision(2) << Producto.PrecioVenta;
               }
               ArchivoProductos.close();
          }

          fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
          indice += 1;
     } while (feof(ArchivoProductos) == 0);

     fclose(ArchivoProductos);
     system("start IMPRIMIR/Codigo_barra/Codigo_barra/bin/Debug/Codigo_barra.exe");
     system("PAUSE");
     remove("IMPRIMIR/Codigo_barra/Codigo_barra/bin/Debug/imprimir.txt");
}

void MenuFacturas()
{
     char opc;
     SetConsoleTitle("MENU DE FACTURA");
     system("CLS");
     for (int a = 10; a <= 101; a++)
     {
          gotoxy(a, 5);
          HOR;
     }
     for (int a = 5; a <= 6; a++)
     {
          gotoxy(9, a);
          VER
     }
     for (int a = 11; a <= 99; a++)
     {
          gotoxy(a, 6);
          PUN;
     }
     for (int a = 10; a <= 101; a++)
     {
          gotoxy(a, 7);
          HOR;
     }
     gotoxy(51, 6);
     cout << " F A C T U R A S ";
     for (int a = 5; a <= 6; a++)
     {
          gotoxy(110, a);
          VER
     }
     gotoxy(9, 5);
     cout << TOPE;
     gotoxy(110, 5);
     cout << EDA;
     gotoxy(9, 7);
     cout << EIB;
     gotoxy(110, 7);
     cout << EDB;

     for (int a = 10; a <= 101; a++)
     {
          gotoxy(a, 9);
          HOR;
     }
     for (int a = 9; a <= 22; a++)
     {
          gotoxy(9, a);
          VER
     }
     for (int a = 10; a <= 101; a++)
     {
          gotoxy(a, 22);
          HOR;
     }
     for (int a = 9; a <= 22; a++)
     {
          gotoxy(110, a);
          VER
     }
     gotoxy(9, 9);
     cout << TOPE;
     gotoxy(110, 9);
     cout << EDA;
     gotoxy(9, 22);
     cout << EIB;
     gotoxy(110, 22);
     cout << EDB;
     for (int a = 10; a <= 20; a++)
     {
          gotoxy(35, a);
          VER
     }
     for (int a = 10; a <= 20; a++)
     {
          gotoxy(84, a);
          VER
     }
     gotoxy(35, 11);
     cout << V << " -->   [1] COMPRA NUEVA                         " << V;
     gotoxy(35, 13);
     cout << V << " -->   [2] BUSQUEDA DE CLIENTES                 " << V;
     gotoxy(35, 15);
     cout << V << " -->   [3] BUSQUEDA DE FACTURAS                 " << V;
     gotoxy(35, 17);
     ARENBJ;
     gotoxy(35, 21);
     ABJ;
     gotoxy(35, 19);
     cout << V << "         <-- REGRESAR / ESC. SALIR              " << V;
     gotoxy(35, 23);
     opc = getch();
     if (opc == 8)
     {
          MenuPrincipal();
     }
     else
     {
          switch (opc)
          {
          case '1':
          {
               Facture();
               ProductosAComprar();
               //FacturaDetalle
               getch();
               MenuFacturas();
               break;
          }
          case '2':
          {
               MenuBusquedaCliente();
               getch();
               MenuFacturas();
               break;
          }
          case '3':
          {
               MenuBusquedaFactura();
               getch();
               MenuFacturas();
               break;
          }

          case 27:
          {
               exit(0);
               break;
          }
          default:
          {
               cout << "Opcion Incorreta elija de nuevo" << endl;
               getch();
               MenuFacturas();
               break;
          }
          }
     }
}
bool ValidacionNIT(string nit)
{
          int tam = nit.size();
          bool ver;
          char frase[tam];
          strcpy(frase, nit.c_str());
          for (int i = 0; i < tam; i++)
          {
               if (frase[i] == '-')
               {
                    ver = true;
               }
          }
          if (ver == false)
          {
               gotoxy(1, 25);
               cout << "\n\t\t NIT INGRESADO NO CONTIENE GUION" << endl;
               real = false;
               Facture();
          }
          char *token, *aux, *numnit;
          token = strtok(frase, "-");
          int numval, tamnum;
          while (token != NULL && ver == true)
          {
               aux = token;
               token = strtok(NULL, "-");
               if (token == NULL)
               {
                    char k = *aux;
                    if (k == 'k')
                    {
                         numval = 10;
                    }
                    numval = atoi(aux);
               }
               else
               {
                    numnit = aux;
                    tamnum = strlen(aux);
               }
          }

          int digitos[tamnum], num1;
          num1 = atoi(numnit);
          for (int i = 0; i < tamnum; i++)
          {
               num1 = numnit[i] - '0';
               digitos[i] = num1;
          }
          int j = 1, acum = 0, mult, n1, n2, n3, n4, n5, codv, codigo;
          for (int i = tamnum - 1; i >= 0; i--)
          {
               j++;
               mult = digitos[i] * j;
               acum = acum + mult;
          }
          n1 = acum / 11;
          n2 = n1 * 11;
          n3 = acum - n2;
          n4 = n3 / 11;
          n5 = n4 * 11;
          codv = n3 - n5;
          codigo = 11 - codv;
          if (numval == codigo)
          {
               real = true;
          }
          if (numval != codigo)
          {
               real = false;
          }
          return real;
     }

void Facture()
{
          SetConsoleTitle("FACTURA");
          Clientes Cliente;
          Facturas Factura;
          FILE *Clients = fopen("Clientes.dat", "a+b");
          FILE *Temporal = fopen("Impresion.txt", "w+");
          int EncontradoNit = 0;
          string Auxnit;
          do
          {
               system("CLS");
               for (int a = 11; a <= 99; a++)
               {
                    gotoxy(a, 3);
                    PUN;
               }
               gotoxy(43, 3);
               cout << " R E G I S T R O  D E   N I T ";
               cout << "\n\n\t\t NIT -> ";
               getline(cin, Auxnit);
               fflush(stdin);
               ValidacionNIT(Auxnit);

          } while (real == false);
          fread(&Cliente, sizeof(Clientes), 1, Clients);
          while (!feof(Clients))
          {
               if (strcmp(Auxnit.c_str(), Cliente.NIT) == 0)
               {
                    EncontradoNit = 1;
                    IA = 1;
                    fflush(stdin);
                    Factura.NoFactura = Contador(IA);
                    FILE *Factures = fopen("Factura.dat", "a+b");
                    strcpy(Factura.NITFactura, Auxnit.c_str());
                    Factura.FechaFactura.d = tmP->tm_mday;
                    Factura.FechaFactura.m = tmP->tm_mon + 1;
                    Factura.FechaFactura.a = tmP->tm_year + 1900;
                    fwrite(&Factura, sizeof(Facturas), 1, Factures);
                    fclose(Factures);
                    system("CLS");
                    cout << "No.Factura " << Factura.NoFactura << "\t Fecha : " << Factura.FechaFactura.d << "/" << Factura.FechaFactura.m << "/" << Factura.FechaFactura.a << endl;
                    cout << "NIT: " << Factura.NITFactura << endl;
                    cout << "Cliente: " << Cliente.NombreCliente << endl;
                    cout << "Direccion: " << Cliente.DireccionCliente << endl;
                    cout << "-------------------------------------------" << endl;
                    fprintf(Temporal, "No.Factura %d \tFecha: %d/%d/%d\n", Factura.NoFactura, Factura.FechaFactura.d, Factura.FechaFactura.m, Factura.FechaFactura.a);
                    fprintf(Temporal, "NIT: %s\n", Factura.NITFactura);
                    fprintf(Temporal, "Cliente: %s\n", Cliente.NombreCliente);
                    fprintf(Temporal, "Direccion: %s\n", Cliente.DireccionCliente);
                    fprintf(Temporal, "-------------------------------------------------\n");
               }
               fread(&Cliente, sizeof(Clientes), 1, Clients);
          }

          if (EncontradoNit == 0)
          {
               fflush(stdin);
               IA = 1;
               cout << "\n\t\t NOMBRE COMPLETO DEL CLIENTE -> ";
               cin.getline(Cliente.NombreCliente, 50, '\n');
               fflush(stdin);
               cout << "\n\t\t DIRECCION DEL CLIENTE -> ";
               cin.getline(Cliente.DireccionCliente, 50, '\n');
               fflush(stdin);
               strcpy(Cliente.NIT, Auxnit.c_str());
               fflush(stdin);
               fwrite(&Cliente, sizeof(Clientes), 1, Clients);
               fflush(stdin);
               Factura.NoFactura = Contador(IA);
               FILE *Factures = fopen("Factura.dat", "a+b");
               strcpy(Factura.NITFactura, Auxnit.c_str());
               Factura.FechaFactura.d = tmP->tm_mday;
               Factura.FechaFactura.m = tmP->tm_mon + 1;
               Factura.FechaFactura.a = tmP->tm_year + 1900;
               fwrite(&Factura, sizeof(Facturas), 1, Factures);
               fclose(Factures);
               system("CLS");
               cout << "No.Factura " << Factura.NoFactura << "\t Fecha : " << Factura.FechaFactura.d << "/" << Factura.FechaFactura.m << "/" << Factura.FechaFactura.a << endl;
               cout << "NIT: " << Factura.NITFactura << endl;
               cout << "Cliente: " << Cliente.NombreCliente << endl;
               cout << "Direccion: " << Cliente.DireccionCliente << endl;
               cout << "-------------------------------------------" << endl;
               fprintf(Temporal, "No.Factura %d \tFecha: %d/%d/%d\n", Factura.NoFactura, Factura.FechaFactura.d, Factura.FechaFactura.m, Factura.FechaFactura.a);
               fprintf(Temporal, "NIT: %s\n", Factura.NITFactura);
               fprintf(Temporal, "Cliente: %s\n", Cliente.NombreCliente);
               fprintf(Temporal, "Direccion: %s\n", Cliente.DireccionCliente);
               fprintf(Temporal, "-------------------------------------------------\n");
          }

          fclose(Clients);
          fclose(Temporal);
     }
int Contador(int valor)
{
          Facturas Factura;
          FILE *Factures = fopen("Factura.dat", "a+b");
          fread(&Factura, sizeof(Facturas), 1, Factures);
          while (!feof(Factures))
          {
               valor = valor + 1;
               fread(&Factura, sizeof(Facturas), 1, Factures);
          }
          fclose(Factures);
          return valor;
     }
void ProductosAComprar()
{
          FILE *Details = fopen("factura_detalle.dat", "a+b");
          FILE *Temporal = fopen("Impresion.txt", "a+");
          Facturas Factura;
          Marcas Marca;
          Productos Producto;
          FacturasDetalle FacturaDetalle;
          double subtotal = 0;
          int AuxCodigo = 0, Contador2 = 0;
          gotoxy(0, 9);
          cout << "No.\tCodigo Producto\tDescripcion\tSubtotal" << endl;
          fprintf(Temporal, "No.\tCodigo\tProducto\tDescripcion\tSubtotal\n");
          FacturaDetalle.idProductos = new int[100];
          FacturaDetalle.PrecioVenta = new double[100];
          do
          {
               int Cantidad = 0;
               gotoxy(0, 8);
               cout << "    ";
               gotoxy(0, 8);
               cin >> AuxCodigo;
               fflush(stdin);
               FILE *Products = fopen("Productos.dat", "rb");
               fread(&Producto, sizeof(Productos), 1, Products);
               while (!feof(Products))
               {
                    if (AuxCodigo == Producto.CodigoProducto)
                    {
                         Contador2++;
                         Cantidad++;
                         FacturaDetalle.idProductos[Cantidad] = AuxCodigo;
                         gotoxy(0, 11 + Contador2);
                         cout << Contador2 << "\t" << Producto.CodigoProducto << "\t" << Producto.DescripcionProducto << " Marca ";
                         fprintf(Temporal, "%d\t%d\t%s\t", Contador2, Producto.CodigoProducto, Producto.DescripcionProducto);
                         FILE *Marcs = fopen("Marcas.dat", "rb");
                         fread(&Marca, sizeof(Marca), 1, Marcs);
                         while (!feof(Marcs))
                         {
                              if (Producto.idMarca == Marca.idMarca)
                              {
                                   cout << Marca.NombreMarca;
                                   fprintf(Temporal, "Marca %s \t", Marca.NombreMarca);
                              }
                              fread(&Marca, sizeof(Marca), 1, Marcs);
                         }
                         fclose(Marcs);
                         cout << "\t Q." << Producto.PrecioVenta << endl;
                         FacturaDetalle.PrecioVenta[Cantidad] = Producto.PrecioVenta;
                         fprintf(Temporal, "Q. %.2f \n", Producto.PrecioVenta);
                         subtotal = subtotal + Producto.PrecioVenta;
                         FacturaDetalle.IdFacturaDetalle = Contador(0);
                         FacturaDetalle.NoFactura = Factura.NoFactura;
                         fwrite(&FacturaDetalle, sizeof(FacturasDetalle), 1, Details);
                    }
                    fread(&Producto, sizeof(Productos), 1, Products);
               }

               fclose(Products);
          } while (AuxCodigo != 0);
          delete[] FacturaDetalle.idProductos;
          delete[] FacturaDetalle.PrecioVenta;
          gotoxy(0, 8);
          cout << "    ";
          gotoxy(0, 12 + Contador2);
          cout << "Total: Q." << subtotal << endl;
          fprintf(Temporal, "Total: Q. %.2f", subtotal);
          fclose(Details);
          fclose(Temporal);
          system("Start imprimir.exe");
     }
void MenuBusquedaCliente()
{
          char opc;
          SetConsoleTitle("MENU BUSQUEDA DE CLIENTES");
          system("CLS");
          for (int a = 10; a <= 101; a++)
          {
               gotoxy(a, 5);
               HOR;
          }
          for (int a = 5; a <= 6; a++)
          {
               gotoxy(9, a);
               VER
          }
          for (int a = 11; a <= 99; a++)
          {
               gotoxy(a, 6);
               PUN;
          }
          for (int a = 10; a <= 101; a++)
          {
               gotoxy(a, 7);
               HOR;
          }
          gotoxy(41, 6);
          cout << " B U S Q U E D A  D E  C L I E N T E S ";
          for (int a = 5; a <= 6; a++)
          {
               gotoxy(110, a);
               VER
          }
          gotoxy(9, 5);
          cout << TOPE;
          gotoxy(110, 5);
          cout << EDA;
          gotoxy(9, 7);
          cout << EIB;
          gotoxy(110, 7);
          cout << EDB;

          for (int a = 10; a <= 101; a++)
          {
               gotoxy(a, 9);
               HOR;
          }
          for (int a = 9; a <= 20; a++)
          {
               gotoxy(9, a);
               VER
          }
          for (int a = 10; a <= 101; a++)
          {
               gotoxy(a, 20);
               HOR;
          }
          for (int a = 9; a <= 20; a++)
          {
               gotoxy(110, a);
               VER
          }
          gotoxy(9, 9);
          cout << TOPE;
          gotoxy(110, 9);
          cout << EDA;
          gotoxy(9, 20);
          cout << EIB;
          gotoxy(110, 20);
          cout << EDB;
          for (int a = 10; a <= 19; a++)
          {
               gotoxy(35, a);
               VER
          }
          for (int a = 10; a <= 19; a++)
          {
               gotoxy(84, a);
               VER
          }
          gotoxy(35, 11);
          cout << V << " -->   [1] POR MEDIO DE NOMBRE                  " << V;
          gotoxy(35, 13);
          cout << V << " -->   [2] POR MEDIO DE NIT                     " << V;
          gotoxy(35, 15);
          ARENBJ;
          gotoxy(35, 19);
          ABJ;
          gotoxy(35, 17);
          cout << V << "         <-- REGRESAR / ESC. SALIR              " << V;
          gotoxy(35, 22);
          opc = getch();
          if (opc == 8)
          {
               MenuFacturas();
          }
          else
          {
               switch (opc)
               {
               case '1':
               {
                    SearchWhitName();
                    getch();
                    MenuBusquedaCliente();
                    break;
               }
               case '2':
               {
                    SearchClientWhitNIT();
                    getch();
                    MenuBusquedaCliente();
                    break;
               }

               case 27:
               {
                    exit(0);
                    break;
               }
               default:
               {
                    cout << "OPCION INCORRECTA, INGRESE NUEVAMENTE LA OPCION" << endl;
                    getch();
                    MenuBusquedaCliente();
                    break;
               }
               }
          }
     }
void SearchWhitName()
{
          fflush(stdin);
          Clientes Cliente;
          FILE *Clients = fopen("Clientes.dat", "rb");
          string aux;
          string nombre;
          bool encontrado = false;
          if (Clients == NULL)
          {
               SetConsoleTitle("Error 002");
               cout << "Error 002" << endl;
               getch();
               MenuBusquedaCliente();
          }
          else
          {
               system("CLS");
               fflush(stdin);
               for (int a = 11; a <= 99; a++)
               {
                    gotoxy(a, 3);
                    PUN;
               }
               gotoxy(38, 3);
               cout << " B U S Q U E D A  D E  C L I E NT E S ";
               cout << "\n\n\t\t NOMBRE DEL CLIENTE QUE DESEA BUSCAR -> ";
               getline(cin, aux);
               fflush(stdin);
               Minusculas(aux);
               SetConsoleTitle("REGISTROS");
               cout << "+--------------------------------------------------------------------------+" << endl;
               cout << "NOMBRE \t\t\t\t   NIT\t\t\tDIRECCION" << endl;
               fread(&Cliente, sizeof(Clientes), 1, Clients);
               do
               {

                    nombre = Cliente.NombreCliente;
                    Minusculas(nombre);
                    fflush(stdin);
                    if (nombre.find(aux) != string::npos)
                    {
                         cout << Cliente.NombreCliente << "\t   " << Cliente.NIT << "\t        " << Cliente.DireccionCliente << endl;
                         cout << "+-------------------------------------------------------------------------+" << endl;
                         encontrado = true;
                    }
                    fread(&Cliente, sizeof(Clientes), 1, Clients);
               } while (feof(Clients) == 0);
               if (encontrado == false)
               {
                    cout << "\n\t\t\t\t\t\t * NO SE ENCUENTRA *" << endl;
               }
               fclose(Clients);
          }
     }
void SearchClientWhitNIT()
{
          fflush(stdin);
          Clientes Cliente;
          FILE *Clients = fopen("Clientes.dat", "rb");
          bool encontrado = false;
          string aux;
          if (Clients == NULL)
          {
               SetConsoleTitle("Error 002");
               cout << "Error 002" << endl;
               getch();
               MenuBusquedaCliente();
          }
          else
          {

               system("CLS");
               fflush(stdin);
               for (int a = 11; a <= 99; a++)
               {
                    gotoxy(a, 3);
                    PUN;
               }
               gotoxy(40, 3);
               cout << " B U S Q U E D A  D E  C L I E NT E S ";
               cout << "\n\n\t\t NIT DEL CLIENTE QUE DESEA BUSCAR -> ";
               getline(cin, aux);
               fflush(stdin);
               SetConsoleTitle("REGISTROS");
               cout << "+--------------------------------------------------------------------------+" << endl;
               cout << "NOMBRE \t\t\t\t   NIT\t\t\tDIRECCION" << endl;
               fread(&Cliente, sizeof(Clientes), 1, Clients);
               do
               {
                    fflush(stdin);
                    if (strcmp(aux.c_str(), Cliente.NIT) == 0)
                    {
                         cout << Cliente.NombreCliente << "\t   " << Cliente.NIT << "\t        " << Cliente.DireccionCliente << endl;
                         cout << "+-------------------------------------------------------------------------+" << endl;
                         encontrado = true;
                    }
                    fread(&Cliente, sizeof(Clientes), 1, Clients);
               } while (feof(Clients) == 0);
               if (encontrado == false)
               {
                    cout << "\n\t\t\t\t\t\t * NO SE ENCUENTRA *" << endl;
               }
               fclose(Clients);
          }
     }
void MenuBusquedaFactura()
{
          char opc;
          SetConsoleTitle("MENU BUSQUEDA DE FACTURA");
          system("CLS");
          for (int a = 10; a <= 101; a++)
          {
               gotoxy(a, 5);
               HOR;
          }
          for (int a = 5; a <= 6; a++)
          {
               gotoxy(9, a);
               VER
          }
          for (int a = 11; a <= 99; a++)
          {
               gotoxy(a, 6);
               PUN;
          }
          for (int a = 10; a <= 101; a++)
          {
               gotoxy(a, 7);
               HOR;
          }
          gotoxy(41, 6);
          cout << " B U S Q U E D A  D E  F A C T U R A ";
          for (int a = 5; a <= 6; a++)
          {
               gotoxy(110, a);
               VER
          }
          gotoxy(9, 5);
          cout << TOPE;
          gotoxy(110, 5);
          cout << EDA;
          gotoxy(9, 7);
          cout << EIB;
          gotoxy(110, 7);
          cout << EDB;

          for (int a = 10; a <= 101; a++)
          {
               gotoxy(a, 9);
               HOR;
          }
          for (int a = 9; a <= 20; a++)
          {
               gotoxy(9, a);
               VER
          }
          for (int a = 10; a <= 101; a++)
          {
               gotoxy(a, 20);
               HOR;
          }
          for (int a = 9; a <= 20; a++)
          {
               gotoxy(110, a);
               VER
          }
          gotoxy(9, 9);
          cout << TOPE;
          gotoxy(110, 9);
          cout << EDA;
          gotoxy(9, 20);
          cout << EIB;
          gotoxy(110, 20);
          cout << EDB;
          for (int a = 10; a <= 19; a++)
          {
               gotoxy(35, a);
               VER
          }
          for (int a = 10; a <= 19; a++)
          {
               gotoxy(84, a);
               VER
          }
          gotoxy(35, 11);
          cout << V << " -->   [1] POR MEDIO DE CORRELATIVO             " << V;
          gotoxy(35, 13);
          cout << V << " -->   [2] POR MEDIO DE NIT                     " << V;
          gotoxy(35, 15);
          ARENBJ;
          gotoxy(35, 19);
          ABJ;
          gotoxy(35, 17);
          cout << V << "         <-- REGRESAR / ESC. SALIR              " << V;
          gotoxy(35, 22);
          opc = getch();
          if (opc == 8)
          {
               MenuFacturas();
          }
          else
          {
               switch (opc)
               {
               case '1':
               {
                    SearchWhitCorrelative();
                    getch();
                    MenuBusquedaFactura();
                    break;
               }
               case '2':
               {
                    SearchFactureWhitNIT();
                    getch();
                    MenuBusquedaFactura();
                    break;
               }

               case 27:
               {
                    exit(0);
                    break;
               }
               default:
               {
                    cout << "Opcion Incorreta elija de nuevo" << endl;
                    getch();
                    MenuBusquedaCliente();
                    break;
               }
               }
          }
     }
void SearchWhitCorrelative()
{
          fflush(stdin);
          Facturas Factura;
          FILE *Factures = fopen("Factura.dat", "rb");
          bool encontrado = false;
          int aux = 0;
          if (Factures == NULL)
          {
               SetConsoleTitle("Error 002");
               cout << "Error 002" << endl;
               getch();
               MenuBusquedaCliente();
          }
          else
          {
               system("CLS");
               fflush(stdin);
               for (int a = 11; a <= 99; a++)
               {
                    gotoxy(a, 3);
                    PUN;
               }
               gotoxy(38, 3);
               cout << " B U S Q U E D A  D E  F A C T U R A S ";
               cout << "\n\n\t\t CORRELATIVO DE LA FACTURA QUE QUE DESEA BUSCAR -> ";
               cin >> aux;
               fflush(stdin);
               SetConsoleTitle("REGISTROS");
               cout << "+--------------------------------------------------------------------------+" << endl;
               cout << "No.Factura\t\tFecha\t\t       NIT" << endl;
               fread(&Factura, sizeof(Facturas), 1, Factures);
               do
               {
                    fflush(stdin);
                    if (aux == Factura.NoFactura)
                    {
                         cout << Factura.NoFactura << "\t                " << Factura.FechaFactura.d << "/" << Factura.FechaFactura.m << "/" << Factura.FechaFactura.a << "\t       " << Factura.NITFactura << endl;
                         cout << "+-------------------------------------------------------------------------+" << endl;
                         encontrado = true;
                    }
                    fread(&Factura, sizeof(Facturas), 1, Factures);
               } while (feof(Factures) == 0);
               if (encontrado == false)
               {
                    cout << "\n\t\t\t\t\t\t * NO SE ENCUENTRA *" << endl;
               }
               fclose(Factures);
          }
     }
void SearchFactureWhitNIT()
{
          fflush(stdin);
          Facturas Factura;
          FILE *Facture = fopen("Factura.dat", "rb");
          bool encontrado = false;
          string aux;
          if (Facture == NULL)
          {
               SetConsoleTitle("Error 002");
               cout << "Error 002" << endl;
               getch();
               MenuBusquedaFactura();
          }
          else
          {
               system("CLS");
               fflush(stdin);
               for (int a = 11; a <= 99; a++)
               {
                    gotoxy(a, 3);
                    PUN;
               }
               gotoxy(38, 3);
               cout << " B U S Q U E D A  D E  F A C T U R A S ";
               cout << "\n\n\t\t NIT QUE DESEA BUSCAR -> ";
               getline(cin, aux);
               fflush(stdin);
               SetConsoleTitle("REGISTROS");
               cout << "+--------------------------------------------------------------------------+" << endl;
               cout << "No.Factura\t\tFecha\t\t       NIT" << endl;
               fread(&Factura, sizeof(Facturas), 1, Facture);
               do
               {
                    fflush(stdin);
                    if (strcmp(aux.c_str(), Factura.NITFactura) == 0)
                    {
                         cout << Factura.NoFactura << "\t                " << Factura.FechaFactura.d << "/" << Factura.FechaFactura.m << "/" << Factura.FechaFactura.a << "\t       " << Factura.NITFactura << endl;
                         cout << "+-------------------------------------------------------------------------+" << endl;
                         encontrado = true;
                    }
                    fread(&Factura, sizeof(Facturas), 1, Facture);
               } while (feof(Facture) == 0);
               if (encontrado == false)
               {
                    cout << "\n\t\t\t\t\t\t * NO SE ENCUENTRA *" << endl;
               }
               fclose(Facture);
          }
     }
void MenuAyuda()
{
          char opc;
          SetConsoleTitle("MENU DE AYUDA");
          system("CLS");
          for (int a = 10; a <= 101; a++)
          {
               gotoxy(a, 5);
               HOR;
          }
          for (int a = 5; a <= 6; a++)
          {
               gotoxy(9, a);
               VER
          }
          for (int a = 11; a <= 99; a++)
          {
               gotoxy(a, 6);
               PUN;
          }
          for (int a = 10; a <= 101; a++)
          {
               gotoxy(a, 7);
               HOR;
          }
          gotoxy(54, 6);
          cout << " A Y U D A ";
          for (int a = 5; a <= 6; a++)
          {
               gotoxy(110, a);
               VER
          }
          gotoxy(9, 5);
          cout << TOPE;
          gotoxy(110, 5);
          cout << EDA;
          gotoxy(9, 7);
          cout << EIB;
          gotoxy(110, 7);
          cout << EDB;

          for (int a = 10; a <= 101; a++)
          {
               gotoxy(a, 9);
               HOR;
          }
          for (int a = 9; a <= 22; a++)
          {
               gotoxy(9, a);
               VER
          }
          for (int a = 10; a <= 101; a++)
          {
               gotoxy(a, 22);
               HOR;
          }
          for (int a = 9; a <= 22; a++)
          {
               gotoxy(110, a);
               VER
          }
          gotoxy(9, 9);
          cout << TOPE;
          gotoxy(110, 9);
          cout << EDA;
          gotoxy(9, 22);
          cout << EIB;
          gotoxy(110, 22);
          cout << EDB;
          for (int a = 10; a <= 20; a++)
          {
               gotoxy(35, a);
               VER
          }
          for (int a = 10; a <= 20; a++)
          {
               gotoxy(84, a);
               VER
          }
          gotoxy(35, 11);
          cout << V << " -->   [1] ERRORES                              " << V;
          gotoxy(35, 13);
          cout << V << " -->   [2] MANUAL DE USUARIO                    " << V;
          gotoxy(35, 15);
          cout << V << " -->   [3] DIAGRAMA ENTIDAD RELACION            " << V;
          gotoxy(35, 17);
          ARENBJ;
          gotoxy(35, 21);
          ABJ;
          gotoxy(35, 19);
          cout << V << "         <-- REGRESAR / ESC. SALIR              " << V;
          gotoxy(35, 23);
          opc = getch();
          if (opc == 8)
          {
               MenuPrincipal();
          }
          else
          {
               switch (opc)
               {
               case '1':
               {

                    getch();
                    MenuAyuda();
                    break;
               }
               case '2':
               {
                    getch();
                    MenuAyuda();
                    break;
               }

               case '3':
               {
                    getch();
                    MenuAyuda();
                    break;
               }
               case 27:
               {
                    exit(0);
                    break;
               }
               default:
               {
                    cout << "Opcion Incorreta elija de nuevo" << endl;
                    getch();
                    MenuAyuda();
                    break;
               }
               }
          }
     }
void Minusculas(string & s)
{
          int i;
          for (i = 0; i < s.length(); i++)
          {
               s[i] = tolower(s[i]);
          }
     }

/*void mostrar(){
     system("CLS");
     Facturas Factura;
     Clientes Cliente;
FILE *Facturation=fopen("Factura.dat","rb");
fread(&Factura,sizeof(Facturas),1,Facturation);
while(!feof(Facturation)){
cout<<Factura.NoFactura<<endl;
cout<<Factura.NITFactura<<endl;
cout<<Factura.FechaFactura.d<<"/"<<Factura.FechaFactura.m<<"/"<<Factura.FechaFactura.a<<endl;
fread(&Factura,sizeof(Facturas),1,Facturation);
}
cout<<"---------------------------------------------------"<<endl;
FILE *Clients=fopen("Clientes.dat","rb");
fread(&Cliente,sizeof(Clientes),1,Clients);
while(!feof(Clients)){
cout<<Cliente.NombreCliente<<endl;
cout<<Cliente.NIT<<endl;
cout<<Cliente.DireccionCliente<<endl;

fread(&Cliente,sizeof(Clientes),1,Clients);
}
fclose(Facturation);
fclose(Clients);

}

*/
