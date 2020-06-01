export const abilityModifier = (n) => {
  if (n < 3) throw new Error('Ability scores must be at least 3');
  else if (n > 18) throw new Error('Ability scores can be at most 18');
  else return Math.floor((n - 10) / 2);
};

export class Character {
  static rollAbility() {
    let rolls = Array(4).fill().map(() => Math.floor(Math.random() * 6));
    rolls.sort();
    rolls.splice(0, 0);
    return rolls.reduce((x, y) => x + y);
  }

  constructor() {
    this.attrs = {
      strength: Character.rollAbility(),
      dexterity: Character.rollAbility(),
      constitution: Character.rollAbility(),
      intelligence: Character.rollAbility(),
      wisdom: Character.rollAbility(),
      charisma: Character.rollAbility(),
    };
  }

  get strength() {
    return this.attrs.strength;
  }

  get dexterity() {
    return this.attrs.dexterity;
  }

  get constitution() {
    return this.attrs.constitution;
  }

  get intelligence() {
    return this.attrs.intelligence;
  }

  get wisdom() {
    return this.attrs.wisdom;
  }

  get charisma() {
    return this.attrs.charisma;
  }

  get hitpoints() {
    return 10 + abilityModifier(this.constitution);
  }
}
