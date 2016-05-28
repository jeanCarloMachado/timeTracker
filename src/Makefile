CC=g++
FLAGS=
ENDPARMS=-lsqlite3
OUT=timeTracker

all: main

main: helpers main.cpp 
	$(CC) -o $(OUT) main.cpp models/dataBase/DataBase.o models/Activity.o views/helpers/Message.o views/Console.o  $(ENDPARMS)

#pre requirements
views: controllers
	cd views; make

controllers: helpers
	cd controllers; make

helpers: models
	cd views/helpers; make

models: dataBase
	cd models; make

dataBase:
		cd models/dataBase; make

#clear function
clean:
	cd models/dataBase; make clean; cd ..; cd ..; cd models; make clean;cd ..; cd controllers; make clean; cd ..; cd views/helpers; make clean; cd ..; cd ..; cd views; make clean; cd .. ;rm -rf $(OUT)