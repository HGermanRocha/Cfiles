create database bd;

use bd;

CREATE TABLE bd.Alumnos
(
	matricula INT NOT NULL,
	nombre VARCHAR(25),
	apellido_p VARCHAR(25),
	carrera VARCHAR(25) NOT NULL,
	semestre INT NOT NULL,
	promedio INT NOT NULL,
	PRIMARY KEY (matricula)
);

INSERT INTO bd.alumnos (matricula, nombre, apellido_p, carrera,semestre, promedio) VALUES(150307, "German", "Rocha", "Software",4, 99);
INSERT INTO bd.alumnos (matricula, nombre, apellido_p, carrera,semestre, promedio) VALUES(015242, "Juan", "Perez", "Mecatronica",4, 98);
INSERT INTO bd.alumnos (matricula, nombre, apellido_p, carrera,semestre, promedio) VALUES(015253, "Rodrigo", "Gomez", "Mecatronica",5, 100);
INSERT INTO bd.alumnos (matricula, nombre, apellido_p, carrera,semestre, promedio) VALUES(015264, "Luis", "Farias", "Sistemas",4, 93);
INSERT INTO bd.alumnos (matricula, nombre, apellido_p, carrera,semestre, promedio) VALUES(015275, "Jesus", "Perez", "Medicina",1, 91);

UPDATE bd.alumnos set semestre=1 WHERE nombre="Luis";

SELECT matricula, nombre, apellido_p from bd.alumnos WHERE promedio >= 90 and promedio <=100;

SELECT * from bd.alumnos WHERE carrera="medicina";

SELECT * from bd.alumnos WHERE semestre=1;

SELECT promedio, nombre from bd.alumnos WHERE semestre=5 and carrera="mecatronica";

SELECT * FROM bd.alumnos;

SELECT SUM(promedio) as 'Suma de Promedios' from bd.alumnos;

SELECT SUM(promedio) as 'Suma de Promedios', MAX(promedio) as 'Promedio mas alto', AVG(promedio) as 'Promedio general', MIN(promedio) as 'Promedio general' from bd.alumnos;

SELECT MAX(promedio) as 'Promedio mas alto' from bd.alumnos;

SELECT AVG(promedio) as 'Promedio general' from bd.alumnos;

SELECT MIN(promedio) as 'Promedio general' from bd.alumnos;

SELECT COUNT(*) carrera from bd.alumnos WHERE carrera="mecatronica";
/*
create database bd;

use bd;


CREATE TABLE bd.policy
(
	policyNumber VARCHAR(25) NOT NULL,
	dateIssued DATE,
	policyType VARCHAR(25),
	customerNumber VARCHAR(25) NOT NULL,
	commisionRate VARCHAR(25) NOT NULL,
	maturityDate DATE NOT NULL,
	PRIMARY KEY (policyNumber)
);

select * from bd.policy;

INSERT INTO bd.policy (policyNumber, dateIssued, policyType, customerNumber,commisionRate, maturityDate) VALUES('V213748', 02/29/1989, "E20", "HAYES01","12%", 02/29/2009);
INSERT INTO bd.policy (policyNumber, dateIssued, policyType, customerNumber,commisionRate, maturityDate) VALUES('N065987', 02/29/1989, "E20", "HAYES01","12%", 02/29/2009);
*/