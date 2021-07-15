const {Model,DataTypes,Sequelize} = require('sequelize');
class model extends Model {}

const sequelize = new Sequelize('NodeJs', 'root', 'root', {
    host: 'localhost',
    port: 3306,
    dialect: 'mysql'
});

const User = model.init({
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
    sequelize,
    modelName: 'User'
});

module.exports = User;