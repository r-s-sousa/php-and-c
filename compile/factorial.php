<?php

declare(strict_types=1);

function factorial(int $number): string
{
    $binaryPath = __DIR__ . '/factorial';

    if (!file_exists($binaryPath)) {
        throw new Exception('Library not found');
    }

    $output = shell_exec("$binaryPath $number");
    if ($output === false) {
        throw new Exception('Failed to execute');
    }

    return $output;
}

const REQUIRED_ARGUMENTS = 2;

if ($argc !== REQUIRED_ARGUMENTS) {
    echo "Usage: php factorial.php <number>\n";
    exit(1);
}

$number = (int)$argv[1];

$result = factorial($number);

echo "Factorial of $number is: $result\n";
