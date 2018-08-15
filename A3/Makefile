all: movie_recommender

movie_recommender: preferences.o distances.o src/movie_recommender.c
	gcc -Iinclude -o movie_recommender preferences.o distances.o src/movie_recommender.c 

preferences.o: src/preferences.c include/preferences.h
	gcc -c -Iinclude src/preferences.c

distances.o: src/distances.c include/distances.h
	gcc -c -Iinclude src/distances.c

clean: 
	rm movie_recommender preferences.o distances.o
