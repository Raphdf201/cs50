-- 13. Names of all people who starred in a movie in which Kevin Bacon also starred
select distinct people.name from people join stars on people.id = stars.person_id where stars.movie_id in (select stars.movie_id from stars join people on stars.person_id = people.id where people.name = 'Kevin Bacon' and people.birth = 1958) and people.name != 'Kevin Bacon';

