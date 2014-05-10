#ifndef INCLUDED_CRONDATA_
#define INCLUDED_CRONDATA_

#include <string>
#include <set>
#include <vector>

class CronData
{
    struct Entry
    {
        std::set<size_t>    minutes;
        std::set<size_t>    hours;
        std::set<size_t>    dayOfMonth;
        std::set<size_t>    monthOfYear;
        std::set<size_t>    dayOfWeek;
    
        std::string         command;
    };

    Entry d_next;

    std::string d_entryName;
    size_t d_entryEnd = 60;

    std::vector<Entry> d_entry;

    std::set<size_t> d_wip;

    std::vector<std::string> d_names;
    std::string d_command;

    size_t d_lineNr;
    bool d_all = false;

    static size_t s_values[60];

    public:
        CronData();

        void addNr(size_t nr);
        void addRange(size_t first, size_t last, size_t step);
        void setAll(size_t step);
        void addName(std::string const &str);
        void setCommand(std::string const &command);
        void process();
        void reset(size_t lineNr = 0);  // 0 means: do not update lineNr

        void setMinutes();
        void setHours();
        void setDayOfMonth();
        void setMonthOfYear();
        void setDayOfWeek();
        
    private:
        void invalidRange(size_t first, size_t last) const;
        void outOfRange(size_t nr) const;

};
        
#endif
