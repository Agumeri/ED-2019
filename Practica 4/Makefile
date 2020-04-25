SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11
all:$(BIN)/cocinero_integral

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/Doxy-file


# ************ Compilación de módulos ************

$(OBJ)/Ingrediente.o: $(SRC)/Ingrediente.cpp $(INC)/Ingrediente.h
	$(CXX) $(CPPFLAGS) $(SRC)/Ingrediente.cpp -o $(OBJ)/Ingrediente.o

$(OBJ)/Ingredientes.o: $(SRC)/Ingredientes.cpp $(INC)/Ingredientes.h $(INC)/Ingrediente.h
	$(CXX) $(CPPFLAGS) $(SRC)/Ingredientes.cpp -o $(OBJ)/Ingredientes.o 

$(OBJ)/receta.o: $(SRC)/receta.cpp $(INC)/receta.h $(INC)/Ingrediente.h $(INC)/Ingredientes.h
	$(CXX) $(CPPFLAGS) $(SRC)/receta.cpp -o $(OBJ)/receta.o

$(OBJ)/recetas.o: $(SRC)/recetas.cpp $(INC)/recetas.h
	$(CXX) $(CPPFLAGS) $(SRC)/recetas.cpp -o $(OBJ)/recetas.o 

$(OBJ)/acciones.o: $(SRC)/acciones.cpp $(INC)/acciones.h
	$(CXX) $(CPPFLAGS) $(SRC)/acciones.cpp -o $(OBJ)/acciones.o

$(OBJ)/instrucciones.o: $(SRC)/instrucciones.cpp $(INC)/acciones.h $(INC)/instrucciones.h $(INC)/arbolbinario.h $(INC)/arbolbinario.tpp
	$(CXX) $(CPPFLAGS)  $(SRC)/instrucciones.cpp -o  $(OBJ)/instrucciones.o

$(OBJ)/cocinero_integral.o: $(SRC)/cocinero_integral.cpp $(INC)/acciones.h $(INC)/receta.h $(INC)/recetas.h $(INC)/Ingrediente.h $(INC)/Ingredientes.h
	$(CXX) $(CPPFLAGS)  $(SRC)/cocinero_integral.cpp -o  $(OBJ)/cocinero_integral.o

$(BIN)/cocinero_integral: $(OBJ)/cocinero_integral.o $(OBJ)/receta.o $(OBJ)/recetas.o $(OBJ)/Ingrediente.o $(OBJ)/Ingredientes.o $(OBJ)/instrucciones.o $(OBJ)/acciones.o
	$(CXX) -o $(BIN)/cocinero_integral	$(OBJ)/cocinero_integral.o  $(OBJ)/receta.o $(OBJ)/recetas.o $(OBJ)/Ingrediente.o $(OBJ)/Ingredientes.o $(OBJ)/instrucciones.o $(OBJ)/acciones.o
# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm $(OBJ)/*.o
	rm $(BIN)/cocinero_integral

mrproper : clean
	-rm -R doc/html doc/latex
