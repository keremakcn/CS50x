-- Find the crime scene report from Humphrey Street on July 28, 2025.
SELECT *
FROM crime_scene_reports
WHERE year = 2025
AND month = 7
AND day = 28
AND street = 'Humphrey Street';


-- Find the interviews from the day of the theft.
SELECT *
FROM interviews
WHERE year = 2025
AND month = 7
AND day = 28;


-- Find cars that left the bakery parking lot within ten minutes of the theft.
SELECT *
FROM bakery_security_logs
WHERE year = 2025
AND month = 7
AND day = 28
AND hour = 10
AND minute BETWEEN 15 AND 25
AND activity = 'exit';


-- Find people who withdrew money from the Leggett Street ATM on July 28, 2025.
SELECT *
FROM atm_transactions
WHERE year = 2025
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';


-- Find people who withdrew money from the ATM and left the bakery parking lot.
SELECT people.name, people.license_plate
FROM people
JOIN bank_accounts
ON people.id = bank_accounts.person_id
JOIN atm_transactions
ON bank_accounts.account_number = atm_transactions.account_number
JOIN bakery_security_logs
ON people.license_plate = bakery_security_logs.license_plate
WHERE atm_transactions.year = 2025
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_transactions.atm_location = 'Leggett Street'
AND atm_transactions.transaction_type = 'withdraw'
AND bakery_security_logs.year = 2025
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute BETWEEN 15 AND 25
AND bakery_security_logs.activity = 'exit';


-- Find phone calls made on July 28, 2025 that lasted less than one minute.
SELECT *
FROM phone_calls
WHERE year = 2025
AND month = 7
AND day = 28
AND duration < 60;


-- Find the suspects who made a phone call lasting less than one minute.
SELECT people.name, people.phone_number, phone_calls.receiver
FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.caller
WHERE phone_calls.year = 2025
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration < 60
AND people.name IN ('Bruce', 'Diana', 'Iman', 'Luca');


-- Find the airport in Fiftyville to identify the origin airport for the earliest flight.
SELECT *
FROM airports
WHERE city = 'Fiftyville';


-- Find flights leaving Fiftyville on July 29, 2025, ordered from earliest to latest.
SELECT *
FROM flights
WHERE origin_airport_id = 8
AND year = 2025
AND month = 7
AND day = 29
ORDER BY hour, minute;


-- Find the destination city of the earliest flight from Fiftyville.
SELECT *
FROM airports
WHERE id = 4;


-- Find the passengers on the earliest flight from Fiftyville.
SELECT *
FROM passengers
WHERE flight_id = 36;


-- Check whether Bruce or Diana was a passenger on the earliest flight.
SELECT people.name, people.passport_number
FROM people
JOIN passengers
ON people.passport_number = passengers.passport_number
WHERE passengers.flight_id = 36
AND people.name IN ('Bruce', 'Diana');


-- Find the person Bruce called before escaping.
SELECT name, phone_number
FROM people
WHERE phone_number = '(375) 555-8161';
