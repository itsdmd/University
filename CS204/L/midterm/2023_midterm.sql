-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: May 30, 2023 at 05:47 AM
-- Server version: 5.7.40
-- PHP Version: 8.0.26

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `2023_midterm`
--

-- --------------------------------------------------------

--
-- Table structure for table `memes`
--

DROP TABLE IF EXISTS `memes`;
CREATE TABLE IF NOT EXISTS `memes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `title` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL,
  `body` text COLLATE utf8mb4_unicode_ci NOT NULL,
  `author` int(11) NOT NULL,
  `img_file` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL,
  `date_created` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `memes`
--

INSERT INTO `memes` (`id`, `title`, `body`, `author`, `img_file`, `date_created`) VALUES
(1, 'What do you meme?', 'Lorem ipsum dolor sit, amet consectetur adipisicing elit. Blanditiis nihil ad nam quae perferendis soluta adipisci facilis aspernatur repellendus.', 2, 'meme1.jpg', '2023-05-30 12:34:58'),
(2, 'To meme or not to meme', 'Ad nam quae perferendis soluta adipisci facilis aspernatur repellendus.', 3, 'meme2.jpg', '2023-05-30 12:34:58'),
(3, 'Check out dat idea-', 'Blanditiis nihil ad nam quae perferendis soluta adipisci facilis aspernatur repellendus, maxime obcaecati voluptates at ut aut incidunt eum impedit nesciunt recusandae?', 3, 'meme3.jpg', '2023-05-30 12:37:00'),
(4, 'Check out dat idea-', 'Blanditiis nihil ad nam quae perferendis soluta adipisci facilis aspernatur repellendus, maxime obcaecati voluptates at ut aut incidunt eum impedit nesciunt recusandae?', 3, 'meme3.jpg', '2023-05-30 12:37:06'),
(5, 'Twitter fire', 'Maxime obcaecati voluptates at ut aut incidunt eum impedit nesciunt recusandae?Blanditiis nihil ad nam quae perferendis soluta adipisci facilis aspernatur repellendus. ', 1, 'meme4.jpg', '2023-05-30 12:37:06'),
(6, 'Chad Honkler', 'Aquae perferendis soluta adipisci facilis aspernatur repellendus, maxime obcaecati voluptates at ut aut incidunt eum impedit nesciunt', 3, 'meme5.jpeg', '2023-05-30 12:38:21'),
(7, 'Clown World', 'Soluta adipisci facilis aspernatur repellendus, maxime obcaecati voluptates at ut aut incidunt eum impedit nesciunt', 3, 'meme6.gif', '2023-05-30 12:38:21'),
(8, 'Dump it!', 'Lorem ipsum dolor sit, amet consectetur adipisicing elit. Blanditiis nihil ad nam quae perferendis soluta adipisci facilis aspernatur repellendus, maxime obcaecati voluptates at ut aut incidunt eum impedit nesciunt', 1, 'meme7.jpg', '2023-05-30 12:39:38'),
(9, 'Crypto Wojak', 'Nihil ad nam quae perferendis soluta adipisci facilis aspernatur repellendus, maxime obcaecati voluptates at ut aut incidunt eum impedit nesciunt.', 1, 'meme8.png', '2023-05-30 12:39:38'),
(10, 'Emotional Damage!', 'Lorem ipsum dolor sit, amet consectetur adipisicing elit. Blanditiis nihil ad nam quae perferendis soluta adipisci facilis aspernatur repellendus, maxime obcaecati voluptates at ut aut incidunt eum impedit nesciunt recusandae?', 4, 'meme9.jpg', '2023-05-30 12:40:45'),
(11, 'Nice~', 'Soluta adipisci facilis aspernatur repellendus, maxime obcaecati voluptates at ut aut incidunt eum impedit nesciunt recusandae?', 3, 'meme10.gif', '2023-05-30 12:40:45');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
CREATE TABLE IF NOT EXISTS `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_name` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL,
  `password` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL,
  `date_created` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `user_name`, `password`, `date_created`) VALUES
(1, 'admin', 'itec2023', '2023-05-30 12:41:13'),
(2, 'wojak', '123456789', '2023-05-30 12:41:13'),
(3, 'chad', 'chadpose2023', '2023-05-30 12:41:40'),
(4, 'honkler', 'honkhonk', '2023-05-30 12:41:40');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
