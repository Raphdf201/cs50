-- 7. All movies and ratings from 2010, in decreasing order by rating (alphabetical for those with same rating)
select movies.title, ratings.rating from ratings join movies on ratings.movie_id == movies.id where movies.year == 2010 order by ratings.rating desc, movies.title;

