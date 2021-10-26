<?php

namespace FormGuide\PHPFormValidator;

class FormValidator
{
    private $fields;

    public function __construct()
    {
        $this->fields = array();
    }

    public static function create()
    {
        return new FormValidator();
    }
    
    public function field($field_name)
    {
        if(isset($this->fields[$field_name]))
        {
            return $this->fields[$field_name];
        }

        $field = new FieldValidator($field_name);

        $this->fields[$field_name] = $field;

        return $field; 
    }

    public function fields($arr_fields)
    {
        $coll = new FieldValidatorCollection();

        foreach($arr_fields as $field)
        {
            $coll->fields[] = $this->field($field);
        }
        return $coll;
    }

    public function test($post)
    {
        foreach($this->fields as $field_name => $rule)
        {
            $rule->test($post); 
        }
        return $this->hasErrors()?false:true;
    }

    public function hasErrors()
    {
        foreach($this->fields as $rule)
        {
            if($rule->hasErrors())
            {
                return true;
            }
        }
        return false;
    }

    public function getErrors($associative = false)
    {
        $errors = array();
        foreach($this->fields as $field_name => $field)
        {
            $error = $field->getError();
            if(!empty($error))
            {
                $errors[$field_name] = $error;
            }
        }   

        if(false == $associative)
        {
            return array_values($errors);   
        }
        
        return $errors; 
    }

}