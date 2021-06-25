
CREATE DATABASE triggers;
USE triggers;

CREATE TABLE user(userID INT AUTO_INCREMENT PRIMARY KEY,
                      firstname VARCHAR(40),
                      lastname VARCHAR(40));

INSERT INTO user(firstname,lastname) VALUES ('Karen','Petrosyan');
INSERT INTO user(firstname,lastname) VALUES ('Tigran','Mazmanyan');



CREATE TABLE userData(userDataID INT AUTO_INCREMENT  PRIMARY KEY,
                      userID INT,
                      age INT NOT NULL,
                      height INT NOT NULL,
                      FOREIGN KEY (userID) REFERENCES user(userID));

INSERT INTO userData(age,height,userID) VALUES (22,187,1);
INSERT INTO userData(age,height,userID) VALUES (18,175,2);

DELIMITER //
CREATE TRIGGER checkingDelete
    BEFORE DELETE
    ON user FOR EACH ROW
    BEGIN
    DELETE FROM userData WHERE userData.userDataID=OLD.userID;
    END//

DELIMITER ;

DELETE FROM user WHERE userID=1;

SELECT * FROM user;
SELECT * FROM userData;


DELIMITER //
CREATE TRIGGER nthInsert
    BEFORE INSERT
    ON user FOR EACH ROW
    if (NEW.userID % 3) = 0 then SET NEW.firstname='3nth row'; end if ;//
DELIMITER ;

INSERT INTO user(firstname,lastname) VALUES ('Karen','Petrosyan');
INSERT INTO user(firstname,lastname) VALUES ('Tigran','Mazmanyan');
INSERT INTO user(firstname,lastname) VALUES ('Hovik','Tigranyan');
INSERT INTO user(firstname,lastname) VALUES ('Karen','Petrosyan');
INSERT INTO user(firstname,lastname) VALUES ('Tigran','Mazmanyan');
INSERT INTO user(firstname,lastname) VALUES ('Hovik','Tigranyan');

SELECT * FROM user;


DROP TABLE userData;
DROP TABLE user;

DROP DATABASE triggers;