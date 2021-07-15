const User = require('../models/User');

async function connection() {
    try {
        await User.sequelize.authenticate();
        // eslint-disable-next-line no-console
        console.log('Connection has been established successfully.');
        await User.sync({alter: true});
    } catch (error) {
        // eslint-disable-next-line no-console
        console.error('Unable to connect to the database:', error);
    }
}

module.exports = connection;
