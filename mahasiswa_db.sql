-- phpMyAdmin SQL Dump
-- version 5.2.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Waktu pembuatan: 09 Jul 2025 pada 02.33
-- Versi server: 8.0.42
-- Versi PHP: 8.3.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `mahasiswa_db`
--

-- --------------------------------------------------------

--
-- Struktur dari tabel `dosen`
--

CREATE TABLE `dosen` (
  `id_dosen` int NOT NULL,
  `nama_dosen` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data untuk tabel `dosen`
--

INSERT INTO `dosen` (`id_dosen`, `nama_dosen`) VALUES
(1, 'Dr. Andi'),
(2, 'Prof. Budi'),
(3, 'Ibu Citra'),
(4, 'Pak Dani'),
(5, 'Ibu Erika'),
(6, 'Dr. Fajar'),
(7, 'Pak Guntur'),
(8, 'Ibu Rosa');

-- --------------------------------------------------------

--
-- Struktur dari tabel `jurusan`
--

CREATE TABLE `jurusan` (
  `id_jurusan` int NOT NULL,
  `nama_jurusan` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data untuk tabel `jurusan`
--

INSERT INTO `jurusan` (`id_jurusan`, `nama_jurusan`) VALUES
(1, 'Ilmu Komputer'),
(2, 'Sistem Informasi'),
(3, 'Sains Data'),
(4, 'Bisnis Digital');

-- --------------------------------------------------------

--
-- Struktur dari tabel `mahasiswa`
--

CREATE TABLE `mahasiswa` (
  `npm` varchar(20) NOT NULL,
  `nama` varchar(100) NOT NULL,
  `id_jurusan` int DEFAULT NULL,
  `id_dosen` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data untuk tabel `mahasiswa`
--

INSERT INTO `mahasiswa` (`npm`, `nama`, `id_jurusan`, `id_dosen`) VALUES
('220001', 'Ali', 1, 1),
('220002', 'Budi', 1, 2),
('220003', 'Citra', 1, 3),
('220004', 'Dedi', 1, 4),
('220005', 'Eka', 1, 5),
('220006', 'Farah', 1, 6),
('220007', 'Gilang', 1, 7),
('220008', 'Hana', 1, 1),
('220009', 'Ivan', 1, 2),
('220010', 'Joko', 1, 3),
('220011', 'Kiki', 2, 4),
('220012', 'Lala', 2, 5),
('220013', 'Mira', 2, 6),
('220014', 'Nina', 2, 7),
('220015', 'Omar', 2, 1),
('220016', 'Putri', 2, 2),
('220017', 'Qori', 2, 3),
('220018', 'Rian', 2, 4),
('220019', 'Santi', 2, 5),
('220020', 'Tono', 2, 6),
('220021', 'Umar', 3, 7),
('220022', 'Vina', 3, 1),
('220023', 'Wira', 3, 2),
('220024', 'Xena', 3, 3),
('220025', 'Yani', 3, 4),
('220026', 'Zaki', 3, 5),
('220027', 'Arif', 3, 6),
('220028', 'Bella', 3, 7),
('220029', 'Cici', 3, 1),
('220030', 'Dian', 3, 2),
('220031', 'Edo', 4, 3),
('220032', 'Fina', 4, 4),
('220033', 'Gita', 4, 5),
('220034', 'Hadi', 4, 6),
('220035', 'Ika', 4, 7),
('220036', 'Jeni', 4, 1),
('220037', 'Kevin', 4, 2),
('220038', 'Linda', 4, 3),
('220039', 'Mahesa', 4, 4),
('220040', 'Novi', 4, 5),
('230862', 'lia', 1, 3);

-- --------------------------------------------------------

--
-- Struktur dari tabel `mata_kuliah`
--

CREATE TABLE `mata_kuliah` (
  `kode_mk` varchar(10) NOT NULL,
  `nama_mk` varchar(100) NOT NULL,
  `sks` int NOT NULL,
  `id_jurusan` int DEFAULT NULL,
  `id_dosen` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data untuk tabel `mata_kuliah`
--

INSERT INTO `mata_kuliah` (`kode_mk`, `nama_mk`, `sks`, `id_jurusan`, `id_dosen`) VALUES
('BD401', 'E-Commerce', 3, 4, 1),
('BD402', 'UI/UX', 2, 4, 2),
('BD403', 'Digital Marketing', 3, 4, 3),
('IF101', 'Algoritma dan Pemrograman', 3, 1, 4),
('IF102', 'Struktur Data', 3, 1, 5),
('IF103', 'Jaringan Komputer', 2, 1, 6),
('SD301', 'Matematika Diskrit', 3, 3, 7),
('SD302', 'Data Mining', 3, 3, 8),
('SD303', 'Kecerdasan Buatan', 3, 3, 1),
('SI201', 'Basis Data', 3, 2, 2),
('SI202', 'Pemrograman Web', 3, 2, 3),
('SI203', 'ERP', 2, 2, 4);

-- --------------------------------------------------------

--
-- Struktur dari tabel `nilai`
--

CREATE TABLE `nilai` (
  `id_nilai` int NOT NULL,
  `npm` varchar(20) DEFAULT NULL,
  `kode_mk` varchar(10) DEFAULT NULL,
  `nilai` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data untuk tabel `nilai`
--

INSERT INTO `nilai` (`id_nilai`, `npm`, `kode_mk`, `nilai`) VALUES
(1, '220011', 'SI201', 83),
(2, '220011', 'SI202', 85),
(3, '220011', 'SI203', 82),
(4, '220012', 'SI201', 90),
(5, '220012', 'SI202', 88),
(6, '220012', 'SI203', 91),
(7, '220013', 'SI201', 72),
(8, '220013', 'SI202', 75),
(9, '220013', 'SI203', 74),
(10, '220014', 'SI201', 85),
(11, '220014', 'SI202', 87),
(12, '220014', 'SI203', 86),
(13, '220015', 'SI201', 80),
(14, '220015', 'SI202', 82),
(15, '220015', 'SI203', 79),
(16, '220016', 'SI201', 70),
(18, '220016', 'SI203', 72),
(19, '220017', 'SI201', 88),
(20, '220017', 'SI202', 89),
(21, '220017', 'SI203', 87),
(22, '220018', 'SI201', 77),
(23, '220018', 'SI202', 76),
(24, '220018', 'SI203', 75),
(25, '220019', 'SI201', 92),
(26, '220019', 'SI202', 90),
(27, '220019', 'SI203', 91),
(28, '220020', 'SI201', 73),
(29, '220020', 'SI202', 71),
(30, '220020', 'SI203', 74),
(31, '220021', 'SD301', 85),
(32, '220021', 'SD302', 87),
(33, '220021', 'SD303', 86),
(34, '220022', 'SD301', 91),
(35, '220022', 'SD302', 90),
(36, '220022', 'SD303', 92),
(37, '220023', 'SD301', 75),
(38, '220023', 'SD302', 78),
(39, '220023', 'SD303', 76),
(40, '220024', 'SD301', 84),
(41, '220024', 'SD302', 83),
(42, '220024', 'SD303', 85),
(43, '220025', 'SD301', 72),
(44, '220025', 'SD302', 74),
(45, '220025', 'SD303', 71),
(46, '220026', 'SD301', 89),
(47, '220026', 'SD302', 90),
(48, '220026', 'SD303', 88),
(49, '220027', 'SD301', 79),
(50, '220027', 'SD302', 81),
(51, '220027', 'SD303', 80),
(52, '220028', 'SD301', 82),
(53, '220028', 'SD302', 84),
(54, '220028', 'SD303', 83),
(55, '220029', 'SD301', 76),
(56, '220029', 'SD302', 75),
(57, '220029', 'SD303', 78),
(58, '220030', 'SD301', 87),
(59, '220030', 'SD302', 86),
(60, '220030', 'SD303', 88),
(61, '220031', 'BD401', 80),
(62, '220031', 'BD402', 82),
(63, '220031', 'BD403', 81),
(64, '220032', 'BD401', 85),
(65, '220032', 'BD402', 87),
(66, '220032', 'BD403', 86),
(67, '220033', 'BD401', 74),
(68, '220033', 'BD402', 76),
(69, '220033', 'BD403', 75),
(70, '220034', 'BD401', 90),
(71, '220034', 'BD402', 89),
(72, '220034', 'BD403', 91),
(73, '220035', 'BD401', 78),
(74, '220035', 'BD402', 77),
(75, '220035', 'BD403', 79),
(76, '220036', 'BD401', 88),
(77, '220036', 'BD402', 86),
(78, '220036', 'BD403', 87),
(79, '220037', 'BD401', 73),
(80, '220037', 'BD402', 74),
(81, '220037', 'BD403', 72),
(82, '220038', 'BD401', 83),
(83, '220038', 'BD402', 84),
(84, '220038', 'BD403', 85),
(85, '220039', 'BD401', 92),
(86, '220039', 'BD402', 90),
(87, '220039', 'BD403', 91),
(88, '220040', 'BD401', 76),
(89, '220040', 'BD402', 75),
(90, '220040', 'BD403', 78);

-- --------------------------------------------------------

--
-- Struktur dari tabel `user`
--

CREATE TABLE `user` (
  `id_user` int NOT NULL,
  `username` varchar(50) NOT NULL,
  `password` varchar(100) NOT NULL,
  `role` enum('admin','operator') NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data untuk tabel `user`
--

INSERT INTO `user` (`id_user`, `username`, `password`, `role`) VALUES
(1, 'admin', 'admin123', 'admin'),
(2, 'operator', 'operator123', 'operator');

--
-- Indexes for dumped tables
--

--
-- Indeks untuk tabel `dosen`
--
ALTER TABLE `dosen`
  ADD PRIMARY KEY (`id_dosen`);

--
-- Indeks untuk tabel `jurusan`
--
ALTER TABLE `jurusan`
  ADD PRIMARY KEY (`id_jurusan`);

--
-- Indeks untuk tabel `mahasiswa`
--
ALTER TABLE `mahasiswa`
  ADD PRIMARY KEY (`npm`),
  ADD KEY `id_jurusan` (`id_jurusan`),
  ADD KEY `id_dosen` (`id_dosen`);

--
-- Indeks untuk tabel `mata_kuliah`
--
ALTER TABLE `mata_kuliah`
  ADD PRIMARY KEY (`kode_mk`),
  ADD KEY `fk_dosen` (`id_dosen`);

--
-- Indeks untuk tabel `nilai`
--
ALTER TABLE `nilai`
  ADD PRIMARY KEY (`id_nilai`),
  ADD KEY `npm` (`npm`),
  ADD KEY `kode_mk` (`kode_mk`);

--
-- Indeks untuk tabel `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`id_user`),
  ADD UNIQUE KEY `username` (`username`);

--
-- AUTO_INCREMENT untuk tabel yang dibuang
--

--
-- AUTO_INCREMENT untuk tabel `dosen`
--
ALTER TABLE `dosen`
  MODIFY `id_dosen` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=44;

--
-- AUTO_INCREMENT untuk tabel `jurusan`
--
ALTER TABLE `jurusan`
  MODIFY `id_jurusan` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=29;

--
-- AUTO_INCREMENT untuk tabel `nilai`
--
ALTER TABLE `nilai`
  MODIFY `id_nilai` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=91;

--
-- AUTO_INCREMENT untuk tabel `user`
--
ALTER TABLE `user`
  MODIFY `id_user` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- Ketidakleluasaan untuk tabel pelimpahan (Dumped Tables)
--

--
-- Ketidakleluasaan untuk tabel `mahasiswa`
--
ALTER TABLE `mahasiswa`
  ADD CONSTRAINT `mahasiswa_ibfk_1` FOREIGN KEY (`id_jurusan`) REFERENCES `jurusan` (`id_jurusan`),
  ADD CONSTRAINT `mahasiswa_ibfk_2` FOREIGN KEY (`id_dosen`) REFERENCES `dosen` (`id_dosen`);

--
-- Ketidakleluasaan untuk tabel `mata_kuliah`
--
ALTER TABLE `mata_kuliah`
  ADD CONSTRAINT `fk_dosen` FOREIGN KEY (`id_dosen`) REFERENCES `dosen` (`id_dosen`);

--
-- Ketidakleluasaan untuk tabel `nilai`
--
ALTER TABLE `nilai`
  ADD CONSTRAINT `nilai_ibfk_1` FOREIGN KEY (`npm`) REFERENCES `mahasiswa` (`npm`),
  ADD CONSTRAINT `nilai_ibfk_2` FOREIGN KEY (`kode_mk`) REFERENCES `mata_kuliah` (`kode_mk`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
