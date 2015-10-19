const char mon[][5] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct Date{
	int year, month, day, hour;
	bool check(int y)
	{
		return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
	}
	int getHours() // to 2000.01.01 0 o'clock
	{
		int hours = 1;
		for(int i = 2000; i < year; i++) hours += 24 * (365 + check(i));
		for(int i = 1; i < month; i++)
			hours += 24 * (days[i] + (i == 2 && check(year)));
		return hours += 24 * (day - 1) + hour;
	}
};

