const sequelize = require('./index');
const Sequelize = require('sequelize');

const company = sequelize.define("company", {
    id : {
        type: Sequelize.INTEGER,
        autoIncrement: true,
        primaryKey: true,
        allowNull: false
    },
    company : {
        type: Sequelize.STRING,
        allowNull: false
    },
    budget : {
        type: Sequelize.INTEGER,
        allowNull: false
    }
},
{
    timestamps: false
});

module.exports = company;

// sequelize.sync({ force: true });