<?php
namespace FormGuide\PHPFormValidator;

class FieldValidator
{   
    private $field_name;
    private $validations;

    private $validator;

    public function __construct($field_name)
    {
        $this->field_name = $field_name;
        $this->validations = array();
        
        $this->validator = Validators::create($field_name);

        $this->validator_map = include('ValidatorMap.php');
    }

    public function __call($function, $arguments)
    {
        if(isset($this->validator_map[$function]))
        {
            return $this->initValidator($function, $arguments);
        }
        else
        {
            trigger_error('Call to undefined method '.__CLASS__.'::'.$function.'()', E_USER_ERROR);         
        }
    
    }

    public function initValidator($function, $arguments)
    {
        $validator_type = $this->validator_map[$function];
        $message = null;
        $constraint = null;
        foreach($arguments as $arg)
        {
            if(is_array($arg))
            {
                if(isset($arg['message']))
                {
                    $message = $arg['message'];
                }
            }
            elseif(empty($constraint))
            {
                $constraint = $arg;
            }
        }

        $this->validations[$validator_type] = 
                array('value'=>$constraint,'message'=>$message  );

        return $this;       
    }
    

    public function test($post)
    {
        foreach($this->validations as $rule => $details)
        {
            $this->validator->$rule($post,$details);
        }
    }

    public function hasErrors()
    {
        return $this->validator->hasErrors();   
    }

    public function getError()
    {
        return $this->validator->getError();
    }
}
