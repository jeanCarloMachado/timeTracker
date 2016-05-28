CC=g++
INITPAR=-c


all: activityController


activityController:	ActivityController.h ActivityController.cpp controller
	$(CC) $(INITPAR) ActivityController.cpp

controller: Controller.h	Controller.cpp
	$(CC) $(INITPAR) Controller.cpp

clean:
	rm -rf *.o