# 🎮 Cuatro en Raya
 
<p align="center">
  <img src="https://raw.githubusercontent.com/isocpp/logos/master/cpp_logo.png" width="110">
</p>
<p align="center">
  <strong>Clásico juego de Cuatro en Raya desarrollado desde cero en C++</strong>
</p>
<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white">
  <img src="https://img.shields.io/badge/Console-Game-222222?style=for-the-badge">
</p>
---
 
## 🎮 Acerca del proyecto
 
**Cuatro en Raya** es un juego de consola para dos jugadores desarrollado
íntegramente en **C++**.
 
Los jugadores se turnan para seleccionar una columna en un tablero de
**6 × 7**, intentando conectar cuatro fichas de forma horizontal, vertical
o diagonal.
 
El proyecto fue construido desde cero, sin librerías externas ni motores
de juego.
 
---
 
## ⚙️ Cómo funciona
 
El juego sigue un bucle simple:
 
```text
┌────────────────┐
│  Inicializar   │
│    Tablero     │
└───────┬────────┘
        ↓
┌────────────────┐
│ Elegir Columna │
└───────┬────────┘
        ↓
┌────────────────┐
│ Colocar Ficha  │
└───────┬────────┘
        ↓
┌────────────────┐
│ Verificar      │
│ Victoria       │
└───────┬────────┘
        ↓
   ┌────┴────┐
   │         │
  SÍ         NO
   │         │
   ↓         ↓
  FIN    Siguiente
         Turno
```

# 🔴🟡 Cuatro en Raya — C++
 
El tablero se representa con un arreglo bidimensional:
 
```cpp
char mapa[6][7];
```
 
Cada jugada guarda su posición y ficha usando:
 
```cpp
struct Coordenadas {
    int fila;
    int columna;
    char ficha;
};
```
 
Después de cada jugada, el programa verifica fichas consecutivas en tres direcciones:
 
```
Horizontal     Vertical       Diagonal
 
X X X X           X             X
                  X               X
                  X                 X
                  X                   X
```
 
Las funciones `horizontal()`, `vertical()` y `diagonal()` realizan estas verificaciones, mientras que `ganador()` determina si la jugada resultó en una victoria.
 
## ✨ Features
 
- 👥 Juego local para dos jugadores
- 🧱 Tablero de 6 × 7
- 🔄 Sistema de turnos automático
- 📍 Colocación de fichas por columna
- 🏆 Detección horizontal, vertical y diagonal
- ⌨️ Interfaz de consola
- ⚡ Sin dependencias externas
## 🧠 Conceptos
 
El proyecto aplica conceptos fundamentales de C++:
 
`struct` · arreglos · funciones · bucles · condicionales · lógica booleana · entrada/salida por consola · parámetros · búsqueda algorítmica · manejo del estado del juego
 
## 🚀 Getting Started
 
### Requisitos
 
Un compilador de C++ como G++.
 
### Compilar
 
```bash
g++ -std=c++17 f_raya.cpp -o out
```
 
### Ejecutar
 
**Linux / WSL**
 
```bash
./out
```
 
**Windows**
 
```bash
out.exe
```
 
## 📁 Estructura del proyecto
 
```
cuatro-en-raya/
├── f_raya.cpp
└── README.md
```
 
El juego completo está implementado en `f_raya.cpp`.
 
## 🎯 Objetivo del proyecto
 
Un pequeño proyecto enfocado en convertir las reglas de un juego clásico en un programa completo de C++, combinando representación de datos, entrada del usuario, control de flujo y algoritmos de detección de victoria.
 
## 👨‍💻 Autor
 
Nícolas Orrego
 
Construido desde cero con C++.
