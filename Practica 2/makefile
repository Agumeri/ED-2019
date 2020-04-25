SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11
all:$(BIN)/test_ingredientes $(BIN)/tipos_ingredientes

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/Doxy-file


# ************ Compilación de módulos ************

$(OBJ)/Ingrediente.o: $(SRC)/Ingrediente.cpp $(INC)/Ingrediente.h
	$(CXX) $(CPPFLAGS) $(SRC)/Ingrediente.cpp -o $(OBJ)/Ingrediente.o

$(OBJ)/Ingredientes.o: $(SRC)/Ingredientes.cpp $(INC)/Ingredientes.h $(INC)/VD.hpp $(INC)/Ingrediente.h
	$(CXX) $(CPPFLAGS) $(SRC)/Ingredientes.cpp -o $(OBJ)/Ingredientes.o 

$(OBJ)/test_ingredientes.o: $(SRC)/test_ingredientes.cpp $(INC)/Ingrediente.h $(INC)/Ingredientes.h
	$(CXX) $(CPPFLAGS) $(SRC)/test_ingredientes.cpp -o $(OBJ)/test_ingredientes.o

$(BIN)/test_ingredientes: $(OBJ)/test_ingredientes.o $(OBJ)/Ingredientes.o $(OBJ)/Ingrediente.o
	$(CXX) -o $(BIN)/test_ingredientes $(OBJ)/test_ingredientes.o $(OBJ)/Ingredientes.o $(OBJ)/Ingrediente.o

$(OBJ)/tipos_ingredientes.o: $(SRC)/tipos_ingredientes.cpp $(INC)/Ingrediente.h $(INC)/Ingredientes.h
	$(CXX) $(CPPFLAGS) $(SRC)/tipos_ingredientes.cpp -o $(OBJ)/tipos_ingredientes.o

$(BIN)/tipos_ingredientes: $(OBJ)/tipos_ingredientes.o $(OBJ)/Ingredientes.o $(OBJ)/Ingrediente.o
	$(CXX) -o $(BIN)/tipos_ingredientes $(OBJ)/tipos_ingredientes.o $(OBJ)/Ingredientes.o $(OBJ)/Ingrediente.o

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm $(OBJ)/*.o
	rm $(BIN)/test_ingredientes
	rm $(BIN)/tipos_ingredientes

mrproper : clean
	-rm -R doc/html doc/latex