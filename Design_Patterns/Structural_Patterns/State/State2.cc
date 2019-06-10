#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <memory>

using namespace std;

typedef enum {DUCK_DOWN, STAND_UP, JUMP, DIVE} Input;

class Fighter;
class StandingState;
class JumpingState;
class DivingState;

class FighterState {
public:
  virtual ~FighterState() = default;
  virtual void handleInput(Fighter &, Input) = 0;
  virtual void update(Fighter &) = 0;

  static shared_ptr<StandingState> standing;
  static shared_ptr<DivingState> diving;
};

class DuckingState : public FighterState {
public:
  DuckingState() : chargingTime(0) {}
  virtual void handleInput(Fighter &, Input) override;
  virtual void update(Fighter &) override;

private:
  int chargingTime;
  static const int FullRestTime = 5;
};

class StandingState : public FighterState {
public:
  virtual void handleInput(Fighter &, Input) override;
  virtual void update(Fighter &) override;
};

class JumpingState : public FighterState {
public:
  JumpingState() : jumpingHeight(rand() % 5 + 1) {}
  virtual void handleInput(Fighter &, Input) override;
  virtual void update(Fighter &) override;

private:
  int jumpingHeight;
};

class DivingState : public FighterState {
public:
  virtual void handleInput(Fighter &, Input) override;
  virtual void update(Fighter &) override;
};

shared_ptr<StandingState> FighterState::standing(new StandingState);
shared_ptr<DivingState> FighterState::diving(new DivingState);

class Fighter {
public:
  Fighter(const string &newName) : name(newName), state(FighterState::standing) {}

  string getName() const {
    return name;
  }

  int getFatigueLevel() const {
    return fatigueLevel;
  }

  virtual void handleInput(Input input) {
    state->handleInput(*this, input);
  }

  void changeState(shared_ptr<FighterState> newState) {
    state = newState;
    updateWithNewState();
  }

  void standsUp() {
    cout << getName() << " stands up." << endl;
  }

  void ducksDown() {
    cout << getName() << " ducks down." << endl;
  }

  void jumps() {
    cout << getName() << " jumps into the air." << endl;
  }

  void dives() {
    cout << getName() << " makes a dive attack in the middle of the jump!" << endl;
  }

  void feelsStrong() {
    cout << getName() << " feels strong!" << endl;
  }

  void changeFatigueLevelBy(int change) {
    fatigueLevel += change;
    cout << "fatigueLevel = " << fatigueLevel << endl;
  }

private:
  virtual void updateWithNewState() {
    state->update(*this);
  }

  string name;
  shared_ptr<FighterState> state;
  int fatigueLevel = rand() % 10;
};

void StandingState::handleInput (Fighter& fighter, Input input)  {
  switch (input) {
  case STAND_UP:  std::cout << fighter.getName() << " remains standing." << std::endl;  return;
  case DUCK_DOWN:  fighter.changeState (std::shared_ptr<DuckingState> (new DuckingState));  return fighter.ducksDown();
  case JUMP:  fighter.jumps();  return fighter.changeState (std::shared_ptr<JumpingState> (new JumpingState));
  default:  std::cout << "One cannot do that while standing.  " << fighter.getName() << " remains standing by default." << std::endl;
  }
}

void StandingState::update (Fighter& fighter) {
  if (fighter.getFatigueLevel() > 0)
    fighter.changeFatigueLevelBy(-1);
}

void DuckingState::handleInput (Fighter& fighter, Input input)  {
  switch (input) {
  case STAND_UP:  fighter.changeState (FighterState::standing);  return fighter.standsUp();
  case DUCK_DOWN:
    std::cout << fighter.getName() << " remains in ducking position, ";
    if (chargingTime < FullRestTime) std::cout << "recovering in the meantime." << std::endl;
    else std::cout << "fully recovered." << std::endl;
    return update (fighter);
  default:
    std::cout << "One cannot do that while ducking.  " << fighter.getName() << " remains in ducking position by default." << std::endl;
    update (fighter);
  }
}

void DuckingState::update (Fighter& fighter) {
  chargingTime++;
  std::cout << "Charging time = " << chargingTime << "." << std::endl;
  if (fighter.getFatigueLevel() > 0)
    fighter.changeFatigueLevelBy(-1);
  if (chargingTime >= FullRestTime && fighter.getFatigueLevel() <= 3)
    fighter.feelsStrong();
}

void JumpingState::handleInput (Fighter& fighter, Input input)  {
  switch (input) {
  case DIVE:  fighter.changeState (FighterState::diving);  return fighter.dives();
  default:
    std::cout << "One cannot do that in the middle of a jump.  " << fighter.getName() << " lands from his jump and is now standing again." << std::endl;
    fighter.changeState (FighterState::standing);
  }
}

void JumpingState::update (Fighter& fighter) {
  std::cout << fighter.getName() << " has jumped " << jumpingHeight << " feet into the air." << std::endl;
  if (jumpingHeight >= 3)
    fighter.changeFatigueLevelBy(1);
}

void DivingState::handleInput (Fighter& fighter, Input)  {
  std::cout << "Regardless of what the user input is, " << fighter.getName() << " lands from his dive and is now standing again." << std::endl;
  fighter.changeState (FighterState::standing);
}

void DivingState::update (Fighter& fighter) {
  fighter.changeFatigueLevelBy(2);
}

int main() {
  std::srand(std::time(nullptr));
  Fighter rex ("Rex the Fighter"), borg ("Borg the Fighter");
  std::cout << rex.getName() << " and " << borg.getName() << " are currently standing." << std::endl;
  int choice;
  auto chooseAction = [&choice](Fighter& fighter) {
    std::cout << std::endl << DUCK_DOWN + 1 << ") Duck down  " << STAND_UP + 1 << ") Stand up  " << JUMP + 1
    << ") Jump  " << DIVE + 1 << ") Dive in the middle of a jump" << std::endl;
    std::cout << "Choice for " << fighter.getName() << "? ";
    std::cin >> choice;
    const Input input1 = static_cast<Input>(choice - 1);
    fighter.handleInput (input1);	
  };
  while (true) {
    chooseAction (rex);
    chooseAction (borg);
  }

  return EXIT_SUCCESS;
}
