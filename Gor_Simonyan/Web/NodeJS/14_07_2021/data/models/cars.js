const sequelize = require('./index');
const Sequelize = require('sequelize');

const cars = sequelize.define("cars", {
    id : {
        type: Sequelize.INTEGER,
        autoIncrement: true,
        primaryKey: true,
        allowNull: false
    },
    mark : {
        type: Sequelize.STRING,
        allowNull: false
    },
    year : {
        type: Sequelize.INTEGER,
        allowNull: false
    }
},
{
    timestamps: false
});

module.exports = cars;

// sequelize.sync({ force: true });