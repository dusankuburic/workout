USE Kadrovi_2017;

GO


SELECT o.SIFRAODELJ, o.NAZIVODELJ, o.GRAD
FROM ODELJENJE o;

SELECT *
FROM RADNIK;

SELECT r.SIFRAODELJ
FROM RADNIK r

SELECT DISTINCT r.SIFRAODELJ 
FROM RADNIK r

SELECT r.IME, r.PREZIME, r.PLATA, r.PLATA + 50000 AS "uvecana plata"
FROM RADNIK r

SELECT r.IME, r.PREZIME, r.PLATA, 12*r.PLATA + 5000 as "Godisnja uv.plata"
FROM RADNIK r

SELECT r.IME, r.PREZIME, r.PLATA, 12*(r.PLATA+5000) as "Godisnja uv.plata"
FROM RADNIK r

SELECT r.IME, r.PREZIME, r.PLATA, r.PREMIJA
FROM RADNIK r

SELECT r.IME, r.PREZIME, r.PLATA, r.PREMIJA, r.PLATA + r.PREMIJA AS "uk. primanja"
FROM RADNIK r;

SELECT r.IME, r.PREZIME, r.PLATA, r.PREMIJA, r.PLATA + ISNULL(r.PREMIJA, 0) AS "uk. primanja"
FROM RADNIK r;

SELECT r.IME + ' ' + r.PREZIME AS "Ime i Prezime"
FROM RADNIK r;

SELECT * 
FROM RADNIK r
WHERE r.SIFRAODELJ = 30;

SELECT r.IME, r.PREZIME, r.PLATA
FROM RADNIK r
WHERE r.SIFRAODELJ = 20 AND r.PLATA > 30000


SELECT r.IME, r.PREZIME, r.SIFRAODELJ, r.SIFRAPROF
FROM RADNIK r
WHERE r.SIFRAODELJ = 40 OR r.SIFRAPROF = 300;

SELECT r.IME, r.PLATA, r.SIFRAODELJ
FROM RADNIK r
WHERE r.PLATA > 30000 AND (r.SIFRAODELJ = 30 OR r.SIFRAODELJ = 10);

SELECT r.IME, r.PREZIME, r.SIFRAODELJ
FROM RADNIK r
WHERE r.PLATA > 30000 AND NOT (r.SIFRAODELJ = 30);

SELECT r.IME, r.PREZIME, r.PLATA, r.SIFRAODELJ
FROM RADNIK r
WHERE r.SIFRAODELJ IN(10,20,30);

SELECT r.IME, r.PREZIME, r.PLATA
FROM RADNIK r
WHERE r.PLATA >= 20000 AND r.PLATA <= 40000;

SELECT r.IME, r.PREZIME, r.PLATA, r.SIFRAODELJ
FROM RADNIK r
WHERE r.IME LIKE 'M%';

