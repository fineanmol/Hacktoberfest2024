
const get = (model) =>async(req, res) => {
    try{
        const user = await model.find().lean()
        res.send(user)}catch(err){
        console.log(err.message);
    }
}

const patch = (model) => async(req, res) => {
    const user = await model.findByIdAndUpdate(req.params.id,req.body,{new:true}).lean()
    res.send(user)
}

const post = (model) => async(req, res) => {
    try{  const user = await model.create(req.body)
    res.send(user)}catch(err){
        console.log(err.message);
        res.send(err.message)
    }
}

const deleteOne = (model) =>async(req, res) => {
    const user = await model.findByIdAndDelete(req.params.id).lean()
    res.send(user)
}

module.exports = (model) => {
    return{ 
        post: post(model),
        patch:patch(model),
        get: get(model),
        deleteOne: deleteOne(model)
    };
}