const express = require('express'); 
const router = express.Router(); // have all the crud functionalities

const Post =  require('../models/post.model');

// console.log(Post);
const crudController = require('./crud.controller');

router.get('',crudController(Post).get)

router.patch('/:id',crudController(Post).patch)

router.post('',crudController(Post).post)

router.delete('/:id',crudController(Post).deleteOne)


module.exports =router;
