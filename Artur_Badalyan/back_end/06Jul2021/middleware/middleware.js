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

module.exports = { checkData,checkID }