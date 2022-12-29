// This stub file contains items that aren't used yet; feel free to remove this module attribute
// to enable stricter warnings.
#![allow(unused)]

const CARS_PER_HOUR: u8 = 221;

pub fn production_rate_per_hour(speed: u8) -> f64 {
    let success = match speed {
        1..=4 => 1.00,
        5..=8 => 0.90,
        9..=10 => 0.77,
        _ => 0.00,
    };
    CARS_PER_HOUR as f64 * speed as f64 * success
}

pub fn working_items_per_minute(speed: u8) -> u32 {
    production_rate_per_hour(speed) as u32 / 60
}
