void findBestFit(Event newSoft, bool calBool[], char* calChar[]) {

  //STEP 1: DIVIDE INTO CHUNKS
  //maybe separate method?
  int duration, numChunks, remainder;
  vector<Event> tempeventlist;
  duration = newSoft->duration;
  numChunks = duration / 3
  remainder = duration % 3;

  for (int i = 0; i < numChunks; i++) {
    Event* temp = new Event(3); //constructor with duration 3
    tempeventlist.push_back(*temp); //maybe keep global temp list with chunks and main list with full task? idfk
  }

  Event* temp = new Event(remainder) //constructor with duration remainder
  tempeventlist.push_back(*temp);

  //STEP 2: FIND FREE-EST DAY
  int temp, max, counter, numFree;
  double tempFreestDay, freestDay;

  for (int i = 0; i < calBool.size(); i++, counter++) {
    if (counter == 23) {
      counter = 0;
      numFree = 0;
    }
    if (calBool[i] == true) {
      ++numFree;
      temp = numFree;
      if (temp > max) {
        max = temp;
        tempFreestDay = i;
      }
    }
  }

  freestDay = floor(tempFreestDay / 24); //will be 0 for 1st day, 1 for 2nd Day etc.

  //STEP 3: FIND FIRST AVAILABLE SPOT ON FREE-EST DAY
  int index, end;
  index = freestDay * 24;
  end = index + 24;

  for (int i = index; i < end; i++) {
    if (calBool[i] == false) {
      calBool[i] = true;   //PLUG CHUNK HERE
      calChar[i] = newSoft->task; //PLUG CHUNK HERE
      break;
    }
  }

}
