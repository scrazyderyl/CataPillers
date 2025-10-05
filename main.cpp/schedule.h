struct PillSchedule {
  String pillName;
  int quantity;
  int[] dayOfWeek;    // 0-6 (Sunday-Saturday) or 7 for daily
   int hour;
//   int minute;
  bool taken;       // Track if taken today
   
};