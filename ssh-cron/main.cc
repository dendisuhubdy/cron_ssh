#include "main.ih"

// Room for Args initialization
namespace   // the anonymous namespace can be used here
{
    Arg::LongOption longOptions[] =
    {
        Arg::LongOption("agent", Arg::Required),
        Arg::LongOption("config", 'c'),

        Arg::LongOption("help", 'h'),
        Arg::LongOption("list", 'l'),
        Arg::LongOption("log",  'L'),

        Arg::LongOption("no-daemon", Arg::None),
        Arg::LongOption("no-syslog", Arg::None),

        Arg::LongOption("pid-file", 'p'),

        Arg::LongOption("reload", 'r'),

        Arg::LongOption("stdout", 's'),

        Arg::LongOption("syslog-facility", Arg::Required),
        Arg::LongOption("syslog-priority", Arg::Required),
        Arg::LongOption("syslog-tag", Arg::Required),

        Arg::LongOption("terminate", 't'),

        Arg::LongOption("verbose", Arg::None),
        Arg::LongOption("version", 'v'),
    };

    auto longEnd = longOptions + sizeof(longOptions) / sizeof(longOptions[0]);
}

int main(int argc, char **argv)
try
{
    ArgConfig &arg = ArgConfig::initialize("c:hl:L:p:rstv", 
                        longOptions, longEnd, argc, argv);
    
    arg.versionHelp(usage, Icmbuild::version, 0);

    Daemon daemon;

    if (not Options::instance().daemon())
        daemon.runParentProcess();
    else
        daemon.fork();
}
catch (exception const &exc)
{
    cerr << exc.what() << endl;
}
catch (int x)
{
    return ArgConfig::instance().option("hv") ? 0 : x;
}


