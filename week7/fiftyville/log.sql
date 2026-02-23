-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find all the reports for the day
select * from crime_scene_reports where year == 2025 and month == 7 and day == 28;
-- The theft happened at 10:15 am
-- All interviews mention "bakery"

-- Check the interviews after the crime
select * from interviews
where year == 2025 and month == 7 and day >= 28
and transcript like '%bakery%';
-- The guy left the parking within 10m of the theft
-- The guy withdrew money earlier that day
-- The guy called his accomplice while leaving

-- Check the license plates
select license_plate from bakery_security_logs 
where year = 2025 and month = 7 and day = 28 
and hour = 10 and minute >= 15 and minute <= 25;

-- Check atm withdrawals
select account_number from atm_transactions 
where year = 2025 and month = 7 and day = 28 
and atm_location = 'Leggett Street' 
and transaction_type = 'withdraw';

-- Check phone calls
select p.name from people p
where p.phone_number in (
    select caller from phone_calls 
    where year = 2025 and month = 7 and day = 28 
    and duration <= 60
);

-- Check first flight on 29
select a.city, from flights f
join airports a on f.destination_airport_id = a.id
where f.year = 2025 and f.month = 7 and f.day = 29
order by f.hour asc, f.minute asc
limit 1;

-- Combine all queries into one to find thief
select p.name from people p
join passengers pas on p.passport_number = pas.passport_number
join flights f on pas.flight_id = f.id
join airports a on f.destination_airport_id = a.id
where p.license_plate in (
    select license_plate from bakery_security_logs
    where year = 2025 and month = 7 and day = 28
    and hour = 10 and minute >= 15 and minute <= 25
)
and p.id in (
    select person_id from bank_accounts
    where account_number in (
        select account_number from atm_transactions
        where year = 2025 and month = 7 and day = 28
        and atm_location = 'Leggett Street'
        and transaction_type = 'withdraw'
    )
)
and p.phone_number in (
    select caller from phone_calls
    where year = 2025 and month = 7 and day = 28
    and duration <= 60
)
and f.year = 2025 and f.month = 7 and f.day = 29
order by f.hour asc, f.minute asc
limit 1;

-- Find accomplice name from thief name (by checking the phone calls)
select p.name
from people p
where p.phone_number in (
    select receiver from phone_calls
    where year = 2025 and month = 7 and day = 28
    and duration <= 60
    and caller in (
        select phone_number from people
        where name = 'Bruce'
    )
);

