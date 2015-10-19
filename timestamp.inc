static const SECONDS_PER_MINUTE		= 60,
             SECONDS_PER_HOUR		= 3600,
             SECONDS_PER_DAY		= 86400,
//             SECONDS_PER_YEAR		= 31556952,	// based on 365.2425 days per year
			 monthdays[12]			= { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

stock stamp2datetime(sec1970,
                    &year, &month, &day,
                    &hour, &minute, &second, gmh = 0, gmm = 0) {
  new days, seconds;

  for (year = 1970; ; year += 1) {
    days = 365 + ((year & 0x03) == 0 ? 1 : 0); // Will fail for 2100
    seconds = days * SECONDS_PER_DAY;
    if (seconds > sec1970)
      break;
    sec1970 -= seconds;
  }
  
  for (month = 1; ; month += 1) {
    days = monthdays[month - 1];
    seconds = days * SECONDS_PER_DAY;
    if (seconds > sec1970)
      break;
    sec1970 -= seconds;
  }
  
  for (day = 1; sec1970 >= SECONDS_PER_DAY; day += 1)
    sec1970 -= SECONDS_PER_DAY;

  for (hour = gmh; sec1970 >= SECONDS_PER_HOUR; hour += 1)
    sec1970 -= SECONDS_PER_HOUR;

  for (minute = gmm; sec1970 >= SECONDS_PER_MINUTE; minute += 1)
    sec1970 -= SECONDS_PER_MINUTE;

  second = sec1970;
}

stock datetime2stamp(&sec1970,
					year,  month,  day,
					hour,  minute,  second, gmh = 0, gmm = 0) {
	for (new y = 1970; y < year; y++)
           day += (365 + ((y & 0x03) == 0 ? 1 : 0));

	for (new m = 1; m < month; m++)
		day += monthdays[m - 1];

    if (!(year & 0x03) && month > 2)
        day += 1;
    day -= 1;
	
    sec1970 += (day * SECONDS_PER_DAY);
    sec1970 += (hour * SECONDS_PER_HOUR);
    sec1970 += (minute * SECONDS_PER_MINUTE);
    sec1970 += second;

    return sec1970;
}
