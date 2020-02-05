use Kadrovi;

SELECT 1 as Tag,
null as Parent,
ODELJENJE.SIFRAODELJ as [Odeljenje!1!SIFRAODELJ],
ODELJENJE.NAZIVODELJ as [Odeljenje!1!NAZIVODELJ],
RADNIK.SIFRAZAP as [Odeljenje!1!SIFRAZAP],
RADNIK.IME as [Odeljenje!1!IME],
RADNIK.PREZIME as [Odeljenje!1!PREZIME]
FROM ODELJENJE, RADNIK
WHERE ODELJENJE.SIFRAODELJ = RADNIK.SIFRAODELJ
FOR XML EXPLICIT,
ROOT('Odeljenja');
GO

SELECT r.SIFRAZAP as "@sifRad", r.IME as "Ime_Prezime/Ime",
r.PREZIME as "Ime_Prezime/Prezime", r.MLB as "Maticni_Broj",
r.PLATA as "Plata", r.PREMIJA as "Premija", o.SIFRAODELJ as "Odeljenje/@sifra",
o.NAZIVODELJ as "Odeljenje/Naziv", o.GRAD as "Odeljenje/Grad"
FROM (RADNIK r INNER JOIN ODELJENJE o ON r.SIFRAODELJ = o.SIFRAODELJ)
WHERE r.SIFRAZAP IN(1,5)
FOR XML PATH('Radnik'),
ELEMENTS XSINIL,
ROOT('Radnici');
GO


SELECT o.SIFRAODELJ as "@sifra", o.NAZIVODELJ as "Naziv",
o.GRAD as "Grad",
(SELECT r.SIFRAZAP as "@sifRad", r.IME as "Ime_Prezime/Ime",
r.PREZIME as "Ime_Prezime/Prezime", r.MLB as "Maticni_Broj",
r.PLATA as "Plata", r.PREMIJA as "Premija"
FROM RADNIK r
WHERE r.SIFRAODELJ = o.SIFRAODELJ
FOR XML PATH('Radnik'),
TYPE) as Radnici
FROM ODELJENJE o
WHERE o.SIFRAODELJ IN(20,30)
ORDER BY o.SIFRAODELJ
FOR XML PATH('Odeljenje'),
ROOT('Odeljenja');
GO

SELECT nad.SIFRAZAP as "@sifRuk", nad.IME as "Ime_Prezime/Ime",
nad.PREZIME as "Ime_Prezime/Prezime", pod.SIFRAZAP as "Podredjeni/@sifraZap",
pod.IME as "Podredjeni/Ime_Prezime/Ime", pod.PREZIME as "Podredjeni/Ime_Prezime/Prezime"
FROM (RADNIK nad INNER JOIN RADNIK pod ON nad.SIFRAZAP = pod.SIFRARUKOV)
ORDER BY nad.SIFRAZAP
FOR XML PATH('Rukovodioc'),
ELEMENTS XSINIL,
ROOT('Rukovodioci');
GO


SELECT
nad.SIFRAZAP as "@sifRuk", nad.IME as "Ime_Prezime/Ime",
nad.PREZIME as "Ime_Prezime/Prezime",
(SELECT pod.SIFRAZAP as "@sifraZap", pod.IME as "Ime_Prezime/Ime",
pod.PREZIME as "Ime_Prezime/Prezime"
FROM RADNIK pod
WHERE nad.SIFRAZAP = pod.SIFRARUKOV
FOR XML PATH('Podredjeni_Radnik'),
TYPE) as Podedjeni
FROM RADNIK nad
WHERE EXISTS(SELECT * FROM RADNIK r WHERE r.SIFRARUKOV = nad.SIFRAZAP)
ORDER BY nad.SIFRAZAP
FOR XML PATH('Rukovodioc'),
ELEMENTS XSINIL,
ROOT('Rukovodioci');
GO

