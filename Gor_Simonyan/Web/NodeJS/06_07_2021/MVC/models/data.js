const sequelize = require('./index')
const Sequelize = require('sequelize')

const data = sequelize.define("data", {
        id : {
            type: Sequelize.INTEGER,
            autoIncrement: true,
            primaryKey: true,
            allowNull: false
        },
        name: {
            type: Sequelize.STRING,
            allowNull: false
        }
    },
    {
        timestamps: false,
    })

module.exports = data

sequelize.sync()