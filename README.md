# Proyecto Final: Algoritmos de Grafos  
**Materia:** Estructuras avanzadas  
**Fecha de entrega:** 4 de diciembre  

---

## Introducción
Este repositorio contiene la implementación de múltiples representaciones y algoritmos fundamentales de grafos, desarrollados en **C++** siguiendo buenas prácticas de programación, modularidad y un flujo profesional con Git/GitHub.

El proyecto es dividio de la siguiente forma, incluyendo los algoritmos correspondientes:
<details>
<summary>/src <--- click</summary>

### Baruc
- Representaciones de Grafo  
- Recorridos 
### Isa 
- Componentes Conexas 
- Caminos más cortos
### Gaby
- Árboles de expansión
- Verificar si un grafo es un árbol
### Fabricio
- Grafo bipartito  
- Matching(Pareo)
### Jorge 
- Pareos perfectos y maximales 

</details>
<details>
<summary>/test <--- click</summary>

### Baruc
- testeo de Representaciones de Grafo  
- testeo de Recorridos 
### Isa 
- testeo de Componentes Conexas 
- testeo de Caminos más cortos
### Gaby
- testeo de Árboles de expansión
- testeo de Verificar si un grafo es un árbol
### Fabricio
- testeo de Grafo bipartito  
- testeo de Matching(Pareo)
## Jorge  
- testeo de Pareos perfectos y maximales

</details>



Cada sección fue implementada por distintos integrantes del equipo utilizando ramas separadas y Pull Requests.

---

---

# Especifiaciones de los algoritmos

Los algoritmos logran funcionar con:

- Grafos dirigidos / no dirigidos  
- Grafos ponderados / no ponderados  

---

# Algoritmos Implementados

###  Representación de grafos
- Matriz de Adyacencia
- Lista de Adyacencia
- Matriz de Incidencia

###  Recorridos
- DFS  
- BFS  

### Componentes Conexas
- Componentes en grafos no dirigidos  
- SCC (Kosaraju, Tarjan)

### Caminos más cortos
- Dijkstra  
- Bellman-Ford  
- Floyd-Warshall  

### Árboles de expansión
- Kruskal  
- Prim  
- Reverse-Kruskal  

### Verificar si es un árbol
- Conectividad  
- Detección de ciclos  
- Validación |E| = n − 1 

### Grafo bipartito
- BFS por coloreo
- DFS por coloreo
- Ciclos impares

## Matching(Pareo)
- Greedy
- Augmentig path
- Simple Alternating path

### Pareos perfectos y maximales
- Perfect matching 
- Maximal Matching
- Eliminación de hojas

---

# Cómo Compilar y Ejecutar el Proyecto

A continuación se presentan varias formas de ejecutar el proyecto dependiendo del entorno.

---

# 1. Ejecutar desde **VSCode** (RECOMENDADO)

##  Prerrequisitos
Instalar extensiones en **vscode**:
- **C/C++** (Microsoft)
- **C/C++ Compile Run** (opcional)
- Tener instalado `g++` (MSYS2, MinGW o WSL)

# Cómo Compilar y Ejecutar el Proyecto en Visual Studio Code (VSCode)

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
---
### 4. Compilar en VSCode
1. Abrir:

```bash
src/NOMBRE_DEL_ARCHIVO.cpp
```

2. Arriba a la derecha verás un botón:

```bash
▶ Run C/C++ File
```
---
---

## Conclusión general

Este proyecto integra representaciones de grafos y algoritmos fundamentales, diseñados durante el curso de Estructuras Computacionales Avanzadas, fueron implementados con claridad y colaboración profesional mediante Git/GitHub.
Es una base sólida tanto para aprendizaje como para ampliaciones futuras.

---
---
