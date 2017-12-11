main: supervisor.cc network_ring.cc robot.cc
	g++ -std=c++11 -pthread main.cc supervisor.cc network_ring.cc robot.cc
ui: supervisor.cc network_ring.cc robot.cc ui.cc
	g++ -std=c++11 -pthread supervisor.cc network_ring.cc robot.cc ui.cc -lGL -lGLU -lglut  
