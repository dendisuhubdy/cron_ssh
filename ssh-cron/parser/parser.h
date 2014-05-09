// Generated by Bisonc++ V4.08.00 on Fri, 09 May 2014 11:23:30 +0200

#ifndef Parser_h_included
#define Parser_h_included

// $insert baseclass
#include "parserbase.h"
// $insert scanner.h
#include "../scanner/scanner.h"


#undef Parser
class Parser: public ParserBase
{
    // $insert scannerobject
    Scanner d_scanner;

    std::set<int> d_minutes;
    std::set<int> d_hours;
    std::set<int> d_dayOfMonth;
    std::set<int> d_monthOfYear;
    std::set<int> d_dayOfWeek;

    static bool s_errors;           // set by the 'off' manipulator

    public:
        int parse();

    private:
        void addSet(std::set<int> &lhs, std::set<int> const &rhs) const;
        void defineRange(std::set<int> &lhs, std::set<int> const &rhs) const;
        std::set<int> acceptNr() const;

        static std::ostream &off(std::ostream &mstream);

        void error(char const *msg);    // called on (syntax) errors
        int lex();                      // returns the next token from the
                                        // lexical scanner. 
        void print();                   // use, e.g., d_token, d_loc

    // support functions for parse():
        void executeAction(int ruleNr);
        void errorRecovery();
        int lookup(bool recovery);
        void nextToken();
        void print__();
        void exceptionHandler__(std::exception const &exc);
};


#endif
