class Solution {
public:
    int countTime(string time) {
        int hours = 0;
        int minutes = 0;
        if (time[0] == '?' && time[1] == '?')
            hours = 24;
        else if (time[0] == '?') {
            if (time[1] <= '3')
                hours = 3;
            else
                hours = 2;
        }
        else if (time[1] == '?') {
            if (time[0] == '2')
                hours = 4;
            else
                hours = 10;
        }
        else
            hours = 1;

        if (time[3] == '?' && time[4] == '?')
            minutes = 60;
        else if (time[3] == '?')
            minutes = 6;
        else if (time[4] == '?')
            minutes = 10;
        else
            minutes = 1;
        return hours * minutes;
    }
};