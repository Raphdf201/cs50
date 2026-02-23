-- 9. Names of all people who starred in a movie released in 2004, ordered by birth year
select distinct people.id, people.name from people join stars ON people.id = stars.person_id join movies on stars.movie_id = movies.id where movies.year = 2004 order by people.birth;

