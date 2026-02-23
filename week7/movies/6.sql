-- 6. Average rating of movies in 2012
select avg(ratings.rating) from ratings join movies on ratings.movie_id = movies.id where movies.year == 2012;

