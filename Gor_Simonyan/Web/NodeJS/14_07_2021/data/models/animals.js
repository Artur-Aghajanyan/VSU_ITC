const sequelize = require('./index');
const Sequelize = require('sequelize');

const animals = sequelize.define("animals", {
    id : {
        type: Sequelize.INTEGER,
        autoIncrement: true,
        primaryKey: true,
        allowNull: false
    },
    name : {
        type: Sequelize.STRING,
        allowNull: false
    },
    age : {
        type: Sequelize.INTEGER,
        allowNull: false
    }
},
{
    timestamps: false
});

module.exports = animals;

// sequelize.sync({ force: true });