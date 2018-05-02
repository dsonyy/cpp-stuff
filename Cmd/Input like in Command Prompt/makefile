CPP=g++
CPPFLAGS= -std=c++11 -pedantic
LFLAGS=

shit: Command.o GemBox.o Room.o main.o
	$(CPP)  $(LFLAGS) $^ -o $@ 
	
Command.o: Command.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@
	
main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

GemBox.o: GemBox.cpp 
	$(CPP) $(CPPFLAGS) -c $< -o $@ 
	
Room.o: Room.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f main.o Command.o