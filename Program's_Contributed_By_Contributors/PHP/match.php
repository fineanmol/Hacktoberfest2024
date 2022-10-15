<?php

declare(strict_types=1);

namespace App\PHP;

final class Match
{
    public static function rematch(mixed $input): string
    {
        return match(true) {
            is_string($input) => 'I am a string',
            is_array($input) => 'I am an array',
            is_int($input) => 'I am an integer',
            default => 'Maybe you should catch me.'
        };
    }
}