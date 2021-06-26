CREATE DATABASE office;
USE office;

CREATE TABLE Section(sectionID INT AUTO_INCREMENT,
                     sectionName VARCHAR(40),
                     PRIMARY KEY(SectionID));

CREATE TABLE Staff(staffID INT AUTO_INCREMENT PRIMARY KEY,
                   sectionID INT NOT NULL,
                   firstname VARCHAR(40),
                   lastname VARCHAR(40),
                   FOREIGN KEY (sectionID) REFERENCES Section(sectionID));

CREATE TABLE Projects(prID INT AUTO_INCREMENT,
                      staffID INT NOT NULL,
                      staffProgram VARCHAR(40),
                      workDate DATE NOT NULL,
                      workTime DATE NULL,
                      active BOOLEAN NOT NULL,
                      PRIMARY KEY(prID),
                      FOREIGN KEY (staffID) REFERENCES Staff(staffID));

INSERT INTO Section (sectionName)
VALUES ('Software Enginering'),('web-frontend'),('web-backend'),('Testing');

INSERT INTO Staff (firstname,lastname,sectionID)
VALUES ('Karen','Mesropyan',1),('Tigran','Mazmanyan',4),
       ('Aram','Xachyan',1),('Artur','Tigranyan',1),
       ('Levon','Evoyan',2),('Karine','Haroyan',3);


INSERT INTO Projects (staffID,staffProgram,workDate,active)
VALUES (1,'Python',STR_TO_DATE('17,12,2019', '%d,%m,%Y'),true),(4,'C++',STR_TO_DATE('02,06,2020', '%d,%m,%Y'),true),
       (3,'C++',STR_TO_DATE('29,08,2019', '%d,%m,%Y'),false),(1,'Android',STR_TO_DATE('06,07,2020', '%d,%m,%Y'),true),
       (2,'Python',STR_TO_DATE('10,11,2018', '%d,%m,%Y'),false),(6,'full-stack',STR_TO_DATE('25,06,2021', '%d,%m,%Y'),true),
       (5,'full-stack',STR_TO_DATE('25,06,2021', '%d,%m,%Y'),true);

SELECT * FROM Staff;
/* Calculation of working hours, starting from the moment of acceptance of the project */
SELECT staffID,staffProgram,workDate,(CURDATE() - workDate) * 8 as 'workTime in hour',active FROM Projects;
SELECT * FROM Section;

DROP TABLE Projects;
DROP TABLE Staff;
DROP TABLE Section;
DROP DATABASE office;
