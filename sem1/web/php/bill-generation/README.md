# Bill Generation System (billgeneration)

A lightweight PHP+MySQL billing management application intended for small installations or a learning project. It supports:

- Admin login (single user in the provided implementation)
- Consumer registration
- Bill entry
- Searching bills by consumer & month

This README documents how to set up and run the project locally (on XAMPP), the database design, files, quick usage, and recommended improvements.

---

## Quick Setup (macOS with XAMPP)

1. Start XAMPP and ensure Apache and MySQL/MariaDB are running.
2. Copy this project to the XAMPP htdocs directory (if not already present):

   ```bash
   cp -R /path/to/this/project /Applications/XAMPP/xamppfiles/htdocs/billgeneration
   ```

3. Import the database schema and sample data (either use phpMyAdmin or the `db_schema.sql` file included in this folder):

   - Using phpMyAdmin: *Open http://localhost/phpmyadmin -> New -> Create database* (e.g., `ajmal`), then import the `db_schema.sql` file.
   - Using MySQL CLI (Mac):
     ```bash
     /Applications/XAMPP/xamppfiles/bin/mysql -u root -p ajmal < /Applications/XAMPP/xamppfiles/htdocs/billgeneration/db_schema.sql
     ```

   > NOTE: The provided SQL file creates `admin`, `consumer`, and `bill` tables and inserts sample data.

4. Open the app in your browser:

   - Visit: http://localhost/billgeneration/index.php

   - Default sample admin credentials in the sample data: **username: admin** / **password: 12345** (for testing only; please change in production)

---

## Database Design

The app uses a database named `ajmal`. The main tables are:

- `admin` — stores admin login username and password
- `consumer` — stores consumer details
- `bill` — stores bill entries for each consumer and month

### Schema (summary)

- `admin`
  - `id` INT PRIMARY KEY AUTO_INCREMENT
  - `username` VARCHAR(50)
  - `password` VARCHAR(255) — passwords are stored in clear text in the sample project (INSECURE)

- `consumer`
  - `id` INT PRIMARY KEY AUTO_INCREMENT
  - `consumer_id` VARCHAR(50) UNIQUE — consumer id used as reference in other tables
  - `consumer_name` VARCHAR(100)
  - `phone_no` VARCHAR(50)
  - `adress` TEXT — note: `adress` spelled as it is in the project files

- `bill`
  - `bill_no` INT PRIMARY KEY AUTO_INCREMENT
  - `consumer_id` VARCHAR(50) — references `consumer`.`consumer_id`
  - `month` VARCHAR(20)
  - `unit` INT
  - `amount` DECIMAL(10,2) or INT in the current sample data

You can find and import the exact SQL to recreate these tables in the `db_schema.sql` file (included with this README).

---

## Files & Brief Description

- `index.php` — Landing page that currently uses a frameset to display both `login.php` and `search_bill.php` side by side.
- `login.php` — Admin login; verifies credentials from the `admin` table. The current implementation uses a `top.location` redirect after successful login to break out of the frameset and navigate to `dashboard.php`.
- `dashboard.php` — Admin dashboard that uses a frameset where the left frame is `sidebar.html` and the right frame is the content (`consumer_reg.php` by default).
- `sidebar.html` — Navigation menu for the admin including links like Registration and Bill Entry.
- `consumer_reg.php` — Form and logic to add a new consumer to the `consumer` table.
- `add_bill.php` — Form to add a bill for a consumer and logic to insert the data into the `bill` table.
- `search_bill.php` — Search form and logic to search a bill by `consumer_id` and `month`.

---

## How to Use (basic)

1. Open `index.php`.
2. Use the admin credentials to login (sample `admin` / `12345`).
3. Use the `sidebar` to navigate: register consumers (`consumer_reg.php`) and add bills (`add_bill.php`).
4. Use the `search` functionality from the public frame (`search_bill.php`) to find a consumer's bill for a particular month.

---

## Sample SQL: create tables & sample data

The `db_schema.sql` file contains the SQL commands to create tables and insert sample data. The file includes sample admin credentials and some consumer & bill rows. If you use phpMyAdmin, import this file to create the sample tables.

---

## Security Notes and Recommended Improvements ⚠️

This is a simple learning/utility project; the implementation contains a number of serious security issues and should not be used as-is in production:

- Passwords are stored in plaintext. Use password hashing (e.g., `password_hash()`/`password_verify()` in PHP) and strong password policy.
- Inputs are vulnerable to SQL injection. Use parameterized/prepared statements (PDO or mysqli with bind parameters) for all SQL.
- There is no CSRF protection on forms; add tokens for safety.
- The app relies on `frameset` elements which are deprecated and fragile; replace with a modern single-page layout and server-side access control.
- Session-based authorization was part of the original design but is currently disabled in some versions — reintroduce secure sessions to control access to `dashboard.php` and other admin pages.
- Always validate and sanitize user input (server-side), as well as encode output to prevent XSS.

---

## Suggested Roadmap / Improvements

1. Convert to a modern layout (no frames), e.g., a single HTML template and include content with PHP/JS.
2. Switch to prepared statements and hashing for admin passwords.
3. Replace the `admin` table for more secure user management (unique email, salted & hashed password, roles).
4. Add secure sessions and middleware to protect admin pages.
5. Add unit/integration tests and input validation steps.
6. Improve UI with Bootstrap or similar CSS frameworks.

---

## Troubleshooting / FAQs

- If you cannot log in: ensure the database is created and `db_schema.sql` was imported to populate the `admin` table with the sample record.
- If a page shows an error: check Apache logs (XAMPP Control Panel) and PHP error log; also confirm the SQL connection credentials are correct.

---

## License & Attribution

This project is provided as a sample/learning project. Use at your own risk. Consider this an internal app: review and follow best security practices before deploying.

---

If you'd like, I can also add a secure implementation of the login system (proper session handling, prepared statements, hashed passwords) and a small step-by-step migration plan to remove harmful practices like plaintext passwords and framesets.

