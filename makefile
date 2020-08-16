run: main.o DemocraticParty.o InvalidData.o InvalidID.o InvalidPartyName.o LeaderDemocrat.o LeaderRepublic.o Party.o PoliticalSys.o Politician.o RepublicParty.o SocialDemocrat.o SocialRepublic.o
	g++  main.o DemocraticParty.o InvalidData.o InvalidID.o InvalidPartyName.o LeaderDemocrat.o LeaderRepublic.o Party.o PoliticalSys.o Politician.o RepublicParty.o SocialDemocrat.o SocialRepublic.o -o run
DemocraticParty.o: DemocraticParty.cpp DemocraticParty.h Party.h \
 Politician.h
	g++ -c DemocraticParty.cpp
InvalidData.o: InvalidData.cpp InvalidData.h
	g++ -c InvalidData.cpp
InvalidID.o: InvalidID.cpp InvalidID.h
	g++ -c InvalidID.cpp
InvalidPartyName.o: InvalidPartyName.cpp InvalidPartyName.h
	g++ -c InvalidPartyName.cpp
LeaderDemocrat.o: LeaderDemocrat.cpp LeaderDemocrat.h Politician.h \
 Party.h
	g++ -c LeaderDemocrat.cpp
LeaderRepublic.o: LeaderRepublic.cpp LeaderRepublic.h Politician.h \
 Party.h
	g++ -c LeaderRepublic.cpp
main.o: main.cpp PoliticalSys.h DemocraticParty.h Party.h Politician.h \
 RepublicParty.h SocialDemocrat.h LeaderDemocrat.h LeaderRepublic.h \
 SocialRepublic.h InvalidData.h InvalidID.h InvalidPartyName.h
	g++ -c main.cpp
Party.o: Party.cpp Party.h Politician.h
	g++ -c Party.cpp
PoliticalSys.o: PoliticalSys.cpp PoliticalSys.h DemocraticParty.h Party.h \
 Politician.h RepublicParty.h SocialDemocrat.h LeaderDemocrat.h \
 LeaderRepublic.h SocialRepublic.h InvalidData.h InvalidID.h \
 InvalidPartyName.h
	g++ -c PoliticalSys.cpp
Politician.o: Politician.cpp Politician.h Party.h
	g++ -c Politician.cpp
RepublicParty.o: RepublicParty.cpp RepublicParty.h Party.h Politician.h
	g++ -c RepublicParty.cpp
SocialDemocrat.o: SocialDemocrat.cpp SocialDemocrat.h Politician.h \
 Party.h
	g++ -c SocialDemocrat.cpp
SocialRepublic.o: SocialRepublic.cpp SocialRepublic.h Politician.h \
 Party.h
	g++ -c SocialRepublic.cpp
clean: 
	rm -f *.o run
