<?php
namespace FormGuide\PHPFormValidator;

class Validators
{
    private $field_name;
    private $errors;
    private $validators_list;

    public function __construct($field_name)
    {
        $this->field_name = $field_name;
        $this->errors = array();
        $this->validators_list = include('ValidatorsList.php');
    }

    public static function create($field_name)
    {
        return new Validators($field_name);
    }

    public function required($post, $details=array())
    {
        if(empty($post[$this->field_name]))
        {
            $this->addError("{$this->field_name} is Required.");
            return false;
        }

        $value = trim($post[$this->field_name]);

        if(empty($value))
        {
            $this->addError("{$this->field_name} is Required.");
            return false;
        }
        return true;
    }

    public function __call($function, $arguments)
    {
        //if(in_array('email', $this->validator_names,TRUE))
        if(isset($this->validators_list[$function]))
        {
            $post = $arguments[0];
            $details = $arguments[1];
            return $this->testField($function, $post, $details);
        }
        else
        {
            trigger_error('Call to undefined method '.__CLASS__.'::'.$function.'()', E_USER_ERROR);
        }
    }

    private function testField($validation, $post, $details)
    {
        if(empty($post[$this->field_name]))
        {
            return true;
        }
        $fn = 'check_'.$validation;

        $res = $this->$fn($post, $details);

        if(false === $res)
        {
            $this->validation_error($validation, $details);
        }
        return $res;
    }

    private function check_email($post,$details)
    {
        return (filter_var($post[$this->field_name] , FILTER_VALIDATE_EMAIL) === false)?false:true;
    }

    private function check_maxlen($post, $details)
    {
        $maxlen = intval($details['value']);

        return (strlen($post[$this->field_name]) <= $maxlen);
    }

    private function check_minlen($post,$details)
    {
        $minlen = intval($details['value']);
        return (strlen($post[$this->field_name]) >= $minlen);
    }

    public function check_alphabetic($post,$details)
    {
        return ctype_alpha($post[$this->field_name]);
    }

    public function check_alphanumeric($post,$details)
    {
        return ctype_alnum($post[$this->field_name]);
    } 

    public function check_alphabetic_space($post,$details)
    {
        $value = str_replace(' ','',$post[$this->field_name]);
        return ctype_alpha($value);
    }

    public function check_alphanumeric_space($post,$details)
    {
        $value = str_replace(' ','',$post[$this->field_name]);
        return ctype_alnum($value);
    }        

    private function validation_error($validation,$details)
    {
        $error_msg = '';

        if(isset($details['message']))
        {
            $error_msg = $details['message'];
        }
        elseif(!empty($this->validators_list[$validation]['message']))
        {
            $error_msg = $this->validators_list[$validation]['message'];
        }

        $error_msg = $this->interpolate_message($error_msg, $details);

        $this->addError($error_msg);
    }

    private function interpolate_message($message, $details)
    {
        $constraint = isset($details['value']) ? $details['value']: '';

        $replacements = array('%field%' => $this->field_name,
                         '%constraint%' => $constraint) ;

        return strtr($message, $replacements);
    }

    public function addError($error)
    {
        $this->errors[] = $error;
    }

    public function hasErrors()
    {
        return empty($this->errors)?false:true; 
    }

    public function getErrorCount()
    {
        return count($this->errors);
    }
    public function getError()
    {
        if(empty($this->errors))
        {
            return null;
        }
        else
        {
            return $this->errors[0];
        }
    }
}