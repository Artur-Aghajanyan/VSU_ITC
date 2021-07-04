const {Sequelize, DataTypes, Model} = require('sequelize');
const express = require('express');
const bodyParser = require('body-parser');
const port = 5005;
const app = express();

app.use(bodyParser.json());

const sequelize = new Sequelize('NodeJs', 'root', 'root', {
    host: 'localhost',
    port: 3306,
    dialect: 'mysql'
});

class User extends Model {}

async function connection() {
    try {
        await sequelize.authenticate();
        console.log('Connection has been established successfully.');

        User.init({
            id: {
                allowNull: false,
                autoIncrement: true,
                primaryKey: true,
                type: DataTypes.INTEGER
            },
            firstName: {
                type: DataTypes.STRING,
                allowNull: false
            },
            lastName: {
                type: DataTypes.STRING,
                allowNull: false
            },
            age: {
                type: Sequelize.DataTypes.INTEGER,
                allowNull: false
            }
        }, {
            timestamps: false,
            sequelize, // We need to pass the connection instance
            modelName: 'User' // We need to choose the model name
        });
        await User.sync({alter: true});
    } catch (error) {
        console.error('Unable to connect to the database:', error);
    }
}

connection().then(() => {
    const checkData = (req, res, next) => {
        const body = req.body;
        const bodyValue = Object.values(body);
        const text = /^[A-Za-z]+$/;
        if (text.test(bodyValue[0]) && text.test(bodyValue[1]) && !text.test(bodyValue[2])) {
            next();
        } else {
            res.status(400);
            res.send('The imported text cannot be numbers');
        }
    };

    const checkID = (req, res, next) => {
        const text = /^[A-Za-z]+$/;
        console.log(req.query.id)
        if (!req.query.id) next();
        else if (!text.test(req.query.id)) {
            next();
        } else {
            res.status(400);
            console.log(("The id can't be text"))
            res.send("The id can't be text")
        }

    }

    app.get('/', checkID, (req, res) => {
        console.log('Got request GET');
        console.log(req.query.id)
        if (!req.query.id) {
            User.findAll().then(data => {
                let arr = [];
                data.forEach((item, index) => {
                    arr[index] = {
                        id: item.id,
                        firstName: item.firstName,
                        lastName: item.lastName,
                        age: item.age
                    }
                })
                res.send(JSON.stringify(arr));
            }).catch((err) => {
                res.status(400);
                res.send(err)
            });
        } else {
            User.findOne({
                where: {
                    id: req.query.id
                }
            }).then((data) => {
                res.end(JSON.stringify({
                    id: data.id,
                    firstname: data.firstName,
                    lastname: data.lastName,
                    age: data.age
                }));
            }).catch((err) => {
                res.status(400);
                res.send(err)
            });
        }
    });

    app.post('/post', checkData, (req, res) => {
        const body = req.body;
        User.create({
            firstName: body.firstName,
            lastName: body.lastName,
            age: body.age,
        }).then(() => {
            res.status(200);
            res.send('The user is added to the table and saved');
        }).catch((err) => {
            res.status(400);
            res.send(err)
        });
    });

    app.delete('/delete', (req, res) => {
        User.destroy({
                where: {
                    id: req.query.id
                }
            }
        ).then(() => {
            res.status(200);
            res.send('The user is delete to the table and saved');
        }).catch((err) => {
            res.status(400);
            res.send(err)
        });
    });

    app.put('/put', (req, res) => {
        User.update(
            {
                firstName: req.body.firstName,
                lastName: req.body.lastName,
                age: req.body.age
            },
            {where: {id: req.query.id}}
        ).then(() => {
            res.status(200);
            res.send('The user is update and saved');
        }).catch((err) => {
            res.send(err);
        });
    });

});

app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`);
});