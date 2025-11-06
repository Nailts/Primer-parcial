#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "../Include/funcionesParcial.h"
using namespace std;


// ====================== CONSTANTES ======================
    const double EPSILON = 1.0e-6; // tolerancia para incluir el tf en el bucle
    const double g = 9.8;  // Contante de aceleracion gravitacional terrestre

// ===================== FUNCIONES =======================

  void solicitarDatos (double &y0, double &y, double &x, double &xf, double &H, double &h, double &VH, double &v,
            double &t0, double &t, double &tf, double &dt, double &z){

        cout <<"    *** CONDICIONES INICIALES DEL PROBLEMA ***"<< endl;  

        cout << "Altura inicial del submarino (m): ";
        cin  >> H;

        cout << "Altura inicial del torpedo y0 (m): ";
        cin  >> y0;

        cout << "Velocidad del submarino VH (m/s): ";
        cin  >> VH;

        cout << "Velocidad del torpedo v (m/s): ";
        cin>> v;

        cout << "Paso del tiempo dt (s): ";
        cin >> dt;


        cout<<" "<<endl;

    }

    // Verifica que los datos cumplan restricciones mínimas.
    void validarDatos(double &y0, double &y, double &x, double &xf, double &H, double &h, double &VH, double &v,
            double &t0, double &t, double &tf, double &dt, double &z) {
        
        // H > 0
        do {
            if (H <= 0.0) {
                cout << "H debe ser positivo. Ingrese H: ";
                cin  >> H;
            }
        } while (H <= 0.0);

        t0=0;

        // y0 >= 0 
        do {
            if (y0 < 0) {
                cout << "y0 debe ser positivo. Ingrese y0: ";
                cin  >> y0;
            }
        } while (y0 < 0);

        // VH != 0 
        do {
            if (VH == 0.0) {
                cout << "VH no puede ser 0. Ingrese VH: ";
                cin  >> VH;
            }
        } while (VH == 0.0);

       // v > VH
        do {
            if (v < VH) {
                cout << "v no puede ser menor o igual que la velocidad VH del submarino. Ingrese v: ";
                cin  >> v;
            }
        } while (v < VH);
        

        double ter1, ter2, ter3,digidt;


        ter3 = (v) / (-pow(VH, 2) + pow(v, 2));
        tf = H*ter3;  // CONSTANTE 

    }

// Simula y guarda en archivo: t, x, y, vxt, vyt (movimiento del torpedo y submarino)
void simularMovimiento(double &y0, double &y, double &x, double &xf, double &H, double &h, double &VH, double &v,
            double &t0, double &t, double &tf, double &dt, double &z) {

    // 1) Crear archivo de salida
    ofstream myfile("Resultados/datos_colisión.dat");
    myfile << fixed << setprecision(5);

    // 2) Encabezado de columnas
    myfile << setw(10) << "t"
           << setw(12) << "x_torpedo"
           << setw(12) << "y_torpedo"
           << setw(12) << "H_sub"
           << setw(12) << "h sub"
           << setw(12) << "vxt"
           << setw(12) << "vyt"
           << setw(12) << "Alpha" << '\n';

    // 3) Variables iniciales
    t = t0;
    int i = 0;

    h = 0;          // posición horizontal del submarino
    x = 0;          // posición horizontal del torpedo
    y = y0;           // posición vertical del torpedo

    // 4) Parámetros iniciales del modelo
    z= 1 - (y0/H);
    double tervy  = pow(z, VH/v) + pow(z, -VH/v);
    double vy    = (2 * v) / tervy;
    double vx    = sqrt(pow(v, 2) - pow(vy, 2));

    // Punto de colisión aproximado (para condición de parada)
    double terxde= 1-(pow(VH,2)/pow(v,2));
    double terxnu= (VH)/(v);
    
    xf = H*(terxnu)/(terxde);
    cout<<" "<<endl;
    cout<< "POSICION DE COLISION: "<<xf<<" m"<<endl; 

    // Variables auxiliares
    double z_t, tervt, vxt, vyt,alpha_rad,alpha;
    

        // 5) Bucle de integración temporal   t <= tf && 
        while (t <= tf &&  h <=  xf - EPSILON ) {

            // Actualizar posición del submarino (MRU)
            h = VH * t;

            // Actualizar factor z dependiente de la posición del torpedo
            z_t = 1 - (y / H);
            
            tervt = pow(z_t, VH/v) + pow(z_t, -VH/v);

            // Actualizar componentes de velocidad del torpedo
            vyt = (2 * v) / tervt;
            vxt = sqrt(pow(v, 2) - pow(vyt, 2));

            //Angulo alpha instantaneo de la trayectoria del proyectil.
            alpha_rad = atan(vyt/vxt);
            alpha= (alpha_rad*180)/M_PI;

            // Guardar datos por paso
            myfile << setw(10) << t
                << setw(12) << x
                << setw(12) << y
                << setw(12) << H
                << setw(12) << h
                << setw(12) << vxt
                << setw(12) << vyt 
                << setw(12) << alpha <<'\n';

             // Avanzar posiciones (integración paso a paso)
            y += vyt*dt ;
            x += vxt*dt;
            // Avanzar tiempo
            i++;
            t = i * dt;
        }

        // 6) Cierre del archivo
        myfile.close();
    }
