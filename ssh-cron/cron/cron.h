#ifndef INCLUDED_CRON_
#define INCLUDED_CRON_

#include <set>
#include <iosfwd>

#include <bobcat/fork>
#include <bobcat/pipe>

#include "../ipcfunction/ipcfunction.h"

namespace FBB
{
    class DateTime;
    class SharedStream;
}

class CronEntry;
class CronData;
class Options;

class Cron: public IPCFunction, public FBB::Fork
{
    enum EndOfRun
    {};

    Options &d_options;
    CronData &d_cronData;

    FBB::Pipe d_childInput;     // child reads this
    
    std::ostream *d_toChild = 0;

    std::string d_passPhrase;

    volatile bool d_run = true;     // set to false by stop

    static std::string s_agent;
    
    public:
        Cron(CronData &cronData);
        void runParentProcess();
        void stop(size_t signal);
        void setPassPhrase(std::string const &passPhrase);

        static Function readRequest(std::istream &in);
        static void writeRequest(std::ostream &out, Function value);
        static std::string hmac2str(std::string const &passPhrase);
    
    private:
        void childRedirections()    override;
        void childProcess()         override;
        void parentProcess()        override;

        std::ostream &idmsg() const;        // imsg << "scheduler: "
        std::ostream &scheduler() const;    // d_options.msg() << "scheduler: "

        void defineRunFunction();
        void sendCommand(std::string line);
        void cronLoop();
        void runCronJobs();
        bool call(FBB::DateTime const &now, CronEntry const &entry);
        void execute(CronEntry const &entry);
        void handleRequests();      // separate thread

        void list(size_t *index, std::streamsize offset,
                  FBB::SharedStream &sharedStream);

        bool reload(std::istream &in);

        static bool specified(size_t value, std::set<size_t> const &request);
        static void requestHandler(Cron *cron);
        static std::string hmac(std::string const &passPhrase);
};

inline void Cron::setPassPhrase(std::string const &passPhrase)
{
    d_passPhrase = hmac(passPhrase);
}

#endif





