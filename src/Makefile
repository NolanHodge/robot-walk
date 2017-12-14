main: supervisor.cc network_ring.cc robot.cc prandom.cc
	g++ -std=c++0x -pthread main.cc prandom.cc supervisor.cc network_ring.cc robot.cc -o robot-walk
ui: supervisor.cc network_ring.cc robot.cc ui.cc prandom.cc
	g++ -std=c++0x -pthread prandom.cc supervisor.cc network_ring.cc robot.cc ui.cc -lGL -lGLU -lglut -o robot-walk-ui
