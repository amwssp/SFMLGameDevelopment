#ifndef STATESTACK_H
#define STATESTACK_H

class StateStack {
 public:
  void pushState(States::ID id);
  void popState();
  void clearStates();
};

#endif
