CXX=g++
CXXFLAGS=-std=c++14 -Wall -Werror=vla -g -MMD
EXEC=watopoly
OBJECTS=movies.o stdghibili.o comedy.o board.o cell.o coop.o time_out_zone.o dice.o christmas.o kids.o popcorn.o viewing.o horror.o loadBoard.o main.o romance.o chance.o non_property.o observer.o ticket.o player.o property.o crew.o action.o thriller.o raffle.o subject.o fine.o totoro.o ponyo.o avengers.o skyfall.o nonstop.o parasite.o notebook.o hangover.o titanic.o producer.o purge.o drive_in.o grinch.o klaus.o kingsmen.o burning.o mother.o frozen.o mulan.o aladdin.o it.o director.o carrie.o theatre.o superbad.o elf.o writer.o camera.o caught_sneaking.o 
DEPENDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean
