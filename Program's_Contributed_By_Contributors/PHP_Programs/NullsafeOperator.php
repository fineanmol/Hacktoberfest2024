<?php
class Order{
    public ?string $item;
}

class Transaction{
    public ?Order $order;
}

function getItem(?Transaction $transaction): ?string
{
    return $transaction?->order?->item;
}

echo getItem(null);