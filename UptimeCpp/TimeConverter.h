#include <sstream>
#include <iomanip>
using namespace std;
class TimeConverter
{
    public:
        string ConvertSectoTimeString(double d) {
            d = d + 0.5 - (d < 0);
            int n = int(d);

            int day = n / (24 * 3600);

            n = n % (24 * 3600);
            int hour = n / 3600;

            n %= 3600;
            int minutes = n / 60;

            n %= 60;
            int seconds = n;


            string s1 = ""; //  day + "day";
            if (day == 1) {
                s1 = to_string(day) + " day, ";
            }
            else if (day > 1) {
                s1 = to_string(day) + " days, ";
            }

            string s2 = "";
            if (hour < 1) {
                s2 = to_string(minutes) + " min";
            }
            else {
                //s2 = to_string(hour) + ":" + to_string(minutes);
                ostringstream oss;
                oss << setfill('0') << setw(2) << hour << ":";
                oss << setfill('0') << setw(2) << minutes;
                s2 = oss.str();
            }
            return s1 + s2;
        }
};
