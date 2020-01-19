boolean hasChanged(int p){
  actualState = digitalRead(p);

  if (lastState != actualState)  // there was a chage in p state
  {
    counter++;                   // count state changes
    int isPair = counter % 2;    // only want pair numbers
    if (isPair != 1)              
    {
      lastState = actualState;
      return true;
    }else{
      lastState = actualState;
      return false;
    }
  }else return false;
}
