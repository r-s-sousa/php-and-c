<?php

declare(strict_types=1);

function factorial(int $number)
{
    $libraryPath = __DIR__ . '/factorial.so';

    if (!file_exists($libraryPath)) {
        throw new Exception('Library not found');
    }

    $cLibrary = FFI::cdef(
        'char* factorial(int n);',
        $libraryPath
    );

    return FFI::string($cLibrary->factorial($number));
}

const REQUIRED_ARGUMENTS = 2;

if ($argc !== REQUIRED_ARGUMENTS) {
    echo "Usage: php factorial.php <number>\n";
    exit(1);
}

$number = (int)$argv[1];

$result = factorial($number);

echo "Factorial of $number is: $result\n";
