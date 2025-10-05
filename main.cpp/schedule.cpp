#include <schedule.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>


vector<PillSchedule> sched; //current pills needed
PillSchedule[] actualSchedule;
int currentDay;


//add medication frequeuncy

//return medication that needs to be taken at a certain time


public schedule(){
    currentDay=0;
    sched = new vector<PillSchedule>;
}

void addMedication(String med, int quantity, int[] days, int hour)
{  
    PillSchedule newPill = new PillSchedule(med, quantity, days, hour, false);
    sched.push_back(newPill);

}



vector<PillSchedule> returnMedication(){
    return sched;

}



