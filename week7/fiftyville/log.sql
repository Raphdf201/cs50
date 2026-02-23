-- Keep a log of any SQL queries you execute as you solve the mystery.

-- 1. Find all the reports for the day
select * from crime_scene_reports where year == 2025 and month == 7 and day == 28;
-- The theft happened at 10:15 am
-- All interviews mention "bakery"

-- 2. Check the interviews after the crime
select * from interviews where year == 2025 and month == 7 and day >= 28 and transcript like '%bakery%';
-- 2.1 Check the bakery security logs within 10m of the theft
select * from bakery_security_logs where year == 2025 and month == 7 and day == 28 and hour == 10 and minute >= 15 and minute <= 25;
-- 2.2 Check the atm transactions earlier that day
select * from atm_transactions where year == 2025 and month == 7 and day == 28 and atm_location == 'Leggett Street' and transaction_type == 'withdraw';
-- 2.3 Check the phone calls near the theft
select * from phone_calls where year == 2025 and month == 7 and day == 28 and duration <= 60;
-- 2.4 Check the flights for the day after

