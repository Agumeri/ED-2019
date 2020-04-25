SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11
all:$(BIN)/test_ingredientes $(BIN)/test_receta $(BIN)/nutricion_receta

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/Doxy-file


# ************ Compilación de módulos ************

$(OBJ)/Ingrediente.o: $(SRC)/Ingrediente.cpp $(INC)/Ingrediente.h
	$(CXX) $(CPPFLAGS) $(SRC)/Ingrediente.cpp -o $(OBJ)/Ingrediente.o

$(OBJ)/Ingredientes.o: $(SRC)/Ingredientes.cpp $(INC)/Ingredientes.h $(INC)/Ingrediente.h
	$(CXX) $(CPPFLAGS) $(SRC)/Ingredientes.cpp -o $(OBJ)/Ingredientes.o 

$(OBJ)/test_ingredientes.o: $(SRC)/test_ingredientes.cpp $(INC)/Ingrediente.h $(INC)/Ingredientes.h
	$(CXX) $(CPPFLAGS) $(SRC)/test_ingredientes.cpp -o $(OBJ)/test_ingredientes.o

$(BIN)/test_ingredientes: $(OBJ)/test_ingredientes.o $(OBJ)/Ingredientes.o $(OBJ)/Ingrediente.o
	$(CXX) -o $(BIN)/test_ingredientes $(OBJ)/test_ingredientes.o $(OBJ)/Ingredientes.o $(OBJ)/Ingrediente.o

$(OBJ)/receta.o: $(SRC)/receta.cpp $(INC)/receta.h $(INC)/Ingrediente.h $(INC)/Ingredientes.h
	$(CXX) $(CPPFLAGS) $(SRC)/receta.cpp -o $(OBJ)/receta.o

$(OBJ)/recetas.o: $(SRC)/recetas.cpp $(INC)/recetas.h
	$(CXX) $(CPPFLAGS) $(SRC)/recetas.cpp -o $(OBJ)/recetas.o 

$(OBJ)/test_receta.o: $(SRC)/test_receta.cpp $(INC)/receta.h $(INC)/recetas.h
	$(CXX) $(CPPFLAGS) $(SRC)/test_receta.cpp -o $(OBJ)/test_receta.o

$(BIN)/test_receta: $(OBJ)/test_receta.o $(OBJ)/recetas.o $(OBJ)/receta.o $(OBJ)/Ingredientes.o $(OBJ)/Ingrediente.o
	$(CXX) -o $(BIN)/test_receta $(OBJ)/test_receta.o $(OBJ)/recetas.o $(OBJ)/receta.o $(OBJ)/Ingredientes.o $(OBJ)/Ingrediente.o

$(OBJ)/nutricion_receta.o: $(SRC)/nutricion_receta.cpp $(INC)/receta.h $(INC)/recetas.h $(INC)/Ingrediente.h $(INC)/Ingredientes.h
	$(CXX) $(CPPFLAGS)  $(SRC)/nutricion_receta.cpp -o  $(OBJ)/nutricion_receta.o

$(BIN)/nutricion_receta: $(OBJ)/nutricion_receta.o $(OBJ)/receta.o $(OBJ)/recetas.o $(OBJ)/Ingredientes.o $(OBJ)/Ingrediente.o
	$(CXX) -o $(BIN)/nutricion_receta $(OBJ)/nutricion_receta.o $(OBJ)/receta.o $(OBJ)/recetas.o $(OBJ)/Ingredientes.o $(OBJ)/Ingrediente.o

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm $(OBJ)/*.o
	rm $(BIN)/test_ingredientes $(BIN)/test_receta $(BIN)/nutricion_receta

mrproper : clean
	-rm -R doc/html doc/latex
