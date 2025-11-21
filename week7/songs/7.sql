select avg(energy) from songs where (select id from artists where name is 'Drake') is artist_id;
