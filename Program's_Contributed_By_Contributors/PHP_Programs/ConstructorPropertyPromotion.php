<?php

class Order{

    public function __construct(Public string $id, Public string $sender, Public string $receiver, Private int $quantity, Private string $item)
    {}

    public function getOrder(){
        return "order id {$this->id} dengan pengirim bernama {$this->sender} dan penerimanya bernama {$this->receiver}";
    }
}

$detail_order = new Order(id: "1", sender: "Fikri Khairul", receiver: "Shaleh", quantity: 2, item: "jajanan");
var_dump($detail_order);