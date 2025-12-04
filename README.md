# Proyecto Final: Algoritmos de Grafos  
**Materia:** Análisis de Algoritmos  
**Fecha de entrega:** 4 de diciembre  
**Equipo:** [Nombres del equipo]

---

## Introducción
Este repositorio contiene la implementación de múltiples representaciones y algoritmos fundamentales de grafos, desarrollados en **C++** siguiendo buenas prácticas de programación, modularidad y un flujo profesional con Git/GitHub.

El proyecto incluye:

- Representaciones internas de grafos  
- Algoritmos de recorrido  
- Algoritmos de componentes  
- Caminos más cortos  
- Árboles de expansión mínima/máxima  
- Verificación de propiedades del grafo  
- Algoritmos de pareos (matchings)  
- Pruebas y demostraciones  

Cada sección fue implementada por distintos integrantes del equipo utilizando ramas separadas y Pull Requests.

---

---

# Representaciones de Grafos

El proyecto incluye 3 representaciones compatibles con:

- Grafos dirigidos / no dirigidos  
- Grafos ponderados / no ponderados  

Representaciones:

- Matriz de Adyacencia  
- Lista de Adyacencia  
- Matriz de Incidencia  

---

# Algoritmos Implementados

###  Representación de grafos
- Matriz de Adyacencia
- Lista de Adyacencia
- Matriz de Incidencia

###  Recorridos
- DFS  
- BFS  

### 🔹 Componentes Conexas
- Componentes en grafos no dirigidos  
- SCC (Kosaraju, Tarjan)

### 🔹 Caminos más cortos
- Dijkstra  
- Bellman-Ford  
- Floyd-Warshall  

### 🔹 Árboles de expansión
- Kruskal  
- Prim  
- Reverse-Kruskal  

### 🔹 Verificar si es un árbol
- Conectividad  
- Detección de ciclos  
- Validación |E| = n − 1  

### 🔹 Pareos (Matchings)
- Matching maximal  
- Matching máximo básico  
- Pareos en bipartitos (versión simple)
- Pareos en no bipartitos (nivel básico)

---

# ⚙️ Cómo Compilar y Ejecutar el Proyecto

A continuación se presentan varias formas de ejecutar el proyecto dependiendo del entorno.

---

# 🟦 1. Ejecutar desde **VSCode** (RECOMENDADO)

## ✔ Prerrequisitos
Instalar extensiones:
- **C/C++** (Microsoft)
- **C/C++ Compile Run** (opcional)
- Tener instalado `g++` (MSYS2, MinGW o WSL)

# ⚙️ Cómo Compilar y Ejecutar el Proyecto en Visual Studio Code (VSCode)

A continuación se muestran las instrucciones completas para configurar VSCode y compilar con un **solo botón**.

---

## 1. Instalar el compilador (g++)

###  Opción recomendada: MSYS2 (ucrt64)

1. Instalar MSYS2.  
2. Abrir **MSYS2 UCRT64**.  
3. Ejecutar:

```bash
pacman -Syu
pacman -S ucrt64/mingw-w64-ucrt-x86_64-gcc
```
## 2. Instalar extensiones de vscode (g++)

1. C/C++ (Microsoft)
2. C/C++ Compile Run ← NECESARIA
3. *(Opcional) Code Runner*

### 3. Configurar VSCode para usar tu compilador

1. Abrir paleta de comandos:

```bash
Ctrl + Shift + P 
```

2. Buscar

```bash 
C/C++: Edit Configurations (UI) 
```

3. En **Compilar path** elegir:

```bash
C:/msys64/ucrt64/bin/g++.exe 
```

4. En **IntelliSense Mode**, seleccionar:

```bash
windows-gcc-x64 
```
### 4. Compilar usando el botón en VSCode
1. Abrir:

```bash
src/NOMBRE_DEL_ARCHIVO.cpp
```

2. Arriba a la derecha verás un botón:

```bash
▶ Run C/C++ File
```

### conclusiones

Este proyecto integra representaciones de grafos y algoritmos fundamentales, diseñados con estructura modular, claridad y colaboración profesional mediante Git/GitHub.
Es una base sólida tanto para aprendizaje como para ampliaciones futuras.