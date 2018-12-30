g++ -std=c++17 \
		src/main.cc \
		src/block.cc \
		src/cfg.cc \
		src/randomgenerator.cc \
		src/environment.cc \
		src/stream.cc \
		-o bin/fall `pkg-config --cflags --libs allegro-5 allegro_primitives-5 allegro_image-5` 2> errors

if [ -s errors ]; then
	vim errors
fi
