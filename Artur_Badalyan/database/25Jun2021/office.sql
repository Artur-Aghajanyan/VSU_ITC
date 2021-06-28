CREATE DATABASE office;
USE office;

CREATE TABLE Section
(
    sectionID   INT AUTO_INCREMENT,
    sectionName VARCHAR(40),
    PRIMARY KEY (SectionID)
);

CREATE TABLE Staff
(
    staffID   INT AUTO_INCREMENT PRIMARY KEY,
    sectionID INT NOT NULL,
    firstname VARCHAR(40),
    lastname  VARCHAR(40),
    FOREIGN KEY (sectionID) REFERENCES Section (sectionID)
);

CREATE TABLE Projects
(
    prID           INT AUTO_INCREMENT,
    ProjectProgram VARCHAR(40),
    active         BOOLEAN NOT NULL,
    PRIMARY KEY (prID)
);

CREATE TABLE ProjectStaff
(
    prID     INT,
    staffID  INT,
    workDate DATE NOT NULL,
    workTime DATE NULL,
    FOREIGN KEY (prID) REFERENCES Projects (prID),
    FOREIGN KEY (staffID) REFERENCES Staff (staffID)
);

INSERT INTO Section (sectionName)
VALUES ('Software Enginering'),
       ('web-frontend'),
       ('web-backend'),
       ('Testing');

INSERT INTO Staff (firstname, lastname, sectionID)
VALUES ('Karen', 'Mesropyan', 1),
       ('Tigran', 'Mazmanyan', 4),
       ('Aram', 'Xachyan', 1),
       ('Artur', 'Tigranyan', 1),
       ('Levon', 'Evoyan', 2),
       ('Karine', 'Haroyan', 3);

INSERT INTO Projects (ProjectProgram, active)
VALUES ('Python', true),
       ('C++', true),
       ('C++', false),
       ('Android', true),
       ('Python', false),
       ('full-stack', true);

INSERT INTO ProjectStaff (prID, staffID, workDate)
VALUES (1, 1, STR_TO_DATE('17,12,2019', '%d,%m,%Y')),
       (2, 4, STR_TO_DATE('02,06,2020', '%d,%m,%Y')),
       (2, 5, STR_TO_DATE('02,06,2020', '%d,%m,%Y')),
       (2, 3, STR_TO_DATE('02,06,2020', '%d,%m,%Y')),
       (3, 1, STR_TO_DATE('29,08,2019', '%d,%m,%Y')),
       (4, 1, STR_TO_DATE('06,07,2020', '%d,%m,%Y')),
       (5, 2, STR_TO_DATE('10,11,2018', '%d,%m,%Y')),
       (6, 3, STR_TO_DATE('25,06,2021', '%d,%m,%Y'));

SELECT * FROM Staff;
/* Calculation of working hours, starting from the moment of acceptance of the project */
SELECT * FROM Projects;
SELECT * FROM Section;
SELECT prID, staffID, workDate, (CURDATE() - workDate) * 8 as 'workTime in hour' FROM ProjectStaff;

/*Function for search employees with Project program name */
DELIMITER //
CREATE PROCEDURE proc(IN x VARCHAR(30))
begin
    SELECT Projects.prID, ProjectProgram, firstname, lastname
    FROM Projects
             INNER JOIN ProjectStaff ON ProjectStaff.prID = Projects.prID and Projects.ProjectProgram = x
             INNER JOIN Staff ON Staff.staffID = ProjectStaff.staffID;
end //
DELIMITER ;

CALL proc('C++');
CALL proc('Python');

DROP TABLE ProjectStaff;
DROP TABLE Projects;
DROP TABLE Staff;
DROP TABLE Section;
DROP DATABASE office;