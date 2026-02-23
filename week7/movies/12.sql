-- 12. Titles of all of movies in which both Jennifer Lawrence and Bradley Cooper starred
select movies.title from movies join stars s1 on movies.id = s1.movie_id join people p1 on s1.person_id = p1.id and p1.name = 'Bradley Cooper' join stars s2 on movies.id = s2.movie_id join people p2 on s2.person_id = p2.id and p2.name = 'Jennifer Lawrence';

