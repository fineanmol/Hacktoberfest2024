<?php
namespace FormGuide\PHPFormValidator;

class FieldValidatorCollection
{
    public $fields;
    private $validator;


    public function __construct()
    {
        $this->fields = array();
        $this->validator_map = include('ValidatorMap.php');     
    }
    
    public function __call($function, $arguments)
    {
        if(isset($this->validator_map[$function]))
        {
            foreach($this->fields as $field)
            {
                $field->initValidator($function, $arguments);   
            }
            return $this;
        }
        else
        {
            trigger_error('Call to undefined method '.__CLASS__.'::'.$name.'()', E_USER_ERROR);             
        }
    }

    

}