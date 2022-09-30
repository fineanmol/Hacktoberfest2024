-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 22, 2022 at 10:42 AM
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
-- Database: `data`
--

-- --------------------------------------------------------

--
-- Table structure for table `adminlogin`
--

CREATE TABLE `adminlogin` (
  `username` varchar(255) DEFAULT NULL,
  `password` varchar(255) DEFAULT NULL,
  `id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `adminlogin`
--

INSERT INTO `adminlogin` (`username`, `password`, `id`) VALUES
('ritam', 'ritam', 1),
('abhi', 'a123', 2),
('admin', 'admin', 3);

-- --------------------------------------------------------

--
-- Table structure for table `course`
--

CREATE TABLE `course` (
  `course_code` varchar(255) NOT NULL,
  `course_name` varchar(255) NOT NULL,
  `course_duration` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `course`
--

INSERT INTO `course` (`course_code`, `course_name`, `course_duration`) VALUES
('BCA2020', 'Bachelor of Computer Application', '3'),
('MCA2020', 'Master Of Computer Application', '2');

-- --------------------------------------------------------

--
-- Table structure for table `faculty_details`
--

CREATE TABLE `faculty_details` (
  `tid` varchar(255) NOT NULL,
  `tname` varchar(255) DEFAULT NULL,
  `qual` varchar(255) DEFAULT NULL,
  `temail` varchar(255) DEFAULT NULL,
  `sub` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `faculty_details`
--

INSERT INTO `faculty_details` (`tid`, `tname`, `qual`, `temail`, `sub`) VALUES
('BCA1', 'Ratnankur Majumder', 'Master In Computer Science', 'ratnankurmajumder@gmail.com', 'Digital Electronics');

-- --------------------------------------------------------

--
-- Table structure for table `ptoall`
--

CREATE TABLE `ptoall` (
  `notice` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `ptoall`
--

INSERT INTO `ptoall` (`notice`) VALUES
('Hello.'),
('Kalse chutti hai');

-- --------------------------------------------------------

--
-- Table structure for table `student_details`
--

CREATE TABLE `student_details` (
  `fname` varchar(255) DEFAULT NULL,
  `lname` varchar(255) DEFAULT NULL,
  `roll` varchar(255) NOT NULL,
  `course` varchar(255) DEFAULT NULL,
  `year` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `student_details`
--

INSERT INTO `student_details` (`fname`, `lname`, `roll`, `course`, `year`) VALUES
('Ritam Kumar', 'Kundu', '33401220074', 'BCA2020', '3'),
('Rajendra Nath', 'Murmu', '33401220077', 'BCA2020', '3');

-- --------------------------------------------------------

--
-- Table structure for table `subject`
--

CREATE TABLE `subject` (
  `scode` varchar(255) NOT NULL,
  `sname` varchar(255) DEFAULT NULL,
  `course_name` varchar(255) DEFAULT NULL,
  `tmarks` varchar(255) DEFAULT NULL,
  `pmark` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `subject`
--

INSERT INTO `subject` (`scode`, `sname`, `course_name`, `tmarks`, `pmark`) VALUES
('BCAC101', 'Programming With C', 'BCA2020', '70', '30');

-- --------------------------------------------------------

--
-- Table structure for table `tassign`
--

CREATE TABLE `tassign` (
  `tassign` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `tassign`
--

INSERT INTO `tassign` (`tassign`) VALUES
('hello');

-- --------------------------------------------------------

--
-- Table structure for table `ttoall`
--

CREATE TABLE `ttoall` (
  `notice` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `ttoall`
--

INSERT INTO `ttoall` (`notice`) VALUES
(''),
('sent'),
('ss'),
('uygygy');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `adminlogin`
--
ALTER TABLE `adminlogin`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `course`
--
ALTER TABLE `course`
  ADD PRIMARY KEY (`course_code`);

--
-- Indexes for table `faculty_details`
--
ALTER TABLE `faculty_details`
  ADD PRIMARY KEY (`tid`);

--
-- Indexes for table `ptoall`
--
ALTER TABLE `ptoall`
  ADD PRIMARY KEY (`notice`);

--
-- Indexes for table `student_details`
--
ALTER TABLE `student_details`
  ADD PRIMARY KEY (`roll`);

--
-- Indexes for table `subject`
--
ALTER TABLE `subject`
  ADD PRIMARY KEY (`scode`);

--
-- Indexes for table `tassign`
--
ALTER TABLE `tassign`
  ADD PRIMARY KEY (`tassign`);

--
-- Indexes for table `ttoall`
--
ALTER TABLE `ttoall`
  ADD PRIMARY KEY (`notice`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `adminlogin`
--
ALTER TABLE `adminlogin`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
