const User = require('../models/User');

const requestGet = (req,res) => {
    console.log('Got request GET');
    console.log(req.query.id)
    if (!req.query.id) {
        User.findAll({raw: true}).then(data => {
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
}

const requestPost = (req,res) => {
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
}

const requestDelete = (req,res) => {
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
}

const requestPut = (req,res) => {
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
}

module.exports = { requestGet,requestPost,requestPut,requestDelete }