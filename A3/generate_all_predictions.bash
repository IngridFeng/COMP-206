#!/bin/bash
for f in $(ls data)	
do
	mv data/$f query
	./movie_recommender query/$f data/*
	mv query/$f data
done
