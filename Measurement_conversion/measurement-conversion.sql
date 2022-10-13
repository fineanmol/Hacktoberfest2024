-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Aug 08, 2022 at 09:25 PM
-- Server version: 10.4.24-MariaDB
-- PHP Version: 8.1.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `measurement-conversion`
--

-- --------------------------------------------------------

--
-- Table structure for table `conversions`
--

CREATE TABLE `conversions` (
  `sno.` int(100) NOT NULL,
  `from_value` varchar(20) DEFAULT NULL,
  `from_unit` varchar(20) DEFAULT NULL,
  `to_value` varchar(20) DEFAULT NULL,
  `to_unit` varchar(20) DEFAULT NULL,
  `dt` datetime(6) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `conversions`
--

INSERT INTO `conversions` (`sno.`, `from_value`, `from_unit`, `to_value`, `to_unit`, `dt`) VALUES
(30, '2', 'inches', '5.08', 'centimeters', '2022-08-08 20:26:03.000000'),
(32, '3', 'square_meters', '30000', 'square_centimeters', '2022-08-08 20:26:18.000000'),
(35, '4', 'imperial_gallons', '639.9991553192', 'imperial_ounces', '2022-08-08 20:26:40.000000'),
(37, '5', 'ounces', '0.3125', 'pounds', '2022-08-08 20:26:53.000000'),
(39, '6', 'kilometers_per_hour', '1.6666666666667', 'meters_per_second', '2022-08-08 20:27:33.000000'),
(41, '7', 'celsius', '44.6', 'fahrenheit', '2022-08-08 20:27:50.000000');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `conversions`
--
ALTER TABLE `conversions`
  ADD PRIMARY KEY (`sno.`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `conversions`
--
ALTER TABLE `conversions`
  MODIFY `sno.` int(100) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=54;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
