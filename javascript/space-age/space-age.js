const ORBITAL_PERIOD_FOR_EARTH_IN_SECONDS = 31557600;
const ORBITAL_PERIODS = {
    'earth': 1,
    'jupiter': 11.862615,
    'mars': 1.8808158,
    'mercury': 0.2408467,
    'neptune': 164.79132,
    'saturn': 29.447498,
    'uranus': 84.016846,
    'venus': 0.61519726,
};

const secondstoEarthYears = (seconds) => {
    return seconds / ORBITAL_PERIOD_FOR_EARTH_IN_SECONDS;
};

export const age = (planet, seconds) => {
    const answer = secondstoEarthYears(seconds) / ORBITAL_PERIODS[planet];
    return Number(answer.toFixed(2));
};
