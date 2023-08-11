.PHONEY: all clean

INCLUDE = $(INCLUDE)

INCLUDE := 

all: clock run clean

clock: main.o display.o 
	cc -o $@ $^ -lncurses

clean:
	rm -f *.o
	rm -f clock

main.o: main.c display.h
	cc -c $<

display.o: display.c display.h
	cc -o $@ -c $< $(INCLUDE)

run:
	bash clock.sh | ./clock
	$(clean)
