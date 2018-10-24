<?php

function from($date) {
    $gs = clone $date;
    $gs->add(new DateInterval('PT1000000000S'));
    return $gs;
}
