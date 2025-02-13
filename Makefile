# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica 2: Cadenas y lenguajes
# Autor: Daniel Alejandro Goncalves Rodrigues
# Correo: alu0101595573@ull.edu.es
# Fecha: 17/09/2024
# Archivo cya-P02-strings.cc: programa cliente.
# Contiene la función main del proyecto que usa las clases X e Y
# para ... (indicar brevemente el objetivo)
# Referencias:
# Enlaces de interés
#
# Historial de revisiones
# 17/09/2024 - Creación (primera versión) del código

CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
LDFLAGS =

# El nombre del ejecutable final
EXECUTABLE = big_unsigned

# Listado de archivos fuente
SOURCES = big_unsigned.cc main_client.cc
# Genera nombres de archivos objeto a partir de los archivos fuente
OBJECTS = $(SOURCES:.cc=.o)

# El objetivo por defecto que se compila
all: $(EXECUTABLE)

# Regla para compilar el ejecutable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Regla para compilar los archivos objeto
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

# Objetivo para limpiar archivos generados
.PHONY: all clean
clean:
	rm -f $(EXECUTABLE) *.o
	rm -rf *~ basura b i
	rm -rf a.out
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;
