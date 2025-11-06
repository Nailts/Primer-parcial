# Trayectoria de Persecución: Torpedo vs Submarino

## 📋 Descripción del Problema

Simulación numérica de la persecución de un submarino por un torpedo. El submarino se mueve en línea recta mientras el torpedo ajusta continuamente su dirección para apuntar siempre hacia el objetivo.

## 🎯 Objetivo

Implementar en C++ un programa que:
- Modele el movimiento de ambos vehículos usando ecuaciones diferenciales
- El torpedo siempre apunte hacia la posición actual del submarino
- Detenga la simulación cuando la distancia sea menor a ε
- Genere archivos de trayectorias para visualización

## 🧮 Física del Problema

### Movimiento del Submarino
- Velocidad constante `u`
- Trayectoria rectilínea con ángulo `α`
- Ecuación: movimiento uniforme

### Movimiento del Torpedo  
- Velocidad constante `v`
- Dirección variable: siempre hacia el submarino
- Ecuaciones diferenciales acopladas

## 📊 Entradas del Programa

```cpp
double v;      // Velocidad del torpedo
double u;      // Velocidad del submarino  
double alpha;  // Ángulo de trayectoria del submarino (radianes)
double h;      // Altura inicial del submarino
double epsilon;// Distancia mínima para intercepción
