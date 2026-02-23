-- 10. Names of all directors who have directed a movie that got a rating of at least 9.0
select distinct people.name from people join directors on people.id == directors.person_id join ratings on directors.movie_id == ratings.movie_id where ratings.rating >= 9;

