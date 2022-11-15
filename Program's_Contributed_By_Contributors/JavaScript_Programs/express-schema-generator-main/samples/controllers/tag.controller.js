const express = require('express'); 
const router = express.Router(); // have all the crud functionalities
const Tag = require('../models/tag.model');

const crudController = require('./crud.controller');

router.get('',crudController(Tag).get)

router.patch('/:id',crudController(Tag).patch)

router.post('',crudController(Tag).post)

router.delete('/:id',crudController(Tag).deleteOne)


module.exports = router;
