const User = require('../models/User')


async function connection() {
    try {
        await User.sequelize.authenticate();
        console.log('Connection has been established successfully.');
        await User.sync({alter: true});
    } catch (error) {
        console.error('Unable to connect to the database:', error);
    }
}

module.exports = connection;