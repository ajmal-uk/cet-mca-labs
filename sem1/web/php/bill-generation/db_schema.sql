-- Database: ajmal
-- Tables for the Bill Generation project

CREATE DATABASE IF NOT EXISTS ajmal;
USE ajmal;

-- admin table
CREATE TABLE IF NOT EXISTS `admin` (
  `id` INT(11) NOT NULL AUTO_INCREMENT,
  `username` VARCHAR(50) NOT NULL,
  `password` VARCHAR(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- consumer table
CREATE TABLE IF NOT EXISTS `consumer` (
  `id` INT(11) NOT NULL AUTO_INCREMENT,
  `consumer_id` VARCHAR(50) NOT NULL UNIQUE,
  `consumer_name` VARCHAR(100) NOT NULL,
  `phone_no` VARCHAR(50) DEFAULT NULL,
  `adress` TEXT DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- bill table
CREATE TABLE IF NOT EXISTS `bill` (
  `bill_no` INT(11) NOT NULL AUTO_INCREMENT,
  `consumer_id` VARCHAR(50) NOT NULL,
  `month` VARCHAR(20) NOT NULL,
  `unit` INT(11) DEFAULT NULL,
  `amount` DECIMAL(10,2) DEFAULT NULL,
  PRIMARY KEY (`bill_no`),
  CONSTRAINT `fk_bill_consumer` FOREIGN KEY (`consumer_id`) REFERENCES `consumer` (`consumer_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Sample data from the screenshot for quick testing
INSERT INTO `admin` (`username`, `password`) VALUES ('admin', '12345');

INSERT INTO `consumer` (`consumer_id`, `consumer_name`, `phone_no`, `adress`) VALUES
('123', 'Alok', '1231321322', 'KNR'),
('1234', 'ajmal', '8547197122', 'TVM'),
('123456', 'Abhinav', '231233213', '123dsadsaasx2131');

INSERT INTO `bill` (`consumer_id`, `month`, `unit`, `amount`) VALUES
('1234', 'jan', 100, 100),
('123', 'feb', 1232312, 1232131),
('1234', 'feb', 313131, 21312);

-- End of db schema
