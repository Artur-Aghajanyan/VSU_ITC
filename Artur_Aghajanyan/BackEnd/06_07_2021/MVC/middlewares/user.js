const user = require('../models/user');

const checkID = (req, res, next) => {
  const checkNum = /^[A-Za-z]+$/;
  const { id } = req.query;
  if (!checkNum.test(id)) {
    user.User.findAll().then((response) => {
      response.forEach((item) => {
        if (item.id === +id) next();
      });
    });
  } else {
    res.status(400);
    res.end('Error');
  }
};

module.exports = { checkID };
