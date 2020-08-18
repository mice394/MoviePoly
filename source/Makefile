CXX=g++
CXXFLAGS=-std=c++14 -Wall -Werror=vla -g -MMD
EXEC=watopoly
OBJECTS=academic.o arts_1.o arts_2.o board.o cell.o coop.o dc_tims_line.o dice.o eng.o env.o goose_nesting.o gym.o health.o loadBoard.o main.o math.o needles_hall.o non_property.o observer.o osap.o player.o property.o residence.o sci_1.o sci_2.o slc.o subject.o tuition.o ml.o al.o phys.o b1.o b2.o c2.o dc.o hh.o mc.o v1.o bmh.o cif.o cph.o dwe.o ech.o eit.o esc.o ev1.o ev2.o ev3.o lhi.o mkv.o opt.o pac.o pas.o rch.o rev.o uwp.o goToTims.o 
DEPENDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean
