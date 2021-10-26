# PHPFormValidator

A PHP Library for 'self-documenting' server side Form Validations.

A typical usage would be like this:

```php
use FormGuide\PHPFormValidator\FormValidator;

$validator = FormValidator::create();

$validator->fields(['name','email'])->areRequired()->maxLength(50);
$validator->field('email')->isEmail();

if(!$validator->test($_POST))
{
	return json_encode($validator->getErrors(true));
}

```

## Installation using composer

```
composer require FormGuide/PHPFormValidator

```

## Declaring validations for single fields

```php
$validator->field('email')->isEmail()->isRequired();
```

## Declaring validations for multiple fields 

```php
$validator->fields(['name','email'])->areRequired()->maxLength(50);
```

This is equivalent to:

```php
$validator->field('name')->isRequired()->maxLength(50);

$validator->field('email')->isRequired()->maxLength(50);
```


